#include<stdio.h>

void sort3(int *na, int *nb, int *nc);
void swap(int *a, int *b);

int main(){
	int na, nb, nc;
	scanf("%d %d %d",&na, &nb, &nc);
	sort3(&na, &nb, &nc);
	printf("The value of `na` is %d\n", na);
	printf("The value of `nb` is %d\n", nb);
	printf("The value of `nc` is %d\n", nc);
	return 0;
} 

void sort3(int *na, int *nb, int *nc){
	if(*nb < *na) swap(na, nb);
	if(*nc < *nb) swap(nc, nb);
	if(*nb < *na) swap(na, nb);
	if(*nc < *nb) swap(nc, nb);
}

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}
