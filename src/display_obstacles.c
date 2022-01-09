/*
** EPITECH PROJECT, 2021
** display_obstacles
** File description:
** Function to display obstacles
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

void display_chainmob2(sfRenderWindow *window, runner_t *run, int i)
{
    if (run->chainmob[i].countain == 4) {
        display_gold(window, run->chainmob[i].gold);
    }
    if (run->chainmob[i].countain == 5) {
        display_flag(window, run->chainmob[i].flag);
    }
}

void display_chainmob(sfRenderWindow *window, runner_t *runner)
{
    for (int i = 0; runner->map[i] != '\0'; i++) {
        if (runner->chainmob[i].countain == 1) {
            display_snowman(window, runner->chainmob[i].snowman);
        }
        if (runner->chainmob[i].countain == 2) {
            display_flysnowman(window, runner->chainmob[i].flysnowman);
        }
        if (runner->chainmob[i].countain == 3) {
            display_snowman(window, runner->chainmob[i].snowman);
        }
        display_chainmob2(window, runner, i);
    }
}
