/*
** EPITECH PROJECT, 2021
** game
** File description:
** Display Game
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <stdlib.h>

void check_collision3(sfRenderWindow *window, runner_t *runner)
{
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 5 &&
        check_flag(window, runner->chainmob[i].flag, runner) == 1) {
            runner->menustate = TRANSITIONWIN;
            sfMusic_stop(runner->gamemusic);
        }
    }
}

void check_collision2(sfRenderWindow *window, runner_t *runner)
{
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 3 &&
        check_snowman(window, runner->chainmob[i].snowman, runner) == 1) {
            runner->menustate = TRANSITIONGO;
            sfMusic_stop(runner->gamemusic);
        }
    }
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 4 &&
        check_gold(window, runner->chainmob[i].gold, runner) == 1) {
            sfSound_play(runner->coinsound);
            runner->scorenb += 100;
            runner->chainmob[i].countain = 0;
        }
    }
}

void check_collision(sfRenderWindow *window, runner_t *runner)
{
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 1 &&
        check_snowman(window, runner->chainmob[i].snowman, runner) == 1) {
            runner->menustate = TRANSITIONGO;
            sfMusic_stop(runner->gamemusic);
        }
    }
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 2 &&
        check_fsnowman(window, runner->chainmob[i].flysnowman, runner) == 1) {
            runner->menustate = TRANSITIONGO;
            sfMusic_stop(runner->gamemusic);
        }
    }
    check_collision2(window, runner);
    check_collision3(window, runner);
}

void game(sfRenderWindow *window, runner_t *runner)
{
    if (runner->loadstate == GAMEUNLOAD) {
        runner->loadstate = GAMELOAD;
    }
    if (sfMusic_getStatus(runner->gamemusic) == 0) {
        sfMusic_play(runner->gamemusic);
    }
    game_clock(runner);
    for (int i = 0; i < 5; i++) {
        display_back(window, runner->backlist[i]);
    }
    jump(window, runner);
    display_chainmob(window, runner);
    check_collision(window, runner);
    display_dino(window, runner->dino);
    display_dino(window, runner->dinoreflect);
    display_s(window, runner);
}
