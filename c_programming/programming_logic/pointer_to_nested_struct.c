#include <stdio.h>

struct flotating2{
	float z;
	float w;
};

struct flotating{
	float x;
	float y;
	struct flotating2 flt2; //initialize a struct of kind flotating2 named flt2
};

//in big programs the function headers can be placed after the main function,
//with the purpose of telling to the main function that there is a function prototype in the rest of the code.
//This allow me to write the body of the function before the main function 

void duplicateFlotating(struct flotating *flt); //the function will take by reference a struct of type flotating, so the struct of type flotating will change

int main(void) {
	struct flotating p; //initialize a struct of kind flotating 
	struct flotating *ptr; //initialize a pointer to an struct of kind flotating
	ptr = &p; //the pointer ptr points to the memory adress of the struct p 
	p.x = 10.5;
	p.y = -1.5;
	p.flt2.w = 2.5;
	p.flt2.z = 5.5;
	
	
	printf("after duplicate %f, %f, %f, %f\n", p.x, p.y, p.flt2.w, p.flt2.z);
	duplicateFlotating(&p);
	printf("before duplicate %f, %f, %f, %f\n", p.x, p.y, p.flt2.w, p.flt2.z);
	return 0;
}

void duplicateFlotating(struct flotating *flt){ //*flt is a pointer to an struct of kind flotating parameter that will recieve a memory address 
	flt->x = flt->x * 2;						//so the same logic of dereferencing using arrow sintax applies for *flt 
	flt->y = flt->y * 2;
	flt->flt2.z = flt->flt2.z * 2;
	flt->flt2.w = flt->flt2.w * 2;
}
