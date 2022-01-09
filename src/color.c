/*
** EPITECH PROJECT, 2022
** color
** File description:
** Functions to manage colors
*/

#include "runner.h"

void change_path_color(sfRenderWindow *window, runner_t *runner)
{
    if (runner->texturedino == 0) {
        runner->boutonlist[6].t_bouton = runner->all_t_dino[0];
        runner->dino.t_dino = runner->all_t_dino[0];
        runner->dinoreflect.t_dino = runner->all_t_dino_r[0];
    }
    if (runner->texturedino == 1) {
        runner->boutonlist[6].t_bouton = runner->all_t_dino[1];
        runner->dino.t_dino = runner->all_t_dino[1];
        runner->dinoreflect.t_dino = runner->all_t_dino_r[1];
    }
    if (runner->texturedino == 2) {
        runner->boutonlist[6].t_bouton = runner->all_t_dino[2];
        runner->dino.t_dino = runner->all_t_dino[2];
        runner->dinoreflect.t_dino = runner->all_t_dino_r[2];
    }
    if (runner->texturedino == 3) {
        runner->boutonlist[6].t_bouton = runner->all_t_dino[3];
        runner->dino.t_dino = runner->all_t_dino[3];
        runner->dinoreflect.t_dino = runner->all_t_dino_r[3];
    }
}

void switch_color(sfRenderWindow *window, runner_t *runner)
{
    if (runner->valid[6] == 1 && runner->event.type == sfEvtMouseButtonPressed
    && runner->event.key.code == sfMouseLeft) {
        runner->texturedino += 1;
        if (runner->texturedino > 3)
            runner->texturedino = 0;
        change_path_color(window, runner);
    }
}
