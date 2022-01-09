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
    TRANSITION,
    TRANSITIONGO,
    TRANSITIONWIN,
    TRANSITIONMENU,
    MENU,
    GAME,
    PAUSE,
    GAMEOVER,
    GAMEWIN
};

enum dino_t {
    NORMAL,
    JUMP,
    JUMPFINISH,
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

typedef struct transition
{
    sfSprite *s_transition;
    sfTexture *t_transition;
    sfVector2f positiontransition;
    sfIntRect recttransition;
    sfVector2f resize;
}transition_t;

typedef struct title
{
    sfSprite *s_title;
    sfTexture *t_title;
    sfVector2f positiontitle;
    sfIntRect recttitle;
    sfVector2f resize;

}title_t;

typedef struct cursor
{
    sfSprite *s_cursor;
    sfTexture *t_cursor;
}cursor_t;

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
    snowman_t snowmanreflect;
    flysnowman_t flysnowman;
    flysnowman_t flysnowmanreflect;
    enemie3_t enemie3;
    gold_t gold;
    flag_t flag;
}chainmob_t;

typedef struct runner
{
    int valid[6];
    int dinojump;
    int scorenb;
    int texturedino;
    char *map;
    char *pathmap;
    char **path_tdino;
    char **path_tdino_c;
    char **path_tdino_r;
    char **path_tdino_c_r;
    enum scene_t menustate;
    enum dino_t dinostate;
    enum load_t loadstate;
    sfEvent event;
    cursor_t cursor;
    title_t title;
    back_t backlist[5];
    transition_t transition;
    bouton_t boutonlist[7];
    chainmob_t *chainmob;
    sfVector2f gravity;
    sfVector2f dinovitesse;
    dino_t dino;
    sfTexture **all_t_dino;
    sfTexture **all_t_dino_c;
    dino_t dinoreflect;
    sfTexture **all_t_dino_r;
    sfTexture **all_t_dino_c_r;
    sfClock *clockback;
    sfClock *clockback2;
    sfClock *clockdino;
    sfClock *clockcloud;
    sfMusic *menumusic;
    sfMusic *gamemusic;
    sfMusic *victorymusic;
    sfSoundBuffer *coinbuffer;
    sfSound *coinsound;
    sfVector2f positionscore;
    sfFont *font;
    sfText *score;
    gold_t scoreicon;
}runner_t;

#ifndef RUNNER
    #define RUNNER

char *fs_open_file(char *mappath);
char **t_dino(void);
char **t_dino_crouch(void);
char **t_dino_reflect(void);
char **t_dino_crouch_reflect(void);
void dino_colors_create(runner_t *runner);
sfTexture **t_sprite_dino(runner_t *runner);
sfTexture **t_sprite_dino_crouch(runner_t *runner);
sfTexture **t_sprite_dino_reflect(runner_t *runner);
sfTexture **t_sprite_dino_crouch_reflect(runner_t *run);
void dino_colors_sprite_create(runner_t *runner);
chainmob_t *parsemap(char *mappath, runner_t *runner);
int check_snowman(sfRenderWindow *window, snowman_t snowman, runner_t *runner);
int check_fsnowman(sfRenderWindow *window, flysnowman_t fsnow, runner_t *run);
int check_gold(sfRenderWindow *window, gold_t gold, runner_t *runner);
int check_flag(sfRenderWindow *window, flag_t flag, runner_t *runner);
void change_path_color(sfRenderWindow *window, runner_t *runner);
void switch_color(sfRenderWindow *window, runner_t *runner);
void crouch(sfRenderWindow *window, runner_t *runner);
void jumpevent(sfRenderWindow *window, runner_t *runner);
void jump(sfRenderWindow *window, runner_t *runner);
void clock_game(runner_t *runner);
void transition(sfRenderWindow *window, runner_t *runner);
void transitionmenu(sfRenderWindow *window, runner_t *runner);
void transitionwin(sfRenderWindow *window, runner_t *runner);
void transitiongo(sfRenderWindow *window, runner_t *runner);
void winanimation(sfRenderWindow *window, runner_t *runner) ;
void menu(sfRenderWindow *window, runner_t *runner);
void game(sfRenderWindow *window, runner_t *runner);
void gamepause(sfRenderWindow *window, runner_t *runner);
void menugo(sfRenderWindow *window, runner_t *runner);
void menuwin(sfRenderWindow *window, runner_t *runner);
void create_a_party(runner_t *runner);
cursor_t create_cursor(const char *path_texture);
void change_butons_coord_win(runner_t *runner);
void change_butons_coord_go(runner_t *runner);
void change_butons_coord_pause(runner_t *runner);
void change_butons_coord_reset(runner_t *runner);
void cursor(sfRenderWindow *window, cursor_t cursor);
title_t create_title(const char *path_texture, sfVector2f pos);
void display_title(sfRenderWindow *window, title_t title);
void jump(sfRenderWindow *window, runner_t *runner);
int check_mobs(sfRenderWindow *window, snowman_t snowman, runner_t *runner);
chainmob_t *parsemap(char *mappath, runner_t *runner);
back_t create_back(const char *path_texture, sfVector2f pos, sfIntRect rect);
transition_t c_transi(const char *texture, sfVector2f pos, sfIntRect rect);
dino_t create_dino(const char *path_texture, sfVector2f pos, sfIntRect rect);
bouton_t create_bouton(const char *texture, sfVector2f pos, sfIntRect rect);
snowman_t create_snowman(const char *path_texture, sfVector2f pos);
flysnowman_t create_flysnowman(const char *path_texture, sfVector2f pos);
enemie3_t create_enemie3(const char *path_texture, sfVector2f pos);
back_t destroy_back(back_t back);
bouton_t destroy_bouton(bouton_t bouton);
dino_t destroy_dino(dino_t dino);
gold_t create_gold(const char *path_texture, sfVector2f pos);
flag_t create_flag(const char *path_texture, sfVector2f pos);
void move_rectback(sfIntRect *rect, int modify, int max_value);
void move_recttransition(sfIntRect *rect, int modify, int max_value);
void move_rectdino(sfIntRect *rect, int base, int move, int max_value);
void move_rectsnowman(sfIntRect *rect, int move, int max_value);
void my_snowman(int i, char *map, chainmob_t mob, chainmob_t *chainmob);
void my_flysnowman(int i, char *map, chainmob_t mob, chainmob_t *mobglobal);
void my_gold(int i, char *map, chainmob_t mob, chainmob_t *chainmobglobal);
void my_flag(int i, char *map, chainmob_t mob, chainmob_t *chainmobglobal);
void display_s(sfRenderWindow *window, runner_t *runner);
void display_back(sfRenderWindow *window, back_t back);
void display_transition(sfRenderWindow *window, transition_t transi);
void display_dino(sfRenderWindow *window, dino_t dino);
void display_snowman(sfRenderWindow *window, snowman_t snowman);
void display_flysnowman(sfRenderWindow *window, flysnowman_t flysnowman);
void display_gold(sfRenderWindow *window, gold_t gold);
void display_flag(sfRenderWindow *window, flag_t flag);
void display_chainmob(sfRenderWindow *window, runner_t *runner);
void display_chainmob2(sfRenderWindow *window, runner_t *run, int i);
void display_bouton(sfRenderWindow *window, bouton_t bouton);
void switch_window(sfRenderWindow *window, runner_t *runner);
void check_mouse(sfRenderWindow *window, runner_t *runner);
int display_window(char *map);
void game_init(runner_t *runner);
void reset_game(runner_t *runner);

#endif
