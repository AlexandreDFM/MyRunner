/*
** EPITECH PROJECT, 2022
** display_obstacles2
** File description:
** Functions to display obstacles
*/

#include "runner.h"

void display_snowman(sfRenderWindow *window, snowman_t snowman)
{
    if (snowman.positionsnowman.x <= 1920
    && snowman.positionsnowman.x > -18 * 3) {
        sfSprite_setTexture(snowman.s_snowman, snowman.t_snowman, sfTrue);
        sfSprite_setPosition(snowman.s_snowman, snowman.positionsnowman);
        sfSprite_setTextureRect(snowman.s_snowman, snowman.rectsnowman);
        sfSprite_setScale(snowman.s_snowman, snowman.resize);
        sfRenderWindow_drawSprite(window, snowman.s_snowman, NULL);
    }
}

void display_flysnowman(sfRenderWindow *window, flysnowman_t fsnow)
{
    if (fsnow.positionflysnowman.x <= 1920
    && fsnow.positionflysnowman.x > -34 * 7) {
        sfSprite_setTexture(fsnow.s_flysnowman, fsnow.t_flysnowman, sfTrue);
        sfSprite_setPosition(fsnow.s_flysnowman, fsnow.positionflysnowman);
        sfSprite_setTextureRect(fsnow.s_flysnowman, fsnow.rectflysnowman);
        sfSprite_setScale(fsnow.s_flysnowman, fsnow.resize);
        sfRenderWindow_drawSprite(window, fsnow.s_flysnowman, NULL);
    }
}

void display_enemie3(sfRenderWindow *window, enemie3_t enemie3)
{
    if (enemie3.positionenemie3.x <= 1920
    && enemie3.positionenemie3.x > -18 * 3) {
        sfSprite_setTexture(enemie3.s_enemie3, enemie3.t_enemie3, sfTrue);
        sfSprite_setPosition(enemie3.s_enemie3, enemie3.positionenemie3);
        sfSprite_setTextureRect(enemie3.s_enemie3, enemie3.rectenemie3);
        sfSprite_setScale(enemie3.s_enemie3, enemie3.resize);
        sfRenderWindow_drawSprite(window, enemie3.s_enemie3, NULL);
    }
}

void display_gold(sfRenderWindow *window, gold_t gold)
{
    if (gold.positiongold.x <= 1920 && gold.positiongold.x > -18 * 3) {
        sfSprite_setTexture(gold.s_gold, gold.t_gold, sfTrue);
        sfSprite_setPosition(gold.s_gold, gold.positiongold);
        sfSprite_setTextureRect(gold.s_gold, gold.rectgold);
        sfSprite_setScale(gold.s_gold, gold.resize);
        sfRenderWindow_drawSprite(window, gold.s_gold, NULL);
    }
}

void display_flag(sfRenderWindow *window, flag_t flag)
{
    if (flag.positionflag.x <= 1920 && flag.positionflag.x > -18 * 3) {
        sfSprite_setTexture(flag.s_flag, flag.t_flag, sfTrue);
        sfSprite_setPosition(flag.s_flag, flag.positionflag);
        sfSprite_setTextureRect(flag.s_flag, flag.rectflag);
        sfSprite_setScale(flag.s_flag, flag.resize);
        sfRenderWindow_drawSprite(window, flag.s_flag, NULL);
    }
}
