#include <stdio.h>
#define TMAX 40


//taking count the difficulties using scanf (don't easily recongize - ' ' etc) and gets (violates memory max allocated memory)
/*Any user input data is saved in the stdin buffer until the program reads and flush it. 
The scanf reads input until it encounters (NL or Whitespaces or EOF). 
When you press enter(which means you enter newline character), 
the scanf reads the data and leaves the newline(NL) in the stdin buffer.*/

//create a new datatype tString who will recieve a complete string 
typedef char tSring[TMAX];

//function for storing a string in a tString datatype 
void scanString(tString strg){
	//c for reading character to character the input buffer
	char c;
	int i = 0;
	c = getchar();
	while(i < TMAX-1 && c != EOF && c != '\n')
}; 


int main(void) {
	tInteger a = 5;
	tInteger b = -20;
	printf("%d, %d\n", a, b);
	return 0;
}

