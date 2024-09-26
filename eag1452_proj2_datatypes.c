/**************************************************************
* File Name: eag1452-Project2-datatypes
*
* Author:Everett Gianni
*
* Created for RIT CMPR271 on: 9-17-2024
*
* Purpose: submission for project 2
*
**************************************************************/


#include  <stdio.h>
#include  <stdint.h>
#include  <math.h>

int main(void)
{
    //declare variables
    
    int myInt;
    char myChar;
    short int myShortInt;
    unsigned int myUnsignedInt;
    unsigned char myUnsignedChar;
    int i;//index variable for loop wich will start one ahead of myInt

    printf("Testing using increments until value overflows...\n\n");

    // Test for "int"
    
    i = 1;
    myInt = 0;

    //itterate untill myInt overflows
    for( int i=1; i > -1;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myInt++;//increment the test value
    }
    
    printf("Biggest int is: $01:%i\n", myInt);

    // Test for "char"
        
    i = 1;
    myChar = 0;

    //itterate untill myInt overflows
    for( char i=1; i > -1;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myChar++;//increment the test value
    }
    
    printf("Biggest char is: $02:%i\n", myChar);

    // Test for "short int"
    i = 1;
    myShortInt = 0;

    //itterate untill myInt overflows
    for( short int i=1; i > -1;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myShortInt++;//increment the test value
    }
    printf("Biggest short int is: $03:%i\n", myShortInt);

    // Test for "unsigned int"
    i = 1;
    myUnsignedInt = 0;
    //itterate untill myInt overflows back to -1
    for( unsigned int i=1; i != 0;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myUnsignedInt++;//increment the test value
    }
        
 
    printf("Biggest unsigned int is: $04:%u\n", myUnsignedInt);
    
    // Test for "unsigned char"
    i = 1;
    myUnsignedChar = 0;

    //itterate untill myInt overflows back to -1
   
    for( unsigned char i=1; i != 0;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myUnsignedChar++;//increment the test value
    }
    printf("Biggest unsigned char is: $05:%i\n", myUnsignedChar);




    // For the rest of the data types, they are too large, and the previous increment/compare method will take far too long to run.
    // So, we'll need another algorithm to figure out the total number of bits used, and figure out the largest number they can hold.
    
    
    printf("\n\nTesting using bit shifts in some way...\n\n");
    
    // Test for "int"
    i = 1;
    myInt = 1;

    //itterate a bit shift untill unsigned char overflows back to -1
   
    for( int i=1; i > -1;i <<= 1 )//shifts the bit of i by one each itteration to count bits
    {    
        ;//add one to the lsb so that once the max value is reached it wil be 1111... not 10000...
        myInt++;//increses for each bit shift to log total times bit shifts occoured
        printf("%d/n", i);
    }
    
    printf("Bits for int is: $06:%i\n", myInt);//print number of times bit shifted 
    printf("Biggest int is $07:%li\n", i);
/*    
    // Test for "char"
    // YOUR CODE GOES HERE
    printf("Bits for char is: $08:%i\n", yourVariable);
    printf("Biggest char is: $09:%li\n", yourVariable);
    
    // Test for "short int"
    // YOUR CODE GOES HERE
    printf("Bits for short int is: $10:%i\n", yourVariable);
    printf("Biggest short int is: $11:%li\n", yourVariable);
    
    // Test for "unsigned int"
    // YOUR CODE GOES HERE
    printf("Bits for unsigned int is: $12:%i\n", yourVariable);
    printf("Biggest unsigned int is: $13:%li\n", yourVariable
    
    // Test for "unsigned char"
    // YOUR CODE GOES HERE
    printf("Bits for unsigned char is: $14:%i\n", yourVariable);
    printf("Biggest unsigned char is: $15:%li\n", yourVariable
    
    // Test for "long int"
    // YOUR CODE GOES HERE
    printf("Bits for long int is: $16:%i\n", yourVariable);
    printf("Biggest long int is: $17:%li\n", yourVariable);
    
    

    printf("\n\nTesting platform independent datatypes\n\n");

    // Test for "int8_t"
    // YOUR CODE GOES HERE
    printf("Bits for int8_t is: $18:%i\n", yourVariable);
    printf("Biggest int8_t is: $19:%li\n", yourVariable);

    // Test for "uint8_t"
    // YOUR CODE GOES HERE
    printf("Bits for uint8_t is: $20:%i\n", yourVariable);
    printf("Biggest uint8_t is: $21:%li\n", yourVariable

    // Test for "int16_t"
    // YOUR CODE GOES HERE
    printf("Bits for int16_t is: $22:%i\n", yourVariable);
    printf("Biggest int16_t is: $23:%li\n", yourVariable);

    // Test for "uint16_t"
    // YOUR CODE GOES HERE
    printf("Bits for uint16_t is: $24:%i\n", yourVariable);
    printf("Biggest uint16_t is: $25:%li\n", yourVariable

    // Test for "int32_t"
    // YOUR CODE GOES HERE
    printf("Bits for int32_t is: $26:%i\n", yourVariable);
    printf("Biggest int32_t is: $27:%li. Notice that if we print as a float, we don't have enough precision to represent this result!\n", yourVariable);

    // Test for "uint32_t"
    // YOUR CODE GOES HERE
    printf("Bits for uint32_t is: $28:%i\n", yourVariable);
    printf("Biggest uint32_t is: $29:%li. Notice that if we print as a float, we don't have enough precision to represent this result!\n", yourVariable

    // Test for "int64_t"
    // YOUR CODE GOES HERE
    printf("Bits for int64_t is: $30:%i\n", yourVariable);
    printf("Biggest int64_t is: $31:%li. Notice that if we print as a float, we don't have enough precision to represent this result!\n", yourVariable);

    // Test for "uint64_t"
    // YOUR CODE GOES HERE
    printf("Bits for uint64_t is: $32:%i\n", yourVariable);
    printf("Biggest uint64_t is: $33:%lu. Notice that if we print as a float, we don't have enough precision to represent this result!\n", yourVariable); 

    // Test for "uintptr_t"
    // YOUR CODE GOES HERE
    printf("Bits for uintptr_t is: $34:%i\n", yourVariable);
    printf("Biggest uintptr_t is: $35:%lu. Notice that if we print as a float, we don't have enough precision to represent this result!\n", yourVariable);

    // Test for "intmax_t"
    // YOUR CODE GOES HERE
    printf("Bits for intmax_t is: $36:%i\n", yourVariable);
    printf("Biggest intmax_t is: $37:%li. Notice that if we print as a float, we don't have enough precision to represent this result!\n", yourVariable);

*/
    return (0);

}   

