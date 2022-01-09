/*
** EPITECH PROJECT, 2021
** init_struct
** File description:
** Functions to init struct
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <stdlib.h>

void init_texture(runner_t *runner)
{
    char *pathback[5] = {"./sprites/backg.png", "./sprites/foreground.png",
    "./sprites/cloud.png", "./sprites/decor_arbre.png", "./sprites/sol.png"};
    dino_colors_create(runner);
    dino_colors_sprite_create(runner);
    sfVector2f positionback = {0, 0};
    sfIntRect rectback = {0, 0, 544, 178};
    for (int i = 0; i < 5; i++)
        runner->backlist[i] = create_back(pathback[i], positionback, rectback);
    runner->transition = c_transi("./sprites/transition.png",
    positionback, rectback);
}
