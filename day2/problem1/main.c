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
        printf("Round:%c-%c", round[0], round[1]);

        if(round[0] == 'A'){
            switch(round[1]) {

	            case 'X': points += 1; points += draw; printf("draw 4"); break;
	            case 'Y': points += 2; points += win; printf("win 8"); break;
	            case 'Z': points += 3; points += lose; printf("lose 3");break;
            	default: printf("error "); return -1;
            }
        }
        if(round[0] == 'B'){
            switch(round[1]) {
	            case 'X': points += 1; points += lose; printf("win 7 "); break;
	            case 'Y': points += 2;  points += draw; printf("draw 5 ");break;
	            case 'Z': points += 3; points += win; printf("lose 3");break;
            	default: printf("error "); return -1;
            }
        }
        if(round[0] == 'C'){
            switch(round[1]) {
	            case 'X': points += 1; points += win;printf("lose 7"); break;
	            case 'Y': points += 2; points += lose; printf("win 2");  break;
	            case 'Z': points += 3; points += draw; printf("draw 6 "); break;
            	default: printf("error "); return -1;
            }
        }
    }
    printf("\n------------------------\n\n");
        printf("%d\n", points);
        printf("-----------------------------");
    fclose(fp);

    return 0;
}