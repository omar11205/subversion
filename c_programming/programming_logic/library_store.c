/*
	A library wants to keem the record of all the books who sells, for this the store keeps the following information:
	ISBN, name, authors, number of pages, and price. 
	The library manager wants a system with a menu that do the next operations:
	1. Load a new book.
	2. Update the book price
	3. Delete a book record
	4. Show the data of a single book
	5. Show the data of all the books
	6. All the books will be ordered alphabetically
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TMAX 40

typedef char tString[TMAX];

typedef struct{
	int numPages;
	int numAuthors;
	long isbn;
	float price;
	tString name;
	tString authors[TMAX];
} tBook;

typedef tBook tBookList[TMAX];

//defining function prototypes
int menu();
tBook newBook();
void clearBuffer();
void scanString(tString s);
void insertOrderedBook(tBookList books, int *N, tBook newB);
int binarySearch(tBookList books, int N, tString name);
void updateBookPrice(tBook *book);
void deleteBook(tBookList books, int *N, int pos);
void showBook(tBook book);
void showBooks(tBookList books, int N);

int main(void) {
	int opc;
	int N = 0;
	int pos;
	tBookList books;
	tBook book;
	tString bookName;
	return 0;
}

void clearBuffer(){
	char c;
	while(c!=EOF && c!='\n'){
		c = getchar();
	}
}
	
int menu(){
	int opc;
	printf("1-Insert a new Book\n");
	printf("2-Update a book price\n");
	printf("3-Delete a book\n");
	printf("4-Show a book\n");
	printf("5-Show all the books\n");
	printf("0-Exit program");
	printf("\nPlease input an option: ");
	
	do {
		scanf("%d", &opc);
	} while(opc < 0 || opc > 5);
	
	clearBuffer();
	
	return opc;
}
