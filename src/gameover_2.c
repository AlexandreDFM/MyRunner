/*
** EPITECH PROJECT, 2022
** gameover
** File description:
** Function if the game is over
*/

#include "runner.h"

void menugo(sfRenderWindow *window, runner_t *runner)
{
    if (runner->loadstate == GAMELOAD) {
        change_butons_coord_go(runner);
        reset_game(runner);
        game_init(runner);
        runner->dinostate = NORMAL;
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
