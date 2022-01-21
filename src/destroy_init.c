/*
** EPITECH PROJECT, 2022
** destroy_init
** File description:
** Function to destroy init
*/

#include "runner.h"
#include <stdlib.h>

void reset_game(runner_t *runner)
{
    sfFont_destroy(runner->font);
    sfText_destroy(runner->score);
    runner->chainmob = parsemap(runner->pathmap, runner);
    sfClock_destroy(runner->clockback);
    sfClock_destroy(runner->clockback2);
    sfClock_destroy(runner->clockcloud);
    sfClock_destroy(runner->clockdino);
    sfMusic_destroy(runner->menumusic);
    sfMusic_destroy(runner->gamemusic);
}

void reset_game2(runner_t *runner)
{
    sfFont_destroy(runner->font);
    sfText_destroy(runner->score);
    free(runner->chainmob);
    sfClock_destroy(runner->clockback);
    sfClock_destroy(runner->clockback2);
    sfClock_destroy(runner->clockcloud);
    sfClock_destroy(runner->clockdino);
}

void destroy_music(runner_t *runner)
{
    if (runner->menumusic) {
        sfMusic_stop(runner->menumusic);
        sfMusic_destroy(runner->menumusic);
    }
    if (runner->gamemusic) {
        sfMusic_stop(runner->gamemusic);
        sfMusic_destroy(runner->gamemusic);
    }
    if (runner->deadmusic) {
        sfMusic_stop(runner->deadmusic);
        sfMusic_destroy(runner->deadmusic);
    }
    if (runner->victorymusic) {
        sfMusic_stop(runner->victorymusic);
        sfMusic_destroy(runner->victorymusic);
    }
    if (runner->coinsound) {
        sfSound_stop(runner->coinsound);
        sfSound_destroy(runner->coinsound);
        sfSoundBuffer_destroy(runner->coinbuffer);
    }
}

void destroy_init(runner_t *runner)
{
    reset_game2(runner);
    sfText_destroy(runner->thighscore);
    sfClock_destroy(runner->clockdinodead);
    destroy_music(runner);
    return;
}
