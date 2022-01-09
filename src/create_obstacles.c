/*
** EPITECH PROJECT, 2021
** create_enemies
** File description:
** Function to create enemies
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *fs_open_file(char *mappath)
{
    char *buffer = malloc(sizeof(char)*(157 + 1));
    int fd = open(mappath, O_RDONLY);
    int total_read = 0, n_read = 0;
    while ((n_read = read(fd, buffer + total_read,
    (157 + 1) - total_read)) > 0) {
        total_read += n_read;
    }
    buffer[157] = '\0';
    return (buffer);
}

void parse2(int i, char *map, chainmob_t mob, chainmob_t *chainmobglobal)
{
    if (map[i] == '3') {
        my_snowman(i, map, mob, chainmobglobal);
        return;
    }
    if (map[i] == '4') {
        my_gold(i, map, mob, chainmobglobal);
        return;
    }
    if (map[i] == '5') {
        my_flag(i, map, mob, chainmobglobal);
        return;
    }
}

void parse(int i, char *map, chainmob_t mob, chainmob_t *chainmobglobal)
{
    if (map[i] != '1' && map[i] != '2' && map[i] != '3'
    && map[i] != '4' && map[i] != '5') {
        mob.countain = 0;
        chainmobglobal[i] = mob;
        return;
    }
    if (map[i] == '1') {
        my_snowman(i, map, mob, chainmobglobal);
        return;
    }
    if (map[i] == '2') {
        my_flysnowman(i, map, mob, chainmobglobal);
        return;
    }
    parse2(i, map, mob, chainmobglobal);
}

chainmob_t *parsemap(char *mappath, runner_t *runner)
{
    char *map = fs_open_file(mappath);
    runner->map = map;
    chainmob_t chainmob;
    chainmob_t *chainmobglobal = malloc(sizeof(chainmob_t)*my_strlen(map));
    for (int i = 0; map[i] != '\0'; i++) {
        parse(i, map, chainmob, chainmobglobal);
    }
    return (chainmobglobal);
}
