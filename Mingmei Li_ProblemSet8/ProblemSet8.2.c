#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//--For sndfile.h to work on your machine, install libsndfile via brew: 
//brew intall libsndfile
//--or follow the instructions here to install libsndfile: https://github.com/erikd/libsndfile
#include <sndfile.h> 

//--Compile this code using:
//clang 3.AudioFileInfo.c -lsndfile -o AudioFileInfo

//--After comppiling, run the program with:
//./AudioFileInfo yourSoundFileName.wav

int main() {

  SNDFILE *sndFile[3] = {NULL, NULL, NULL}; //three sndfile pointer to a sound file
  SF_INFO sfInfo[3]; //hold an information about a sound file

  memset(&sfInfo[0], 0, sizeof(SF_INFO)); //Initialize SF_INFO with 0s
  memset(&sfInfo[1], 0, sizeof(SF_INFO));
  memset(&sfInfo[2], 0, sizeof(SF_INFO));
  
  char *fileName[3] = {"00-calung1.wav", "05-gangsahi1.wav", "10-gangsamid1.wav"};
  

  //Open the sound file as read only
  int i;
  for(i = 0; i < 3; i++){
  	sndFile[i] = sf_open(fileName[i], SFM_READ, &sfInfo[i]);

	if(!sndFile[i]){ //Exit the program if we failed to open the file
	  printf("The sound file %s does not exist or cannot be openned\n", fileName[i]);
	  exit(2);
	}
  }
  
  
  for(i = 0; i < 3; i++){
  //print out information about opened sound file
    printf("Sample rate for %s is %d\n", fileName[i], sfInfo[i].samplerate);
	printf("A number of channels in %s is %d\n", fileName[i], sfInfo[i].channels);
    printf("A number of frames in %s is %lld\n", fileName[i], sfInfo[i].frames);
    printf("time is %f\n", (double)sfInfo[i].frames / sfInfo[i].samplerate);
  }
  
  for(i = 0; i < 3; i++){
    if(sndFile[i]){ //Close the sound file after done using
	  sf_close(sndFile[i]);
	  sndFile[i] = NULL;
	}
  }
	return 0;
}
