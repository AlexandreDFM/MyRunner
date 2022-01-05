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
    MENU,
    GAME,
    PAUSE,
    GAMEOVER,
    GAMEWIN,
    JUMPFINISH
};

enum dino_t {
    NORMAL,
    JUMP,
    FALL,
    CROUCH
};

enum load_t {
    GAMEUNLOAD,
    GAMELOAD
};

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
}framebuffer_t;

typedef struct background
{
    sfSprite *s_back;
    sfTexture *t_back;
    sfVector2f positionback;
    sfIntRect rectback;
    sfVector2f resize;
}back_t;

typedef struct bouton
{
    sfSprite *s_bouton;
    sfTexture *t_bouton;
    sfVector2f positionbouton;
    sfIntRect rectbouton;
    sfVector2f resize;
}bouton_t;

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

typedef struct flysnowman
{
    sfSprite *s_flysnowman;
    sfTexture *t_flysnowman;
    sfVector2f positionflysnowman;
    sfIntRect rectflysnowman;
    sfVector2f resize;
}flysnowman_t;

typedef struct enemie3
{
    sfSprite *s_enemie3;
    sfTexture *t_enemie3;
    sfVector2f positionenemie3;
    sfIntRect rectenemie3;
    sfVector2f resize;
}enemie3_t;

typedef struct gold
{
    sfSprite *s_gold;
    sfTexture *t_gold;
    sfVector2f positiongold;
    sfIntRect rectgold;
    sfVector2f resize;
}gold_t;

typedef struct flag
{
    sfSprite *s_flag;
    sfTexture *t_flag;
    sfVector2f positionflag;
    sfIntRect rectflag;
    sfVector2f resize;
}flag_t;

typedef struct chainmob
{
    int countain;
    snowman_t snowman;
    flysnowman_t flysnowman;
    enemie3_t enemie3;
    gold_t gold;
    flag_t flag;
}chainmob_t;

typedef struct runner
{
    int valid[4];
    int dinojump;
    int scorenb;
    int texturedino;
    char *map;
    char *pathmap;
    char **path_tdino;
    char **path_tdinocrouch;
    char **path_tdinoreflect;
    char **path_tdinocrouchreflect;
    enum scene_t menustate;
    enum dino_t dinostate;
    enum load_t loadstate;
    sfEvent event;
    back_t backlist[5];
    bouton_t boutonlist[5];
    chainmob_t *chainmob;
    sfVector2f gravity;
    sfVector2f dinovitesse;
    dino_t dino;
    dino_t dinoreflect;
    sfClock *clockback;
    sfClock *clockback2;
    sfClock *clockdino;
    sfClock *clockcloud;
    sfMusic *menumusic;
    sfMusic *gamemusic;
    sfSound *coinsound;
    sfVector2f positionscore;
    sfFont *font;
    sfText *score;
    gold_t scoreicon;
}runner_t;

#ifndef RUNNER
    #define RUNNER

char *fs_open_file(char *mappath);
chainmob_t *parsemap(char *mappath, runner_t *runner);
int check_snowman(sfRenderWindow *window, snowman_t snowman, runner_t *runner);
int check_flysnowman(sfRenderWindow *window, flysnowman_t flysnowman, runner_t *runner);
int check_gold(sfRenderWindow *window, gold_t gold, runner_t *runner);
int check_flag(sfRenderWindow *window, flag_t flag, runner_t *runner);
void clock_game(runner_t *runner);
void menu(sfRenderWindow *window, runner_t *runner);
void game(sfRenderWindow *window, runner_t *runner);
void gamepause(sfRenderWindow *window, runner_t *runner);
void menugo(sfRenderWindow *window, runner_t *runner);
void menuwin(sfRenderWindow *window, runner_t *runner);
void create_a_party(runner_t *runner);
void jump(sfRenderWindow *window, runner_t *runner);
int check_mobs(sfRenderWindow *window, snowman_t snowman, runner_t *runner);
chainmob_t *parsemap(char *mappath, runner_t *runner);
back_t create_back(const char *path_texture, sfVector2f pos, sfIntRect rect);
dino_t create_dino(const char *path_texture, sfVector2f pos, sfIntRect rect);
bouton_t create_bouton(const char *path_texture, sfVector2f pos, sfIntRect rect);
snowman_t create_snowman(const char *path_texture, sfVector2f pos);
flysnowman_t create_flysnowman(const char *path_texture, sfVector2f pos);
enemie3_t create_enemie3(const char *path_texture, sfVector2f pos);
back_t destroy_back(back_t back);
bouton_t destroy_bouton(bouton_t bouton);
dino_t destroy_dino(dino_t dino);
gold_t create_gold(const char *path_texture, sfVector2f pos);
flag_t create_flag(const char *path_texture, sfVector2f pos);
void move_rectback(sfIntRect *rect, int modify, int max_value);
void move_rectdino(sfIntRect *rect, int base, int move, int max_value);
void move_rectsnowman(sfIntRect *rect, int move, int max_value);
void my_snowman(int i, char *map, chainmob_t chainmob, chainmob_t *chainmobglobal);
void my_flysnowman(int i, char *map, chainmob_t mob, chainmob_t *mobglobal);
void my_gold(int i, char *map, chainmob_t chainmob, chainmob_t *chainmobglobal);
void my_flag(int i, char *map, chainmob_t chainmob, chainmob_t *chainmobglobal);
void display_s(sfRenderWindow *window, runner_t *runner);
void display_back(sfRenderWindow *window, back_t back);
void display_dino(sfRenderWindow *window, dino_t dino);
void display_snowman(sfRenderWindow *window, snowman_t snowman);
void display_gold(sfRenderWindow *window, gold_t gold);
void display_flag(sfRenderWindow *window, flag_t flag);
void display_chainmob(sfRenderWindow *window, runner_t *runner);
void display_bouton(sfRenderWindow *window, bouton_t bouton);
void switch_window(sfRenderWindow *window, runner_t *runner);
void check_mouse(sfRenderWindow *window, runner_t *runner);
int display_window(char *map);
void game_init(runner_t *runner);
void reset_game(runner_t *runner);

#endif
