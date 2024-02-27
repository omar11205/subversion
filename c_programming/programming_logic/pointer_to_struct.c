#include <stdio.h>

struct flotating{
	float x;
	float y;
};

//in big programs the function headers can be placed after the main function,
//with the purpose of telling to the main function that there is a function prototype in the rest of the code.
//This allow me to write the body of the function before the main function 

void duplicateFlotating(struct flotating *flt); //the function will take by reference a struct of type flotating, so the struct of type flotating will change

int main(void) {
	struct flotating p; //initialize a struct of kind flotating 
	struct flotating *ptr; //initialize a pointer to an struct of kind flotating
	p.x = 10.5;
	p.y = -1.5;
	
	ptr = &p; //the pointer ptr points to the memory adress of the struct p 
	
	//its specting, extending the normal pointer logic, that if i want to access the elements in the struct p 
	//i can derreference the pointer ptr with * (*ptr) and with the dot operator (.) access the element: (*ptr.x or *ptr.y) 
	//this is not alowed in c. Instead of *ptr.x i can use the arrow operator (->): ptr->x or ptr->y
	
	printf("after duplicate %f, %f\n", ptr->x, ptr->y);
	
	duplicateFlotating(&p); //the function expects a memory direction of a struct of kind flotating as argument: &p
	printf("before duplicate %f, %f\n", p.x, p.y);
	return 0;
}

void duplicateFlotating(struct flotating *flt){ //*flt is a pointer to an struct of kind flotating parameter that will recieve a memory adress 
	flt->x = flt->x * 2;						//so the same logic of dereferencing using arrow sintax applies for *flt 
	flt->y = flt->y * 2;
}
