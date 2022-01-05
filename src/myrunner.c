/*
** EPITECH PROJECT, 2021
** bsmyrunner
** File description:
** Boostrap of runner
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void clock_game(runner_t *runner)
{
    if (sfClock_getElapsedTime(runner->clockback).microseconds > 16700.0) {
        move_rectback(&runner->backlist[2].rectback, 1, 272);
        move_rectback(&runner->backlist[3].rectback, 1, 272);
        move_rectback(&runner->backlist[4].rectback, 1, 272);
        //move_rectsnowman(&runner->scoreicon.rectgold, 12, 84);
        runner->scorenb += 1;
        for (int i = 0; runner->map[i] != '\0'; i++) {
            /*
            if (runner->chainmob[i].countain == 1)
                //move_rectsnowman(&runner->chainmob[i].snowman.rectsnowman, 1, 18);
                runner->chainmob[i].snowman.positionsnowman.x -= 7.3;
                runner->chainmob[i].gold.positiongold.x -= 7.3;
            */
            switch (runner->chainmob[i].countain)
            {
                case 1 :
                    //move_rectsnowman(runner->chainmob[i].gold.rectgold, 12, 24);
                    //runner->chainmob[i].snowman.positionsnowman.x -= 3.5;
                    runner->chainmob[i].snowman.positionsnowman.x -= 7.3;
                    break;
                case 2 :
                    //move_rectsnowman(&runner->chainmob[i].flysnowman.rectflysnowman, 34, 102);
                    runner->chainmob[i].flysnowman.positionflysnowman.x -= 7.3;
                    break;
                case 3 :
                    runner->chainmob[i].snowman.positionsnowman.x -= 7.3;
                    break;
                case 4 :
                    //move_rectsnowman(&runner->chainmob[i].gold.rectgold, 12, 84);
                    runner->chainmob[i].gold.positiongold.x -= 7.3;
                    break;
                case 5 :
                    runner->chainmob[i].flag.positionflag.x -= 7.3;
                    break;
            }
        }
        //move_rectdino(&runner->dino.rectdino, 0, 240);
        //move_rectdino(&runner->dinoreflect.rectdino, 0, 240);
        sfClock_restart(runner->clockback);
    }
    if (sfClock_getElapsedTime(runner->clockback2).microseconds > 20000.0) {
        //move_rectback(&runner->back.rectback, 0, 272);
        //move_rectback(&runner->back3.rectback, 0, 272);
        move_rectback(&runner->backlist[1].rectback, 1, 272);
        sfClock_restart(runner->clockback2);
    }
    /*
    if (sfClock_getElapsedTime(runner->clockcloud).microseconds > 30000.0) {
        move_rectback(&runner->back3.rectback, 0, 272);
        sfClock_restart(runner->clockcloud);
    }
    */
    if (sfClock_getElapsedTime(runner->clockdino).microseconds > 50000.0) {
        for (int i = 0; runner->map[i] != '\0'; i++) {
            switch (runner->chainmob[i].countain)
                {
                    case 1 :
                        break;
                    case 2 :
                        move_rectsnowman(&runner->chainmob[i].flysnowman.rectflysnowman, 34, 102);
                        break;
                    case 3 :
                        break;
                    case 4 :
                        move_rectsnowman(&runner->chainmob[i].gold.rectgold, 12, 84);
                        break;
                    case 5 :
                        break;
                }
        }
        move_rectsnowman(&runner->scoreicon.rectgold, 12, 84);
        if (runner->dinostate == CROUCH) {
            move_rectdino(&runner->dino.rectdino, 0, 18, 108);
            move_rectdino(&runner->dinoreflect.rectdino, 0, 18, 108);
        } else {
            move_rectdino(&runner->dino.rectdino, 0, 15, 105);
            move_rectdino(&runner->dinoreflect.rectdino, 0, 15, 105);
        }
        sfClock_restart(runner->clockdino);
    }
}

void close_window(sfRenderWindow *window, runner_t *runner)
{
    if (runner->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyBackspace)) {
        if (runner->menumusic) {
            sfMusic_stop(runner->menumusic);
            sfMusic_destroy(runner->menumusic);
        }
        if (runner->gamemusic) {
            sfMusic_stop(runner->gamemusic);
            sfMusic_destroy(runner->gamemusic);
        }
        sfRenderWindow_close(window);
    }
}

void jumpevent(sfRenderWindow *window, runner_t *runner)
{
    if (runner->dinostate != CROUCH) {
        if (runner->event.type == sfEvtKeyPressed && runner->event.key.code == sfKeyRShift && runner->dinostate == NORMAL) {
            runner->dinovitesse.y = -25;
            runner->dinostate = JUMP;
        }
        if (runner->event.type == sfEvtKeyReleased && runner->event.key.code == sfKeyRShift && runner->dinostate == JUMP) {
            runner->dinovitesse.y = -runner->dinovitesse.y;
            runner->dinostate = FALL;
        }
        if (runner->event.type != sfEvtKeyPressed && runner->event.key.code == sfKeyRShift && runner->dinostate == JUMPFINISH) {
            runner->dinostate = NORMAL;
        }
    }
}

void jump(sfRenderWindow *window, runner_t *runner)
{
    if (runner->dinostate != CROUCH) {
        if (runner->dinovitesse.y >= 0 && runner->dinostate == JUMP) {
            runner->dinovitesse.y = 0;
            runner->dinostate = FALL;
        }
        if (runner->dinovitesse.y <= 0 && runner->dinostate == JUMP) {
            runner->dino.positiondino.y += runner->dinovitesse.y;
            runner->dinoreflect.positiondino.y -= runner->dinovitesse.y;
            runner->dinovitesse.y += runner->gravity.y;
        } else if (runner->dino.positiondino.y >= 0 && runner->dinostate == FALL) {
            runner->dino.positiondino.y += runner->dinovitesse.y;
            runner->dinoreflect.positiondino.y -= runner->dinovitesse.y;
            runner->dinovitesse.y += runner->gravity.y;
            runner->dinostate = FALL;
        }
        if (runner->dino.positiondino.y >= 525 || runner->dinovitesse.y > 24 && runner->dinostate == FALL) {
            runner->dinovitesse.y = -25;
            runner->dino.positiondino.y = 525;
            runner->dinoreflect.positiondino.y = 760;
            runner->dinostate = NORMAL;
        }
    }
}

// void jump2(sfRenderWindow *window, runner_t *runner)
// {
//     if (runner->event.type == sfEvtKeyPressed && runner->event.key.code == sfKeySpace && runner->dinostate == NORMAL) {
//         runner->dinostate = JUMP;
//     }
//     if (runner->event.type == sfEvtKeyReleased && runner->event.key.code == sfKeySpace && runner->dinostate == JUMP)
//         runner->dinostate = FALL;
//     if (runner->dino.positiondino.y >= 350 && runner->dinostate == JUMP) {
//         runner->dino.positiondino.y += -10;
//         runner->dinoreflect.positiondino.y += 10;
//     } else if (runner->dino.positiondino.y < 525) {
//         runner->dino.positiondino.y += 8;
//         runner->dinoreflect.positiondino.y += -8;
//         runner->dinostate= FALL;
//     }
//     if (runner->dino.positiondino.y >= 525 && runner->dinostate != CROUCH) {
//         runner->dino.positiondino.y = 525;
//         runner->dinoreflect.positiondino.y = 760;
//         runner->dinostate = NORMAL;
//     }
// }

void crouch(sfRenderWindow *window, runner_t *runner)
{
    if (runner->event.type == sfEvtKeyPressed && runner->event.key.code == sfKeyLShift && runner->dinostate == NORMAL) {
        runner->dino.t_dino = sfTexture_createFromFile(runner->path_tdinocrouch[runner->texturedino], NULL);
        runner->dinoreflect.t_dino = sfTexture_createFromFile(runner->path_tdinocrouchreflect[runner->texturedino], NULL);
        runner->dino.positiondino.y = 540;
        runner->dinoreflect.positiondino.y = 760;
        sfIntRect rectdinocrouch = {0, 0, 18, 15};
        runner->dino.rectdino = rectdinocrouch;
        runner->dinoreflect.rectdino = rectdinocrouch;
        runner->dinostate = CROUCH;
    }
    if (runner->event.type == sfEvtKeyReleased && runner->event.key.code == sfKeyLShift && runner->dinostate == CROUCH) {
        runner->dino.t_dino = sfTexture_createFromFile(runner->path_tdino[runner->texturedino], NULL);
        runner->dinoreflect.t_dino = sfTexture_createFromFile(runner->path_tdinoreflect[runner->texturedino], NULL);
        sfIntRect rectdinonormal = {0, 0, 15, 17};
        runner->dino.positiondino.y = 525;
        runner->dinoreflect.positiondino.y = 760;
        runner->dino.rectdino = rectdinonormal;
        runner->dinoreflect.rectdino = rectdinonormal;
        runner->dinostate = NORMAL;
    }
}

void change_path_color(sfRenderWindow *window, runner_t *runner)
{
    if (runner->texturedino == 0) {
        runner->boutonlist[4].t_bouton = sfTexture_createFromFile(runner->path_tdino[0], NULL);
        runner->dino.t_dino = sfTexture_createFromFile(runner->path_tdino[0], NULL);
        runner->dinoreflect.t_dino = sfTexture_createFromFile(runner->path_tdinoreflect[0], NULL);
    }
    if (runner->texturedino == 1) {
        runner->boutonlist[4].t_bouton = sfTexture_createFromFile(runner->path_tdino[1], NULL);
        runner->dino.t_dino = sfTexture_createFromFile(runner->path_tdino[1], NULL);
        runner->dinoreflect.t_dino = sfTexture_createFromFile(runner->path_tdinoreflect[1], NULL);
    }
    if (runner->texturedino == 2) {
        runner->boutonlist[4].t_bouton = sfTexture_createFromFile(runner->path_tdino[2], NULL);
        runner->dino.t_dino = sfTexture_createFromFile(runner->path_tdino[2], NULL);
        runner->dinoreflect.t_dino = sfTexture_createFromFile(runner->path_tdinoreflect[2], NULL);
    }
    if (runner->texturedino == 3) {
        runner->boutonlist[4].t_bouton = sfTexture_createFromFile(runner->path_tdino[3], NULL);
        runner->dino.t_dino = sfTexture_createFromFile(runner->path_tdino[3], NULL);
        runner->dinoreflect.t_dino = sfTexture_createFromFile(runner->path_tdinoreflect[3], NULL);
    }
}

void switch_color(sfRenderWindow *window, runner_t *runner)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && runner->valid[4] == 1) {
        runner->texturedino += 1;
        my_printf("%d\n", runner->texturedino);
        if (runner->texturedino > 3)
            runner->texturedino = 0;
        change_path_color(window, runner);
    }
}

void boucle(sfRenderWindow *window, runner_t *runner)
{
    //my_printf("%s\n", runner->path_tdino[0]);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &runner->event)) {
            close_window(window, runner);
            switch_color(window, runner);
            if (runner->menustate == GAME) {
                jumpevent(window, runner);
                crouch(window, runner);
            }
            if (runner->menustate == GAME && runner->event.type == sfEvtKeyPressed && runner->event.key.code == sfKeyEscape)
                runner->menustate = PAUSE;
        }
        //my_printf("%s\n", runner->path_tdino[0]);
        if (runner->menustate == MENU)
            menu(window, runner);
        if (runner->menustate == GAME)
            game(window, runner);
        if (runner->menustate == PAUSE)
            gamepause(window, runner);
        if (runner->menustate == GAMEOVER)
            menugo(window, runner);
        if (runner->menustate == GAMEWIN)
            menuwin(window, runner);
        sfRenderWindow_display(window);
    }
}

int display_window(char *map)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    runner_t runner;
    runner.pathmap = map;
    create_a_party(&runner);
    //my_printf("%s\n", runner.path_tdino[0]);
    char *name = "MyRunner Project";
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    //sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    //my_printf("%s\n", runner.path_tdino[0]);
    boucle(window, &runner);
    if (window) {
        sfRenderWindow_close(window);
    }
}
