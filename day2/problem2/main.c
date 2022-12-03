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
    int lose = 0, draw = 3, win = 6; 
    int points = 0;
    char buffer[5];
    char round[2];

    
    while (fgets(buffer, 5, fp) ){
        round[0] = buffer[0];
        round[1] = buffer[2];
        int currentPoints;

        if(round[0] == 'A'){
            switch(round[1]) {

	            case 'X': points += 3; points += lose;  break;
	            case 'Y': points += 1; points += draw;  break;
	            case 'Z': points += 2; points += win;   break;
            	default: printf("error "); return -1;
            }
            printf("%d", points);
        }
        if(round[0] == 'B'){
            switch(round[1]) {
	            case 'X': points += 1; points += lose;  break;
	            case 'Y': points += 2;  points += draw; break;
	            case 'Z': points += 3; points += win;   break;
            	default: printf("error "); return -1;
            }
            printf("%d", points);
        }
        if(round[0] == 'C'){
            switch(round[1]) {
	            case 'X': points += 2; points += lose;  break;
	            case 'Y': points += 3; points += draw;  break;
	            case 'Z': points += 1; points += win;   break;
            	default: printf("error "); return -1;
            }
            printf("%d", points);
        }
    }
    printf("\n------------------------\n\n");
        printf("%d\n", points);
        printf("-----------------------------");
    fclose(fp);

    return 0;
}