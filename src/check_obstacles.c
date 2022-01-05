/*
** EPITECH PROJECT, 2022
** check_obstacles
** File description:
** Functions to check colisions with obstacles
*/

#include "runner.h"

int check_snowman(sfRenderWindow *window, snowman_t snowman, runner_t *runner)
{
    float posdinox = runner->dino.positiondino.x;
    float posdinoy = runner->dino.positiondino.y;
    sfFloatRect dinopos = {posdinox, posdinoy, 15*7, 17*6.1};
    float possnowmanx = snowman.positionsnowman.x;
    float possnowmany = snowman.positionsnowman.y;
    sfFloatRect snowmanpos = {possnowmanx, possnowmany, 18*7, 16*6};
    return (sfFloatRect_intersects(&dinopos, &snowmanpos, NULL));
}

int check_flysnowman(sfRenderWindow *window, flysnowman_t flysnowman, runner_t *runner)
{
    float posdinox = runner->dino.positiondino.x;
    float posdinoy = runner->dino.positiondino.y;
    sfFloatRect dinopos = {posdinox, posdinoy, 15*7, 17*6};
    float posflysnowmanx = flysnowman.positionflysnowman.x + 13*7;
    float posflysnowmany = flysnowman.positionflysnowman.y;
    sfFloatRect flysnowmanpos = {posflysnowmanx, posflysnowmany, 21*7, 24*6};
    return (sfFloatRect_intersects(&dinopos, &flysnowmanpos, NULL));
}

int check_gold(sfRenderWindow *window, gold_t gold, runner_t *runner)
{
    float posdinox = runner->dino.positiondino.x;
    float posdinoy = runner->dino.positiondino.y;
    sfFloatRect dinopos = {posdinox, posdinoy, 15*7, 17*6.1};
    float posgoldx = gold.positiongold.x;
    float posgoldy = gold.positiongold.y;
    sfFloatRect goldpos = {posgoldx, posgoldy, 12*5, 12*4.1};
    return (sfFloatRect_intersects(&dinopos, &goldpos, NULL));
}

int check_flag(sfRenderWindow *window, flag_t flag, runner_t *runner)
{
    float posdinox = runner->dino.positiondino.x;
    float posdinoy = runner->dino.positiondino.y;
    sfFloatRect dinopos = {posdinox, posdinoy, 15*7, 17*6.1};
    float posflagx = flag.positionflag.x;
    float posflagy = flag.positionflag.y;
    sfFloatRect flagpos = {posflagx, posflagy, 18*5, 36*4.1};
    return (sfFloatRect_intersects(&dinopos, &flagpos, NULL));
}