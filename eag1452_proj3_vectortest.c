/**************************************************************
* File Name: eag1452_proj3_vectortest.c
*
* Author: Everett Gianni
* Created for RIT CMPR271 on: 10/29/2024
*
* Purpose: Test vector operation function on trig functions
*
**************************************************************/

#include <stdio.h>
#include <math.h>
#include "eag1452_proj3_vector.h"
#include <stdio.h>


int main (void)
{
    float sinOut[SIZE];
    float cosOut[SIZE];
    
    //test area for basic function operations
    
    double result[SIZE];
    double v1[SIZE] = {1,2,1,4,100,6};
    double v2[SIZE] = {1,2,3,4,5,6};
    
    
    ////////////////////////////////////////////////   
    //generate array with sin/cosine function values
    ////////////////////////////////////////////////
    
    for (size_t i = 0; i < SIZE; i++)
    {
        sinOut[i] = 10 * sin(2*3.1416* (i/360.0)); 
    }
    
    for (size_t i = 0; i < SIZE; i++)
    {
        cosOut[i] = 10 * cos(2*3.1416* (i/360.0)); 
    }
    
    //////////////////////////////////////
    //preform operations and print results
    //////////////////////////////////////
    
    vect_add(sinOut, cosOut, result, SIZE);//sum trig function outputs
    printf("Max value of arrays when summed:\n");
    printf("%f \n\n", vect_max(result, SIZE));//print max of sum
    
    printf("Mean of sin array:\n");
    printf("%f \n\n", vect_mean(sinOut, SIZE));//find mean of sin function
    
    printf("Mean of the product of arrays:\n");
    vect_prod(sinOut, cosOut, result, SIZE);//multiply elements of sin and cos
    printf("%f \n\n", vect_mean(result, SIZE));//find mean of the product array
    
    printf("Median of cos array:\n");
    printf("%f \n\n", vect_median(cosOut, SIZE));//find median of cosine function

    printf("Dot product of cos and sin arrays:\n");
    printf("%f \n\n", vect_dot_prod(cosOut, sinOut, SIZE));//dot product of sin and cos functions
    
    printf("Dot product of reversed cos array and sin array:\n");
    vect_reverse(cosOut, SIZE);
    printf("%f \n\n", vect_dot_prod(cosOut, sinOut, SIZE));//dot product of sin and reversed cos functions
     
}