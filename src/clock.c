/*
** EPITECH PROJECT, 2022
** clock
** File description:
** Functions to manage clock functions
*/

#include "runner.h"

void first_clock(runner_t *runner)
{
    if (sfClock_getElapsedTime(runner->clockback).microseconds > 16700.0) {
        move_rectback(&runner->backlist[3].rectback, 1, 272);
        move_rectback(&runner->backlist[4].rectback, 1, 272);
        runner->scorenb += 1;
        for (int i = 0; runner->map[i] != '\0'; i++) {
            switch_first_clock(runner, i);
        }
        sfClock_restart(runner->clockback);
    }
}

void second_clock(runner_t *runner)
{
    if (sfClock_getElapsedTime(runner->clockcloud).microseconds > 20000.0) {
        move_rectback(&runner->backlist[2].rectback, 1, 272);
        sfClock_restart(runner->clockcloud);
    }
    if (sfClock_getElapsedTime(runner->clockback2).microseconds > 50000.0) {
        move_rectback(&runner->backlist[1].rectback, 1, 272);
        sfClock_restart(runner->clockback2);
    }
}

void game_clock(runner_t *runner)
{
    first_clock(runner);
    second_clock(runner);
    if (sfClock_getElapsedTime(runner->clockdino).microseconds > 50000.0) {
        third_clock(runner);
        move_rectsnowman(&runner->scoreicon.rectgold, 12, 84);
        if (runner->dinostate == CROUCH) {
            move_rectdino(&runner->dino.rectdino, 0, 18, 108);
            move_rectdino(&runner->dinoreflect.rectdino, 0, 18, 108);
        } else {
            move_rectdino(&runner->dino.rectdino, 0, 15, 105);
            move_rectdino(&runner->dinoreflect.rectdino, 0, 15, 105);
        }
        sfClock_restart(runner->clockdino);
    }
}
