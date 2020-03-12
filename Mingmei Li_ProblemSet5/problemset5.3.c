#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	if(1 == argc){
		printf("Input any arbitrary number of integers as command-line arguments to run this program.\n");
	}else{
		int i;
		int sum = 0;
		for(i = 1; i < argc; i++){	
			sum += atoi(argv[i]);
		}
	
		printf("The sum of integers is %d.\n", sum);
	}
	return 0;
}
