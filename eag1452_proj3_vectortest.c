//put header here

#include <stdio.h>
#include <math.h>

#define SIZE 720

int main (void)
{
    float sinOut[SIZE];
    float cosOut[SIZE];
    
    //generate array with sin function values
    
    for (size_t i = 0; i < SIZE; i++)
    {
        sinOut[i] = 10 * sin(2*3.1416* (i/360.0)); 
    }
    
    for (size_t i = 0; i < SIZE; i++)
    {
        cosOut[i] = 10 * cos(2*3.1416* (i/360.0)); 
    }
    
    printf("sin function output:\n");
    
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%f\n", sinOut[i]);
    }
    
    printf("sin function output:\n");
    
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%f\n", cosOut[i]);
    }
    
}