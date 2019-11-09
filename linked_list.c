
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Revisions
 Doron Nussbaum 2019

 
 
 
 
 Copyright 2019 Doron Nussbaum
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// DEFINE



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
head - head of linked list
person - the data of the new person

output
head - head of linked list

return
A pointer to the node that was allocated.  
NULL - if the operation was not successful

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL
2. person is not NULL

*/

ListNode *insertToList(ListNode **head, PersonInfo *person)
{
	//If Head is null
	if(!*head){

		//Allocate memory for a new node
		ListNode *p = malloc(sizeof(ListNode));
		
		if(!p){
			printf("An Error has occured in allocating memory\n");
			return NULL;
		}

		//Set the properties
		p->next = NULL;
		p->person = *person;

		//Point head to p
		(*head) = p;

		return (*head);

	}

	//Make new node
	ListNode *p = malloc(sizeof(ListNode));

	if(!p){;
		return NULL;
	}

	//Set properties
	p->person = *person;	

	p->next = (*head);
	
	(*head) = p;
	//Return that bitch
	return (p);

}


/************************************************************************/
/*
Purpose: find the first node in the list with the input family name and insert a new node containing the 
person data into the list.

If there is no node that matches that given family name then the operation is considered a failure.  

Input
head - head of list
familyName - the family name that must be used to find the first matching recrod
person - the person record to insert into the list as new node


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

Assumptions:
familyName is not NULL
person is not NULL

*/


ListNode *insertAfter(ListNode *head, char *familyName, PersonInfo *person)
{	
	//If List is empty || Head is null
	if(!head){
		return NULL;
	}

	int flag = 1;

	//Find Proper Node
	do{
		if(  strcmp(head->person.familyName, familyName)==0 ){
			flag = 0;
			break;
		}
		head = head->next;

	} while(head);

	//Check if we found a spot
	if(flag){
		return NULL;
	}

	//Found the proper node
	ListNode *p = malloc(sizeof(ListNode));

	if(!p){
		printf("Error occurred in allocating memory \n");
		return NULL;
	}


	p->person = *person;
	p->next = head->next;
	head->next = p;
	
	return p;




}


/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
person - person data that is stored in the list


return
0 if node was deleted
1 if node was not deleted or list is empty

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty
2. If person is NULL then the person information stored in the node is not required to the output

*/


int deleteFromList(ListNode **head, PersonInfo *person)
{
	//If Head is NULL
	if(!(*head)){
		printf("Error \n");
		return 0;
	}

	//If person is not NULL
	if( &(*head)->person ){
		*person = (*head)->person;	
	}
	
	//If Head is only node in list
	if(   !(*head)->next  ){
		free( *head );
		(*head) = NULL;
		return 1;
	}

	//p is reference to head
	ListNode *p = (*head);

	//Move head to the next one
	*head = (*head)->next;

	//Free the original head
	free(p);

	return 1;


}


/************************************************************************/

/*
Purpose: delete the first node with the matching family name
Input
head - the head of the list
familyName - family name of person

output
head - the head of the list
person - data of the person in the node


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

Assumptions
1. familyName is not NULL
2. Function has to be robuse enough to handle cases where head is NULL or the list is empty
3. If person is NULL then the person information stored in the node is not required to the output

*/

int deleteNodeByName(ListNode **head, char *familyName, PersonInfo *person)
{
	//If head is null || list is empty
	if(!(*head)){
		return 1;
	}

	//Tracker nodes needed for function
	ListNode *hold = (*head);
	ListNode *prev = NULL;


	while(hold){
		//If the names match;	
		if( strcmp(hold->person.familyName, familyName) == 0){
			
			//Save value
			*person = hold->person;

			//If theres a previous node we have to move up
			if(prev){
				prev->next = hold->next;
			}
			else{
				(*head) = (*head)->next;
			}

			//Save node we're deleting
			ListNode *del = hold;
			
			hold = hold->next;

			free(del);

			return 0;
		}
		else{
			//Otherwise advance
			prev = hold;
			hold = hold->next;
		}
	}

	//If nothing was found
	return 1;

}

/************************************************************************/
/*
Purpose: deletes all nodes from the list

input
head - the head of the list

output
head - the head of the list

return
none

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/


void deleteList(ListNode **head)
{
	//Head is null
	if(!(*head)){
		return;
	}

	//Head is the last node in the list || Base Case
	if(!(*head)->next){
		free((*head));
		return;
	}

	//Recursive Step
	deleteList(&(*head)->next);

	//Post Condition
	free((*head));

}



/************************************************************************/
/*
Purpose: search for the first node with the matching familyName
Input
head - the head of the list
familyName - family name of person

Output
person - a copy of the person record in the node

return
a pointer to the node that was found.
NULL - if no node was found or list empty


Assumptions
1. familyName is not NULL
2. person can be NULL.  If person is NULL then no coping of the person record is required. 

*/


ListNode *searchByName(ListNode *head, char *familyName, PersonInfo *person)
{
	if(!head){
		return NULL;
	}

	do{
		if(strcmp(head->person.familyName, familyName) == 0){
			*person = head->person;
			return head;
		}

		head = head->next;

	} while(head);

	return NULL;
}



/************************************************************************/
/*
Purpose: prints all the records in the list according to their type a student or an employee

input
head - the head of the list
*/


void printList(ListNode *head)
{
	//If head is null don't bother
	if(!head){
		return;
	}

	do{
		//If the node has a person
		if(&head->person){
				if(head->person.empOrStudent == STUDENT_TYPE){
					printStudent(&head->person);
				}

				else{
					printEmployee(&head->person);
				}
		}
		head = head->next;

	} while (head);

	

}

/************************************************************************/
/*
Purpose: prints all the students in the list

input
head - the head of the list

Output 
None

Return
None
*/

void printStudents(ListNode *head)
{
	//If head is null don't bother
	if(!head){
		return;
	}

	do{
		if(head->person.empOrStudent == STUDENT_TYPE){
			printStudent(&head->person);
		}
		head = head->next;
	}while(head);

}
/************************************************************************/
/*
Purpose: prints all the employees in the list

input
head - the head of the list

Output
None

Return
None
*/


void printEmployees(ListNode *head)
{
	//If head is null don't bother
	if(!head){
		return;
	}

	do{
		if(head->person.empOrStudent == EMPLOYEE_TYPE){
			printEmployee(&head->person);
		}
		head = head->next;
	}while(head);
}


/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


unsigned int listSize(ListNode *head)
{	
	//Start with inital size of 0
	int count = 0;

	//If node isn't null count increases
	if(head){
		count++;
	}
	
	//If there is another node to count add it recursively
	if(head->next){
		return count += listSize(head->next);
	}

	//Return final count
	return count;
}


/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL


*/

int copyList(ListNode *head, ListNode **newListHead)
{
	//Allocate memory for new node
	(*newListHead) = malloc(sizeof(ListNode));

	if(!(*newListHead)){
		return 1;
	}

	//Set Properties
	(*newListHead)->next = NULL;
	(*newListHead)->person = head->person;

	//Make holder node so we can traverse without losing data
	ListNode *nextNode = (*newListHead);

	head = head->next;

	while(head){
		//Allocate
		ListNode *holder = malloc(sizeof(ListNode));

		if(!holder){
			return 1;
		}

		//Set Properties
		holder->next = NULL;
		holder->person = head->person;

		//Change counters
		nextNode->next = holder;
		head = head->next;

		//Advance
		nextNode = nextNode->next;
	}

	return 0;
}
/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL

*/
int copyListRecursive(ListNode *head, ListNode **newListHead)
{
	//Allocate memory for new list head
	(*newListHead) = malloc(sizeof(ListNode));


	if(!newListHead){
		return 1;
	}

	//Set Properties of this new node
	(*newListHead)->person = head->person;
	(*newListHead)->next = NULL;

	//If head has another node that needs copying
	if(head->next){
		copyListRecursive(head->next, &(*newListHead)->next);
	}

	return 0;
}

/************************************************************************/
/*
Purpose: removes all the nodes that have student data from the list
input
head - the head of the list

output
head the modified list

return
0 if successful
1 if failed

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/

int removeStudents(ListNode **head)
{
	//Check if head is null || list is empty
	if(!(*head)){
		return 1;
	}

	//Node needed to track indexes
	ListNode *hold = (*head);
	ListNode *prev = NULL;

	while(hold){

		if(hold->person.empOrStudent == STUDENT_TYPE){
			//If Prev is defined then make sure the right node is next
			if(prev){
				prev->next = hold->next;
			}

			//Otherwise move the head of the list up
			else{
				(*head) = (*head)->next;
			}

			//Keep track of node we're deleting
			ListNode *del = NULL;
			del = hold;

			hold=hold->next;

			free(del);
		}

		else{
			//If node was not student just move index up
			prev = hold;
			hold = hold->next;
		}

	}

	//Success
	return 0;
}

/******************************** PART II ************************************************/




void generalTraverse(ListNode *head, void (*fPtr)(PersonInfo*ptr) )
{
	fPtr(&head->person);
	
	if(head->next){
		generalTraverse(head->next, fPtr);
	}

}

void printStudentPtr(PersonInfo *pi)
{
	if(pi->empOrStudent == 1){
		printf("%s %s ID: %d CGPA: %f Required: %u Completed: %u \n", pi->firstName, pi->familyName, pi->id, pi->stu.gpa, pi->stu.numRequiredCourses, pi->stu.numCompletedCourses);
	}
}