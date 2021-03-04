#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "setting.h"

int levelSetter(int *min,int *max) {
    int randNum = 0, level;
    do {
        printf("what level do you want ?\n 1: from 1 to 100\n 2: from 1 to 1000\n 3: from 1 to 10000\n");
        scanf_s("%d", &level);
        *min = 0;
        switch (level) {
        case 1:
            *max = 100;
            randNum = (rand() % (*max - *min + 1)) + *min;
            break;
        case 2:
            *max = 1000;
            randNum = (rand() % (*max - *min + 1)) + *min;
            break;
        case 3:
            *max = 10000;
            randNum = (rand() % (*max - *min + 1)) + *min;
            break;
        default:
            printf("your selection is icorrect, please enter a number between 1 and 3 accordingly\n");
        }
    } while (randNum == 0);
    return randNum;
}
int gameMode() {
    int mode = 0;
    do {
        printf("what level do you want ?\n 1: Solo\n 2: Two player\n 3: Against computer\n 4: Demo(computer alone)\n");
        scanf_s("%d", &mode);
        if (mode == 0) {
            printf("your selection is icorrect, please enter a number between 1 and 3 accordingly\n");
        }
    } while (mode == 0);
    return mode;
}