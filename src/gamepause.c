/*
** EPITECH PROJECT, 2022
** pause
** File description:
** Function if the game is in pause state
*/

#include "runner.h"

void check_mouse_pause(sfRenderWindow *window, runner_t *runner)
{
    sfFloatRect ctn = {sfSprite_getPosition(runner->boutonlist[5].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[5].s_bouton).y, 144, 50};
    sfFloatRect rtry = {sfSprite_getPosition(runner->boutonlist[4].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[4].s_bouton).y, 144, 50};
    sfFloatRect menu = {sfSprite_getPosition(runner->boutonlist[3].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[3].s_bouton).y, 144, 50};
    sfFloatRect quit = {sfSprite_getPosition(runner->boutonlist[1].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[1].s_bouton).y, 144, 50};
    float posmousex = sfMouse_getPositionRenderWindow(window).x;
    float posmousey = sfMouse_getPositionRenderWindow(window).y;
    runner->valid[5] = sfFloatRect_contains(&ctn, posmousex, posmousey);
    runner->valid[4] = sfFloatRect_contains(&rtry, posmousex, posmousey);
    runner->valid[3] = sfFloatRect_contains(&menu, posmousex, posmousey);
    runner->valid[1] = sfFloatRect_contains(&quit, posmousex, posmousey);
}

void switch_window_pause2(sfRenderWindow *window, runner_t *runner)
{
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
    return;
}

void switch_window_pause(sfRenderWindow *window, runner_t *runner)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && runner->valid[5] == 1) {
        runner->menustate = GAME;
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && runner->valid[4] == 1) {
        sfMusic_stop(runner->gamemusic);
        reset_game(runner);
        game_init(runner);
        runner->menustate = TRANSITION;
        return;
    }
    switch_window_pause2(window, runner);
    return;
}

void gamepause(sfRenderWindow *window, runner_t *runner)
{
    if (runner->loadstate == GAMELOAD) {
        change_butons_coord_pause(runner);
        runner->loadstate = GAMEUNLOAD;
    }
    for (int i = 0; i < 5; i++) {
        display_back(window, runner->backlist[i]);
    }
    display_s(window, runner);
    display_chainmob(window, runner);
    display_dino(window, runner->dino);
    display_dino(window, runner->dinoreflect);
    display_bouton(window, runner->boutonlist[1]);
    display_bouton(window, runner->boutonlist[3]);
    display_bouton(window, runner->boutonlist[4]);
    display_bouton(window, runner->boutonlist[5]);
    check_mouse_pause(window, runner);
    switch_window_pause(window, runner);
    cursor(window, runner->cursor);
}
