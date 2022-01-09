/*
** EPITECH PROJECT, 2022
** jump
** File description:
** Functions to manage jumps actions
*/

#include "runner.h"

void jumpevent(sfRenderWindow *window, runner_t *runner)
{
    if (runner->dinostate != CROUCH) {
        if (runner->dinostate == NORMAL &&
        runner->event.type == sfEvtKeyPressed
        && runner->event.key.code == sfKeyRShift) {
            runner->dinovitesse.y = -25;
            runner->dinostate = JUMP;
        }
        if (runner->dinostate == JUMP && runner->event.type == sfEvtKeyReleased
        && runner->event.key.code == sfKeyRShift) {
            runner->dinovitesse.y = -runner->dinovitesse.y;
            runner->dinostate = FALL;
        }
        if (runner->dinostate == JUMPFINISH
        && runner->event.type != sfEvtKeyPressed
        && runner->event.key.code == sfKeyRShift) {
            runner->dinostate = NORMAL;
        }
    }
}

void up_jump(sfRenderWindow *window, runner_t *runner)
{
    runner->dino.positiondino.y += runner->dinovitesse.y;
    runner->dinoreflect.positiondino.y -= runner->dinovitesse.y;
    runner->dinovitesse.y += runner->gravity.y;
}

void fall_jump(sfRenderWindow *window, runner_t *runner)
{
    runner->dino.positiondino.y += runner->dinovitesse.y;
    runner->dinoreflect.positiondino.y -= runner->dinovitesse.y;
    runner->dinovitesse.y += runner->gravity.y;
    runner->dinostate = FALL;
}

void reset_jump(sfRenderWindow *window, runner_t *runner)
{
    runner->dinovitesse.y = -25;
    runner->dino.positiondino.y = 525;
    runner->dinoreflect.positiondino.y = 760;
    runner->dinostate = NORMAL;
}

void jump(sfRenderWindow *window, runner_t *runner)
{
    if (runner->dinostate != CROUCH) {
        if (runner->dinovitesse.y >= 0 && runner->dinostate == JUMP) {
            runner->dinovitesse.y = 0;
            runner->dinostate = FALL;
        }
        if (runner->dinovitesse.y <= 0 && runner->dinostate == JUMP) {
            up_jump(window, runner);
        } else if (runner->dino.positiondino.y >= 0
        && runner->dinostate == FALL) {
            fall_jump(window, runner);
        }
        if (runner->dino.positiondino.y >= 525 || runner->dinovitesse.y > 24
        && runner->dinostate == FALL) {
            reset_jump(window, runner);
        }
    }
}
