/**
    Group #: 16

    DANIELES, MARICON  S09
    EDEP , TOBIAS RAIAN  S09
    SUAZON, KRISHA GEANE  S09 

    PURPOSE OF THIS FILE: 
    This header file contains the Point structure as well as the
    function prototypes for the Bubble sort and Merge sort. 
*/
#ifndef SORT_H
#define SORT_H

#include "stack.h"

double CrossProduct(Point a, Point b, Point c);

/*Used when two points have the same polar angle*/
double DistanceSquared(Point a, Point b);

int ComparePolarAngle(Point anchor, Point p1, Point p2);

void BubbleSort(Point points[], int n, Point anchor);

void MergeSort(Point points[], int left, int right, Point anchor);

void Merge(Point points[], int left, int mid, int right, Point anchor);

#endif
