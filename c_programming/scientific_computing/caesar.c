#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void caesar(char message[], int offset){
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	int alphalen = strlen(alphabet);
	int len = strlen(message);
	int index;
	int newIndex;
	for (int j = 0; j < len; j++) {
		message[j] = tolower(message[j]);
	}
	char *encryptedText = (char*)malloc(sizeof(char)*(len+1));
	for (int i = 0; i<=len; i++){
		if (message[i] == ' ' || message[i]=='\0'){
			char temp = message[i];
			encryptedText[i] = message[i];
		} else {
			char *tempindex = strchr(alphabet, message[i]);
			if (tempindex != NULL){
				index = alphalen - strlen(tempindex);
			}
			newIndex = (index + offset)%alphalen;
			encryptedText[i] = alphabet[newIndex];
			printf("Current Encr %s\n", encryptedText);
		}
	}
	printf("Final Encr: -%s-\n", encryptedText);
	free(encryptedText);
}	
	
int main(void) {
	clock_t start, end;
	double cpu_time_used;
	char text[] = "Hello World";
	int shift = 3;
	
	start = clock();
	caesar(text, shift);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Caesar took %f seconds to execute.\n", cpu_time_used);
	
	return 0;
}

