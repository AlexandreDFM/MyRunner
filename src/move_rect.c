/*
** EPITECH PROJECT, 2021
** move_rect
** File description:
** Function to moving rect
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

void move_rectback(sfIntRect *rect, int modify, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = modify;
    } else {
        rect->left += modify;
    }
}

void move_rectdino(sfIntRect *rect, int base, int move, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = base;
    } else {
        rect->left += move;
    }
}

void move_rectsnowman(sfIntRect *rect, int move, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = 0;
    } else {
        rect->left += move;
    }
}
