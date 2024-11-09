/**************************************************************
* File Name: eag1452_proj3_matrix.c
*
* Author: Everett Gianni
* Created for RIT CMPR271 on: 10/29/2024
*
* Purpose: functions that add 2D matrices as well as find matrix determinant
*
**************************************************************/

#include <stddef.h>

void matrix_add(unsigned rMax, unsigned cMax, const double A[][cMax], const double B[][cMax], double ans[][cMax])
{
    //itterate twice for each row and collumn adding values
    //start with a given row
    for(unsigned j = 0; j < rMax; j++)
    {
        for(unsigned i = 0; i < cMax; i++)//shift down the row
        {
            ans[j][i] = A[j][i] + B[j][i];       
        }
        
    }    
}


double matrix_determinant(unsigned rMax, unsigned cMax, const double A[][cMax])
{
    double det = 0;//initilize determinant sum
    double B[rMax-1][cMax-1];//initilize submatrix
    
    if(rMax == cMax)//check for an incorrect matrix input
    {
        if(rMax == 2)//preform the 2x2 matrix. also this is the base case :)
        {
            return A[0][0]*A[1][1]-A[0][1]*A[1][0];
        }       
        if(rMax == 1)//if its a 1x1 matrix return the single element
        {
            return A[0][0];           
        }
        
        //itterate through top row values by masked lower portions of array
        for(size_t c = 0; c < cMax; c++)//lol c++
        {
            //pass the lower masked matrix into a new matrix B[][]
            
            
            //cycle through matrix to pass values to submatrix
            for(size_t jA = 1, jB = 0; jA < rMax; jA++, jB++)//initilize to 1 to skip top masked row
            {            
                for(size_t iA = 0, iB = 0; iA < cMax; iA++)//cycles through columns in a given row
                {
                    if(iA != c)//skip the collumn if the collumn is the same as the current c value, thereby masking this collumn
                    {                   
                        B[jB][iB] = A[jA][iA];
                        iB++;//increment here so that the sub-array wont increment when masked collumns are skipped
                          
                    }
                       
                }
            
            }
           
            //add the multiplication to the chain of additiona and subtractions
            //multiply current top number by determinant of lower masked array calling matrix_determinant with B[][] as the input to solve the smaller array           
            if( c % 2 == 0)//check if even or zero
            {
               det += A[0][c] * matrix_determinant(rMax - 1,  cMax - 1, B);//add to sum when even  
            }
            else//it will be odd
            {
               det -=  A[0][c] * matrix_determinant(rMax - 1,cMax - 1, B);//subtract from sum when odd
            }
                  
        }        
    //return the determinant
    return det;
    
    }
}
    
    
    
    
    
    
