/*
** EPITECH PROJECT, 2022
** gamewin
** File description:
** Functions if the game is win
*/

#include "runner.h"

void clock_win(sfRenderWindow *window, runner_t *runner)
{
    if (sfClock_getElapsedTime(runner->clockdino).microseconds > 50000.0) {
        runner->dino.positiondino.x += 10;
        runner->dinoreflect.positiondino.x += 10;
        move_rectsnowman(&runner->scoreicon.rectgold, 12, 84);
        if (runner->dinostate == CROUCH) {
            move_rectdino(&runner->dino.rectdino, 0, 18, 108);
            move_rectdino(&runner->dinoreflect.rectdino, 0, 18, 108);
        } else {
            move_rectdino(&runner->dino.rectdino, 0, 15, 105);
            move_rectdino(&runner->dinoreflect.rectdino, 0, 15, 105);
        }
        sfClock_restart(runner->clockdino);
    }
}

void winanimation(sfRenderWindow *window, runner_t *runner)
{
    if (sfMusic_getStatus(runner->victorymusic) == 0) {
        sfMusic_play(runner->victorymusic);
    }
    for (int i = 0; i < 5; i++) {
        display_back(window, runner->backlist[i]);
    }
    clock_win(window, runner);
    display_s(window, runner);
    display_chainmob(window, runner);
    display_dino(window, runner->dino);
    display_dino(window, runner->dinoreflect);
}

void menuwin(sfRenderWindow *window, runner_t *runner)
{
    if (runner->loadstate == GAMELOAD) {
        reset_game(runner);
        game_init(runner);
    }
    reset_game(runner);
    game_init(runner);
    if (sfMusic_getStatus(runner->menumusic) == 0) {
        sfMusic_play(runner->menumusic);
    }
    for (int i = 5; i < 5; i++)
        display_back(window, runner->backlist[i]);
    runner->menustate = MENU;
}
