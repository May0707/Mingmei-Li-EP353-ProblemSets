#include <stdio.h>
int main(){
    FILE *file;
    file = fopen ("LoremIpsum.txt", "r");
    if (file == NULL) {
        printf("Can't open the file or doesn't exist.\n");
        return 1;
    }
    int newLineCount = 0;
    int gothtoughFile;

    while((gothroughFile=fgetc(file)) !=EOF){
        if(gothroughFile == '\n'){
            newLineCount++;
        }
    }
    if(file) fclose(file);
    printf("%d\n", newLineCount);
    return 0;
}