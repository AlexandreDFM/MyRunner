/*
** EPITECH PROJECT, 2022
** create_sprite_color
** File description:
** Function to create sprite color
*/

#include "runner.h"
#include <stdlib.h>

sfTexture **t_sprite_dino(runner_t *runner)
{
    sfTexture **all_t_dino = malloc(sizeof(sfTexture *)* 4);
    all_t_dino[0] = sfTexture_createFromFile(runner->path_tdino[0], NULL);
    all_t_dino[1] = sfTexture_createFromFile(runner->path_tdino[1], NULL);
    all_t_dino[2] = sfTexture_createFromFile(runner->path_tdino[2], NULL);
    all_t_dino[3] = sfTexture_createFromFile(runner->path_tdino[3], NULL);
    return all_t_dino;
}

sfTexture **t_sprite_dino_crouch(runner_t *runner)
{
    sfTexture **all_t_dino_c = malloc(sizeof(sfTexture *)* 4);
    all_t_dino_c[0] = sfTexture_createFromFile(runner->path_tdino_c[0], NULL);
    all_t_dino_c[1] = sfTexture_createFromFile(runner->path_tdino_c[1], NULL);
    all_t_dino_c[2] = sfTexture_createFromFile(runner->path_tdino_c[2], NULL);
    all_t_dino_c[3] = sfTexture_createFromFile(runner->path_tdino_c[3], NULL);
    return all_t_dino_c;
}

sfTexture **t_sprite_dino_reflect(runner_t *runner)
{
    sfTexture **all_t_dino_r = malloc(sizeof(sfTexture *)* 4);
    all_t_dino_r[0] = sfTexture_createFromFile(runner->path_tdino_r[0], NULL);
    all_t_dino_r[1] = sfTexture_createFromFile(runner->path_tdino_r[1], NULL);
    all_t_dino_r[2] = sfTexture_createFromFile(runner->path_tdino_r[2], NULL);
    all_t_dino_r[3] = sfTexture_createFromFile(runner->path_tdino_r[3], NULL);
    return all_t_dino_r;
}

sfTexture **t_sprite_dino_crouch_reflect(runner_t *run)
{
    sfTexture **all_t_dino_c_r = malloc(sizeof(sfTexture *)* 4);
    all_t_dino_c_r[0] = sfTexture_createFromFile(run->path_tdino_c_r[0], NULL);
    all_t_dino_c_r[1] = sfTexture_createFromFile(run->path_tdino_c_r[1], NULL);
    all_t_dino_c_r[2] = sfTexture_createFromFile(run->path_tdino_c_r[2], NULL);
    all_t_dino_c_r[3] = sfTexture_createFromFile(run->path_tdino_c_r[3], NULL);
    return all_t_dino_c_r;
}

void dino_colors_sprite_create(runner_t *runner)
{
    runner->all_t_dino = t_sprite_dino(runner);
    runner->all_t_dino_r = t_sprite_dino_reflect(runner);
    runner->all_t_dino_c = t_sprite_dino_crouch(runner);
    runner->all_t_dino_c_r = t_sprite_dino_crouch_reflect(runner);
}
