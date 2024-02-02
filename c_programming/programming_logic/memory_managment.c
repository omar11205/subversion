#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void Play(int bet){
	//first mode without using Dinamic Memory Allocation
	//char C[3] = {'J','K','Q'};
	//second mode using Dinamic Memory Allocation (malloc)
	char *C = (char*)malloc(3*sizeof(char));
	C[0] = 'J';
	C[1] = 'Q';
	C[2] = 'K';
	printf("Shuffling...\n");
	srand(time(NULL)); //seeding random number generator
	int i;
	for(i=0;i<5;i++){
		int x = rand()%3;
		int y = rand()%3;
		int temp = C[x];
		C[x] = C[y];
		C[y] = temp; //swaps characters at position x and y
	}
	int playersGuess;
	printf("What is the position of queen - 1,2 or 3?");
	scanf("%d", &playersGuess);
	if(C[playersGuess-1] == 'Q'){
		cash += 3*bet;
		printf("You win! Result %c %c %c Total cash = %d", C[0], C[1], C[2], cash);
	} else {
		cash -= bet;
		printf("You Loose! Result %c %c %c Total cash = %d", C[0], C[1], C[2], cash);
	}
	free(C);
}


int main(void) {
	int bet;
	printf("** Welcome to the Virtual Cassino ** \n");
	printf("Total cash = $%d\n", cash);
	while (cash>0){
		printf("What's your bet? $");
		scanf("%d", &bet);
		if(bet == 0 || bet > cash){
			break;
		} else {
			Play(bet);
			printf("\n************************\n");
		}
	}
	
	return 0;
}

