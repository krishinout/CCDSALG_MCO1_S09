/**
    Group #: 16

    DANIELES, MARICON  S09
    EDEP , TOBIAS RAIAN  S09
    SUAZON, KRISHA GEANE  S09 

    PURPOSE OF THIS FILE: (edit this)
*/
#include <stdio.h>
#include <stdlib.h>
// include your own stack C source file
#include "stack.c"

int main()
{
   Stack S;
   Point p1 = {1.0, 2.0};
   Point p2 = {3.0, 4.0};
   Point p3 = {5.0, 6.0};
   Point p4 = {7.0, 8.0};
   Point result;

   printf("\n\n=== Testing Stack Operations ===\n");

   //CREATE, ISEMPTY, & ISFULL
   printf("CREATE, ISEMPTY, & ISFULL OPERATION\n");
   CREATE(&S);
   printf("After CREATE: ISEMPTY = %d (should be 1)\n", ISEMPTY(&S));
   printf("ISFULL = %d (should be 0)\n\n", ISFULL(&S));

   //PUSH & TOP
   printf("PUSH & TOP OPERATION\n");
   printf("Pushing (1,2), (3,4), (5,6)\n");
   PUSH(&S, p1);
   PUSH(&S, p2);
   PUSH(&S, p3);
   result = TOP(&S);

   printf("TOP = (%.1f, %.1f) (should be (5,6))\n", result.x, result.y);
   printf("ISEMPTY = %d (should be 0)\n", ISEMPTY(&S));

   //NEXT TO TOP
   printf("NEXT_TO_TOP OPERATION\n");
   result = NEXT_TO_TOP(&S);
   printf("NEXT_TO_TOP = (%.1f, %.1f) (should be (3,4))\n", result.x, result.y);

   //POP
   printf("POP OPERATION\n");
   result = POP(&S);
   printf("POP returned (%.1f, %.1f) (should be (5,6))\n", result.x, result.y);
   result = TOP(&S);
   printf("After POP, TOP = (%.1f, %.1f) (should be (3,4))\n", result.x, result.y);

   //DOUBLE CHECKING
   printf("Pushing (7,8)");
   PUSH(&S, p4);
   result = NEXT_TO_TOP(&S);
   printf("NEXT_TO_TOP = (%.1f, %.1f) (should be (3,4))\n", result.x, result.y);
   result = TOP(&S);
   printf("TOP = (%.1f, %.1f) (should be (7,8))\n", result.x, result.y);

   printf("=== Stack Operations Test Completed ===\n\n");


   printf("===Testing Stack Edge Cases ===\n");

   // POP UNTIL EMPTY
    printf("\nEDGE CASE 1: Pop until stack becomes empty\n");

    while (!ISEMPTY(&S)) {
        result = POP(&S);
        printf("Popped (%.1f, %.1f)\n", result.x, result.y);
}

   printf("After popping everything: ISEMPTY = %d (should be 1)\n", ISEMPTY(&S));
   printf("After popping everything: ISFULL = %d (should be 0)\n", ISFULL(&S));

   //REUSE STACK AFTER EMPTYING
   printf("\nEDGE CASE 2: Reuse stack after emptying\n");

   Point negativePoint = {-1.5, -2.5};
   Point decimalPoint = {3.75, 4.25};

   PUSH(&S, negativePoint);
   result = TOP(&S);
   printf("After pushing negative point, TOP = (%.2f, %.2f) (should be (-1.50, -2.50))\n",
            result.x, result.y);

    PUSH(&S, decimalPoint);
    result = TOP(&S);
    printf("After pushing decimal point, TOP = (%.2f, %.2f) (should be (3.75, 4.25))\n", 
            result.x, result.y);

     result = NEXT_TO_TOP(&S);
     printf("NEXT_TO_TOP = (%.2f, %.2f) (should be (-1.50, -2.50))\n",
          result.x, result.y);

    //FILL STACK TO MAX CAP
    printf("\nEDGE CASE 4: Fill stack until full\n");

    CREATE(&S);

    for (int i = 0; i < MAX_STACK; i++) {
      Point tempPoint;
      tempPoint.x = i;
      tempPoint.y = i + 0.5;

      PUSH(&S, tempPoint);
   }

    printf("After pushing MAX_STACKS items: ISFULL = %d (should be 1)\n", ISFULL(&S));
    printf("After pushing MAX_STACKS items: ISEMPTY = %d (should be 0)\n", ISEMPTY(&S));

    result = TOP(&S);
    printf("TOP after full stack = (%.1f, %.1f) (should be (32767.0, 32767.5))\n",
            result.x, result.y);

    
//TRY PUSHING WHEN STACK ALREADY FULL
 printf("\nEDGE CASE 5: Push when stack is already full\n");

   Point extraPoint = {99999.0, 99999.0};

   PUSH(&S, extraPoint);

   result = TOP(&S);
   printf("After extra PUSH, TOP = (%.1f, %.1f)\n", result.x, result.y);
   printf("If your PUSH is correct, TOP should still be (32767.0, 32767.5)\n");


   /* EDGE CASE 6: Pop once from full stack */
   printf("\nEDGE CASE 6: Pop once from full stack\n");

   result = POP(&S);
   printf("POP from full stack returned (%.1f, %.1f) (should be (32767.0, 32767.5))\n",
          result.x, result.y);

   printf("After one POP: ISFULL = %d (should be 0)\n", ISFULL(&S));

   printf("\n=== Stack Edge Case Tests Completed ===\n");
    
   return 0;
}


