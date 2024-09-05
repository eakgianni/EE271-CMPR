/******************************************************************************
* File Name: cabeee_proj1_hello_world_delay.c
*
* Author: Carlos Barrios
*
* Created for CMPR-271 on: August 9, 2019
*
* Purpose: Prints Hello World to the screen, then waits a few moments
*           using a SW delay, and then prints another string.
*           This is an example program for students to learn how to 
*           compile and run their first program and satisfy the requirements
*           of Project 1.
*
******************************************************************************/

#include  <stdio.h>
void my_delay(int delayValue);
 
int main(void)
{
    printf("Hello World!\n");
    my_delay(65535); // insert a SW delay
    printf("This is my very first program! I love CMPR271.\n");
    return 0;
}

/**************************************************************
* Function Name: my_delay()
*
* Purpose: To waste some time by introducing a small SW delay
*           using a looping structure with a dummy operation.
*
* Arguments: delayValue - the ammount of delay to be used.
*
* Returns: nothing.
*
**************************************************************/
void my_delay(int delayValue)
{
    int i = delayValue;
    int j;
    int k = 1;
    while (i > 0)
    {
        j = delayValue;
        while (j > 0)
        {
            k = i+j; // insert breakpoint here
            j = j - 1;
        }
        i = i - 1;
    }
}

