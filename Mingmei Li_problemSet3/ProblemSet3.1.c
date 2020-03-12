#include <stdio.h>
#include <math.h>

int main(){
char MIDInote = 65;
float frequency = 0.0;

int x = 2;
float y =(MIDInote-69.0)/12.0;
float P = pow(x,y);   

frequency = P * 440;

printf("The frequnecy of a MIDI note number %d is %fHz\n", MIDInote, frequency);
return 0;
}
