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
        sfMusic_destroy(runner->menumusic);
        sfMusic_destroy(runner->gamemusic);
        sfRenderWindow_close(window);
        return;
    }
}

void menugo(sfRenderWindow *window, runner_t *runner)
{
    if (runner->loadstate == GAMELOAD) {
        change_butons_coord_go(runner);
        reset_game(runner);
        game_init(runner);
        runner->loadstate = GAMEUNLOAD;
    }
    if (sfMusic_getStatus(runner->menumusic) == 0) {
        sfMusic_play(runner->menumusic);
    }
    for (int i = 0; i < 5; i++)
        display_back(window, runner->backlist[i]);
    for (int i = 1; i < 4; i++)
        display_bouton(window, runner->boutonlist[i]);
    check_mouse_go(window, runner);
    switch_windowgo(window, runner);
    cursor(window, runner->cursor);
}
