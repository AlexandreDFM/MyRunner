/*
** EPITECH PROJECT, 2021
** detect_obstacles
** File description:
** Function to dectect if obstacles is present
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"

void my_snowman(int i, char *map, chainmob_t mob, chainmob_t *chainmobglobal)
{
    if (map[i] == '1') {
        mob.countain = 1;
        sfVector2f positionsman = {i*100, 530};
        snowman_t sman = create_snowman("./sprites/snowman.png", positionsman);
        mob.snowman = sman;
        sfVector2f positionsmanreflect = {i*100, 760};
        snowman_t smanreflect = create_snowman(
        "./sprites/snowman_reflect.png", positionsmanreflect);
        mob.snowmanreflect = smanreflect;
        chainmobglobal[i] = mob;
    }
}

void my_flysnowman(int i, char *map, chainmob_t mob, chainmob_t *mobglobal)
{
    if (map[i] == '2') {
        mob.countain = 2;
        sfVector2f pos = {i*100, 390};
        flysnowman_t sman = create_flysnowman("./sprites/flysnowman.png", pos);
        mob.flysnowman = sman;
        mob.countain = 2;
        sfVector2f posreflect = {i*100, 860};
        flysnowman_t smanreflect = create_flysnowman(
        "./sprites/flysnowman_reflect.png", posreflect);
        mob.flysnowmanreflect = smanreflect;
        mobglobal[i] = mob;
    }
}

void my_gold(int i, char *map, chainmob_t chainmob, chainmob_t *chainmobglobal)
{
    if (map[i] == '4') {
        chainmob.countain = 4;
        sfVector2f positiongold = {i*100, 530};
        gold_t gold = create_gold("./sprites/gold.png", positiongold);
        chainmob.gold = gold;
        sfVector2f positiongoldreflect = {i*100, 800};
        gold_t goldreflect = create_gold(
        "./sprites/gold_reflect.png", positiongoldreflect);
        chainmob.goldreflect = goldreflect;
        chainmobglobal[i] = chainmob;
    }
}

void my_flag(int i, char *map, chainmob_t chainmob, chainmob_t *chainmobglobal)
{
    if (map[i] == '5') {
        chainmob.countain = 5;
        sfVector2f positionflag = {i*100, 402};
        flag_t flag = create_flag("./sprites/flag.png", positionflag);
        chainmob.flag = flag;
        sfVector2f positionflagreflect = {i*100, 780};
        flag_t flagreflect = create_flag(
        "./sprites/flag_reflect.png", positionflagreflect);
        chainmob.flagreflect = flagreflect;
        chainmobglobal[i] = chainmob;
    }
}
