/*
** EPITECH PROJECT, 2022
** pause
** File description:
** Function if the game is in pause state
*/

#include "runner.h"

void gamepause(sfRenderWindow *window, runner_t *runner)
{
    for (int i = 0; i < 5; i++) {
        display_back(window, runner->backlist[i]);
    }
    display_s(window, runner);
    display_chainmob(window, runner);
    display_dino(window, runner->dino);
    display_dino(window, runner->dinoreflect);
    for (int i = 0; i < 2; i++)
        display_bouton(window, runner->boutonlist[i]);
    check_mouse(window, runner);
    switch_window(window, runner);
}