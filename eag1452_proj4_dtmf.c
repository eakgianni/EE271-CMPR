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


#include "eag1452_wavefile.h" // specific for dealing with .wav files
//#include "eag1452_dtmf.h"     // specific to your application - function prototypes
                   // for any functions you write should go in this file.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BITS_PER_SAMPLE 16 



int main (int argc, const char* argv[])
{
         
    WAVEFILE wavHeader;
       
    int sampleNum;//current sample within allocated memory. used for incrementing
    int samplesPerTone;//number of samples in each tone
    uint16_t sampleValue;//holds the value of a single tone sample
    int numSamples;//hold number of samples
    float toneLength = atof(argv[2]);// declare and change the string of the tone length to a numerical value
    int numDigits;//number of user input phone number values
      
    int freq1;//will hold first frequency of a sample
    int freq2;//will hold second frequency of a sample
    int validChar;//used for testing for valid char
       
    //arrays that store digit corresponding tone values
    char inputChar[13] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#', '-'}; 
    short int tone1[13] = {697, 697, 697, 770, 770, 770, 852, 852, 852, 941, 941, 941, 0};
    short int tone2[13] = {1209, 1336, 1477, 1209, 1336, 1477, 1209, 1336, 1477, 1209, 1336, 1477, 0};
        
      
    //initilize the header section
    
    // check if user typed 4 arguments in the command line
    // using argc
    // if not, show user proper format
    
    if (argc != 4)
    {
        // printf proper format for use
        show_usage();
        return -1;
    }
        
    // Check for valid numbers and symbols in phone number and tonelength
    // using argv[]
    
    for(size_t i = 0; argv[3][i] != '\0'; i++)
    {
        validChar = 0;
        for(size_t f = 0; f < 13; f++)
        {    
            
            if(argv[3][i] == inputChar[f])
            {                           
                validChar = 1;
                break;//break out of the loop once a valid character is detected               
            }    
            
        }       
        
        if(validChar == 0)//if you reached the end of the list without identifying a valid char
        {
            show_usage();//throw an error
            return -1;                  
        }
        numDigits = i+1;//count the number of phone number characters
    }
    
    
    
    
    // check for valid tone lengths
    // if not, show user proper format
    
    
    if (1.0 < toneLength)//check if tonelength is above bounds
    {
        show_usage();
        return -1;
    }
    if (0.1 > toneLength)//check if tonelength is below bounds
    {
        show_usage();
        return -1;
    }
    
    //calculate how many samples will be preformed per tone
    samplesPerTone = SAMPLE_RATE * toneLength;//multiply sample rate with tone length     
    numSamples = samplesPerTone * numDigits;//multiply samples for each tone by number of tones (chars in arg3) truncating bc you can only have whole samples    
    
    
    
    //assign ChunkID    
    wavHeader.ChunkID[0] = 'R';
    wavHeader.ChunkID[1] = 'I';
    wavHeader.ChunkID[2] = 'F';
    wavHeader.ChunkID[3] = 'F';
    
    //assign ChunkSize
    wavHeader.ChunkSize = 36 + numSamples * NUM_CHANNELS * BYTES_PER_SAMPLE;
   
    // assign format 
    wavHeader.Format[0] = 'W';
    wavHeader.Format[1] = 'A';
    wavHeader.Format[2] = 'V';
    wavHeader.Format[3] = 'E';
    
    
    //assign subchunk 1 id
    wavHeader.SubChunk1ID[0] = 'f';
    wavHeader.SubChunk1ID[1] = 'm';
    wavHeader.SubChunk1ID[2] = 't';
    wavHeader.SubChunk1ID[3] = ' ';
    
    //assign subchunk 1 size
    wavHeader.SubChunk1Size = 16;

    //assign audio format
    wavHeader.AudioFormat = PCM_FORMAT;
    
    //assign number of channels
    wavHeader.NumChannels = NUM_CHANNELS;
    
    //assign samplerate
    wavHeader.SampleRate = SAMPLE_RATE;
    
    //assign byte rate
    wavHeader.ByteRate = SAMPLE_RATE * NUM_CHANNELS * BYTES_PER_SAMPLE;

    //assign block align
    wavHeader.BlockAlign = NUM_CHANNELS * BITS_PER_SAMPLE / 8;
    
    //assign bits per sample
    wavHeader.BitsPerSample = BITS_PER_SAMPLE;
    
    //assign subchunk2 id
    wavHeader.SubChunk2ID[0] = 'd';
    wavHeader.SubChunk2ID[1] = 'a';
    wavHeader.SubChunk2ID[2] = 't';
    wavHeader.SubChunk2ID[3] = 'a';

    //assign subchunk2 size
    wavHeader.SubChunk2Size =  numSamples * NUM_CHANNELS * BYTES_PER_SAMPLE;
    
    
    //need to allocate memory to store the samples before writing. ammount needed is == sub chunk 2
    uint16_t *wavSamplesPtr = (uint16_t *) malloc(wavHeader.SubChunk2Size);
    
    //check for failed memory allocation
    if(wavSamplesPtr == NULL)
    {
        puts("allocation error");
        return -1;
    }
    
    
    //generate the samples  
    //loop through each number in the user phone# string    
    sampleNum = 0;
    for(size_t i = 0; i < numDigits; i++)
    {
        //cycle through valid characters
        for(size_t f = 0; f < 14; f++)
        {    
            //detect a valid character from valid character array
            if( argv[3][i] == inputChar[f])
            {
                freq1 = (int) tone1[f];//assign corresponding freq1
                freq2 = (int) tone2[f];//assign corresponding freq2
                                
                for(size_t j = 0; j <= samplesPerTone; j++)//generate all the samples for a single digit-tone
                {
                    sampleValue = AMPLITUDE * (sin(sampleNum * freq1 * 2 * 3.14159 / SAMPLE_RATE) +//single sample calculation
                                               sin(sampleNum * freq2 * 2 * 3.14159 / SAMPLE_RATE));
                                                                 
                    wavSamplesPtr[sampleNum] = sampleValue;//put the sample in its spot in the allocated mem
                    sampleNum ++;//go to the next spot in memory for the next sample
                }     
            }    
        }                 
    }       
                                
    
    // write (copy) the wavefile-header of the wavefile, from allocated
    // memory, into the file, and check it wrote properly   
    FILE *wavFilePtr = fopen(argv[1], "wb");//create wav file with user-inputed name
    fwrite(&wavHeader, sizeof(wavHeader), 1, wavFilePtr); 
    
    
    
    // write (copy) the data-samples of the wavefile, from allocated
    // memory, into the file, and check it wrote properly
    fwrite(wavSamplesPtr, wavHeader.SubChunk2Size, 1, wavFilePtr);
    
    
    // close the file
    fclose(wavFilePtr);
    
  
    // free all allocated memory
    free(wavSamplesPtr);
    
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
   
