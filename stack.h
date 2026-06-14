/*
    Group #: 16

    DANIELES, MARICON  S09
    EDEP , TOBIAS RAIAN  S09
    SUAZON, KRISHA GEANE  S09 

    PURPOSE OF THIS FILE: (edit this)
*/

/*
    You may encode any of the following below this comment the following:   
    1. #define directives
    2. typedef alias(es) 
    3. declaration of your user-defined struct data type(s)
    4. typedef alias(es) for your struct data type(s) -- you have to put an inline comment 
       for each struct member as part of the documentation. 

    The header should NOT include the codes for any function definitions.  

    Function definitions should be encoded in your C source file only!
*/
#ifndef STACK_H
#define STACK_H

#define MAX_STACK 32768

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point data[MAX_STACK];
    int top;
} Stack;

void CREATE(Stack *S);
void PUSH(Stack *S, Point elem);
Point POP(Stack *S);
Point TOP(Stack *S);
int ISFULL(Stack *S);
int ISEMPTY(Stack *S);
Point NEXT_TO_TOP (Stack *S);

#endif



  
