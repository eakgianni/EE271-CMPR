/**************************************************************
* File Name: eag1452_hwq3_3.20.c
*
* Author: Everett Gianni
*
* Created for RIT CMPR271 on: 9/23/2024
*
* Purpose: hwq problem: salary calculator
*
**************************************************************/

#include <stdio.h>

int main(void)
{
    float hours = 0;//initilize hours
    float rate = 0;//initilize rate
    float salary = 0;//initilize salary
    

    while (hours != -1)//loop until -1 setinel value is entered for hours
    {
        puts("Enter number of hours worked (-1 to end):");//prompt for hours
        scanf("%f", &hours);//user enters hours
        puts("\n");//newline to clean stuff up
        
        if (hours != -1) //if hours user enters number of hours worked != -1
        {
            puts("Enter the hourly rate of the worker (format 00.00):");//user enters rate
            scanf("%f", &rate);
            
            if (hours > 40)//checks for overtime
            {
                salary = (40 * rate) + ((hours - 40) * (rate * 1.5));//calculate the 40 hours then subtract the excess hours to get ot
            }//end if
            else//if not overtime
            {
                salary = (hours * rate);//else just calculate number of hours at standard rate
            }//end else
        
        printf("\nSalary is: %.2f$", salary);//print total salary for the week   
    
    }//end if              
           
    }//end while 
         
}//end main