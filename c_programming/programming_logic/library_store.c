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

typedef char tString[TMAX]; //maximum legth of the custom strings tString = 39 characters

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
	opc = menu();
	while(opc != 0){
		system("cls"); //clear console
		switch(opc){
			case 1:
				if(N < TMAX){
					printf(" --- Insert new book --- \n");
					book = newBook();
					insertOrderedBook(books, &N, book);
					printf("The book has been successfully added\n");
				} else {
					printf("The book was not added. Maximum number of books reached\n")
				}
				break;
			case 2: 
				printf(" --- Update book price --- \n");
				printf("Input the name of the book to be updated: ");
				scanString(bookName);
				pos = 
		}	
	}
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
	
void scanString(tString s){
	char c;
	int i = 0;
	
	while (i < TMAX-1 && (c=getchar()) != EOF && c != '\n'){
		s[i] = c;
		i++
	}
	
	s[j] = '\0';
	clearBuffer();
}
	
tBook newBook(){
	tBook book;
	int i;
	
	printf("Provide the book ISBN: "); scanf("%ld", &book.isbn); clearBuffer();
	printf("Provide the book name: "); scanString(book.name);
	printf("Input the number of book authors: "); scanf("%d", &book.numAuthors); clearBuffer();
	printf("\n");
	
	for(i=0; i<book.numAuthors; i++){
		printf("Provide the author name # %d: ", i);
		scanString(book.authors[i]);
	}
	
	printf("\nIngrese la cantidad de páginas del libro: "); scanf("%d", &book.numPages); clearBuffer();
	printf("Input the book price: USD $"); scanf("%f", &book.price); clearBuffer();
	
	return book;
}
	
void insertOrderedBook(tBookList books, int *N, tBook newB){
	int i = *N - 1;
	
	while(i>=0 && strcmp(newB.name, books[i].name) < 0){
		books[i+1] = books[i];
		i--;
	}
	
	books[i+1] = newB;
	*N = *N + 1;
}
