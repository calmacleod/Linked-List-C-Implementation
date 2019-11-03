
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

	if(!p){
		printf("Error occurred in allocating memory \n");
		return NULL;
	}

	//Set properties
	p->person = *person;	
	p->next = (*head)->next;
	(*head)->next = p;

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

	printf("Inserting Node After: %s\n",familyName);


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
		person = &(*head)->person;	
	}
	
	//If Head is only node in list
	if(   !(*head)->next  ){
		free( *head );
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
	// add code 


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
	// add code 

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
	// add code 



}



/************************************************************************/
/*
Purpose: prints all the records in the list according to their type a student or an employee

input
head - the head of the list
*/


void printList(ListNode *head)
{
	// add code 

	if(!head){
		return;
	}


	do{

		if(&head->person){
				printEmployee(&head->person);
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
	// add code 




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
	// add code 


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
	// add code 



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

}
