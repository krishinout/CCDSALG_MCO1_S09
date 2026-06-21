/**
    Group #: 16

    DANIELES, MARICON       S09
    EDEP , TOBIAS RAIAN     S09
    SUAZON, KRISHA GEANE    S09 

    PURPOSE OF THIS FILE: 
    To compute the convex hull using Graham Scan with BubbleSort (slow version).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include "sort.h"

/*  
    a. Name of Programmer(s): EDEP, TOBIAS RAIAN & SUAZON, KRISHA GEANE
    b. Name of Tester(s)    : DANIELES, MARICON
    c. Code Type -- 100% Human Generated
    d. Purpose: this function will compute the convex hull using Graham Scan with BubbleSort (slow).
    e. Return: None
    f. Parameters: 
            points[] is the input array
            n is the number of points
            convexHull[] is the output array for hull points
            *convexHullSize is the pointer to store number of hull points
*/
void grahamSlow(Point points[], int n, Point convexHull[], int *convexHullSize){
    
    // Declaration of variables used.
    clock_t the_start; //Start
    clock_t the_end; //End
    double totalTime;

    // Start recording the timestap
    the_start = clock();

    int anchorIndex;
    Point temp, anchor;
    int i;
    int valid;
    Point point1, point2, point3;
    Stack S;
    
    /*
     Trivial case: Where 0, 1, or 2 points can't form a real convex hull.
     Instead, copy all input points directly into the output array.
    */
    if (n<=2) {
        for(i=0; i< n; i++){
            convexHull[i] = points[i];
        }
        *convexHullSize = n;
    }

    // General case using Graham Scan.
    else {
        /* 
         (1) Finding the anchor point:
         Find lowest y value. If same y values, find lowest
         x value as a tiebreaker 
         */
        anchorIndex = findAnchor(points, n);

        /*
         (2) Swap the anchor to position 0 if it's not already there.
         Create a copy anchor for sorting.
        */
        if (anchorIndex != 0){
            temp = points[0];
            points[0] = points[anchorIndex];
            points[anchorIndex] = temp;
        }
        anchor = points[0];

        /*
         (3) Using BubbleSort, sort all points except the anchor by polar angle
         that's relative to it.
         - point+1 shifts array for index 0 to be points[1] of the original.
         - n-1 as the number of elements being sorted but the anchor
        */
        BubbleSort(points+1, n-1, anchor);

        /* 
         (4) Initialize the stack and push first two points (anchor first
         sorted point) to start the hull.
        */
        CREATE(&S);
        PUSH(&S, points[0]);
        PUSH(&S, points[1]);

        /* 
         (5) Continue with remaining points in angular order.
        */
        for(i=2;i < n; i++){
            valid = 0;
            while (S.top >= 1 && (valid == 0)){
                point1 = NEXT_TO_TOP(&S);
                point2 = TOP(&S);
                point3 = points[i];
                
                if (CrossProduct(point1, point2, point3) <= 0){
                    POP(&S); ///POP if last 3 points form a CLOCKWISE or COLLINEAR turn.
                } else {
                    valid = 1;
                }
            }
            PUSH(&S, points[i]); // PUSH if last 3 points form a COUNTERCLOCKWISE turn.
        }
        
        /*
         (6) Transfer contents of the stack into the output array.
         - Drain into an empty array as popping returns elements in reverse.
        */
        int m = 0;
        Point tempConvexHull[MAX_STACK];
        
        while(!ISEMPTY(&S)){
            tempConvexHull[m++] = POP(&S);
        }

        // Copy into convexHull in reverse order for final result to be in counterclockwise sequence.
        for(i = 0; i < m; i++){
            convexHull[i] = tempConvexHull[m-1-i];
        }

        // Store amount of points in the convex hull.
        *convexHullSize = m;
    }

    /*
     (7) Stop timer and convert clock ticks -> seconds -> miliseconds.
    */
    the_end = clock();
    totalTime = ((double)(the_end - the_start) / CLOCKS_PER_SEC) * 1000;
    printf("Slow version execution time: %.6f ms\n", totalTime); 
}
