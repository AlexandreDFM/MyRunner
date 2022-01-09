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

void game_init(runner_t *runner)
{
    runner->scorenb = 0;
    sfVector2f positionscore = {830, 980};
    runner->positionscore = positionscore;
    sfFont* font = sfFont_createFromFile("./police/police_8bit.ttf");
    runner->font = font;
    sfText* score = sfText_create();
    runner->score = score;
    runner->chainmob = parsemap(runner->pathmap, runner);
    char *path_texturedinoreflect = "./sprites/dino_sprites_blue_reflect.png";
    sfVector2f positiondino = {40, 525};
    sfVector2f positiondinoreflect = {40, 760};
    sfIntRect rectdino = {0, 0, 15, 17};
    runner->cursor = create_cursor("./sprites/cursor.png");
    sfVector2f titlepos = {288+400, 70};
    runner->title = create_title("./sprites/title.png", titlepos);
    runner->gravity = (sfVector2f) {0, 1};
    runner->dinovitesse = (sfVector2f) {0, -25.0};
    runner->dino = create_dino(runner->path_tdino[runner->texturedino],
    positiondino, rectdino);
    runner->dinoreflect = create_dino(
    runner->path_tdino_r[runner->texturedino], positiondinoreflect, rectdino);
    runner->dinostate = NORMAL;
    runner->clockback = sfClock_create();
    runner->clockback2 = sfClock_create();
    runner->clockcloud = sfClock_create();
    runner->clockdino = sfClock_create();
    runner->clockdinodead = sfClock_create();
    runner->menumusic = sfMusic_createFromFile("./music/spidermanmusic.ogg");
    runner->gamemusic = sfMusic_createFromFile("./music/mariomusic.ogg");
    runner->deadmusic = sfMusic_createFromFile("./music/mariodead.ogg");
    runner->victorymusic = sfMusic_createFromFile("./music/mariovictory.ogg");
    runner->coinbuffer = sfSoundBuffer_createFromFile("./music/coinsound.ogg");
    runner->coinsound = sfSound_create();
    sfSound_setBuffer(runner->coinsound, runner->coinbuffer);
    sfSound_setVolume(runner->coinsound, 15);
}

void reset_game(runner_t *runner)
{
    sfFont_destroy(runner->font);
    sfText_destroy(runner->score);
    runner->chainmob = parsemap(runner->pathmap, runner);
    sfClock_destroy(runner->clockback);
    sfClock_destroy(runner->clockback2);
    sfClock_destroy(runner->clockcloud);
    sfClock_destroy(runner->clockdino);
    sfMusic_destroy(runner->menumusic);
    sfMusic_destroy(runner->gamemusic);
}

void create_a_party(runner_t *runner)
{
    runner->menustate = MENU;
    runner->loadstate = GAMELOAD;
    create_highscore(runner);
    runner->thighscore = sfText_create();
    char *pathback[5] = {"./sprites/backg.png", "./sprites/foreground.png",
    "./sprites/cloud.png", "./sprites/decor_arbre.png", "./sprites/sol.png"};
    dino_colors_create(runner);
    dino_colors_sprite_create(runner);
    char *pathbtn[7] = {"./sprites/play_game.png",
    "./sprites/quit_prog.png", "./sprites/play_again.png",
    "./sprites/play_menu.png", "./sprites/retry.png",
    "./sprites/continue.png", "./sprites/dino_run_blue.png"};
    sfVector2f positionback = {0, 0};
    sfIntRect rectback = {0, 0, 544, 178};
    for (int i = 0; i < 5; i++)
        runner->backlist[i] = create_back(pathback[i], positionback, rectback);
    runner->transition = c_transi("./sprites/transition.png",
    positionback, rectback);

    sfVector2f playbpos = {328+530, 200+240};
    sfVector2f quitbpos = {328+530, 250+240};
    sfVector2f pabpos = {328+530, 136+240};
    sfVector2f menubpos = {328+530, 250+240};
    sfVector2f retrybpos = {328+530, 200+240};
    sfVector2f ctnbpos = {306+530, 146+240};

    sfVector2f dinobpos = {40, 525};
    sfIntRect rectbtn = {0, 0, 144, 50};
    sfIntRect rectbtnpa = {0, 0, 144, 89};
    sfIntRect rectbtnretry = {0, 0, 140, 46};
    sfIntRect rectbtnctn = {0, 0, 188, 50};
    sfIntRect rectdinobtn = {0, 0, 15, 17};
    runner->boutonlist[0] = create_bouton(pathbtn[0], playbpos, rectbtn);
    runner->boutonlist[1] = create_bouton(pathbtn[1], quitbpos, rectbtn);
    runner->boutonlist[2] = create_bouton(pathbtn[2], pabpos, rectbtnpa);
    runner->boutonlist[3] = create_bouton(pathbtn[3], menubpos, rectbtn);
    runner->boutonlist[4] = create_bouton(pathbtn[4], retrybpos, rectbtnretry);
    runner->boutonlist[5] = create_bouton(pathbtn[5], ctnbpos, rectbtnctn);
    runner->boutonlist[6] = create_bouton(pathbtn[6], dinobpos, rectdinobtn);
    runner->valid[6] = 0;
    runner->boutonlist[6].resize = (sfVector2f) {7, 6.1};
    runner->texturedino = 0;
    sfVector2f positiongold = {730, 980};
    runner->scoreicon = create_gold("./sprites/gold.png", positiongold);
    sfVector2f resize = {3, 3.1};
    runner->scoreicon.resize = resize;
    game_init(runner);
}
