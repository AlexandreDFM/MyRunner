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
#include <stdio.h>
#include <unistd.h>

char *fs_open_file(char *mappath, int size_of_read)
{
    char *buffer = malloc(sizeof(char) * (size_of_read + 1));
    int fd = open(mappath, O_RDONLY);
    int total_read = 0, n_read = 0;
    while ((n_read = read(fd, buffer + total_read,
    (size_of_read + 1) - total_read)) > 0) {
        total_read += n_read;
    }
    buffer[size_of_read] = '\0';
    return (buffer);
}

int count_int_read(char *mappath)
{
    char *map = "";
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    int read_size = 0;
    ssize_t line_size;
    FILE *fp = fopen(mappath, "r");
    if (!fp) {
        return 84;
    }
    line_size = getline(&line_buf, &line_buf_size, fp);
    while (line_size >= 0) {
        line_count++;
        read_size += (int) line_size;
        line_size = getline(&line_buf, &line_buf_size, fp);
    }
    free(line_buf);
    line_buf = NULL;
    fclose(fp);
    return read_size;
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
    if (map[i] != '1' && map[i] != '2'
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
    int size_of_read = count_int_read(mappath);
    char *map = fs_open_file(mappath, size_of_read);
    runner->map = map;
    chainmob_t chainmob;
    chainmob_t *chainmobglobal = malloc(sizeof(chainmob_t)*my_strlen(map));
    for (int i = 0; map[i] != '\0'; i++) {
        parse(i, map, chainmob, chainmobglobal);
    }
    return (chainmobglobal);
}
