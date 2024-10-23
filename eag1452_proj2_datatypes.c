/**************************************************************
* File Name: eag1452-proj2-datatypes
*
* Author:Everett Gianni
*
* Created for RIT CMPR271 on: 9-17-2024
*
* Purpose: assess bit values and max values of various datatypes
* and satisfying project 2 requirements
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
    long int myLongInt;
    int bits = 0;//used for keeping track of number of bits shifted
    intmax_t myVar;//this is used for the last few system independednt datatypes

    printf("Testing using increments until value overflows...\n\n");

    ////////////////////////////////////////////////////////////////////////////////////
    // Test for "int"
    
    myInt = 0;
    //itterate untill myInt overflows
    for( int i=1; i > -1;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myInt++;//increment the test value
    }
    
    printf("Biggest int is: $01:%i\n", myInt);



    ////////////////////////////////////////////////////////////////////////////////////
    // Test for "char"
       
    myChar = 0;

    //itterate untill overflows to -1
    for( char i=1; i > -1;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myChar++;//increment the test value
    }
    
    printf("Biggest char is: $02:%i\n", myChar);



    ////////////////////////////////////////////////////////////////////////////////////
    // Test for "short int"
   
    myShortInt = 0;

    //itterate untill myShortInt overflows to -1
    for( short int i=1; i > -1;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myShortInt++;//increment the test value
    }
    printf("Biggest short int is: $03:%i\n", myShortInt);

   

   ////////////////////////////////////////////////////////////////////////////////////
    // Test for "unsigned int"
   
    myUnsignedInt = 0;
    //itterate untill myInt overflows back to 0
    for( unsigned int i=1; i != 0;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myUnsignedInt++;//increment the test value
    }
        
 
    printf("Biggest unsigned int is: $04:%u\n", myUnsignedInt);
    
   

   ////////////////////////////////////////////////////////////////////////////////////
    // Test for "unsigned char"
    
    myUnsignedChar = 0;

    //itterate untill myInt overflows back to 0
   
    for( unsigned char i=1; i != 0;i++)//unsigned datatype so it will overflow to a negetive number
    {    
        myUnsignedChar++;//increment the test value
    }
    printf("Biggest unsigned char is: $05:%i\n", myUnsignedChar);





    // For the rest of the data types, they are too large, and the previous increment/compare method will take far too long to run.
    // So, we'll need another algorithm to figure out the total number of bits used, and figure out the largest number they can hold
    printf("\n\nTesting using bit shifts in some way...\n\n");
    
    
    
   

   ////////////////////////////////////////////////////////////////////////////////////
    // Test for "int" 
    myInt = 0;//reset variable to be printed to 0
    bits = 1;//resets bit to 1 since the bit count will start with 1 and itterate to 2 on the first itteration
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( int i = 1; i > -1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myInt = (myInt<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    
    printf("Bits for int is: $06:%i\n",bits);//print number of times bit shifted 
    printf("Biggest int is $07:%li\n", myInt);//prints the maxed out myInt value 
   
    
    
    ////////////////////////////////////////////////////////////////////////////////////
    // Test for "char"
    
    myChar = 0;//reset myInt to 0
    bits = 1;//resets bit to 1 since the bit count will start with 1 and itterate to 2 on the first itteration
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( char i = 1; i > -1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myChar = (myChar<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
     
    printf("Bits for char is: $08:%i\n", bits);
    printf("Biggest char is: $09:%li\n", myChar);
    

    
    ////////////////////////////////////////////////////////////////////////////////////
    // Test for "short int"

    myShortInt = 0;//reset myInt to 0
    bits = 1;//resets bit to 1 since the bit count will start with 1 and itterate to 2 on the first itteration
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( short int i = 1; i > -1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myShortInt = (myShortInt<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    
    printf("Bits for short int is: $10:%i\n", bits);
    printf("Biggest short int is: $11:%li\n", myShortInt);
    
    
     
    ////////////////////////////////////////////////////////////////////////////////////
    // Test for "unsigned int"
    myUnsignedInt = 0;//reset to 0
    bits = 0;//reset bits to 0 to account for starting the index i at 3 so the final overflow condition can be i > 1
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( unsigned int i = 3; i > 1 ; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myUnsignedInt = (myUnsignedInt<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
        
    }
    
    printf("Bits for unsigned int is: $12:%i\n", bits );
    printf("Biggest unsigned int is: $13:%li\n", myUnsignedInt);
    
    
    
    
    //I really really hope we can do functions on the next project...
    /////////////////////////////////////////////////////////////////////////////////////
    // Test for "unsigned char"
    
    myUnsignedChar = 0;//reset to 0
    bits = 0;
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( unsigned char i = 3; i > 1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myUnsignedChar = (myUnsignedChar<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for unsigned char is: $14:%i\n", bits);
    printf("Biggest unsigned char is: $15:%li\n", myUnsignedChar);
    
    
    
    
    /////////////////////////////////////////////////////////////////////////////////////
    // Test for "long int"
    myLongInt = 0;//reset myInt to 0
    bits = 1;//resets bit to 1 since the bit count will start with 1 and itterate to 2 on the first itteration
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( long int i = 1; i > -1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myLongInt = (myLongInt<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for long int is: $16:%i\n", bits);
    printf("Biggest long int is: $17:%li\n", myLongInt);
    
   
    /////////////////////////////////////////////////////////
    printf("\n\nTesting platform independent datatypes\n\n");
    /////////////////////////////////////////////////////////
    
    
    /////////////////////////////////////////////////////////////////////////////////////
    // Test for "int8_t"
    myVar = 0;//reset myVar to 0, i realized at this point that because im initilizing the variables in the for loop i dont need a new variable for the display so im going to use "myVar" from now on
    bits = 1;//resets bit to 1 since the bit count will start with 1 and itterate to 2 on the first itteration
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( int8_t i = 1; i > -1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for int8_t is: $18:%i\n", bits);
    printf("Biggest int8_t is: $19:%li\n", myVar);
    
    
    
    /////////////////////////////////////////////////////////////////////////////
    // Test for "uint8_t"
    myVar = 0;//reset myInt to 0
    bits = 0;//reset bits to 0 to account for starting the index i at 3 so the final overflow condition can be i > 1
    
    //itterate a bit shift untill overflows back to 1 since it is unsigned
    for( uint8_t i = 3; i > 1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for uint8_t is: $20:%i\n", bits);
    printf("Biggest uint8_t is: $21:%li\n", myVar);
    
    
    
    /////////////////////////////////////////////////////////////////////////////
    // Test for "int16_t"
    myVar = 0;//reset myInt to 0
    bits = 1;//reset bits so bits are a 1 that can be shifted
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( int16_t i = 1; i > -1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for int16_t is: $22:%i\n", bits);
    printf("Biggest int16_t is: $23:%li\n", myVar);
    
    
       
    /////////////////////////////////////////////////////////////////////////////
    // Test for "uint16_t"
    myVar = 0;//reset myInt to 0
    bits = 0;//reset bits to 0 to account for starting the index i at 3 so the final overflow condition can be i > 1
    
    //itterate a bit shift untill overflows back to 1 since it is unsigned
    for( uint16_t i = 3; i > 1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
   

    printf("Bits for uint16_t is: $24:%i\n", bits);
    printf("Biggest uint16_t is: $25:%li\n", myVar);
    
    
    
    
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Test for "int32_t"
    myVar = 0;//reset myInt to 0
    bits = 1;//reset bits so bits are a 1 that can be shifted
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( int32_t i = 1; i > -1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
   
    
    printf("Bits for int32_t is: $26:%i\n", bits);
    printf("Biggest int32_t is: $27:%li. Notice that if we print as a float, we don't have enough precision to represent this result!\n", myVar);



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    // Test for "uint32_t"
    myVar = 0;//reset myInt to 0
    bits = 0;//reset bits to 0 to account for starting the index i at 3 so the final overflow condition can be i > 1
    
    //itterate a bit shift untill overflows back to 1 since it is unsigned
    for( uint32_t i = 3; i > 1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total amount of times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for uint32_t is: $28:%i\n", bits);
    printf("Biggest uint32_t is: $29:%li. Notice that if we print as a float, we don't have enough precision to represent this result!\n", myVar);



    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Test for "int64_t"
    myVar = 0;//reset myInt to 0
    bits = 1;//reset bits so bits are a 1 that can be shifted
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( int64_t i = 1; i > -1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for int64_t is: $30:%i\n", bits);
    printf("Biggest int64_t is: $31:%li. Notice that if we print as a float, we don't have enough precision to represent this result!\n", myVar);



    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Test for "uint64_t"
    myVar = 0;//reset myInt to 0
    bits = 0;//reset bits to 0 to account for starting the index i at 3 so the final overflow condition can be i > 1
    
    //itterate a bit shift untill overflows back to 1 since it is unsigned
    for( uint64_t i = 3; i > 1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total amount of times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for uint64_t is: $32:%i\n", bits);
    printf("Biggest uint64_t is: $33:%lu. Notice that if we print as a float, we don't have enough precision to represent this result!\n", myVar); 
    
    
     
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Test for "uintptr_t"
    myVar = 0;//reset myInt to 0
    bits = 0;//reset bits to 0 to account for starting the index i at 3 so the final overflow condition can be i > 1
    
    //itterate a bit shift untill overflows back to 1 since it is unsigned
    for( uintptr_t i = 3; i > 1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total amount of times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for uintptr_t is: $34:%i\n", bits);
    printf("Biggest uintptr_t is: $35:%lu. Notice that if we print as a float, we don't have enough precision to represent this result!\n", myVar);
   


   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Test for "intmax_t"
    myVar = 0;//reset myInt to 0
    bits = 1;//reset bits so bits are a 1 that can be shifted
    
    //itterate a bit shift untill unsigned char overflows back to -1
    for( intmax_t i = 1; i > -1; i = i<<1 )//shifts the bit of i by one each itteration to count bits
    {    
        myVar = (myVar<<1)+1;//increses for each bit shift to log total times bit shifts occoured
        bits++;//increments to count number of itterations of bit shifts
    }
    printf("Bits for intmax_t is: $36:%i\n", bits);
    printf("Biggest intmax_t is: $37:%li. Notice that if we print as a float, we don't have enough precision to represent this result!\n", myVar);


    return (0);

}   

