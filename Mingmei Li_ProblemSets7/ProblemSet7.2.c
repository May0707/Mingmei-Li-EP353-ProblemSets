#include<stdio.h>
#include<stdlib.h>

typedef struct Note{
	unsigned char pitch;
	unsigned char velocity;
	unsigned char channel;
}Note;

void printNote(Note *note);

int main(){
	Note *note = (Note*)malloc(sizeof(Note));
	printf("please input pitch, velocity and channel of Note:\n");
	scanf("%d", &note->pitch);
	scanf("%d", &note->velocity);
	scanf("%d", &note->channel);
	printNote(note);
	free(note);	
	return 0;
}

void printNote(Note *note){
	printf("The MIDI Note has:\n");
	printf("Pitch -> %d\n", note->pitch);
	printf("Velocity -> %d\n", note->velocity);
	printf("Channel -> %d\n", note->channel);
}

