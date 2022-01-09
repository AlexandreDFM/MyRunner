/*
** EPITECH PROJECT, 2022
** clock
** File description:
** Functions to manage clock functions
*/

#include "runner.h"

void switch_first_clock2(runner_t *runner, int i, int j)
{
    if (j == 1) {
        runner->chainmob[i].snowman.positionsnowman.x -= 7.3;
        runner->chainmob[i].snowmanreflect.positionsnowman.x -= 7.3;
    }
    if (j == 2) {
        runner->chainmob[i].flysnowman.positionflysnowman.x -= 7.3;
        runner->chainmob[i].flysnowmanreflect.positionflysnowman.x -= 7.3;
    }
}

void switch_first_clock(runner_t *runner, int i)
{
    switch (runner->chainmob[i].countain)
        {
            case 1 :
                switch_first_clock2(runner, i, 1);
                break;
            case 2 :
                switch_first_clock2(runner, i, 2);
                break;
            case 4 :
                runner->chainmob[i].gold.positiongold.x -= 7.3;
                runner->chainmob[i].goldreflect.positiongold.x -= 7.3;
                break;
            case 5 :
                runner->chainmob[i].flag.positionflag.x -= 7.3;
                runner->chainmob[i].flagreflect.positionflag.x -= 7.3;
                break;
        }
}

void third_clock2(runner_t *runner, int i, int j)
{
    if (j == 1) {
        move_rectsnowman(&runner->chainmob[i].
        flysnowman.rectflysnowman, 34, 102);
        move_rectsnowman(&runner->chainmob[i].
        flysnowmanreflect.rectflysnowman, 34, 102);
    }
    if (j == 2) {
        move_rectsnowman(&runner->chainmob[i].gold.rectgold, 12, 84);
        move_rectsnowman(&runner->chainmob[i].goldreflect.rectgold, 12, 84);
    }
}

void third_clock(runner_t *runner)
{
    for (int i = 0; runner->map[i] != '\0'; i++) {
        switch (runner->chainmob[i].countain)
        {
            case 1 :
                break;
            case 2 :
                third_clock2(runner, i, 1);
                break;
            case 4 :
                third_clock2(runner, i, 2);
                break;
            case 5 :
                break;
        }
    }
}
