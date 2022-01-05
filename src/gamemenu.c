/*
** EPITECH PROJECT, 2021
** menu
** File description:
** Display Functions for Menu
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

void check_mouse(sfRenderWindow *window, runner_t *runner)
{
    sfFloatRect play = {sfSprite_getPosition(runner->boutonlist[0].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[0].s_bouton).y, 144, 50};
    sfFloatRect quit = {sfSprite_getPosition(runner->boutonlist[1].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[1].s_bouton).y, 144, 50};
    sfFloatRect color = {sfSprite_getPosition(runner->boutonlist[4].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[4].s_bouton).y, 15*7, 17*6};
    float posmousex = sfMouse_getPositionRenderWindow(window).x;
    float posmousey = sfMouse_getPositionRenderWindow(window).y;
    runner->valid[0] = sfFloatRect_contains(&play, posmousex, posmousey);
    runner->valid[1] = sfFloatRect_contains(&quit, posmousex, posmousey);
    runner->valid[4] = sfFloatRect_contains(&color, posmousex, posmousey);
}

// void change_path_color(sfRenderWindow *window, runner_t *runner)
// {
//     char *texturedino[4] = {"./sprites/dino_run_blue.png",
//     "./sprites/dino_run_blue.png", "./sprites/dino_run_blue.png",
//     "./sprites/dino_run_blue.png"};
//     if (runner->path_texturedino == 0) {
//         runner->boutonlist[4].t_bouton = sfTexture_createFromFile(texturedino[0], NULL);
//         runner->dino.t_dino = sfTexture_createFromFile(texturedino[0], NULL);
//     }
//     if (runner->path_texturedino == 1) {
//         runner->boutonlist[4].t_bouton = sfTexture_createFromFile(texturedino[1], NULL);
//         runner->dino.t_dino = sfTexture_createFromFile(texturedino[1], NULL);
//     }
//     if (runner->path_texturedino == 2) {
//         runner->boutonlist[4].t_bouton = sfTexture_createFromFile(texturedino[2], NULL);
//         runner->dino.t_dino = sfTexture_createFromFile(texturedino[2], NULL);
//     }
//     if (runner->path_texturedino == 3) {
//         runner->boutonlist[4].t_bouton = sfTexture_createFromFile(texturedino[3], NULL);
//         runner->dino.t_dino = sfTexture_createFromFile(texturedino[3], NULL);
//     }
// }

// void switch_color(sfRenderWindow *window, runner_t *runner)
// {
//     int i = 0;
//     if (runner->valid[4] == 1 && sfMouse_isButtonPressed(sfMouseLeft) && i == 0) {
//         runner->path_texturedino += 1;
//         i = 1;
//         my_printf("%d\n", runner->path_texturedino);
//         if (runner->path_texturedino > 3)
//             runner->path_texturedino = 0;
//         change_path_color(window, runner);
//     }
// }

void switch_window(sfRenderWindow *window, runner_t *runner)
{
    if (runner->valid[0] == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        runner->menustate = GAME;
        sfMusic_stop(runner->menumusic);
    }
    else if (runner->valid[1] == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_destroy(runner->menumusic);
        sfMusic_destroy(runner->gamemusic);
        sfRenderWindow_close(window);
    }
}

void display_bouton(sfRenderWindow *window, bouton_t bouton)
{
    sfSprite_setTexture(bouton.s_bouton, bouton.t_bouton, sfTrue);
    sfSprite_setTextureRect(bouton.s_bouton, bouton.rectbouton);
    sfSprite_setPosition(bouton.s_bouton, bouton.positionbouton);
    sfSprite_setScale(bouton.s_bouton, bouton.resize);
    sfRenderWindow_drawSprite(window, bouton.s_bouton, NULL);
}

void menu(sfRenderWindow *window, runner_t *runner)
{
    if (sfMusic_getStatus(runner->menumusic) == 0) {
        sfMusic_play(runner->menumusic);
    }
    for (int i = 0; i < 5; i++)
        display_back(window, runner->backlist[i]);
    for (int i = 0; i < 2; i++)
        display_bouton(window, runner->boutonlist[i]);
    display_bouton(window, runner->boutonlist[4]);
    check_mouse(window, runner);
    switch_window(window, runner);
}
