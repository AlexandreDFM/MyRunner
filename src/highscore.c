/*
** EPITECH PROJECT, 2022
** Highscore
** File description:
** Functions to display and create highscore
*/

#include "runner.h"
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int create_highscore(runner_t *runner)
{
    int size_of_read = count_int_read("./highscore/highscore.txt");
    char *highscore = fs_open_file("./highscore/highscore.txt", size_of_read);
    runner->highscore = highscore;
}

void open_write(runner_t *runner)
{
    char *newscore = my_put_nbrstr(runner->scorenb / 10);
    my_revstr(newscore);
    int fd = open("./highscore/highscore.txt", O_WRONLY);
    write(fd, newscore, my_strlen(newscore));
    write(fd, "\n", 1);
}

void check_highscore(runner_t *runner)
{
    int oldhighscore = my_getnbr(runner->highscore);
    if (oldhighscore < runner->scorenb) {
        open_write(runner);
    }
}

void display_thighscore(sfRenderWindow *window, runner_t *runner)
{
    sfText_setString(runner->thighscore, "HIGHSCORE :");
    sfText_setFont(runner->thighscore, runner->font);
    sfText_setCharacterSize(runner->thighscore, 40);
    sfText_setPosition(runner->thighscore, (sfVector2f) {600, 980});
    sfRenderWindow_drawText(window, runner->thighscore, NULL);
}

void display_highscore(sfRenderWindow *window, runner_t *runner)
{
    display_thighscore(window, runner);
    sfText_setString(runner->score, make_highscore(runner));
    sfText_setFont(runner->score, runner->font);
    sfText_setCharacterSize(runner->score, 40);
    sfText_setPosition(runner->score, (sfVector2f) {1100, 980});
    sfRenderWindow_drawText(window, runner->score, NULL);
}
