/* File Name: eag1452_proj3_matrix.c
*
* Author: Everett Gianni
* Created for RIT CMPR271 on: 10/29/2024
*
* Purpose: test functions that add 2D matrices as well as find matrix determinant
*
**************************************************************/

#include "eag1452_proj3_matrix.h"
#include <stdio.h> 
#include <stdlib.h>
#define SIZE 10

int main(void)
{   
    double a[SIZE][SIZE];                  
    double b[SIZE][SIZE]; 
    double result[SIZE][SIZE];
                       
    
    //populate a
    for(size_t j = 0; j < SIZE; ++j)
    {       
        for(size_t i = 0; i < SIZE; ++i)//shift down the row
        {
            a[j][i] = (int) (rand() % 20) + 1;      
        }
        printf("\n");
    }
    
    //populate b
    for(size_t j = 0; j < SIZE; ++j)
    {       
        for(size_t i = 0; i < SIZE; ++i)//shift down the row
        {
            b[j][i] = (int) (rand() % 20) - 10;      
        }
        printf("\n");
    }
    
    //print determinants
    printf("Determinant of summed arrays:\n");
    matrix_add(SIZE, SIZE, a, b, result);
    printf("%f\n", matrix_determinant(SIZE, SIZE, result));
       
}

