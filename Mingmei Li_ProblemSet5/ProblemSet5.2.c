#include<stdio.h>

int characterExists(char alphabets[52], char letter);

int main(){
	char letter;
	scanf("%c", &letter);
	char alphabets[52];
	int i;
	for(i = 0; i < 26; i++){
		alphabets[i] = 'a' + i;
		alphabets[i + 26] = 'A' + i;
	}
	int result =  characterExists(alphabets, letter);
	if(1 == result){
		printf("A character %c exists in the alphabets string.", letter);
	} else{
		printf("A character %c does not exists in the alphabets string.", letter);
	}
	return 0;
}

int characterExists(char alphabets[52], char letter){
	int i;
	for(i = 0; i < 52; i++){
		if(letter == alphabets[i]) return 1;
	}
	return 0;
}
