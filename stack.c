/**
    Group #: 16

    DANIELES, MARICON  S09
    EDEP , TOBIAS RAIAN  S09
    SUAZON, KRISHA GEANE  S09 

    PURPOSE OF THIS FILE: (edit this)
*/

#include <stdio.h>
#include <stdlib.h>

// include your own stack header file
#include "stack.h"

void CREATE(Stack *S) {
    S->top = -1;
}

void PUSH(Stack *S, Point elem){
    if (ISFULL(S)) {
        printf("Error: Stack overflow\n");
    } else {
        S->top++;
        S->data[S->top] = elem;
    }
}

Point POP(Stack *S) {
    Point p;
    if (ISEMPTY(S)) {
        printf("Error: Stack underflow\n");
        p.x = 0.0;
        p.y = 0.0;
    } else {
        p = S->data[S->top];
        S->top--;
    }
    return p;
}

Point TOP(Stack *S){
    Point p;
    if (ISEMPTY(S)){
        printf("Error: Stack empty\n");
        p.x = 0.0;
        p.y = 0.0;
    } else {
        p = S->data[S->top];
    }
    return p;
}

int ISFULL(Stack *S){
    int result;
    if (S->top == (MAX_STACK - 1)) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int ISEMPTY(Stack *S){
    int result;
    if (S->top == -1){
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

Point NEXT_TO_TOP (Stack *S){
    Point p;
    if (S->top < 1){
        printf("Error: Only 1 Element in the Stack\n");
        p.x = 0.0;
        p.y = 0.0;
    } else {
        p = S->data[S->top - 1];
    }
    return p;
}

