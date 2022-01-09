/*
** EPITECH PROJECT, 2022
** create_colors
** File description:
** Functions to init colors
*/

#include "runner.h"
#include <stdlib.h>

char **t_dino(void)
{
    char **texturedino = malloc(sizeof(char *)* 4);
    texturedino[0] = "./sprites/dino_run_blue.png";
    texturedino[1] = "./sprites/dino_run_red.png";
    texturedino[2] = "./sprites/dino_run_yellow.png";
    texturedino[3] = "./sprites/dino_run_green.png";
    return texturedino;
}

char **t_dino_crouch(void)
{
    char **tdinocrouch = malloc(sizeof(char *)* 4);
    tdinocrouch[0] = "./sprites/dino_crouch_blue.png";
    tdinocrouch[1] = "./sprites/dino_crouch_red.png";
    tdinocrouch[2] = "./sprites/dino_crouch_yellow.png";
    tdinocrouch[3] = "./sprites/dino_crouch_green.png";
    return tdinocrouch;
}

char **t_dino_reflect(void)
{
    char **texturedinoreflect = malloc(sizeof(char *)* 4);
    texturedinoreflect[0] = "./sprites/dino_run_blue_reflect.png";
    texturedinoreflect[1] = "./sprites/dino_run_red_reflect.png";
    texturedinoreflect[2] = "./sprites/dino_run_yellow_reflect.png";
    texturedinoreflect[3] = "./sprites/dino_run_green_reflect.png";
    return texturedinoreflect;
}

char **t_dino_crouch_reflect(void)
{
    char **tdinocrouchreflect = malloc(sizeof(char *)* 4);
    tdinocrouchreflect[0] = "./sprites/dino_crouch_blue_reflect.png";
    tdinocrouchreflect[1] = "./sprites/dino_crouch_red_reflect.png";
    tdinocrouchreflect[2] = "./sprites/dino_crouch_yellow_reflect.png";
    tdinocrouchreflect[3] = "./sprites/dino_crouch_green_reflect.png";
    return tdinocrouchreflect;
}

void dino_colors_create(runner_t *runner)
{
    runner->path_tdino = t_dino();
    runner->path_tdino_d = t_dino_d();
    runner->path_tdino_c = t_dino_crouch();
    runner->path_tdino_r = t_dino_reflect();
    runner->path_tdino_c_r = t_dino_crouch_reflect();
}
