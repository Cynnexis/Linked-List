#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "list.h"

int main(int argc, char *argv[])
{
	int choice = -1, value, index, n, i;
	List l;
	
	initList(&l);
	
	while (choice != 0)
	{
		do {
			printf("=== Linked List ===\n");
			printf("1. Enter\n");
			printf("2. Print\n");
			printf("3. Add...\n");
			printf("4. Add... at...\n");
			printf("5. Delete...\n");
			printf("6. Change...\n");
			printf("7. Get...\n");
			printf("8. Free\n");
			printf("0. Exit\n");
			scanf(" %i", &choice);
		} while (choice < 0);
	
		switch (choice)
		{
			case 1:
				do {
					printf("Enter the number of element in the list: ");
					scanf(" %i", &n);
				} while (n <= 0);
			
				for (i = 1 ; i <= n ; i++)
				{
					printf("Value n°%i: ", i);
					scanf(" %i", &value);
					add(&l, value);
				}
				break;
			case 2:
				printList(l);
				printf("\n");
				break;
			case 3:
				printf("Enter the value to add at the end of the list: ");
				scanf("%i", &value);
				add(&l, value);
				break;
			case 4:
				do {
					printf("Enter an index (between 0 and %i): ", getLength(l));
					scanf(" %i", &index);
				} while (index < 0 && index > getLength(l));
				
				printf("Enter a value: ");
				scanf("%i", &value);
				addAt(&l, index, value);
				break;
			case 5:
				do {
					printf("Choose a value to delete: ");
					scanf("%i", &index);
				} while (!belongs(l, index));
			
				delete(&l, index);
				break;
			case 6:
				do {
					printf("Enter an index (between 0 and %i): ", getLength(l));
					scanf(" %i", &index);
				} while (index < 0 && index > getLength(l));
				printf("Enter a value: ");
				scanf("%d", &value);
				set(&l, index, value);
				break;
			case 7:
				do {
					printf("Enter an index (between 0 and %i): ", getLength(l));
					scanf(" %i", &index);
				} while (index < 0 && index > getLength(l));
				printf("The value at the index %i is %i.\n", index, get(l, index));
				break;
			case 8:
				freeList(&l);
				break;
			default:
				choice = 0;
				break;
		}
	}

	return 0;
}
