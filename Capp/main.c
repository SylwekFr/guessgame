#include <stdio.h>
#include <stdlib.h>
#include "setting.h"
#include "games.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int secretNum, guess, counter, mode, min = 0, max = 0;
    char playagain; 
    do {
        counter = 1;
        mode = gameMode();
        secretNum = levelSetter(&min, &max);
        do {
            switch (mode)
            {
            case 1:
                guess = classicalgame(secretNum, counter, &min, &max);
                break;
            case 2:
                guess = multiplayergame(secretNum, counter, &min, &max);
                break;
            case 3:
                guess = againstcomputer(secretNum, counter, &min, &max);
                break;
            case 4:
                guess = computerplay(secretNum, counter, &min, &max);
                break;
            default:
                guess = classicalgame(secretNum, counter, &min, &max);
            }
            ++counter;
        } while (guess != secretNum);
        printf("do you want to play again\ntip y for yes, anything else for no\n");
        scanf_s(" %c", &playagain, 1);
        printf("%c\n", playagain);
    } while (playagain == 'y');
    return 0;
}