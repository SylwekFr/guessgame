#include <stdio.h>
#include <stdlib.h>
#include "games.h"

int classicalgame(int secretNum, int counter, int* min, int* max) {
    int guess;
    printf("what's you guess ?\n");
    scanf_s("%d", &guess);
    if (guess > secretNum) {
        printf("you guess more than it is\n");
        *max = guess;
    }
    else if (guess < secretNum) {
        printf("you guess less than it is\n");
        *min = guess;
    }
    else {
        printf("you guess right in %d\n", counter);
    }
    return guess;
}
int multiplayergame(int secretNum, int counter, int* min, int* max) {
    int guess;
    if (counter % 2 == 0) {
        printf("player 2, your turn\n");
    }
    else {
        printf("player 1, your turn\n");
    }
    guess = classicalgame(secretNum, counter, min, max);
    return guess;
}
int againstcomputer(int secretNum, int counter, int* min, int* max) {
    int guess;
    if (counter % 2 == 0) {
        guess = computerplay(secretNum, counter, min, max);
    }
    else {
        guess = classicalgame(secretNum, counter, min, max);
    }

    return guess;
}
int computerplay(int secretNum, int counter, int* min, int* max) {
    int guess = *min + ((*max - *min) / 2);
    if (guess == *min) {
        guess += 1;
    }
    if (guess == *max) {
        guess -= 1;
    }
    printf("the computer guessed %d,", guess);
    if (guess > secretNum) {
        printf("it is too much\n");
        *max = guess;
    }
    else if (guess < secretNum) {
        printf("it is not enough\n");
        *min = guess;
    }
    else {
        printf("it is right in %d\n", counter);
    }
    return guess;
}