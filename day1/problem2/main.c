#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main(){
    char *nFile = "../input.txt";
    FILE *fp = fopen(nFile, "r");
    if(fp == NULL) {
        printf("Error opening input file");
        return -1;
    }

    char buffer[MAX];
    int current = 0, sum = 0, totalSum = 0, iLowest = 0;
 
    int highest3[3];

    while (fgets(buffer, MAX, fp)){

        current = atoi(buffer);
        if(current == 0){
            for(int i = 0; i < 3; i++){
                if(highest3[i] < highest3[iLowest]) iLowest = i;
            }
            if(sum > highest3[iLowest]) highest3[iLowest] = sum;
            sum = 0;
        }else{
            sum += current;
        }
    }
    for(int i = 0; i < 3; i++){
        totalSum += highest3[i];
    }
    fclose(fp);

    printf("Total calories: %d", totalSum);

    return 0;
}