/*
** EPITECH PROJECT, 2021
** game
** File description:
** Display Game
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <stdlib.h>

// framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
// {
//     framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
//     framebuffer->width = width;
//     framebuffer->height = height;
//     framebuffer->pixels = malloc(sizeof(sfUint8)*(width*height*4));
//     return framebuffer;
// }

// void mypp(framebuffer_t *fbuffer, unsigned int x, unsigned int y, sfColor color)
// {
//     fbuffer->pixels[x*y + 0] = color.r;
//     fbuffer->pixels[x*y + 1] = color.g;
//     fbuffer->pixels[x*y + 2] = color.b;
//     fbuffer->pixels[x*y + 3] = color.a;
// }

void check_collision(sfRenderWindow *window, runner_t *runner)
{
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 1 &&
        check_snowman(window, runner->chainmob[i].snowman, runner) == 1) {
            runner->menustate = GAMEOVER;
            sfMusic_stop(runner->gamemusic);
        }
    }
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 2 &&
        check_flysnowman(window, runner->chainmob[i].flysnowman, runner) == 1) {
            runner->menustate = GAMEOVER;
            sfMusic_stop(runner->gamemusic);
        }
    }
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 3 &&
        check_snowman(window, runner->chainmob[i].snowman, runner) == 1) {
            runner->menustate = GAMEOVER;
            sfMusic_stop(runner->gamemusic);
        }
    }
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 4 &&
        check_gold(window, runner->chainmob[i].gold, runner) == 1) {
            //sfSound_play(runner->coinsound);
            //sfMusic_play(runner->coinsound);
            runner->scorenb += 100;
            //framebuffer_t *framebuffer = framebuffer_create(1920, 1080);
            // sfUint8 *pixels = malloc(sizeof(sfUint8)*12*12*4);
            // sfTexture *texture = sfTexture_create(12, 12);
            // for (int x = 0; x < 12; x++) {
            //     for (int y = 0; y < 12; y++) {
            //         pixels[y * 12 + x + 0] = 255;
            //         pixels[y * 12 + x + 1] = 255;
            //         pixels[y * 12 + x + 2] = 255;
            //         pixels[y * 12 + x + 3] = 255;
            //     }
            // }
            // sfTexture_updateFromPixels(texture, (sfUint8*) pixels, 12, 12, 0, 0);
            // sfSprite_setTexture(runner->chainmob[i].gold.s_gold, texture, sfTrue);
            // sfRenderWindow_drawSprite(window, runner->chainmob[i].gold.s_gold, NULL);
            // sfRenderWindow_display(window);
            runner->chainmob[i].countain = 0;
        }
    }
    for (int i = 0; i < my_strlen(runner->map); i++) {
        if (runner->chainmob[i].countain == 5 &&
        check_flag(window, runner->chainmob[i].flag, runner) == 1) {
            runner->menustate = GAMEWIN;
            sfMusic_stop(runner->gamemusic);
        }
    }
}

void game(sfRenderWindow *window, runner_t *runner)
{
    if (sfMusic_getStatus(runner->gamemusic) == 0) {
        sfMusic_play(runner->gamemusic);
        //runner->musicplayed = 1;
    }
    clock_game(runner);
    for (int i = 0; i < 5; i++) {
        display_back(window, runner->backlist[i]);
    }
    display_s(window, runner);
    jump(window, runner);
    display_chainmob(window, runner);
    check_collision(window, runner);
    display_dino(window, runner->dino);
    display_dino(window, runner->dinoreflect);
}
