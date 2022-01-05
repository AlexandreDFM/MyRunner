/*
** EPITECH PROJECT, 2022
** destroy_sprite
** File description:
** Functions to destroy a sprite
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

back_t destroy_back(back_t back)
{
    sfSprite_destroy(back.s_back);
    sfTexture_destroy(back.t_back);
    //back.positionback = pos;
    //back.rectback = rect;
    //sfVector2f resize = {7, 6.1};
    //back.resize = resize;
    //return (back);
}

bouton_t destroy_bouton(bouton_t bouton)
{
    sfSprite_destroy(bouton.s_bouton);
    sfTexture_destroy(bouton.t_bouton);
    //bouton.positionbouton = pos;
    //bouton.rectbouton = rect;
    //sfVector2f resize = {7, 6.1};
    //bouton.resize = resize;
    //return (bouton);
}

dino_t destroy_dino(dino_t dino)
{
    sfSprite_destroy(dino.s_dino);
    sfTexture_destroy(dino.t_dino);
    //dino.positiondino = pos;
    //dino.rectdino = rect;
    //sfVector2f resize = {7, 6.1};
    //dino.resize = resize;
    //return (dino);
}