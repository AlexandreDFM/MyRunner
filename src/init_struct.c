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
    runner->gravity = (sfVector2f) {0, 1};
    runner->dinovitesse = (sfVector2f) {0, -25.0};
    runner->dino = create_dino(runner->path_tdino[runner->texturedino], positiondino, rectdino);
    runner->dinoreflect = create_dino(runner->path_tdinoreflect[runner->texturedino], positiondinoreflect, rectdino);
    runner->dinostate = NORMAL;
    runner->clockback = sfClock_create();
    runner->clockback2 = sfClock_create();
    runner->clockcloud = sfClock_create();
    runner->clockdino = sfClock_create();
    runner->menumusic = sfMusic_createFromFile("./music/The Amazing Spider-Man 2 - Theme.ogg");
    runner->gamemusic = sfMusic_createFromFile("./music/Fossil Falls - Super Mario Odyssey.ogg");
    //runner->coinsound = sfMusic_createFromFile("./music/CoinSound.ogg");
    // crosshair->buffer_shot = sfSoundBuffer_createFromFile("sprites/shot.ogg");
    // crosshair->sound_shot = sfSound_create();
    // sfSound_setBuffer(crosshair->sound_shot, crosshair->buffer_shot);
    // sfSound_setVolume(crosshair->sound_shot, 0);
    // crosshair->buffer_hit = sfSoundBuffer_createFromFile("sprites/hit.ogg");
    // crosshair->sound_hit = sfSound_create();
    // sfSound_setBuffer(crosshair->sound_hit, crosshair->buffer_hit);
    // sfSound_setVolume(crosshair->sound_hit, 55);
    // sfSound_setPlayingOffset(crosshair->sound_hit, off);
}

void reset_game(runner_t *runner)
{
    sfFont_destroy(runner->font);
    sfText_destroy(runner->score);
    runner->chainmob = parsemap(runner->pathmap, runner);
    destroy_dino(runner->dino);
    destroy_dino(runner->dinoreflect);
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
    char *pathback[5] = {"./sprites/backg.png", "./sprites/foreground.png",
    "./sprites/cloud.png", "./sprites/decor_arbre.png", "./sprites/sol.png"};
    char **texturedino = malloc(sizeof(char *)* 4);
    char **tdinocrouch = malloc(sizeof(char *)* 4);
    char **texturedinoreflect = malloc(sizeof(char *)* 4);
    char **tdinocrouchreflect = malloc(sizeof(char *)* 4);

    texturedino[0] = "./sprites/dino_run_blue.png";
    texturedino[1] = "./sprites/dino_run_red.png";
    texturedino[2] = "./sprites/dino_run_yellow.png";
    texturedino[3] = "./sprites/dino_run_green.png";

    tdinocrouch[0] = "./sprites/dino_crouch_blue.png";
    tdinocrouch[1] = "./sprites/dino_crouch_red.png";
    tdinocrouch[2] = "./sprites/dino_crouch_yellow.png";
    tdinocrouch[3] = "./sprites/dino_crouch_green.png";

    texturedinoreflect[0] = "./sprites/dino_run_blue_reflect.png";
    texturedinoreflect[1] = "./sprites/dino_run_red_reflect.png";
    texturedinoreflect[2] = "./sprites/dino_run_yellow_reflect.png";
    texturedinoreflect[3] = "./sprites/dino_run_green_reflect.png";

    tdinocrouchreflect[0] = "./sprites/dino_crouch_blue_reflect.png";
    tdinocrouchreflect[1] = "./sprites/dino_crouch_red_reflect.png";
    tdinocrouchreflect[2] = "./sprites/dino_crouch_yellow_reflect.png";
    tdinocrouchreflect[3] = "./sprites/dino_crouch_green_reflect.png";
    // char texturedino[4][100] = {"./sprites/dino_run_blue.png",
    // "./sprites/dino_run_red.png", "./sprites/dino_run_yellow.png",
    // "./sprites/dino_run_green.png"};
    runner->path_tdino = texturedino;
    runner->path_tdinocrouch = tdinocrouch;
    runner->path_tdinoreflect = texturedinoreflect;
    runner->path_tdinocrouchreflect = tdinocrouchreflect;
    char *pathbouton[5] = {"./sprites/play_game.png",
    "./sprites/quit_prog.png", "./sprites/play_again.png",
    "./sprites/play_menu.png", "./sprites/dino_run_blue.png"};
    sfVector2f positionback = {0, 0};
    sfIntRect rectback = {0, 0, 544, 178};
    for (int i = 0; i < 5; i++)
        runner->backlist[i] = create_back(pathback[i], positionback, rectback);
    sfVector2f playboutonposition = {328+530, 200+240};
    sfVector2f quitboutonposition = {328+530, 250+240};
    sfIntRect rectbouton = {0, 0, 544, 178};
    sfIntRect rectdinobouton = {0, 0, 15, 17};
    sfVector2f dinoboutonposition = {40, 525};
    runner->boutonlist[0] = create_bouton(pathbouton[0], playboutonposition, rectbouton);
    runner->boutonlist[1] = create_bouton(pathbouton[1], quitboutonposition, rectbouton);
    runner->boutonlist[4] = create_bouton(pathbouton[4], dinoboutonposition, rectdinobouton);
    runner->valid[4] = 0;
    runner->boutonlist[4].resize = (sfVector2f) {7, 6.1};
    runner->texturedino = 0;
    sfVector2f positiongold = {730, 980};
    runner->scoreicon = create_gold("./sprites/gold.png", positiongold);
    sfVector2f resize = {3, 3.1};
    runner->scoreicon.resize = resize;
    game_init(runner);
}