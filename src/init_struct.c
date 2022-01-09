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

void game_init2(runner_t *runner)
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
    runner->cursor = create_cursor("./sprites/cursor.png");
    sfVector2f titlepos = {288+400, 70};
    runner->title = create_title("./sprites/title.png", titlepos);
    runner->gravity = (sfVector2f) {0, 1};
    runner->dinovitesse = (sfVector2f) {0, -25.0};
}

void game_init3(runner_t *runner)
{
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
}

void game_init(runner_t *runner)
{
    game_init2(runner);
    game_init3(runner);
    sfVector2f positiondino = {40, 525};
    sfVector2f positiondinoreflect = {40, 760};
    sfIntRect rectdino = {0, 0, 15, 17};
    runner->dino = create_dino(runner->path_tdino[runner->texturedino],
    positiondino, rectdino);
    runner->dinoreflect = create_dino(
    runner->path_tdino_r[runner->texturedino], positiondinoreflect, rectdino);
    runner->dinostate = NORMAL;
    sfSound_setBuffer(runner->coinsound, runner->coinbuffer);
    sfSound_setVolume(runner->coinsound, 15);
}

void init_bouton(runner_t *runner)
{
    char *pathbtn[7] = {"./sprites/play_game.png",
    "./sprites/quit_prog.png", "./sprites/play_again.png",
    "./sprites/play_menu.png", "./sprites/retry.png",
    "./sprites/continue.png", "./sprites/dino_run_blue.png"};
    sfVector2f posbtn[7] = { (sfVector2f) {328+530, 200+240},
    (sfVector2f) {328+530, 250+240}, (sfVector2f) {328+530, 136+240},
    (sfVector2f) {328+530, 250+240}, (sfVector2f) {328+530, 200+240},
    (sfVector2f) {306+530, 146+240}, (sfVector2f) {40, 525}};
    sfIntRect rectbtn[5] = {(sfIntRect) {0, 0, 144, 50},
    (sfIntRect) {0, 0, 144, 89}, (sfIntRect) {0, 0, 140, 46},
    (sfIntRect) {0, 0, 188, 50}, (sfIntRect) {0, 0, 15, 17}};
    runner->boutonlist[0] = create_bouton(pathbtn[0], posbtn[0], rectbtn[0]);
    runner->boutonlist[1] = create_bouton(pathbtn[1], posbtn[1], rectbtn[0]);
    runner->boutonlist[2] = create_bouton(pathbtn[2], posbtn[2], rectbtn[1]);
    runner->boutonlist[3] = create_bouton(pathbtn[3], posbtn[3], rectbtn[0]);
    runner->boutonlist[4] = create_bouton(pathbtn[4], posbtn[4], rectbtn[2]);
    runner->boutonlist[5] = create_bouton(pathbtn[5], posbtn[5], rectbtn[3]);
    runner->boutonlist[6] = create_bouton(pathbtn[6], posbtn[6], rectbtn[4]);
}

void create_a_party(runner_t *runner)
{
    runner->menustate = MENU;
    runner->loadstate = GAMELOAD;
    create_highscore(runner);
    runner->thighscore = sfText_create();
    init_texture(runner);
    init_bouton(runner);
    runner->valid[6] = 0;
    runner->boutonlist[6].resize = (sfVector2f) {7, 6.1};
    runner->texturedino = 0;
    sfVector2f positiongold = {730, 980};
    runner->scoreicon = create_gold("./sprites/gold.png", positiongold);
    sfVector2f resize = {3, 3.1};
    runner->scoreicon.resize = resize;
    game_init(runner);
}
