#include <stdio.h>

typedef enum{FALSE, TRUE} boolean;
typedef enum{MOONDAY=1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} days; //MOONDAY = 1, SET THE COUNT TO BEGIN IN 1 TO MOONDAY AND FOR THE OTHER += 1


void prenting(void){
	boolean b;
	days d;
	
	b=TRUE;
	printf("B = %d\n", b);
	
	for(d = MOONDAY; d<=SUNDAY; d++){
		printf("Current day: %d\n", d);
	}
}

int main(void) {
	prenting();
	return 0;
}

