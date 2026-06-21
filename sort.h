/**
    Group #: 16

    DANIELES, MARICON       S09
    EDEP , TOBIAS RAIAN     S09
    SUAZON, KRISHA GEANE    S09 

    PURPOSE OF THIS FILE: 
    To declare helper functions and sorting functions needed for convex hull computation.
*/
#ifndef SORT_H
#define SORT_H

#include "stack.h"

/*Computes the cross product of vectors AB and BC*/
double CrossProduct(Point a, Point b, Point c);

/*Used when two points have the same polar angle*/
double DistanceSquared(Point a, Point b);

/*Compares two points based on their polar angle from the anchor*/
int ComparePolarAngle(Point anchor, Point p1, Point p2);

/*Sorts points by polar angle using bubble sort (O(n²), slow)*/
void BubbleSort(Point points[], int n, Point anchor);

/*Finds the point with the lowest y-coordinate*/
int findAnchor(Point points[], int n);

/*Recursively sorts points by polar angle using merge sort*/
void MergeSort(Point points[], int left, int right, Point anchor);

/*Merges two sorted sub-arrays into one sorted array by polar angle*/
void Merge(Point points[], int left, int mid, int right, Point anchor);

#endif
