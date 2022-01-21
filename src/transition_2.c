/*
** EPITECH PROJECT, 2022
** transition
** File description:
** Functions to create, display transition
*/

#include "runner.h"

void transitionwin2(sfRenderWindow *window, runner_t *runner)
{
    for (int i = 0; i < 5; i++)
            display_back(window, runner->backlist[i]);
    display_transition(window, runner->transition);
    if (sfClock_getElapsedTime(runner->clockback).microseconds > 25000.0) {
        move_recttransition(&runner->transition.recttransition, 272, 6256);
        sfClock_restart(runner->clockback);
    }
}

void transitionwin(sfRenderWindow *window, runner_t *runner)
{
    if (runner->dino.positiondino.x < 1930) {
        if (runner->dinostate != NORMAL && runner->dinostate != CROUCH)
            jump(window, runner);
        winanimation(window, runner);
    } else if (runner->transition.recttransition.left < 6256) {
        transitionwin2(window, runner);
    } else {
        runner->transition.recttransition = (sfIntRect) {0, 0, 6528, 178};
        sfClock_restart(runner->clockback);
        runner->menustate = GAMEWIN;
    }
}

void transitionmenu(sfRenderWindow *window, runner_t *runner)
{
    if (runner->transition.recttransition.left < 6256) {
        for (int i = 0; i < 5; i++)
            display_back(window, runner->backlist[i]);
        display_transition(window, runner->transition);
        if (sfClock_getElapsedTime(runner->clockback).microseconds > 25000.0) {
            move_recttransition(&runner->transition.recttransition, 272, 6256);
            sfClock_restart(runner->clockback);
        }
    } else {
        runner->transition.recttransition = (sfIntRect) {0, 0, 6528, 178};
        sfClock_restart(runner->clockback);
        runner->loadstate = GAMELOAD;
        runner->menustate = MENU;
    }
}
