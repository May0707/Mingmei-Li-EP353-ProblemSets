#include<stdio.h>

int numChars(const char *s, char character);

int main(){
	//char *str = (char*)malloc(10 * sizeof(char));
	char str[100];
	char character;
	printf("plese input a string:\n");
	scanf("%s", str);
	getchar();
	printf("plese input a char:\n");
	scanf("%c", &character);
	//printf("%s", str);
	int count = numChars(str, character);
	printf("There are %d %c in the string", count, character);
	return 0;
} 

int numChars(const char *s, char character){
	int count = 0;
	while(*s != '\0'){
		if(*s == character) count++;
		s++;
	}
	return count;
}
