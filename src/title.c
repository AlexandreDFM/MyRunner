/*
** EPITECH PROJECT, 2022
** title
** File description:
** Function to manage title display and creation
*/

#include "runner.h"

title_t create_title(const char *path_texture, sfVector2f pos)
{
    title_t title;
    title.t_title = sfTexture_createFromFile(path_texture, NULL);
    title.s_title = sfSprite_create();
    title.positiontitle = pos;
    title.resize = (sfVector2f) {0.70, 0.70};
    sfSprite_setTexture(title.s_title, title.t_title, sfTrue);
    sfSprite_setPosition(title.s_title, title.positiontitle);
    sfSprite_setScale(title.s_title, title.resize);
    return (title);
}

void display_title(sfRenderWindow *window, title_t title)
{
    sfSprite_setTexture(title.s_title, title.t_title, sfTrue);
    sfSprite_setPosition(title.s_title, title.positiontitle);
    sfSprite_setScale(title.s_title, title.resize);
    sfRenderWindow_drawSprite(window, title.s_title, NULL);
}
