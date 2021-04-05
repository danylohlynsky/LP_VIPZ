#include "Functions.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
//--------------------------------------------------------------------------------
void readBooksFromTxtFile(struct Sbooks* booksFirst, struct Sbooks* p) {
	 char str_all[200];
	 auto* fl = fopen("Sbooks.txt", "r");
	 char* ptr;
	 do {
		 fgets(str_all, 200, fl);
		 ptr = strtok(str_all, "<>");
		 if (!booksFirst) {
			 booksFirst = p;
		 }
		 strcpy(p->sAuthor, ptr);
		 ptr = strtok(NULL, "<>");
		 strcpy(p->sName, ptr);
		 ptr = strtok(NULL, "<>");
		 p->iYear = atoi(ptr);
		 ptr = strtok(NULL, "<>");
		 p->iPageAmount = atoi(ptr);
		 ptr = strtok(NULL, "<>");
		 p->iPrice = atoi(ptr);
		 ptr = strtok(NULL, "<>");
		 if (!booksFirst) booksFirst = p;
		 auto* pp = (struct Sbooks*)malloc(sizeof(struct Sbooks));
		 p->pNext = pp;
		 p = pp;
	 } while (ptr);
	 p->pNext = NULL;
 }
//--------------------------------------------------------------------------------
void printStruct(struct Sbooks* p, struct Sbooks* booksFirst) {
	p = booksFirst;
	while (p->pNext != NULL) {
		printf("%-25s|\t%-40s|\t%-8d|\t%-8d|\t%d\n", p->sAuthor, p->sName, p->iYear, p->iPageAmount, p->iPrice);
		p = p->pNext;
	}
	p = booksFirst;
	printf("\n");
}
//--------------------------------------------------------------------------------
double averageNumberOfPages(struct Sbooks* p, struct Sbooks* booksFirst) {
	double sum = 0;
	double n = 0;
	p = booksFirst;
	while (p->pNext != NULL) {
		sum += p->iPageAmount;
		p = p->pNext;
		n++;
	}
	p = booksFirst;
	return sum / n;
}
//--------------------------------------------------------------------------------
void sortByYear(struct Sbooks* p) {
	struct Sbooks* tmp;
	while (p->pNext->pNext->pNext != NULL)
	{
		if (p->pNext->iYear > p->pNext->pNext->iYear) {
			tmp = p->pNext;
			p->pNext = p->pNext->pNext;
			tmp->pNext = tmp->pNext->pNext;
			p->pNext->pNext = tmp;
		}
		p = p->pNext;
	}
}
//--------------------------------------------------------------------------------
void deleteElementsByPages(struct Sbooks* p, struct Sbooks* booksFirst, double midPage) {
	printf("\n");
	p = booksFirst;
	while (1) {
		auto* pp = p;
		p = p->pNext;
		if (!p) break;
		if (p->iPageAmount > midPage) {
			if (!p->pNext) {
				pp->pNext = NULL;
				break;
			}
			pp->pNext = p->pNext;
			free(p);
			p = pp;
		}
	}

	p = booksFirst;
	if (p->iPageAmount > midPage) {
		if (p->pNext) {
			booksFirst = p->pNext;
		}
		else {
			booksFirst = NULL;
		}
	}
}
//--------------------------------------------------------------------------------
void deleteElementsByYear(struct Sbooks* p, struct Sbooks* booksFirst, double midPage) {
	while (1) {
		auto* pp = p;
		p = p->pNext;
		if (!p) break;
		if ((p->iYear < 2000) && (p->iPageAmount < 150)) {
			if (!p->pNext) {
				pp->pNext = NULL;
				break;
			}
			pp->pNext = p->pNext;
			free(p);
			p = pp;
		}
	}
	p = booksFirst;
	if ((p->iYear < 2000) && (p->iPageAmount < 150)) {
		if (p->pNext) {
			booksFirst = p->pNext;
		}
		else {
			booksFirst = NULL;
		}
	}
}
//--------------------------------------------------------------------------------
void enterNewBook(struct Sbooks* p, struct Sbooks* booksFirst) {
	auto* k = (struct Sbooks*)malloc(sizeof(struct Sbooks));
	p = booksFirst;
	printf("New book:\n");
	scanf("%s %s %d %d %d", &k->sAuthor, &k->sName, &k->iYear, &k->iPageAmount, &k->iPrice);
	while (p->pNext != NULL) {
		if (k->iYear < p->pNext->iYear) {
			k->pNext = p->pNext;
			p->pNext = k;
			break;
		}
		else {
			p = p->pNext;
		}
	}
}
//--------------------------------------------------------------------------------
void freeMemory(struct Sbooks* booksFirst) {
	while (booksFirst != NULL) {
		struct Sbooks* tmp = booksFirst;
		booksFirst = booksFirst->pNext;
		free(tmp);
	}
}
