/*
** EPITECH PROJECT, 2021
** create_sprite_obstacles
** File description:
** Function to create sprite obstacles
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"

snowman_t create_snowman(const char *path_texture, sfVector2f pos)
{
    snowman_t snowman;
    snowman.t_snowman = sfTexture_createFromFile(path_texture, NULL);
    snowman.s_snowman = sfSprite_create();
    snowman.positionsnowman = pos;
    sfIntRect rectsnowman = {0, 0, 18, 16};
    snowman.rectsnowman = rectsnowman;
    sfVector2f resize = {7, 6.1};
    snowman.resize = resize;
    return (snowman);
}

flysnowman_t create_flysnowman(const char *path_texture, sfVector2f pos)
{
    flysnowman_t flysnowman;
    flysnowman.t_flysnowman = sfTexture_createFromFile(path_texture, NULL);
    flysnowman.s_flysnowman = sfSprite_create();
    flysnowman.positionflysnowman = pos;
    sfIntRect rectflysnowman = {0, 0, 34, 24};
    flysnowman.rectflysnowman = rectflysnowman;
    sfVector2f resize = {7, 6.1};
    flysnowman.resize = resize;
    return (flysnowman);
}

enemie3_t create_enemie3(const char *path_texture, sfVector2f pos)
{
    enemie3_t enemie3;
    enemie3.t_enemie3 = sfTexture_createFromFile(path_texture, NULL);
    enemie3.s_enemie3 = sfSprite_create();
    enemie3.positionenemie3 = pos;
    sfIntRect rectenemie3 = {0, 0, 18, 16};
    enemie3.rectenemie3 = rectenemie3;
    sfVector2f resize = {7, 6.1};
    enemie3.resize = resize;
    return (enemie3);
}

gold_t create_gold(const char *path_texture, sfVector2f pos)
{
    gold_t gold;
    gold.t_gold = sfTexture_createFromFile(path_texture, NULL);
    gold.s_gold = sfSprite_create();
    gold.positiongold = pos;
    sfIntRect rectgold = {0, 0, 12, 12};
    gold.rectgold = rectgold;
    sfVector2f resize = {7, 6.1};
    gold.resize = resize;
    return (gold);
}

flag_t create_flag(const char *path_texture, sfVector2f pos)
{
    flag_t flag;
    flag.t_flag = sfTexture_createFromFile(path_texture, NULL);
    flag.s_flag = sfSprite_create();
    flag.positionflag = pos;
    sfIntRect rectflag = {0, 0, 18, 36};
    flag.rectflag = rectflag;
    sfVector2f resize = {7, 6.1};
    flag.resize = resize;
    return (flag);
}
