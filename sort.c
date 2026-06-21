/**
    Group #: 16

    DANIELES, MARICON       S09
    EDEP , TOBIAS RAIAN     S09
    SUAZON, KRISHA GEANE    S09 

    PURPOSE OF THIS FILE:
    To implement the functions declared from the sort.h file.
*/
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*  
    a. Name of Programmer(s): EDEP, TOBIAS RAIAN
    b. Name of Tester(s)    : DANIELES, MARICON
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will compute the cross product of vectors AB and BC
    e. Return: double - the cross product value
    f. Parameters: 
            a is the first point
            b is the second point
            c is the third point
*/
double CrossProduct(Point a, Point b, Point c){
    double result;

    /*
     Computes cross product value which will be stored to result.
     Negative result is a clockwise turn.
     Positive result is a counterclockwise turn.
     Zero means three results are collinear.
    */
    result = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return result;
}

/*  
    a. Name of Programmer(s): EDEP, TOBIAS RAIAN
    b. Name of Tester(s)    : DANIELES, MARICON
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will compute the squared distance between two points.
    e. Return: double - squared distance between points a and b
    f. Parameters: 
            a is the first point
            b is the second point
*/
double DistanceSquared(Point a, Point b){
    
    // Computes and stores the standard distance along x and y values.
    double dx = b.x - a.x;
    double dy = b.y - a.y;

    // Computes and returns the square distance which will be used for sorting.
    return dx * dx + dy * dy;
}

/*  
    a. Name of Programmer(s): DANIELES, MARICON & EDEP, TOBIAS RAIAN
    b. Name of Tester(s)    : SUAZON, KRISHA GEANE
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will compare two points based on their polar angle from the anchor.
    e. Return: int - -1 if p1 < p2, 1 if p1 > p2, 0 if equal  
    f. Parameters: 
            anchor is the reference point
            p1 is the first point to compare
            p2 is the second point to compare
*/
int ComparePolarAngle(Point anchor, Point p1, Point p2){
    
    // Using cross product for the relative angular order.
    double crossproduct = CrossProduct(anchor, p1, p2);
    double d1, d2;
    int result;
    if (crossproduct > 0){ // COUNTERCLOCKWISE: if p1 has a smaller angle than p2.
        result = -1;
    } else if (crossproduct < 0){ // CLOCKWISE: if 1 has a larger polar angle than p2.
        result = 1;
    } else { // COLLINEAR: Zero meaning p1 and p2 have the same angle
        
        // Use distance as a tiebreaker, the closer point comes first.
        d1 = DistanceSquared(anchor, p1);
        d2 = DistanceSquared(anchor, p2);
        if (d1 < d2){
            result = -1;
        } else if (d1 > d2){
            result = 1;
        } else { // For cases where points have the same angle and distance.
            result = 0;
        }
    }
    return result;
}

/*  
    a. Name of Programmer(s): SUAZON, KRISHA GEANE
    b. Name of Tester(s)    : EDEP, TOBIAS RAIAN
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will swap two point in an array given their indices.
    e. Return: None
    f. Parameters: 
            *points is the array of points
            i is the first point
            j is the second point
*/
void swap(Point* points, int i, int j) {
    Point temp = points[i];
    points[i] = points[j];
    points[j] = temp;
}

/*  
    a. Name of Programmer(s): EDEP, TOBIAS RAIAN & SUAZON, KRISHA GEANE
    b. Name of Tester(s)    : DANIELES, MARICON
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will sort an rray of points by polar angle using bubble sort.
    e. Return: None
    f. Parameters: 
            points[] is the array of points to sort
            n is the number if points
            anchor is the reference point for polar angle
*/
void BubbleSort(Point points[], int n, Point anchor) {
    int i, j;

    // Outer loop ensures one more element goes into its correct position at the end of the array.
    for(i=0; i<n-1; i++) {
        /*
         Inner loop sorts through each portion based on polar-angle order.
         Compare the adjacement elements and swap if out of polar-angle order.
        */
        for(j=0; j < n-i-1; j++) {
            if(ComparePolarAngle(anchor, points[j], points[j+1]) > 0)
                swap(points, j, j+1);
        }
    }
}

/*  
    a. Name of Programmer(s): DANIELES, MARICON
    b. Name of Tester(s)    : SUAZON, KRISHA GEANE
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will find the anchor point (lowest y, then lowest x if tie).
    e. Return: int - index of the anchor point in the array
    f. Parameters: 
            points[] is the array of points
            n is the number of points
*/
int findAnchor(Point points[], int n) {
    int i, index = 0;

    /*
    Assuming index 0 is the anchor to start.
    Scan the array looking for the lowest y value.
    If y values are the same, find the smaller x value as a tiebreaker.
    */
    for(i = 1; i < n; i++) {
        if(points[i].y < points[index].y || (points[i].y == points[index].y 
        && points[i].x < points[index].x)) 
          index = i;
    }

    return index;
}

/*  
    a. Name of Programmer(s): DANIELES, MARICON & SUAZON, KRISHA GEANE
    b. Name of Tester(s)    : EDEP, TOBIAS RAIAN
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will merge two sorted sub-arrays into one sorted array by polar angle.
    e. Return: None
    f. Parameters: 
           points[] is the array containing sub-arrays to merge 
           left is the starting index of first sub-array
           mid is the ending index of first sub-array
           right is the ending index of second sub-array
           anchor is the reference point for polar angle
*/
void Merge(Point points[], int left, int mid, int right, Point anchor) {
   
    int i, j, k;
    /*
     Sizes of the two sub-arrays being murged.
     - The left sub-array is [left,mid].
     - The right sub-array is [mid+1, right].
    */
    int side1 = mid - left + 1;
    int side2 = right - mid;
   
   // Creation of temporary arrays to hold copies of each sub-array being merging.
   Point L[side1];
   Point R[side2];
   
   // Copy left half of points array into L array.
    for(i = 0; i < side1; i++){
        L[i] = points[left+i];
    }

    // Copy right half of points array into R array.
    for(j=0; j< side2; j++){
        R[j] = points[mid + j + 1];
    }
    
    i = 0; // Tracks position in L[]
    j = 0; // Tracks position in R[]
    k = left; // Tracks the position of element being assigned back into points[]

    // Repeatedly take whichever element of L or R come first based on polar angle, and place into points.
    while(i < side1 && j <side2) {
        if(ComparePolarAngle(anchor, L[i], R[j]) <= 0) // will change according to polar angles
            points[k++] = L[i++];
        else
            points[k++] = R[j++];
    }

    // Copy leftover elements from L[] if R[] is empty first.
    while(i< side1) {
        points[k++] = L[i++];
    }

    // Copy leftover elements from R[] if L[] is empty first.
    while(j < side2) {
        points[k++] = R[j++];
    }
}

/*  
    a. Name of Programmer(s): DANIELES, MARICON
    b. Name of Tester(s)    : EDEP, TOBIAS RAIAN
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will recursively sort an array of points by polar angle using merge sort.
    e. Return: None
    f. Parameters: 
            points[] is the array of points to sort
            left is the starting index
            right is the ending index
            anchor is the reference point for polar angle
*/
void MergeSort(Point points[], int left, int right, Point anchor){
  // Base case with a sub-array with one element already "sorted."  
if(left < right){
    // Find midpoint to split the array and to avoid integer overflow.
    int mid = left + (right - left) / 2;
        // Sort left half.
        MergeSort(points, left, mid, anchor);
        // Sort right half.
        MergeSort(points, mid+1, right, anchor);
        // Merge the newly sorted sub-arrays back into points array in polar-angle order.
        Merge(points, left, mid, right, anchor);
    }
}
