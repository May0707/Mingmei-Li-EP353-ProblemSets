#include <stdio.h>
#include <math.h>

int freq2midi(float);

int freq2midi(float midiNote){
    return midiNote;
}

float baseFrequency =440.0;
float midiNote;
int x = 12;
int y = 69;
in z;

int main(){
    float log = log2(baseFrequency/440.0);
    midiNote = x*log+y;

    z = freq2midi(midiNote);

    printf("The MIDI note number of %f is %d\n", baseFrequency, z);

    return 0;
}
