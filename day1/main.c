#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main(){
    char *nFile = "input.txt";
    FILE *fp = fopen(nFile, "r");
    if(fp == NULL) {
        printf("Error opening input file");
        return -1;
    }

    char buffer[MAX];
    int current, highest, sum = 0;

    while (fgets(buffer, MAX, fp)){
        current = atoi(buffer);
        if(current == 0){
            if(sum > highest) highest = sum;
            sum = 0;
        }else{
            sum += current;
        }
    }
    printf("highest: %d", highest);
    fclose(fp);

    return 0;
}