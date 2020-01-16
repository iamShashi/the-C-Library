#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include "qsortList.h"

void recursiveReverse( struct node** heads)
{
	struct node* first;
	struct node* second;
	if(heads == NULL)
	return;
	
	first = *heads;
	second = first->next;
	
	if(second==NULL)
		{
			return;
		}
	
		recursiveReverse(&second);
		
	first->next->next = first;
	first->next= NULL;
	*heads = second;
	
}

struct node *last(struct node *head){
	struct node *p;
	p = head;
	while(p->next!= NULL){
		p = p->next;
	}
	return p;
}



//void reverse(struct node** head)
//{
//	recursiveReverse(*head, head);
//}


int main(){
	int n;
	struct node* headStart;
	printf("Enter the Mumber in linked list");
	scanf("%d",&n);
	headStart = createList(n);
	printList(headStart);
//	lasthea = last(headStart);
//	printList(lasthea);
//	printf("\nReversing the Linked list...\n");
	recursiveReverse(&headStart);
//	printList(newHeadStart);
	printf("\nReversing the Linked list tw...\n");
	printList(headStart);
//	printList(newHeadStart);
	return 0;
return 0;	
}
