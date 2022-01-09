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
    sfFloatRect col = {sfSprite_getPosition(runner->boutonlist[6].s_bouton).x,
    sfSprite_getPosition(runner->boutonlist[6].s_bouton).y, 15*7, 17*6};
    float posmousex = sfMouse_getPositionRenderWindow(window).x;
    float posmousey = sfMouse_getPositionRenderWindow(window).y;
    runner->valid[0] = sfFloatRect_contains(&play, posmousex, posmousey);
    runner->valid[1] = sfFloatRect_contains(&quit, posmousex, posmousey);
    runner->valid[6] = sfFloatRect_contains(&col, posmousex, posmousey);
}

void switch_window(sfRenderWindow *window, runner_t *runner)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && runner->valid[0] == 1) {
        runner->menustate = GAME;
        sfMusic_stop(runner->menumusic);
    }
    else if (sfMouse_isButtonPressed(sfMouseLeft) && runner->valid[1] == 1) {
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
    if (runner->loadstate == GAMELOAD) {
        change_butons_coord_reset(runner);
        runner->loadstate = GAMEUNLOAD;
    }
    if (sfMusic_getStatus(runner->menumusic) == 0) {
        sfMusic_play(runner->menumusic);
    }
    for (int i = 0; i < 5; i++)
        display_back(window, runner->backlist[i]);
    for (int i = 0; i < 2; i++)
        display_bouton(window, runner->boutonlist[i]);
    display_bouton(window, runner->boutonlist[6]);
    display_dino(window, runner->dinoreflect);
    display_title(window, runner->title);
    display_highscore(window, runner);
    check_mouse(window, runner);
    switch_window(window, runner);
    cursor(window, runner->cursor);
}
