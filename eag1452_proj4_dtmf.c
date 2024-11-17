/******************************************************************************
* File Name: eag1452_proj4_dtmf.c
*
* Author: Everett Gianni
*
* Created for CMPR-271 on: Nov. 11, 2024
*
* Purpose: Takes arguments from the command line and generates a Window's
* wave format file composed of DTMF tones.
*
******************************************************************************/


//#include "wavefile.h" // specific for dealing with .wav files
//#include "dtmf.h"     // specific to your application - function prototypes
                   // for any functions you write should go in this file.
#include <stdio.h>


int main (int argc, const char* argv[])
{
    // declare local variables, such as
    // variable and pointer to WAVEFILE structure   
    // pointers to data samples
    // variables used for user input, etc
    FILE *cfPtr;
    //initilize the header section
    HEADER wavHeader; 
    

    // check if user typed 4 arguments in the command line
    // using argc
    // if not, show user proper format
    if (argc != 4)
    {
        // printf proper format for use
        return -1;
    }


    // Check for valid numbers and symbols in phone number and tonelength
    // using argv[]
    for(size_t i = 0; *(argv[3]+i) != 0; i++)
    {
        if(!isdigit(*(argv[3]+i))  && *(argv[3]+i) != '-' && *(argv[3]+i) != '*' && *(argv[3]+i) != '#')
        {
            show_usage();// if not, show user proper format
            return -1;
        }
    }
   

    // change the string of the tone length to a numerical value
    // check for valid tone lengths
    // if not, show user proper format
    if ( atof(*(argv[2])) < 0.1 || atof(*(argv[2])) > 1.0)//check if tonelength is out of bounds
    {
        show_usage();
        return -1;
    }
    

    // Now, either a) declare a varible of WAVEFILE datatype to
    // hold the 'header' of the wavefile,
    // or b) allocate memory for the 'header' of the wavefile
    // using malloc()
    //headerPtr = malloc(sizeof(WAVEFILE));
    // and check it was properly allocated (did malloc return NULL?)
    
    HEADER wavHeader.ChunkID
    
    
    
    
    // allocate memory for the data in the file (for the samples)
    // using malloc()
    //dataSamplesPtr = malloc(<expression to figure out # of bytes needed>);
    // number of bytes will depend on:
    // 1) number of digits in number
    // 2) toneLength per digit
    // 3) SAMPLE_RATE - defined in wavefile.h
    // 4) BYTES_PER_SAMPLE - defined in wavefile.h

    // and check it was properly allocated (did malloc return NULL?)

    // fill in the wavefile-header structure (members) into the allocated memory,
    // using dot (.) or arrow (->) operators
    // (use dot if you created a WAVEFILE variable, use arrow if you used malloc and have a pointer)

    // open/create the file using fopen(), and check it was properly opened

    // create the data samples, populating the allocated data memory
    // sampleValue = AMPLITUDE * (sin(sampleNum * freq1 * 2 * 3.14159 / SAMPLE_RATE) +
    //                                    sin(sampleNum * freq2 * 2 * 3.14159 / SAMPLE_RATE));
                                
    

    // write (copy) the wavefile-header of the wavefile, from allocated
    // memory, into the file, and check it wrote properly

    // write (copy) the data-samples of the wavefile, from allocated
    // memory, into the file, and check it wrote properly

    // close the file

  
    // free all allocated memory

    return (0);


}




/******************************************************************************
* Function Name: show_usage
*
* Purpose: Shows user how to use this program
* 
* Arguments: None
*
* Returns: Nothing
*
******************************************************************************/
void show_usage(void)
{
   printf("\nUsage: ./dtmf.exe X Y Z\n\n");
   printf(" Where X is the name of the Wave file to create\n");
   printf(" Where Y is the duration (in seconds) of each dtmf tone, valid range is 0.1 - 1.0\n");
   printf(" Where Z is the string of digits to create tones for, valid\n");
   printf("    digits are 0-9, #, * and - for a duration of silence\n");
   printf("\nExample: ./dtmf.exe wavy.wav 0.3 123-3831\n");
}
   
