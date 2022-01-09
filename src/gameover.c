/*
** EPITECH PROJECT, 2022
** gameover
** File description:
** Function if the game is over
*/

#include "runner.h"

void check_mouse_go(sfRenderWindow *window, runner_t *runner)
{
    sfFloatRect pa = {sfSprite_getPosition(runner->boutonlist[2].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[2].s_bouton).y, 144, 89};
    sfFloatRect menu = {sfSprite_getPosition(runner->boutonlist[3].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[3].s_bouton).y, 144, 50};
    sfFloatRect quit = {sfSprite_getPosition(runner->boutonlist[1].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[1].s_bouton).y, 144, 50};
    float posmousex = sfMouse_getPositionRenderWindow(window).x;
    float posmousey = sfMouse_getPositionRenderWindow(window).y;
    runner->valid[2] = sfFloatRect_contains(&pa, posmousex, posmousey);
    runner->valid[3] = sfFloatRect_contains(&menu, posmousex, posmousey);
    runner->valid[1] = sfFloatRect_contains(&quit, posmousex, posmousey);
}

void clock_go(sfRenderWindow *window, runner_t *runner)
{
    if (sfClock_getElapsedTime(runner->clockdino).microseconds > 50000.0) {
        if (runner->dinostate == DEAD)
            runner->dino.positiondino.y += 25;
        move_rectsnowman(&runner->scoreicon.rectgold, 12, 84);
        if (runner->dinostate == CROUCH) {
            move_rectdino(&runner->dino.rectdino, 0, 18, 108);
        } else if (runner->dinostate != DEAD) {
            move_rectdino(&runner->dino.rectdino, 0, 15, 105);
        }
        sfClock_restart(runner->clockdino);
    }
    if (sfClock_getElapsedTime(runner->clockdinodead).
    microseconds > 100000.0) {
        if (runner->dino.rectdino.left < 90 && runner->dinostate == DEAD)
            move_rectdino(&runner->dino.rectdino, 0, 15, 90);
        sfClock_restart(runner->clockdinodead);
    }
}

void go_check_animation(sfRenderWindow *window, runner_t *runner)
{
    if (runner->dinostate != NORMAL && runner->dinostate != CROUCH) {
        clock_go(window, runner);
        jump(window, runner);
        display_dino(window, runner->dino);
    } else if (runner->dinostate == CROUCH) {
        runner->dinostate = NORMAL;
    }
    if (runner->dinostate == NORMAL) {
        runner->dino.t_dino = runner->all_t_dino_d[runner->texturedino];
        runner->dino.rectdino = (sfIntRect) {0, 0, 15, 18};
        sfClock_restart(runner->clockdinodead);
        runner->dinostate = DEAD;
    }
    if (runner->dinostate == DEAD) {
        clock_go(window, runner);
        display_dino(window, runner->dino);
    }
}

void goanimation(sfRenderWindow *window, runner_t *runner)
{
    if (sfMusic_getStatus(runner->deadmusic) == 0) {
        sfMusic_play(runner->deadmusic);
    }
    for (int i = 0; i < 5; i++) {
        display_back(window, runner->backlist[i]);
    }
    display_s(window, runner);
    display_chainmob(window, runner);
    display_dino(window, runner->dinoreflect);
    go_check_animation(window, runner);
}

void switch_windowgo(sfRenderWindow *window, runner_t *runner)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && runner->valid[2] == 1) {
        sfMusic_stop(runner->gamemusic);
        reset_game(runner);
        game_init(runner);
        runner->menustate = TRANSITION;
        sfMusic_stop(runner->menumusic);
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && runner->valid[3] == 1) {
        sfMusic_stop(runner->gamemusic);
        runner->menustate = TRANSITIONMENU;
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && runner->valid[1] == 1) {
        destroy_init(runner);
        sfRenderWindow_close(window);
        return;
    }
}
