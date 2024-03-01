#include <stdio.h>
#define TMAX 40

//taking count the difficulties using scanf (don't easily recongize - ' ' etc) and gets (violates memory max allocated memory)
/*Any user input data is saved in the stdin buffer until the program reads and flush it. 
The scanf reads input until it encounters (NL or Whitespaces or EOF). 
When you press enter(which means you enter newline character), 
the scanf reads the data and leaves the newline(NL) in the stdin buffer.*/
//for better understanding place a breakpoint in the line 18 or line 21 and debug

//create a new datatype tString who will recieve a complete string 
typedef char tString[TMAX];

//function for storing a string in a tString datatype 
void scanString(tString strg){
	//c for reading character to character the input buffer
	char c;
	int i = 0;
	// '(c=getchar()) != EOF' gets a character from buffer and delete it from buffer in each call untill the End Of File 
	// in order to use a while cicle the assignation 'c=getchar()' MUST be placed inside the while condition
	while(i < TMAX-1 && (c = getchar()) != EOF && c != '\n'){ 
		strg[i] = c;
		i++;
	}
	//finally insert the end of string character
	strg[i]='\0';
	//now clean the characters that remain for 40 - length of string strg
	while(c != EOF && c != '\n'){
		c=getchar();
	}
	
}


int main(void) {
	tString s;
	scanString(s);
	printf("%s", s);
	return 0;
}

