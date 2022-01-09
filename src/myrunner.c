/*
** EPITECH PROJECT, 2021
** bsmyrunner
** File description:
** Boostrap of runner
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void close_window(sfRenderWindow *window, runner_t *runner)
{
    if (runner->event.type == sfEvtClosed ||
    (runner->event.type == sfEvtKeyPressed &&
    runner->event.key.code == sfKeyBackspace)) {
        destroy_init(runner);
        sfRenderWindow_close(window);
    }
}

void change_display(sfRenderWindow *window, runner_t *runner)
{
    if (runner->menustate == TRANSITION)
        transition(window, runner);
    if (runner->menustate == TRANSITIONMENU)
        transitionmenu(window, runner);
    if (runner->menustate == TRANSITIONWIN)
        transitionwin(window, runner);
    if (runner->menustate == TRANSITIONGO)
        transitiongo(window, runner);
    if (runner->menustate == MENU)
        menu(window, runner);
    if (runner->menustate == GAME)
        game(window, runner);
    if (runner->menustate == PAUSE)
        gamepause(window, runner);
    if (runner->menustate == GAMEOVER)
        menugo(window, runner);
    if (runner->menustate == GAMEWIN)
        menuwin(window, runner);
}

void boucle(sfRenderWindow *window, runner_t *runner)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &runner->event )) {
            close_window(window, runner);
            if (runner->menustate == MENU) {
                switch_color(window, runner);
            }
            if (runner->menustate == GAME) {
                jumpevent(window, runner);
                crouch(window, runner);
            }
            if (runner->menustate == GAME &&
            runner->event.type == sfEvtKeyPressed &&
            runner->event.key.code == sfKeyEscape)
                runner->menustate = PAUSE;
        }
        change_display(window, runner);
        sfRenderWindow_display(window);
    }
    destroy_init(runner);
}

int display_window(char *map)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    runner_t runner;
    runner.pathmap = map;
    create_a_party(&runner);
    char *name = "MyRunner Project";
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    boucle(window, &runner);
    if (window) {
        sfRenderWindow_close(window);
    }
}
