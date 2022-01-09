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

void clock_game(runner_t *runner)
{
    if (sfClock_getElapsedTime(runner->clockback).microseconds > 16700.0) {
        move_rectback(&runner->backlist[2].rectback, 1, 272);
        move_rectback(&runner->backlist[3].rectback, 1, 272);
        move_rectback(&runner->backlist[4].rectback, 1, 272);
        runner->scorenb += 1;
        for (int i = 0; runner->map[i] != '\0'; i++) {
            switch (runner->chainmob[i].countain)
            {
                case 1 :
                    runner->chainmob[i].snowman.positionsnowman.x -= 7.3;
                    break;
                case 2 :
                    runner->chainmob[i].flysnowman.positionflysnowman.x -= 7.3;
                    break;
                // case 3 :
                //     runner->chainmob[i].snowman.positionsnowman.x -= 7.3;
                //     break;
                case 4 :
                    runner->chainmob[i].gold.positiongold.x -= 7.3;
                    break;
                case 5 :
                    runner->chainmob[i].flag.positionflag.x -= 7.3;
                    break;
            }
        }
        sfClock_restart(runner->clockback);
    }
    if (sfClock_getElapsedTime(runner->clockback2).microseconds > 20000.0) {
        move_rectback(&runner->backlist[1].rectback, 1, 272);
        sfClock_restart(runner->clockback2);
    }
    if (sfClock_getElapsedTime(runner->clockdino).microseconds > 50000.0) {
        for (int i = 0; runner->map[i] != '\0'; i++) {
            switch (runner->chainmob[i].countain)
                {
                    case 1 :
                        break;
                    case 2 :
                        move_rectsnowman(&runner->chainmob[i].flysnowman.rectflysnowman, 34, 102);
                        break;
                    // case 3 :
                    //     break;
                    case 4 :
                        move_rectsnowman(&runner->chainmob[i].gold.rectgold, 12, 84);
                        break;
                    case 5 :
                        break;
                }
        }
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

void close_window(sfRenderWindow *window, runner_t *runner)
{
    if (runner->event.type == sfEvtClosed ||
    (runner->event.type == sfEvtKeyPressed &&
    runner->event.key.code == sfKeyBackspace)) {
        if (runner->menumusic) {
            sfMusic_stop(runner->menumusic);
            sfMusic_destroy(runner->menumusic);
        }
        if (runner->gamemusic) {
            sfMusic_stop(runner->gamemusic);
            sfMusic_destroy(runner->gamemusic);
        }
        sfRenderWindow_close(window);
    }
}

void boucle(sfRenderWindow *window, runner_t *runner)
{
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            static int i = 0;
            runner->event = event;
            close_window(window, runner);
            if (runner->menustate == MENU) {
                switch_color(window, runner);
            }
            if (runner->menustate == GAME) {
                jumpevent(window, runner);
                crouch(window, runner);
            }
            if (runner->menustate == GAME &&
            event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
                runner->menustate = PAUSE;
        }
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
        sfRenderWindow_display(window);
    }
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
