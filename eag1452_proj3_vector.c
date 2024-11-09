
/**************************************************************
* File Name: eag1452_proj3_vector.c
*
* Author: Everett Gianni
* Created for RIT CMPR271 on: 10/29/2024
*
* Purpose: functions to preform vector array operations for project 3
*
**************************************************************/

#include <stddef.h>
//vector addition definition




void vect_add(const double x[],const double y[],double ans[],unsigned length)
{
  //for loop to itterate the addition of each element in x[] with corresponding element of y[]  
    for (size_t i = 0; i < length; i++)
    {
        ans[i] = x[i] + y[i];//sum the values at index 
    }  
}


//vector sub definition
void vect_sub(const double x[],const double y[],double ans[],unsigned length)
{
    for (size_t i = 0; i < length; i++)
    {
        ans[i] = x[i] - y[i];//sum the values at index 
    }      
}


//product definition
void vect_prod(const double x[],const double y[],double ans[],unsigned length)
{
    for (size_t i = 0; i < length; i++)
    {
        ans[i] = x[i] * y[i];//multiply the values at index 
    }     
    
}


//vector dot product 
double vect_dot_prod(const double x[],const double y[],unsigned length)
{
    double sum = 0;//initilize running sum
    for (size_t i = 0; i < length; i++)
    {
        sum += (x[i] * y[i]);//add product of current values to running sum
         
    }     
    return sum;
}


//vector mean definition
double vect_mean(const double x[],unsigned length)
{
    double sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += x[i]; 
    }     
    return (sum/length);//divides sum by number of values in array and returns this value
    
}

// vector median definition
double vect_median(const double x[],unsigned length)
{
    double a[length];
    
    for(size_t i = 0; i < length; i++)
    {
        a[i] = x[i];        
    }
    
    //stort the array is ascending order via bubble sort
    
    for(size_t i = 0; i < length - 1; ++i)
    {
        for(size_t i = 0; i < length - 1; ++i)
        {
            if(a[i] > a[i+1])
            {
                double hold = x[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }//end if
        }//end for
    }//end for
    
    if(length % 2 == 0)//if even return avrage of the middle two elements
    {
        //first value is index half the array length wich is the upper-middle element, 
        //and average this with the previous index wich will be the lower-middle element  
        return(((a[length / 2]) + (a[(length / 2) - 1])) / 2);
    }
    
    else //else return the middle element
    {
        //truncation automatically causes result to become the median
        return(a[length / 2]);
    }
   
}


//vector max definition
double vect_max(const double x[],unsigned length)
{
    double a[length];
    for(size_t i = 0; i < length; i++)
    {
        a[i] = x[i];        
    }
    
    //stort the array is ascending order via bubble sort
  
    for(size_t i = 0; i < length - 1; ++i)
    {
        for(size_t i = 0; i < length - 1; ++i)
        {
            if(a[i] > a[i+1])
            {
                double hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }//end if
        }//end for
    }//end for
    return(a[length -1]);//returns the first element of sorted array
    
}


//vector min definition
double vect_min(const double x[],unsigned length)
{
    //stort the array is ascending order via bubble sort
    double a[length];
    
    for(size_t i = 0; i < length; i++)
    {
        a[i] = x[i];        
    }
    
    
    for(size_t i = 0; i < length - 1; ++i)
    {
        for(size_t i = 0; i < length - 1; ++i)
        {
            if(a[i] > a[i+1])
            {
                double hold = x[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }//end if
        }//end for
    }//end for
    return(a[0]);//returns the last element of sorted array
    
}
 

//vector reverse definition
void vect_reverse(double x[], unsigned length)
{
    
    //itterate in two directions from bottom and top, swaping corresponding elements
    for(size_t i = 0, j = length - 1; i < j; i++, j--)
    {
        double hold = x[i];   //hold bottom element 
        x[i] = x[j];//set bottom element to top
        x[j] = hold;//set top element to bottom   
        
    }      
}