#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const int row = 3; 
	const int col = 4; 
	int i; 
	int j; 
	int count;
	
	int (*arr)[row][col] = malloc(sizeof*arr);
	
	count = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			(*arr)[i][j] = ++count;
	    }
	}
	
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			printf("%d ", (*arr)[i][j]);
		}
	}

	free(arr);


	return 0;
}

