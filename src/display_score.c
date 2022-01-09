/*
** EPITECH PROJECT, 2021
** displayscore
** File description:
** Function to display the game score
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/runner.h"
#include <stdlib.h>

char *my_put_nbrstr(int number)
{
    int number2, i = 0;
    char *str = malloc(sizeof(char)*10);
    for (; number > 0;) {
        if (number >= 10) {
            number2 = number % 10;
            number = (number - number2) / 10;
            str[i] = number2 + 48;
            i += 1;
        } else {
            str[i] = number + 48;
            i += 1;
            number = 0;
        }
    }
    str[i] = '\0';
    return (str);
}

char *make_score(runner_t *runner)
{
    char *nb = my_put_nbrstr(runner->scorenb / 10);
    if (my_strlen(nb) < 6) {
        char *nb2 = malloc(sizeof(char)*7);
        int i = 0;
        for (; i < my_strlen(nb); i++)
            nb2[i] = nb[i];
        for (; i < 6; i++)
            nb2[i] = '0';
        nb2[i] = '\0';
        my_revstr(nb2);
        return (nb2);
    } else if (my_strlen(nb) > 6) {
        runner->scorenb = 0;
        return ("000000");
    }
    return (my_revstr(nb));
}

void display_s(sfRenderWindow *window, runner_t *runner)
{
    display_gold(window, runner->scoreicon);
    sfText_setString(runner->score, make_score(runner));
    sfText_setFont(runner->score, runner->font);
    sfText_setCharacterSize(runner->score, 40);
    sfText_setPosition(runner->score, runner->positionscore);
    sfRenderWindow_drawText(window, runner->score, NULL);
}
