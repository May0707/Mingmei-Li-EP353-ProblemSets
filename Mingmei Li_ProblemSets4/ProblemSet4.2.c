#include <stdio.h>
void min3();
int a;
int b;
int c;
int z;
int main()
{
    printf("Type 3 numbers, each followed by a comma\n");
    scanf("%d, %d, %d\n", &a, &b, &c);
    printf("a=%d,b=%d,c=%d\n",a,b,c);
    min3();
    return 0;
    }

    void min3(){
        if(a<b){
            if(a<c){
                z = a;
            }
        }
        if(b<a){
            if(b<c){
                z = b;
            }
        }
        if(c<b){
            if(c<b)
            z = c;
        }
    }

    printf("The smallest number is %d\n", z);
    }