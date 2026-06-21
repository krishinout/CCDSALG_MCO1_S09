/**
    Group #: 16

    DANIELES, MARICON       S09
    EDEP , TOBIAS RAIAN     S09
    SUAZON, KRISHA GEANE    S09 

    PURPOSE OF THIS FILE:
    To test the sorting module functions, including Bubble Sort, Merge Sort,
    polar angle comparison, distance checking, and edge cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*  
    a. Name of Programmer(s): DANIELES, MARICON
    b. Name of Tester(s)    : SUAZON, KRISHA GEANE
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will print an array of points to the console with one point per line.
    e. Return: None
    f. Parameters: 
            points[] is the array of points to print
            n is the number of points
*/
void PrintPoints(Point points[], int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        printf("(%.1f, %.1f)\n", points[i].x, points[i].y);
    }
    printf("\n");
}

/*  
    a. Name of Programmer(s): SUAZON, KRISHA GEANE
    b. Name of Tester(s)    : EDEP, TOBIAS RAIAN
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will copy an array points from source to destination.
    e. Return: None
    f. Parameters: 
            source[] is the source array
            destination[] is the destination array
            n is the number of points to copy
*/
void CopyPoints(Point source[], Point destination[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

/*  
    a. Name of Programmer(s): EDEP, TOBIAS RAIAN
    b. Name of Tester(s)    : DANIELES, MARICON
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will verify if an array is correctly sorted by polar angle
    e. Return: int - 1 if sorted correctly, o otherwise
    f. Parameters: 
            points[] is the array to check
            n is the number of points
            anchor is the reference point
*/
int IsSortedByPolarAngle(Point points[], int n, Point anchor)
{
    int i;
    for (i = 0; i < n - 1; i++) {
        if (ComparePolarAngle(anchor, points[i], points[i + 1]) > 0) {
            return 0;   // Out of order
        }
    }
    return 1;   // Sorted correctly
}

/*  
    a. Name of Programmer(s): EDEP, TOBIAS RAIAN & SUAZON, KRISHA GEANE
    b. Name of Tester(s)    : DANIELES, MARICON
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will test all sorting functions, geometry helpers, and edge cases.
    e. Return: int - 0 on success
    f. Parameters: 
            None
*/
int main()
{
    Point anchor = {0.0, 0.0};
    Point bubbleTest[6];
    Point mergeTest[6];

    double resultDouble;
    int resultInt;
    int n = 6;

    Point original[] = {
        {5.0, 5.0},     // 45 degrees
        {10.0, 0.0},    // 0 degrees
        {0.0, 10.0},    // 90 degrees
        {3.0, 4.0},     // between 45 and 90
        {10.0, 2.5},    // small angle
        {5.0, 0.0}      // 0 degrees, closer than (10,0)
    };

    printf("\n\n=== Testing Sort Operations ===\n");

    /*
        TEST 1: CrossProduct
    */
    printf("\nTEST 1: CrossProduct\n");
    resultDouble = CrossProduct(anchor, original[1], original[2]);
    printf("CrossProduct((0,0), (10,0), (0,10)) = %.1f\n", resultDouble);
    printf("Expected: positive (counterclockwise)\n");

    resultDouble = CrossProduct(anchor, original[2], original[1]);
    printf("CrossProduct((0,0), (0,10), (10,0)) = %.1f\n", resultDouble);
    printf("Expected: negative (clockwise)\n");

    /*
        TEST 2: DistanceSquared
    */
    printf("\nTEST 2: DistanceSquared\n");
    resultDouble = DistanceSquared(anchor, original[5]);
    printf("DistanceSquared((0,0), (5,0)) = %.1f (expected: 25.0)\n", resultDouble);

    resultDouble = DistanceSquared(anchor, original[1]);
    printf("DistanceSquared((0,0), (10,0)) = %.1f (expected: 100.0)\n", resultDouble);

    /*
        TEST 3: ComparePolarAngle
    */
    printf("\nTEST 3: ComparePolarAngle\n");
    resultInt = ComparePolarAngle(anchor, original[1], original[2]);
    printf("Compare (10,0) vs (0,10) = %d (expected: -1)\n", resultInt);

    resultInt = ComparePolarAngle(anchor, original[2], original[1]);
    printf("Compare (0,10) vs (10,0) = %d (expected: 1)\n", resultInt);

    resultInt = ComparePolarAngle(anchor, original[5], original[1]);
    printf("Compare (5,0) vs (10,0) = %d (expected: -1, closer first)\n", resultInt);

    /*
        TEST 4: BubbleSort
    */
    printf("\nTEST 4: BubbleSort\n");
    CopyPoints(original, bubbleTest, n);
    printf("Before BubbleSort:\n");
    PrintPoints(bubbleTest, n);

    BubbleSort(bubbleTest, n, anchor);
    printf("After BubbleSort:\n");
    PrintPoints(bubbleTest, n);
    printf("Is sorted by polar angle? %d (expected: 1)\n", IsSortedByPolarAngle(bubbleTest, n, anchor));

    /*
        TEST 5: MergeSort
    */
    printf("\nTEST 5: MergeSort\n");
    CopyPoints(original, mergeTest, n);
    printf("Before MergeSort:\n");
    PrintPoints(mergeTest, n);

    MergeSort(mergeTest, 0, n - 1, anchor);
    printf("After MergeSort:\n");
    PrintPoints(mergeTest, n);
    printf("Is sorted by polar angle? %d (expected: 1)\n", IsSortedByPolarAngle(mergeTest, n, anchor));

    /*
        TEST 6: Compare BubbleSort and MergeSort Results
    */
    printf("\nTEST 6: Compare BubbleSort and MergeSort\n");
    int identical = 1;
    int i=0;
    /* for (i = 0; i < n; i++) {
        if (bubbleTest[i].x != mergeTest[i].x || bubbleTest[i].y != mergeTest[i].y) {
            identical = 0;
        }
    } */

    while(i < n && identical) {
        if (bubbleTest[i].x != mergeTest[i].x || bubbleTest[i].y != mergeTest[i].y) {
            identical = 0;
        }
        i++;
    }

    if (identical) {
        printf("SUCCESS: Both sorts produced the same order.\n");
    } else {
        printf("ERROR: Sorted orders differ.\n");
    }

    /*
        EDGE CASE 1: Already sorted input
    */
    printf("\nEDGE CASE 1: Already sorted input\n");
    Point sortedPoints[] = {
        {5.0, 0.0},
        {10.0, 0.0},
        {10.0, 2.5},
        {5.0, 5.0},
        {3.0, 4.0},
        {0.0, 10.0}
    };
    BubbleSort(sortedPoints, 6, anchor);
    printf("After BubbleSort on already sorted input:\n");
    PrintPoints(sortedPoints, 6);
    printf("Is sorted? %d (expected: 1)\n",
           IsSortedByPolarAngle(sortedPoints, 6, anchor));

    /*
        EDGE CASE 2: Same polar angle points
    */
    printf("\nEDGE CASE 2: Same polar angle points\n");
    Point sameAnglePoints[] = {
        {15.0, 0.0},
        {5.0, 0.0},
        {10.0, 0.0},
        {20.0, 0.0}
    };
    BubbleSort(sameAnglePoints, 4, anchor);
    printf("After BubbleSort on same-angle points:\n");
    PrintPoints(sameAnglePoints, 4);
    printf("Expected: (5,0), (10,0), (15,0), (20,0)\n");

    /*
        EDGE CASE 3: Single point
    */
    printf("\nEDGE CASE 3: Single point\n");
    Point onePoint[] = {{3.0, 4.0}};
    BubbleSort(onePoint, 1, anchor);
    printf("BubbleSort on one point:\n");
    PrintPoints(onePoint, 1);
    MergeSort(onePoint, 0, 0, anchor);
    printf("MergeSort on one point:\n");
    PrintPoints(onePoint, 1);

    /*
        EDGE CASE 4: Two points
    */
    printf("\nEDGE CASE 4: Two points\n");
    Point twoPoints[] = {
        {0.0, 10.0},
        {10.0, 0.0}
    };
    MergeSort(twoPoints, 0, 1, anchor);
    printf("After MergeSort on two points:\n");
    PrintPoints(twoPoints, 2);
    printf("Expected: (10,0), (0,10)\n");

    printf("\n=== Sort Operations Test Completed ===\n");

    return 0;
}
