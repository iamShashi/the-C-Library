#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node *createList(int n){
	struct node* head=NULL;
	struct node* p=NULL;
	struct node* curr=NULL;
	while(n){
		curr = (struct node*)malloc(sizeof(struct node));
		if(head==NULL)
		{
			head=curr;
			p=head;
			p->next = NULL;
		}
		else
		{
			p->next=curr;
			p=curr;
			p->next = NULL;
		}
		
		printf("\nEnter the Element");
		scanf("%d",&curr->data);
		n--;
	}
	return head;
}

void printList(struct node *start){
	while(start){
		printf("%d->",start->data);
		start=start->next;
	}
}


