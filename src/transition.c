/*
** EPITECH PROJECT, 2022
** transition
** File description:
** Functions to create, display transition
*/

#include "runner.h"

transition_t c_transi(const char *texture, sfVector2f pos, sfIntRect rect)
{
    transition_t transi;
    transi.t_transition = sfTexture_createFromFile(texture, NULL);
    transi.s_transition = sfSprite_create();
    transi.positiontransition = pos;
    transi.recttransition = rect;
    sfVector2f resize = {7, 6.1};
    transi.resize = resize;
    sfSprite_setTexture(transi.s_transition, transi.t_transition, sfTrue);
    sfSprite_setPosition(transi.s_transition, transi.positiontransition);
    sfSprite_setScale(transi.s_transition, transi.resize);
    return (transi);
}

void move_recttransition(sfIntRect *rect, int modify, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = modify;
    } else {
        rect->left += modify;
    }
}

void display_transition(sfRenderWindow *window, transition_t transi)
{
    sfSprite_setTexture(transi.s_transition, transi.t_transition, sfTrue);
    sfSprite_setPosition(transi.s_transition, transi.positiontransition);
    sfSprite_setTextureRect(transi.s_transition, transi.recttransition);
    sfSprite_setScale(transi.s_transition, transi.resize);
    sfRenderWindow_drawSprite(window, transi.s_transition, NULL);
}

void transitiongo2(sfRenderWindow *window, runner_t *runner)
{
    for (int i = 0; i < 5; i++)
        display_back(window, runner->backlist[i]);
    display_transition(window, runner->transition);
    if (sfClock_getElapsedTime(runner->clockback).microseconds > 25000.0) {
        move_recttransition(&runner->transition.recttransition, 272, 6256);
        sfClock_restart(runner->clockback);
    }
}

void transitiongo(sfRenderWindow *window, runner_t *runner)
{
    if (runner->dino.positiondino.y < 1880) {
        goanimation(window, runner);
    } else if (runner->transition.recttransition.left < 6256) {
        transitiongo2(window, runner);
    } else {
        runner->transition.recttransition = (sfIntRect) {0, 0, 6528, 178};
        sfClock_restart(runner->clockback);
        runner->menustate = GAMEOVER;
    }
}
