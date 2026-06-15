/**
    Group #: 16

    DANIELES, MARICON  S09
    EDEP , TOBIAS RAIAN  S09
    SUAZON, KRISHA GEANE  S09 

    PURPOSE OF THIS FILE: (edit this)
*/
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

//Checks if three points make a left turn, right turn, or are collinear 
double CrossProduct(Point a, Point b, Point c){
    double result;
    result = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return result;
}

//Used when two points have the same polar angle. The closer point comes first
double DistanceSquared(Point a, Point b){
    double dx = b.x - a.x;
    double dy = b.y - a.y;

    return dx * dx + dy * dy;
}

// if p1 ccw from p2 - return -1
// if p2 has smaller angle - return 1
// if equal - return 0
int ComparePolarAngle(Point anchor, Point p1, Point p2){
    double crossproduct = CrossProduct(anchor, p1, p2);
    double d1, d2;
    int result;
    if (crossproduct > 0){
        result = -1;
    } else if (crossproduct < 0){
        result = 1;
    } else {
        d1 = DistanceSquared(anchor, p1);
        d2 = DistanceSquared(anchor, p2);
        if (d1 < d2){
            result = -1;
        } else if (d1 > d2){
            result = 1;
        } else {
            result = 0;
        }
    }
    return result;
}

//swapping func
void swap(Point* points, int i, int j) {
    Point temp = points[i];
    points[i] = points[j];
    points[j] = temp;
}

//slow // bubble sort algorithm
void BubbleSort(Point points[], int n, Point anchor) {
    int i, j;

    for(i=0; i<n-1; i++) {
        for(j=0; j < n-i-1; j++) {
            if(ComparePolarAngle(anchor, points[j], points[j+1]) > 0)
                swap(points, j, j+1);
        }
    }
}

// find lowest point, if same y values, then find the lesser x value
int findAnchor(Point points[], int n) {
    int i, index = 0;

    for(i = 1; i < n; i++) {
        if(points[i].y < points[index].y || points[i].y == points[index].y 
        && points[i].x < points[index].x)
          index = i;
    }

    return index;
}

// to merge the sorted sub-arrays
void Merge(Point points[], int left, int mid, int right, Point anchor) {
   
    int i, j, k;
    // creating indexes for separated arrays
    int side1 = mid - left + 1;
    int side2 = right - mid;
   
   //creating sub-arrays
   Point L[side1];
   Point R[side2];

   for(i = 0; i < side1; i++)
    L[i] = points[left+i];

    for(j=0; j< side2; j++)
        R[j] = points[mid + j + 1];
    
    i = 0;
    j = 0; 
    k = left;

    while(i < side1 && j <side2) {
        if(ComparePolarAngle(anchor, L[i], R[j]) == -1) // will change according to polar angles
            points[k++] = L[i++];
        else
            points[k++] = R[j++];
    }

    while(i< side1) {
        points[k++] = L[i++];
    }

    while(j < side2) {
        points[k++] = R[j++];
    }
}

void MergeSort(Point points[], int n) {
    int signal;
    int left = 1;
    int right = n - 1;
    int mid;

    if(n < 3)
        signal = 0;

    if (signal == 1) {
        if(left < right) {
            mid = left + (right - left) / 2;
        }

        // recursively sorts first half
        MergeSort(points, mid+1);

        // sorts second half
        MergeSort(points + mid, n-mid);

        // merges it together
        Merge(points, points[0], left, mid, right);
    }
}
