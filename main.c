#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "list.h"

void printMenu() {
	printf("=== Linked List ===\n");
	printf("1.  Enter\n");
	printf("2.  Print\n");
	printf("3.  Add...\n");
	printf("4.  Add... at...\n");
	printf("5.  Remove...\n");
	printf("6.  Change...\n");
	printf("7.  Get...\n");
	printf("8.  To Array\n");
	printf("9.  From Array\n");
	printf("10. Sort\n");
	printf("11. Remove all\n");
	printf("0.  Exit\n");
}

int main(int argc, char *argv[])
{
	int choice = -1, value, index, n, i, r = 0;
	char c;
	int* array;
	List l;
	
	list_new(&l);
	
	// While the user don't put '0' as a choice, we continue the program...
	while (choice != 0)
	{
		// While the use enter a wrong choice, we repeat again...
		do {
			printMenu();
			scanf(" %i", &choice);
		} while (choice < 0);
		
		// We compute the user's choice:
		switch (choice)
		{
			// Enter
			case 1:
				printf("Enter the numbers seperated with spaces, and followed by a dot at the end:\n");
				for (r = scanf("%d", &value) ; r != 0 ; r = scanf("%d", &value))
				{
					if (r == 1)
						list_add(&l, value);
				}
				scanf("%c", &c);
				break;
			// Print
			case 2:
				list_print(l);
				printf("\n");
				break;
			// Add
			case 3:
				printf("Enter the value to add at the end of the list: ");
				scanf("%i", &value);
				list_add(&l, value);
				break;
			// Add... at..
			case 4:
				do {
					printf("Enter an index (between 0 and %i): ", list_length(l)-1);
					scanf(" %i", &index);
				} while (index < 0 && index > list_length(l));
				
				printf("Enter a value: ");
				scanf("%i", &value);
				list_addAt(&l, index, value);
				break;
			// Remove
			case 5:
				do {
					printf("Enter an index (between 0 and %i): ", list_length(l)-1);
					scanf(" %i", &index);
				} while (index < 0 && index > list_length(l));
			
				list_remove(&l, index);
				break;
			// Change
			case 6:
				do {
					printf("Enter an index (between 0 and %i): ", list_length(l)-1);
					scanf(" %i", &index);
				} while (index < 0 && index > list_length(l));
				printf("Enter a value: ");
				scanf("%d", &value);
				list_set(&l, index, value);
				break;
			// Get
			case 7:
				do {
					printf("Enter an index (between 0 and %i): ", list_length(l)-1);
					scanf(" %i", &index);
				} while (index < 0 && index > list_length(l));
				printf("The value at the index %i is %i.\n", index, list_get(l, index));
				break;
			// To array
			case 8:
				array = listToArray(l);
				printf("Array created with success: ");
				for (i = 0 ; i < list_length(l) ; i++)
					printf("%i ", array[i]);
				printf("\n");
				break;
			// From array
			case 9:
				n = 5;
				printf("Enter 5 numbers:\n");
				for (i = 0 ; i < n ; i++)
				{
					printf("Value n°%i: ", i);
					scanf("%i", &value);
					array[i] = value;
				}
				listFromArray(&l, array, n);
				break;
			// Sort
			case 10:
				printf("Sorting...\n");
				list_sort(&l);
				printf("Sorted.\n");
				break;
			// Remove all
			case 11:
				list_removeAll(&l);
				break;
			// If user's choice is wrong, we exit.
			default:
				choice = 0;
				break;
		}
	}
	
	list_delete(&l);

	return 0;
}
