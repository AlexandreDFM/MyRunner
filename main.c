/*
** EPITECH PROJECT, 2021
** main
** File description:
** Main of Runner
*/

#include "./include/my.h"
#include "./include/my_printf.h"
#include "./include/runner.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>

void print_manual(void)
{
    my_putstr("\n                                                  DINO "
                "RUN\n\n");
    my_putstr("Dino run is a runner game in which the objective is to "
                "jump and crouch to avoid the ennemies on the screen in.\n");
    my_putstr("The dino will move faster with the score.\n");
    my_putstr("\n                                                  RULES\n\n");
    my_putstr("Don't be killed by ennemies.\n");
    my_putstr("\n                                                  "
                "CONTROLS\n\n");
    my_putstr("      - Click on the play bouton to start or exit bouton to "
                "exit.\n");
    my_putstr("      - Once in game press escape to pause.\n");
    my_putstr("      - If paused press space or click on the play bouton to "
                "resume, you can also click on the exit bouton to exit.\n");
    my_putstr("      - If you Game Over you can press R to retry or Escape "
    "to close.\n");
}

void print_manual2(void)
{
    my_putstr("      - Jump with Space and Crouch with L-Shift.\n\n");
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        srand(time(0));
        display_window(argv[1]);
    } else if (argc == 2 && my_strlen(argv[1]) == 2 && argv[1][0] == '-'
    && argv[1][1] == 'h') {
        print_manual();
        print_manual2();
    }
    return (0);
}
