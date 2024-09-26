/**************************************************************
* File Name: eag1452_hwq3_13.8.c
*
* Author: Everett Gianni
*
* Created for RIT CMPR271 on: 9/23/2024
*
* Purpose: hwq problem: sales commision calculator
*
**************************************************************/

#include <stdio.h>// allow in/out

int main(void)//main 
{
    float sales = 0;//initilize sales
    float salary = 0;//initilize salary
    
    while (sales != -1)//while the setinel values hasnt been entered
    {
        puts("\nEnter sales in dollars (-1 to end): ");//display text
        scanf("%f", &sales);//get sales value from user
        
        if ( sales != -1)//only calculate if user doesnt exit
        {
           salary = 200 + 0.09 * sales;//calculates salary from sales
           printf("\nSalary is $%.2f\n", salary);//print salarry to 2 decimal places
        }//end if
                
    }//end while
        
    
    
    
}//end main