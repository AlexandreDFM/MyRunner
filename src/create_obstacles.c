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

void switchparse(int i, char *map, chainmob_t mob, chainmob_t *chainmobglobal)
{
    switch (map[i])
    {
        case '1' :
            my_snowman(i, map, mob, chainmobglobal);
            break;
        case '2' :
            my_flysnowman(i, map, mob, chainmobglobal);
            break;
        case '3' :
            my_snowman(i, map, mob, chainmobglobal);
            break;
        case '4' :
            my_gold(i, map, mob, chainmobglobal);
            break;
        case '5' :
            my_flag(i, map, mob, chainmobglobal);
            break;
        default :
            mob.countain = 0;
            chainmobglobal[i] = mob;
        break;
    }
}

chainmob_t *parsemap(char *mappath, runner_t *runner)
{
    char *map = fs_open_file(mappath);
    runner->map = map;
    chainmob_t chainmob;
    //my_putstr(map);
    chainmob_t *chainmobglobal = malloc(sizeof(chainmob_t)*my_strlen(map));
    for (int i = 0; map[i] != '\0'; i++) {
        switchparse(i, map, chainmob, chainmobglobal);
    }
    return (chainmobglobal);
}