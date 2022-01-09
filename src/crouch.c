/*
** EPITECH PROJECT, 2022
** crouch
** File description:
** Functions to crouch
*/

#include "runner.h"

void set_to_crouch(runner_t *runner)
{
    runner->dino.t_dino = runner->all_t_dino_c[runner->texturedino];
    runner->dinoreflect.t_dino =
    runner->all_t_dino_c_r[runner->texturedino];
    runner->dino.positiondino.y = 540;
    runner->dinoreflect.positiondino.y = 760;
    runner->dino.rectdino = (sfIntRect) {0, 0, 18, 15};
    runner->dinoreflect.rectdino = (sfIntRect) {0, 0, 18, 15};
    runner->dinostate = CROUCH;
}

void set_to_normal(runner_t *runner)
{
    runner->dino.t_dino = runner->all_t_dino[runner->texturedino];
    runner->dinoreflect.t_dino = runner->all_t_dino_r[runner->texturedino];
    runner->dino.positiondino.y = 525;
    runner->dinoreflect.positiondino.y = 760;
    runner->dino.rectdino = (sfIntRect) {0, 0, 15, 17};
    runner->dinoreflect.rectdino = (sfIntRect) {0, 0, 15, 17};
    runner->dinostate = NORMAL;
}

void crouch(sfRenderWindow *window, runner_t *runner)
{
    if (runner->dinostate == NORMAL && runner->event.type == sfEvtKeyPressed
    && runner->event.key.code == sfKeyLShift) {
        set_to_crouch(runner);
    }
    if (runner->dinostate == CROUCH && runner->event.type == sfEvtKeyReleased
    && runner->event.key.code == sfKeyLShift) {
        set_to_normal(runner);
    }
}
