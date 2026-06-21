/**
    Group #: 16

    DANIELES, MARICON       S09
    EDEP , TOBIAS RAIAN     S09
    SUAZON, KRISHA GEANE    S09 

    PURPOSE OF THIS FILE:
    To implement all stack operations using an array.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/*  
    a. Name of Programmer(s): EDEP , TOBIAS RAIAN
    b. Name of Tester(s)    : DANIELES, MARICON
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will initialize a stack by setting its top index to -1 (empty state).
    e. Return: None
    f. Parameters: 
            *S is the pointer to the stack to be initialized  
*/
void CREATE(Stack *S) {
    // top is -1 for first element to be pushed is at index 0.
    S->top = -1;
}


/*
    a. Name of Programmer(s): SUAZON, KRISHA GEANE
    b. Name of Tester(s)    : EDEP , TOBIAS RAIAN
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will add point element to the top of the stack if space is available.
    e. Return: None
    f. Parameters: 
            *S is the pointer to the stack
            elem is the point to be pushed onto the stack
*/
void PUSH(Stack *S, Point elem){
    // To avoid stack overflow
    if (ISFULL(S)) {
        printf("Error: Stack overflow\n");
    } 
    // Increment top first, then push new element.
    else {
        S->top++;
        S->data[S->top] = elem;
    }
}

/*  
    a. Name of Programmer(s): SUAZON, KRISHA GEANE
    b. Name of Tester(s)    : DANIELES, MARICON
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will remove and return to the top element from the stack.
    e. Return: Point - the top element; returns (0,0) if stack is empty
    f. Parameters: 
            *S is the pointer to the stack
*/
Point POP(Stack *S) {
    Point p;

    // Avoids stack underflow
    if (ISEMPTY(S)) {
        printf("Error: Stack underflow\n");
        p.x = 0.0;
        p.y = 0.0;
    } 
    /*
     Take current top element and decrement top value. Old data is left in the array 
     but is inaccessible until overwritten.
     */ 
    else {
        p = S->data[S->top];
        S->top--;
    }
    return p;
}

/*  
    a. Name of Programmer(s): SUAZON, KRISHA GEANE
    b. Name of Tester(s)    : EDEP, TOBIAS RAIAN
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will return the top element of the stack without removing it.
    e. Return: Point - the top element; returns (0,0) if stack is empty
    f. Parameters: 
            *S is the pointer to the stack
*/
Point TOP(Stack *S){
    Point p;
    // Prints error if stack is empty and point values are set to 0 for now.
    if (ISEMPTY(S)){
        printf("Error: Stack empty\n");
        p.x = 0.0;
        p.y = 0.0;
    } 
    // If stack is not empty, returns the element in the top index.
    else {
        p = S->data[S->top];
    }
    return p;
}

/*  
    a. Name of Programmer(s): DANIELES, MARICON
    b. Name of Tester(s)    : SUAZON, KRISHA GEANE
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will check if the stack has reached its max capacity.
    e. Return: int - 1 if stack is full, 0 if not full
    f. Parameters: 
            *S is the pointer to the stack
*/
int ISFULL(Stack *S){
    int result;
    if (S->top == (MAX_STACK - 1)) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/*  
    a. Name of Programmer(s): DANIELES, MARICON
    b. Name of Tester(s)    : SUAZON, KRISHA GEANE
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will check if the stack is empty.
    e. Return: int - 1 if stack is empty, 0 if not empty
    f. Parameters: 
            *S is the pointer to the stack
*/
int ISEMPTY(Stack *S){
    int result;
    if (S->top == -1){
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/*  
    a. Name of Programmer(s): EDEP, TOBIAS RAIAN
    b. Name of Tester(s)    : SUAZON, KRISHA GEANE
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will retrun the element below the top of the stack without removing it.
    e. Return: Point - the element below the top; returns (0,0) if only one element exists
    f. Parameters: 
            *S is the pointer to the stack
*/
Point NEXT_TO_TOP (Stack *S){
    Point p;

    // Must have at least 2 elements (index 0 and 1) for return value to exist
    if (S->top < 1){
        printf("Error: Only 1 Element in the Stack\n");
        p.x = 0.0;
        p.y = 0.0;
    } 
    // Assigns the element before the current to p, to be used by the Graham Scan.
    else {
        p = S->data[S->top - 1];
    }
    return p;
}

