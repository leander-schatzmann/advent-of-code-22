#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *nFile = "../input.txt";
    FILE *fp = fopen(nFile, "r");
    if(fp == NULL) {
        printf("Error opening input file");
        return -1;
    }


    char buffer[256];
    char shared = 0;
    int value = 0, sum = 0;
    while (fgets(buffer, 256, fp) ){
        //find common char of halves
        int nChar = strlen(buffer)-1;   //without \n
        for(int i = 0; i < nChar/2; i++){
            for(int y = nChar/2; y < nChar; y++){
                if(buffer[i] == buffer[y]) shared = buffer[i];
            }
        }
        //find priority->add to priotities sum
        if(shared >= 'A' && shared <= 'Z'){
            value = (int) shared - (int)'A' + 26 + 1;
        }else if(shared >= 'a' && shared <= 'z'){
            value = (int) shared - (int)'a' + 1;
        }

        printf("%c val: %d\n", shared, value);
        sum+= value;
    }
    printf("\n sum= %d", sum);
    fclose(fp);

    return 0;
}