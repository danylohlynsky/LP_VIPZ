#include <cstdio>
#include <conio.h>
#include <cstdlib>

#include "Functions.h"

int main() {
	auto* p = (struct Sbooks*)malloc(sizeof(struct Sbooks));
	struct Sbooks* booksFirst = NULL;
	
	readBooksFromTxtFile(booksFirst, p);

	printStruct(p, booksFirst);

	const auto midPage = averageNumberOfPages(p,booksFirst);
	
	sortByYear(p);

	deleteElementsByPages(p, booksFirst, midPage);
	
	printf("Average number of pages: %lf\n", midPage);
	
	printStruct(p, booksFirst);
	
	deleteElementsByYear(p, booksFirst, midPage);
	
	printStruct(p, booksFirst);
	
	enterNewBook(p, booksFirst);
	
	printStruct(p, booksFirst);

	freeMemory(booksFirst);
	
	return 0;
}