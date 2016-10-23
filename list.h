#ifndef __LIST_H__
#define __LIST_H__

#include "boolean.h"

typedef struct Cell {
	int value;
	struct Cell* next;
} Cell;

typedef struct {
	Cell* head;
} List;

/* The keyword 'extern' stands for 'public function'. I use it to export these
 * functions as library. If you compiled this program by using 'make' (from the
 * Makefile in this directory/project), you can see the file 'liblist.a', which
 * is the static library of list.c
 * In other words, don't mind this keyword. It won't change the source code
 * if I wouldn't create a library.
 * Note: You can compile list.c and list.h as a normal C file, 'extern' won't
 * interfer with gcc.
 */

extern void initList(List* l);
extern int getLength(List l);
extern Cell* getHead(List l);
extern Cell* getTail(List l);
extern Cell* getCell(List l, int index);
extern int get(List l, int index);
extern void add(List* l, int value);
extern bool addAt(List* l, int index, int value);
extern bool delete(List* l, int index);
extern bool reset(List* l);
extern bool set(List* l, int index, int value);
extern bool belongs(List l, int value);
extern int* toArray(List l);
extern void fromArray(List* l, int* array, int n);
extern void sort(List *l);
extern void printList(List l);
extern void freeList(List* l);

#endif
