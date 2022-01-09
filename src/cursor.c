/*
** EPITECH PROJECT, 2022
** cursor
** File description:
** Function to display a cursor
*/

#include "runner.h"

cursor_t create_cursor(const char *path_texture)
{
    cursor_t cursor;
    cursor.t_cursor = sfTexture_createFromFile(path_texture, NULL);
    cursor.s_cursor = sfSprite_create();
    sfVector2f origin = {12, 12};
    sfSprite_setTexture(cursor.s_cursor, cursor.t_cursor, sfTrue);
    sfSprite_setOrigin(cursor.s_cursor, origin);
    return (cursor);
}

void cursor(sfRenderWindow *window, cursor_t cursor)
{
    float posx = sfMouse_getPositionRenderWindow(window).x;
    float posy = sfMouse_getPositionRenderWindow(window).y;
    sfVector2f coord = {posx, posy};
    sfSprite_setTexture(cursor.s_cursor, cursor.t_cursor, sfTrue);
    sfSprite_setPosition(cursor.s_cursor, coord);
    sfRenderWindow_drawSprite(window, cursor.s_cursor, NULL);
}
