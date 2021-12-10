/*
** EPITECH PROJECT, 2021
** runner.h
** File description:
** Header of Runner
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

enum scene_t {
    GAME,
    MENU
};

typedef struct game_object
{
    enum scene_t scene;
    sfSprite *s_back;
    sfTexture *t_back;
    sfSprite *s_back2;
    sfTexture *t_back2;
    sfSprite *s_back3;
    sfTexture *t_back3;
    sfVector2f positionback;
    sfIntRect rectback;
    sfVector2f positionback2;
    sfIntRect rectback2;
    sfVector2f positionback3;
    sfIntRect rectback3;
    sfClock *clockrunner;
} game_object_t;

typedef struct background
{
    sfSprite *s_back;
    sfTexture *t_back;
    sfVector2f positionback;
    sfIntRect rectback;
    sfVector2f resize;
}back_t;

typedef struct dino
{
    sfSprite *s_dino;
    sfTexture *t_dino;
    sfVector2f positiondino;
    sfIntRect rectdino;
    sfVector2f resize;
}dino_t;

typedef struct snowman
{
    sfSprite *s_snowman;
    sfTexture *t_snowman;
    sfVector2f positionsnowman;
    sfIntRect rectsnowman;
    sfVector2f resize;
}snowman_t;

typedef struct chainmob
{
    int countain;
    snowman_t snowman;
    struct chainmob *next;
}chainmob_t;

typedef struct runner
{
    int space;
    int dinojump;
    sfEvent event;
    back_t back;
    back_t back2;
    back_t back3;
    back_t back4;
    back_t back5;
    chainmob_t *chainmob;
    dino_t dino;
    dino_t dinoreflect;
    snowman_t snowman;
    sfClock *clockback;
    sfClock *clockback2;
    sfClock *clockdino;
    sfClock *clockcloud;
}runner_t;

#ifndef RUNNER
    #define RUNNER



#endif
