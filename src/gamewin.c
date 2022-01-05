/*
** EPITECH PROJECT, 2022
** gamewin
** File description:
** Functions if the game is win
*/

#include "runner.h"

void menuwin(sfRenderWindow *window, runner_t *runner)
{
    reset_game(runner);
    game_init(runner);
    if (sfMusic_getStatus(runner->menumusic) == 0) {
        sfMusic_play(runner->menumusic);
    }
    for (int i = 5; i < 5; i++)
        display_back(window, runner->backlist[i]);
    for (int i = 2; i < 2; i++)
        display_bouton(window, runner->boutonlist[i]);
    check_mouse(window, runner);
    switch_window(window, runner);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        runner->menustate = MENU;
}