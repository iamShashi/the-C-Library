#include<stdio.h>
#include<conio.h>

	struct linkedList{
		int data;
		struct linkedList *next;
	};
	struct linkedListmain{
		struct linkedList *right;
		struct linkedListmain *next;
	};

	void addDatatoList(struct linkedlist *head,int datatoEnter)
	{
		struct linkedList *curr;
		curr = (struct linkedList*)malloc(sizeof(struct linkedList));
		curr->data = (int)datatoEnter;
		if(head==null)
		{
			head = curr;
			head->next=null;
		}
		else{
			struct linkedList *p;
			p=head;
			while(p->next!==null)
			{
				p=p->next;
			}
			if(p->next==null)
			{
				p->next = curr;
				p=curr;
				p->next=null;
			}
		}
	}

	void mergeFinalList(struct linkedListmain *final,struct linkedList *q){
		struct linkedList *head, *p;
		head = final;
		p = head;
		if(final==null && q!=null){
			while(q!=null)
			{
				final->data = q->data;
				curr = (struct linkedList*)malloc(sizeof(struct linkedList));
				final->next = curr;
				final=curr;
				q=q->next;
			}
		}
		else if(final!=null && q!=null){
			while(p->next!=null && q->next!=null){
				if(p->data>=q->data)
				{
					curr = (struct linkedList*)malloc(sizeof(struct linkedList));
					struct linkedList *temp;
					temp = p->next;
					p->next = curr;
					p=curr;
					p->data = q->data;
					p=p->next;
					q=q->next;
				}
			}
			if(p->next==null){
				while(q!=null)
				{
					curr = (struct linkedList*)malloc(sizeof(struct linkedList));
					p->next = curr;
					p->data = q->data;
					q=q->next;
				}
			}
			//since we are already adjusting
			//in middle so we dont need to write
			//the second step
//			else if(p->next==null){
//				while(p!=null)
//				{
//					curr = (struct linkedList*)malloc(sizeof(struct linkedList));
//					->next = curr;
//					p->data = q->data;
//					q=q->next;
//				}
//			}		
		}
		
	}
	
	void freeTheList(struct linkedList *head){
		while(head!=null)
		{
			struct linkedList *temp;
			temp = head;
			head=head->next;
			free(temp);
		}
	}
	
	int main(){

		printf("Enter -99 to end inputting values");
		int inputval=-1;
		struct linkedListmain *mainHead,*p;
		mainHead = null;
		p=head;
		while(inputval!=-99){
			printf("Enter -10 to start new list");
			int newList = -11;
			struct linkedList *head;
			head = null;
			while(newList!=-11){
				printf("enter the values of the list");
				int insertdata;
				scanf("%d",&insertdata);
				addDatatoList(*head,insertdata);
			}
//			addDatatoList(mainHead,head);
			curr = (struct linkedListmain*)malloc(sizeof(struct linkedListmain));
			if(mainHead==null)
			{
				head = curr;
				p=curr;
				p->right = head;
				p->next = null;
			}
			else
			{
				p->next = curr;
				p = curr;
				p->right = head;
				p->next = null;
			}	
		}
		struct linkedListmain *q;
		struct linkedList *final;
		finalHead = null;
		q=mainHead;
		while(q!=p)
		{
			mergeFinalList(*finalHead,*q);
			p=p->next;
		}
	}
