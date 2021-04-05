//
// Sbooks contains all the data about the books and a pointer to the next item
//
struct Sbooks
{
	char sAuthor[50];
	char sName[50];
	int iYear;
	int iPageAmount;
	int iPrice;
	struct Sbooks* pNext;
};
//
// Reads information about all books from the file
//
void readBooksFromTxtFile(struct Sbooks* booksFirst, struct Sbooks* p);
//
// Displays information about all books on the console
//
void printStruct(struct Sbooks* p, struct Sbooks* booksFirst);
//
// Returns the average number of pages of all books
//
double averageNumberOfPages(struct Sbooks* p, struct Sbooks* booksFirst);
//
// Sorts the structure by year in ascending order
//
void sortByYear(struct Sbooks* p);
//
// Removes all items that have more than average pages
//
void deleteElementsByPages(struct Sbooks* p, struct Sbooks* booksFirst, double midPage);
//
// Deletes all items that were published after 2000 and have less than 150 pages
//
void deleteElementsByYear(struct Sbooks* p, struct Sbooks* booksFirst, double midPage);
//
// Adds a new element to the structure in sorted order
//
void enterNewBook(struct Sbooks* p, struct Sbooks* booksFirst);
//
// Frees the allocated memory
//
void freeMemory(struct Sbooks* booksFirst);