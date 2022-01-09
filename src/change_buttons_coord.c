/*
** EPITECH PROJECT, 2022
** change_butons_coord
** File description:
** Function to change boutons coord
*/

#include "runner.h"

void change_butons_coord_win(runner_t *runner)
{
    sfVector2f playagainbpos = {328+530, 136+240};
    sfVector2f menubpos = {328+530, 225+240};
    sfVector2f quitbpos = {328+530, 275+240};
    runner->boutonlist[1].positionbouton = quitbpos;
    runner->boutonlist[2].positionbouton = playagainbpos;
    runner->boutonlist[3].positionbouton = menubpos;
}

void change_butons_coord_go(runner_t *runner)
{
    sfVector2f pabpos = {328+530, 136+240};
    sfVector2f menubpos = {328+530, 225+240};
    sfVector2f quitbpos = {328+530, 275+240};
    runner->boutonlist[1].positionbouton = quitbpos;
    runner->boutonlist[3].positionbouton = menubpos;
    runner->boutonlist[2].positionbouton = pabpos;
}

void change_butons_coord_pause(runner_t *runner)
{
    sfVector2f continuebpos = {306+530, 146+240};
    sfVector2f retrybpos = {328+530, 200+240};
    sfVector2f menubpos = {328+530, 250+240};
    sfVector2f quitbpos = {328+530, 300+240};
    runner->boutonlist[1].positionbouton = quitbpos;
    runner->boutonlist[4].positionbouton = retrybpos;
    runner->boutonlist[3].positionbouton = menubpos;
    runner->boutonlist[5].positionbouton = continuebpos;
}

void change_butons_coord_reset(runner_t *runner)
{
    sfVector2f playbpos = {328+530, 200+240};
    sfVector2f quitbpos = {328+530, 250+240};
    runner->boutonlist[0].positionbouton = playbpos;
    runner->boutonlist[1].positionbouton = quitbpos;
}
