/*
** EPITECH PROJECT, 2021
** display
** File description:
** Functions display
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

void display_back(sfRenderWindow *window, back_t back)
{
    sfSprite_setTexture(back.s_back, back.t_back, sfTrue);
    sfSprite_setPosition(back.s_back, back.positionback);
    sfSprite_setTextureRect(back.s_back, back.rectback);
    sfSprite_setScale(back.s_back, back.resize);
    sfRenderWindow_drawSprite(window, back.s_back, NULL);
}

void display_dino(sfRenderWindow *window, dino_t dino)
{
    sfSprite_setTexture(dino.s_dino, dino.t_dino, sfTrue);
    sfSprite_setPosition(dino.s_dino, dino.positiondino);
    sfSprite_setTextureRect(dino.s_dino, dino.rectdino);
    sfSprite_setScale(dino.s_dino, dino.resize);
    sfRenderWindow_drawSprite(window, dino.s_dino, NULL);
}
