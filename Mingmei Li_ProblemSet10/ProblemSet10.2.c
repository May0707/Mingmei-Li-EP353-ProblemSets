#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

//Compile with:
//clang Template.c -o Template -lsndfile
//Run with:
//./Template

#define kInputFileName "CheeseSynth.wav"
#define kOutputFileName "Delay.wav"

static int keepBits = 1;

//Hold SNDFILE and SF_INFO together
typedef struct SoundFile {
  SNDFILE *file;
  SF_INFO info;
} SoundFile;

//Function prototypes
int openInputSndFile(SoundFile*);
int createOutputSndFile(SoundFile *inFile, SoundFile *outFile);
void process(short *inBuffer, short *outBuffer, sf_count_t bufferSize);
short keep_bits_from_16( short input, int keepBits ); 

int main(void){
  SoundFile inFile, outFile;
  
  //Open input file and create output file
  int error = openInputSndFile(&inFile);

  if(error) return 1;

  // Get buffer size
  sf_count_t bufferSize = inFile.info.frames;

  //Allocate buffers for sound processing
  short *inBuffer = (short *) malloc(bufferSize*sizeof(short));
  short *outBuffer = (short *) calloc(bufferSize,sizeof(short));

  //Copy content the file content to the buffer
  sf_read_short(inFile.file, inBuffer, bufferSize);
  
  //process inBuffer and copy the result to outBuffer
  process(inBuffer, outBuffer, bufferSize);
  
  //Create output file and write the result
  error = createOutputSndFile(&inFile, &outFile);
  if(error) return 1;
  sf_write_short(outFile.file, outBuffer, bufferSize);
  
  // //Clean up
  sf_close(inFile.file);
  sf_close(outFile.file);
  free(inBuffer);
  free(outBuffer);
  
  return 0;
}

//TODO: Implement your DSP here
void process(short *inBuffer, short *outBuffer, sf_count_t bufferSize){
	int i;
	for(i = 0; i < bufferSize; i++){
		outBuffer[i] = keep_bits_from_16(inBuffer[i], keepBits);
	}	
}

int openInputSndFile(SoundFile *sndFile){
  //Initialize SF_INFO with 0s (Required for reading)
  memset(&sndFile->info, 0, sizeof(SF_INFO));

  //Open the original sound file as read mode
  sndFile->file = sf_open(kInputFileName, SFM_READ, &sndFile->info);
  if(!sndFile->file){//Check if the file was succefully opened
    printf("Error : could not open file : %s\n", kInputFileName);
		puts(sf_strerror(NULL));
		return 1;
  }

  //Check if the file format is in good shape
  if(!sf_format_check(&sndFile->info)){	
    sf_close(sndFile->file);
		printf("Invalid encoding\n");
		return 1;
	}

  //Check if the file is mono
  if(sndFile->info.channels > 1){
    printf("Input file is not mono\n");
    return 1;
  }

  //print out information about opened sound file
  printf("Sample rate for this file is %d\n", sndFile->info.samplerate);
	printf("A number of channels in this file is %d\n", sndFile->info.channels);
  printf("A number of frames in this file is %lld\n", sndFile->info.frames);
  printf("time is %f\n", (double)sndFile->info.frames / sndFile->info.samplerate);

  return 0;
}

int createOutputSndFile(SoundFile *inFile, SoundFile *outFile){
  //Open another sound file in write mode
  outFile->file = sf_open(kOutputFileName, SFM_WRITE, &inFile->info);
  if(!outFile->file){//Check if the file was succefully opened
    printf("Error : could not open file : %s\n", kOutputFileName);
		puts(sf_strerror(NULL));
		return 1;
	}
  return 0;
}

short keep_bits_from_16( short input, int keepBits ) {
    short prevent_offset = (unsigned short)(-1) >> keepBits+1;
    input &= (-1 << (16-keepBits));
    return input + prevent_offset; 
}
