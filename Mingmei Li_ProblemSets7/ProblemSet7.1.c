#include<stdio.h>
#include<stdlib.h>

int main(){
	printf("please input some integers, end with negative number\n");
	int c;
	int *array = (int*)malloc(0); 
	int index = 0;
	while(1){
		scanf("%d", &c);
		if(c < 0) break;
		else{
			array = (int*)realloc(array, (index + 1)*sizeof(int));
			array[index++] = c;
		}
	}
	int i;
	for(i = 0; i < index; i++){
		printf("%d ", array[i]);
	}
	free(array);
	return 0;
}

