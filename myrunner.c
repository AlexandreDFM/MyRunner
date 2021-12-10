/*
** EPITECH PROJECT, 2021
** bsmyrunner
** File description:
** Boostrap of runner
*/

#include "./include/my.h"
#include "./include/printf.h"
#include "./include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
runner_t *create_object(const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect)
{
    runner_t *runner = malloc(sizeof(runner_t));
    runner->t_back = sfTexture_createFromFile(path_to_spritesheet, NULL);
    runner->s_back = sfSprite_create();
    runner->positionback = pos;
    runner->rectback = rect;

    runner->t_back2 = sfTexture_createFromFile("./images/vegetation_(middle_layer).png", NULL);
    runner->s_back2 = sfSprite_create();
    runner->positionback2 = pos;
    runner->rectback2 = rect;
    
    runner->t_back3 = sfTexture_createFromFile("./images/ground_(front_layer).png", NULL);
    runner->s_back3 = sfSprite_create();
    runner->positionback3 = pos;
    runner->rectback3 = rect;
    return (runner);
}
*/

back_t create_back(const char *path_texture, sfVector2f pos, sfIntRect rect)
{
    back_t back;
    back.t_back = sfTexture_createFromFile(path_texture, NULL);
    back.s_back = sfSprite_create();
    back.positionback = pos;
    back.rectback = rect;
    sfVector2f resize = {7, 6.1};
    back.resize = resize;
    return (back); 
}

dino_t create_dino(const char *path_texture, sfVector2f pos, sfIntRect rect)
{
    dino_t dino;
    dino.t_dino = sfTexture_createFromFile(path_texture, NULL);
    dino.s_dino = sfSprite_create();
    dino.positiondino = pos;
    dino.rectdino = rect;
    sfVector2f resize = {7, 6.1};
    dino.resize = resize;
    return (dino); 
}

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

/*
void destroy_object(runner_t *runner)
{  
    sfTexture_destroy(runner->t_back);
    sfSprite_destroy(runner->s_back);
}
*/

void destroy_back(back_t back)
{
    sfTexture_destroy(back.t_back);
    sfSprite_destroy(back.s_back);
}

void move_rectback(sfIntRect *rect, int modify, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = modify;
    } else {
        rect->left += modify;
    }
}

void move_rectdino(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = 96;
    } else {
        rect->left += 24;
    }
}

void clock_game(runner_t *runner)
{
    if (sfClock_getElapsedTime(runner->clockback).microseconds > 47000.0) {
        move_rectback(&runner->back.rectback, 4, 272);
        move_rectback(&runner->back2.rectback, 4, 272);
        move_rectback(&runner->back3.rectback, 1, 272);
        move_rectback(&runner->back4.rectback, 5, 272);
        move_rectback(&runner->back5.rectback, 5, 272);
        move_rectdino(&runner->dino.rectdino, 0, 240);
        move_rectdino(&runner->dinoreflect.rectdino, 0, 240);
        sfClock_restart(runner->clockback);
    }
    /*
    if (sfClock_getElapsedTime(runner->clockback2).microseconds > 20000.0) {
        //move_rectback(&runner->back.rectback, 0, 272);
        //move_rectback(&runner->back3.rectback, 0, 272);
        move_rectback(&runner->back4.rectback, 0, 272);
        move_rectback(&runner->back5.rectback, 0, 272);
        sfClock_restart(runner->clockback2);
    }
    if (sfClock_getElapsedTime(runner->clockcloud).microseconds > 30000.0) {
        move_rectback(&runner->back3.rectback, 0, 272);
        sfClock_restart(runner->clockcloud);
    }
    if (sfClock_getElapsedTime(runner->clockdino).microseconds > 50000.0) {
        move_rectdino(&runner->dino.rectdino, 0, 240);
        move_rectdino(&runner->dinoreflect.rectdino, 0, 240);
        sfClock_restart(runner->clockdino);
    }
    */
}

void close_window(sfRenderWindow *window, runner_t *runner, sfEvent event)
{
    int i = 0;
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyBackspace))
        sfRenderWindow_close(window);
}

void display_back(sfRenderWindow *window, back_t back)
{
    sfSprite_setTexture(back.s_back, back.t_back, sfTrue);
    sfSprite_setPosition(back.s_back, back.positionback);
    sfSprite_setTextureRect(back.s_back, back.rectback);
    sfSprite_setScale(back.s_back, back.resize);
    sfRenderWindow_drawSprite(window, back.s_back, NULL);
}

void display_dino(sfRenderWindow *window, dino_t dino)
{
    sfSprite_setTexture(dino.s_dino, dino.t_dino, sfTrue);
    sfSprite_setPosition(dino.s_dino, dino.positiondino);
    sfSprite_setTextureRect(dino.s_dino, dino.rectdino);
    sfSprite_setScale(dino.s_dino, dino.resize);
    sfRenderWindow_drawSprite(window, dino.s_dino, NULL);
}

void display_snowman(sfRenderWindow *window, snowman_t snowman)
{
    sfSprite_setTexture(snowman.s_snowman, snowman.t_snowman, sfTrue);
    sfSprite_setPosition(snowman.s_snowman, snowman.positionsnowman);
    sfSprite_setTextureRect(snowman.s_snowman, snowman.rectsnowman);
    sfSprite_setScale(snowman.s_snowman, snowman.resize);
    sfRenderWindow_drawSprite(window, snowman.s_snowman, NULL);
}

void display_chainmob(sfRenderWindow *window, chainmob_t *chainmob)
{
    chainmob_t *currentNode = malloc(sizeof(chainmob_t));
    currentNode = chainmob;
    //printf("%d", currentNode->next->next->next->);
    for (int i = 0; currentNode->next != NULL; i++) {
        currentNode = currentNode->next;
        printf("%d\n", 45);
        if (currentNode->countain == 1) {
            printf("%d\n", 1);
            display_snowman(window, currentNode->snowman);
        }
    }
}

void jump(sfRenderWindow *window, runner_t *runner)
{
    if (runner->event.type == sfEvtKeyPressed && runner->event.key.code == sfKeySpace && runner->dinojump == 0)
        runner->dinojump = 1;
    if (runner->event.type == sfEvtKeyReleased && runner->event.key.code == sfKeySpace && runner->dinojump == 1)
        runner->dinojump = 2;
    if (runner->dino.positiondino.y >= 350 && runner->dinojump == 1) {
        runner->dino.positiondino.y += -10;
        runner->dinoreflect.positiondino.y += 10;
    } else if (runner->dino.positiondino.y < 500) {
        runner->dino.positiondino.y += 8;
        runner->dinoreflect.positiondino.y += -8;
        runner->dinojump = 2;
    }
    if (runner->dino.positiondino.y >= 500)
        runner->dinojump = 0;
    runner->space = 0;
}

char *fs_open_file(char *mappath)
{
    char *buffer = malloc(sizeof(char)*(378 + 1));
    int fd = open(mappath, O_RDONLY);
    int total_read = 0, n_read = 0;
    while ((n_read = read(fd, buffer + total_read,
                          (378 + 1) - total_read)) > 0) {
        total_read += n_read;
    }
    buffer[378] = '\0';
    return (buffer);
}

chainmob_t *create_list(chainmob_t *chainmob, int size)
{
    chainmob_t *temp, *currentNode;
    for (int counter = 0; counter != size; counter++) {
        if (counter == 0) {
            chainmob = temp = currentNode;
        } else {
            temp = currentNode->next;
        }
    }
}

chainmob_t *parsemap(char *mappath)
{
    char *map = fs_open_file(mappath);
    my_printf("%s\n", map);
    chainmob_t *chainmob, *currentNode = malloc(sizeof(chainmob_t));
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '1') {
            my_printf("%s\n", "J'ai un snowman");
            currentNode->countain = 1;
            sfVector2f positionsnowman = {i, 500};
            currentNode->snowman = create_snowman("./sprites/snowman.png", positionsnowman);
        } else {
            //my_printf("%d", 423);
            currentNode->countain = 0;
            //my_printf("%d", 423);
        }
        if (i == 0) {
            chainmob = currentNode;
        } else {
            currentNode->next = currentNode;
        }
    }
    currentNode->next = NULL;
    return (chainmob);
}

void boucle(sfRenderWindow *window, runner_t *runner)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            runner->event = event;
            close_window(window, runner, event);
            jump(window, runner);
            //if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            //    runner->dino.positiondino.y += -20;
        }
        //printf("%d", 57);
        clock_game(runner);
        display_back(window, runner->back);
        display_back(window, runner->back2);
        display_back(window, runner->back3);
        display_back(window, runner->back4);
        display_back(window, runner->back5);
        jump(window, runner);
        //printf("%d", 59);
        //display_chainmob(window, runner->chainmob);
        display_dino(window, runner->dino);
        display_dino(window, runner->dinoreflect);
        sfRenderWindow_display(window);
    }
}

int display_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    runner_t runner;
    char *path_texture = "./sprites/backg.png";
    char *path_texture2 = "./sprites/foreground.png";
    char *path_texture3 = "./sprites/cloud.png";
    char *path_texture4 = "./sprites/decor_arbre.png";
    char *path_texture5 = "./sprites/sol.png";
    sfVector2f positionback = {0, 0};
    sfIntRect rectback = {0, 0, 544, 178};
    runner.back = create_back(path_texture, positionback, rectback);
    runner.back2 = create_back(path_texture2, positionback, rectback);
    runner.back3 = create_back(path_texture3, positionback, rectback);
    runner.back4 = create_back(path_texture4, positionback, rectback);
    runner.back5 = create_back(path_texture5, positionback, rectback);
    runner.chainmob = parsemap("./maps/map1.txt");
    char *path_texturedino = "./sprites/dino_sprites_blue.png";
    char *path_texturedinoreflect = "./sprites/dino_sprites_blue_reflect.png";
    sfVector2f positiondino = {0, 500};
    sfVector2f positiondinoreflect = {0, 760};
    sfIntRect rectdino = {120, 0, 24, 24};
    runner.dino = create_dino(path_texturedino, positiondino, rectdino);
    runner.dinoreflect = create_dino(path_texturedinoreflect, positiondinoreflect, rectdino);
    runner.clockback = sfClock_create();
    runner.clockback2 = sfClock_create();
    runner.clockcloud = sfClock_create();
    runner.clockdino = sfClock_create();
    char *name = "MyRunner Project";
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    //char *mappath = "./maps/map1.txt";
    //runner.chainmob = parsemap(mappath);
    boucle(window, &runner);
    if (window) {
        sfRenderWindow_close(window);
    }
    destroy_back(runner.back);
}

int main(void)
{
    display_window();
}
