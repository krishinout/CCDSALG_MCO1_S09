/**
    Group #: 16

    DANIELES, MARICON       S09
    EDEP , TOBIAS RAIAN     S09
    SUAZON, KRISHA GEANE    S09 

    PURPOSE OF THIS FILE:
    Driver program for the slow version of Graham Scan (using BubbleSort).
    This code reads points from an input file, computes the convex hull,
    and writes the hull points to an output file with 6 decimal places.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "sort.h"

void grahamSlow(Point points[], int n, Point convexHull[], int *convexHullSize);

/*  
    a. Name of Programmer(s): DANIELES, MARICON & EDEP, TOBIAS RAIAN
    b. Name of Tester(s)    : SUAZON, KRISHA GEANE
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function is the driver program for slow Graham Scan.
                Reads from file, computes hull, writes to file.
    e. Return: int - 0 on success, 1 on failure
    f. Parameters: 
            None
*/
int main(){
    char inputFilename[100];
    char outputFilename[100];
    FILE *inputFile, *outputFile;
    int n, i;
    Point *points;
    Point *convexHull;
    int convexHullSize;

    //Ask the user fot the input filename
    printf("Enter input filename: ");
    scanf("%s", inputFilename);

    //Ask the user for the output filename
    printf("Enter output filename: ");
    scanf("%s", outputFilename);

    //Open the input file for reading
    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL){
        printf("Cannot open input file %s\n", inputFilename);
        return 1;
    }

    //Read the total number of points from the input file
    fscanf(inputFile, "%d", &n);
    printf("Reading %d points from %s\n", n, inputFilename);

    //Allocate memory for the points array
    points = (Point*)malloc(n * sizeof(Point));
    if (points == NULL){
        printf("Memory allocation failed\n");
        fclose(inputFile);
        return 1;
    }

    //Read all point coordinates from the input file
    for(i=0; i < n; i++){
        fscanf(inputFile, "%lf %lf", &points[i].x, &points[i].y);       
    }
    fclose(inputFile);

    //Allocate memory for the convex hull points
    convexHull = (Point*)malloc(n * sizeof(Point));
    if (convexHull == NULL){
        printf("Memory allocation failed\n");
        free(points);
        return 1;
    }
    
    //Compute the convex hull using the slow Graham Scan version
    grahamSlow(points, n, convexHull, &convexHullSize);

    //Open the output file for writing
    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL){
        printf("Cannot create output failed\n");
        free(points);
        free(convexHull);
        return 1;
    }

    //Write the hull size and hull points with 6 decimal places
    fprintf(outputFile, "%d\n", convexHullSize);
    for (i=0; i<convexHullSize; i++){
        fprintf(outputFile, "%9.6lf  %9.6lf\n", convexHull[i].x, convexHull[i].y);
    }
    //Close the output file
    fclose(outputFile);

    //Free allocated memory
    free(points);
    free(convexHull);

    printf("Convex Hull is Computed!\n");

    return 0;
}
