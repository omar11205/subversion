#include <stdio.h>

int main() {
	int reach = 7;
	for (int i = 0; i<reach; i++){
		printf("vi = %d\n", i);
		if ((i+1) % 3 == 1){ //1 divided by 3: 3*0 = 0, one minus cero = 1, thus remainder = 1
			printf("Reached when vi = %d\n", i);
		}
	}
	return 0;
}

