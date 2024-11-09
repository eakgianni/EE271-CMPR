#ifndef __VECTOR_H_
#define __VECTOR_H_

/******************************************************************************
* File Name: vector.h
*
* Author: Carlos Barrios
*
* Created for CMPR271 on: Aug 28, 2020
*
* Purpose: Contains function prototypes for the module vector.c
* 
******************************************************************************/

// Useful definitions
#define TRUE 1
#define FALSE 0

#define SIZE 27


#define VECT_ADD_WORKING        TRUE
#define VECT_SUB_WORKING        TRUE
#define VECT_PROD_WORKING       TRUE
#define VECT_DOT_PROD_WORKING   TRUE
#define VECT_MEAN_WORKING       TRUE
#define VECT_MEDIAN_WORKING     TRUE
#define VECT_MAX_WORKING        TRUE
#define VECT_MIN_WORKING        TRUE
#define VECT_REVERSE_WORKING    TRUE

// Function prototypes

void vect_add(const double x[],const double y[],double ans[],unsigned length);
void vect_sub(const double x[],const double y[],double ans[],unsigned length);
void vect_prod(const double x[],const double y[],double ans[],unsigned length);
double vect_dot_prod(const double x[],const double y[],unsigned length);
double vect_mean(const double x[],unsigned length);
double vect_median(const double x[],unsigned length);
double vect_max(const double x[],unsigned length);
double vect_min(const double x[],unsigned length);
void vect_reverse(double x[],unsigned length);//can i add an ans?? how else do i do?

//double vect_print(const double x[], unsigned length);


#endif



