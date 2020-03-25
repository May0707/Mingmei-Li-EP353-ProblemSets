#include<stdio.h>
#include<stdlib.h>

typedef struct Note {
	unsigned char pitch;
	unsigned char velocity;
	unsigned char channel;
}Note;

int main(){
	FILE *fp;
	Note note;
	
	fp = fopen("MIDINotes.bin", "rb");
	if(!fp){
		printf("can not open the file");
		return 0;
	}
	
	int count = 0;
	while(fread(&note, sizeof(Note), 1, fp) != 0){
		count++;
	}
	rewind(fp);
	int i;
	Note *notes = (Note*)malloc(count * sizeof(Note));
	for(i = 0; i < count; i++){
		fread(&notes[i], sizeof(Note), 1, fp);
	}
	
	for(i = 0; i < count; i++){
		printf("MIDINote %d contains: Pitch: %d,  Velocity %d, Channel %d.\n",
		i + 1, notes[i].pitch, notes[i].velocity, notes[i].channel);
	}
	return 0;
} 
