/*
** EPITECH PROJECT, 2021
** create_sprite
** File description:
** Create Sprite
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

back_t create_back(const char *path_texture, sfVector2f pos, sfIntRect rect)
{
    back_t back;
    back.t_back = sfTexture_createFromFile(path_texture, NULL);
    back.s_back = sfSprite_create();
    back.positionback = pos;
    back.rectback = rect;
    sfVector2f resize = {7, 6.1};
    back.resize = resize;
    sfSprite_setTexture(back.s_back, back.t_back, sfTrue);
    sfSprite_setPosition(back.s_back, back.positionback);
    sfSprite_setScale(back.s_back, back.resize);
    return (back);
}

bouton_t create_bouton(const char *texture, sfVector2f pos, sfIntRect rect)
{
    bouton_t bouton;
    bouton.t_bouton = sfTexture_createFromFile(texture, NULL);
    bouton.s_bouton = sfSprite_create();
    bouton.positionbouton = pos;
    bouton.rectbouton = rect;
    sfVector2f resize = {1, 1};
    bouton.resize = resize;
    return (bouton);
}

dino_t create_dino(const char *path_texture, sfVector2f pos, sfIntRect rect)
{
    dino_t dino;
    dino.t_dino = sfTexture_createFromFile(path_texture, NULL);
    dino.s_dino = sfSprite_create();
    dino.positiondino = pos;
    dino.rectdino = rect;
    sfVector2f resize = {7, 6.1};
    dino.resize = resize;
    return (dino);
}
