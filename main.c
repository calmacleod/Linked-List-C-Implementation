// FILE IS main.c
/*
Description:

This is an exmaple of a test program that you should write to test your code.  
The testing is not complete because it checks only a subset of the required functionality
and not all aspects of it. 

The file includes a function to populate the struct personInfo with with either student or employee information.  The function is used to create data required for testing linked list insertion function.
The function name is populatePerson()

This code will not be used by the TAs to test your code.


Revisions:
Doron Nussbaum 2019
Copyright Doron Nussbaum 2019

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "linked_list.h"
#include "person.h"

#define CONTINUE {printf("hit <cr> to continue \n"); getchar();}

void populatePerson(PersonInfo *person);


int main(int argc, char* argv[])
{
	
	PersonInfo person;
	ListNode *head = NULL;
	ListNode *p = NULL;

    char familyName[64];
	int i;

	
	for (i = 0; i < 20; i++) {
		populatePerson(&person);
		p = insertToList(&head,  &person);
	}

	printf("Printing List: \n");

	printList(head);

	printf("\nDeleting Name: Bronson\n\n");
	
	PersonInfo *pi;
	deleteFromList(&head, pi);

	printf("\nPrinting Saved Person: \n");
	printEmployee(pi);

	printf("\nList After: \n");
	printList(head);


	deleteList(&head);



	return 0;
}


	

/***************************************************************************/
/* purpose: the function populate the person info

input/output
struct personInfo *p - allocated memory to the struct pointer which the function assigns values.




*/

void populatePerson(PersonInfo *person)
{
	static int initRand = 0;
	int j;
	char *first[10] = { "John", "Don", "Edna", "Bev", "Miya", "Oliver", "James", "Liam", "Emily", "Alice"  };
	char *family[10] = { "Broker", "Smith", "Tower", "Little", "Bronson", "Brown", "Tayloy", "King", "Green", "Baker"   };

	if (!initRand) {
		srand(1557);
		initRand ++;
	}
	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 10;
	// copy the first name to the structure pointed by p using strcpy
	strncpy(person->firstName, first[j], NAME_LENGTH);

	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 10;
	// copy the family name to the structure pointed by p using strcpy
	strncpy(person->familyName, family[j], NAME_LENGTH);

	// populate the student id using the random numnber in the range of 0-4096  
	person->id = rand() % 150;

	// populate either the student field of the employee field
	if (rand() % 100 < 20) {
		// employee record
		person->emp.salary = rand() % 50000 + 50000;
		person->emp.yearsOService = rand() % 41;
		person->empOrStudent = EMPLOYEE_TYPE;
	}
	else {
		// student record
		person->stu.gpa = rand() % 9 + 4;
		person->stu.numCompletedCourses = rand() % 31 + 10;
		person->stu.numRequiredCourses = 40;
		person->empOrStudent = STUDENT_TYPE;

	}

}






