/*
    Group #: 16

    DANIELES, MARICON       S09
    EDEP , TOBIAS RAIAN     S09
    SUAZON, KRISHA GEANE    S09 

    PURPOSE OF THIS FILE:
    To declare the Point and Stack structures and the stack functions.
*/

#ifndef STACK_H
#define STACK_H

#define MAX_STACK 32768 //max capacity of the stack

/*
    Point structure: represents a 2D coordinate point
        x is the x-coordinate of the point
        y is the y-coordinate of the point
*/
typedef struct {
    double x; //x-coordinate of the point
    double y; //y-coordinate of the point
} Point;

/*
    Stack structure: array-based stack implementation
        data is the fixed-size array of Points
        top is the index of the topmost element
*/
typedef struct {
    Point data[MAX_STACK]; //Array to store stack elements
    int top; //Index of top element
} Stack;

/*Initializes a stack to an empty state*/
void CREATE(Stack *S);

/*Adds a point to the top of the stack*/
void PUSH(Stack *S, Point elem);

/*Removes and returns the top element of the stack*/
Point POP(Stack *S);

/*Returns the top element without removing it*/
Point TOP(Stack *S);

/*Checks if the stack has reached its maximum capacity*/
int ISFULL(Stack *S);

/*Checks if the stack is empty*/
int ISEMPTY(Stack *S);

/*Returns the element below the top without removing it*/
Point NEXT_TO_TOP (Stack *S);

#endif



  
