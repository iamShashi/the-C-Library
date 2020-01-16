#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Heap OPerations

//also AVL tree crud operations
struct tree{
	int data;
	struct tree* left;
	struct tree* right;
};

void printDLL(struct tree* node)
{
	while(node->right)
	{
		printf("\n%d",node->data);
		node = node->right;
	}
}


void reverseDLL(struct tree* head, struct tree* &headSt){
	struct tree* p = head;
	struct tree* q = head->right;
	while(q->right)
	{
		struct tree* a;
//		a = p->left;
//		q = p->right;
		a = q;
//		if(!a) p->right = null;
		p->left = q;
		headSt = q;
		q->right  = p;
		q->left  = NULL;
		q = p;
		a->right = q;
	}
}

//void isIsoMorphic(){
//	
//}
//
//void isMirror(){
//	
//}
//
//void diagonalTraversal(){
//	
//}
//
//
//void deleteNodeBST(){
//	
//}
//
//
//void dfsTraversal(){
//	
//}
//
//void bfsTraversal(){
//	
//}

void binaryTreeToDLL(struct tree* node, struct tree* &head){
	if(!node) return;
	
	binaryTreeToDLL(node->left,head);
	
	struct tree* right = node->right;
	
	node->right = head;
	if(head!=NULL)
	{
		head->left = node;
		
	}
	
	head = node;
	
	binaryTreeToDLL(right,head);
}



void smallest(struct tree* node,int* head)
{
	if(!node) return;
	
	if(*head>=node->data)
		*head = node->data;
		

		smallest(node->left,head);
		smallest(node->right,head);
}


void findfirstleft(struct tree* node,int *ft,int elem){
	if(!node)
		 	return;
	
	if(node->data>elem)
		{
			*ft = node->data;
			findfirstleft(node->left,ft,elem);
		}
		else
			findfirstleft(node->right,ft,elem);
}


void inorderSuccesor(struct tree* node,int elem,int* head,struct tree* root)
{
	if(!node)
		return;
	
	if(node->data == elem)
	{
		if(node->right)
		{
			int smal = 999;
			smallest(node->right,&smal);
			*head = smal;
		}
		else
		{
			int ftLeft = NULL;
			findfirstleft(root,&ftLeft,elem);
			*head = ftLeft;
			if(ftLeft==NULL)
				printf("This is the Last element of the tree in inorder successor %d",node->data);
		}
	}
	if(node->data<elem)
	{
		inorderSuccesor(node->right,elem,head,root);	
	}
	else if(node->data>elem)
	{
		inorderSuccesor(node->left,elem,head,root);	
	}		
}

void findBiggestNodeTree(struct tree* node,int *bgt){
	if(!node) return;
	
	if(node->data>=*bgt)
	{
		*bgt = node->data;
	}
	findBiggestNodeTree(node->left,bgt);
	findBiggestNodeTree(node->right,bgt);
	
}

void firstRight(struct tree* node,int elem,int* trck)
{
	if(!node) return;
	if(node->data<elem){
		*trck = node->data;
		firstRight(node->right,elem,trck);
	}
	else if(node->data>elem)
	{
		firstRight(node->left,elem,trck);
	}
}



void inorderPredecessor(struct tree* node,int *head,struct tree* root,int elem){
	if(!node) return;
	
	if(node->data==elem)
	{
		if(node->left)
		{
			int bgNt = -999;
			findBiggestNodeTree(node->left,&bgNt);
			*head = bgNt;
		}
		else
			{
				int trckpath = NULL;
				firstRight(root,node->data,&trckpath);
				*head = trckpath;
				if(trckpath==NULL)
				{
					printf("\n This is the LeftMost Element and Hence no Inorder Predecessor");
				}
			}
	}
	if(node->data>elem)
	{
		inorderPredecessor(node->left,head,root,elem);
	}
	else if(node->data<elem)
	{
		inorderPredecessor(node->right,head,root,elem);
	}
}

struct tree* newNode(int data) 
{ 
     struct tree* node = (struct tree*) 
                                  malloc(sizeof(struct tree)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 



void greatest(struct tree* node,int* head)
{
	if(!node) return;
	
	if(*head<=node->data)
		*head = node->data;
		

		greatest(node->left,head);
		greatest(node->right,head);
}

void preorder(struct tree* node)
{
	if(node==NULL)
		return;
	
	printf("\n%d",node->data);
	preorder(node->left);
	preorder(node->right);
}

void postorder(struct tree* node)
{
	if(node==NULL)
		return;
	
	
	postorder(node->left);
	postorder(node->right);
	printf("\n%d",node->data);
}

//struct tree* findrightPos(struct tree* node,int datain){
//
//	if(node==NULL)
//		return NULL;
//	if(node->data>datain)
//		{
//			printf("\nadding to left of it upar %d",node->data);
//			findrightPos(node->left,datain);
//			if(rightpos==NULL)
//			rightpos = node;
//		}
//	else if(node->data<datain)
//		{
//			printf("\nadding to right of it upar %d",node->data);
//			findrightPos(node->right,datain);
//			if(rightpos==NULL)
//			rightpos = node;
//		}
//	return rightpos;
//}

void insertnode(struct tree* node,int datain)
{
	if(node==NULL)
		return ;
	
	if(node->data>=datain)
	{
		if(node->left==NULL)
		{
			node->left=newNode(datain);
//			node->left->data = datain;
printf("\nadding to left of it %d",node->data);
		}
		else
			insertnode(node->left,datain);
	}
	else
	{
		if(node->right==NULL)
		{
			node->right=newNode(datain);
			printf("\nadding to right of it %d",node->data);
//			node->right->data= datain;
		}
		else
			insertnode(node->right,datain);
	}
	
}

void inorder(struct tree* node){
	if(node==NULL)
	return;
	
		inorder(node->left);
	
	printf("\n%d ->",node->data);
	
		inorder(node->right);
	
	
}

struct tree* createTree(int count){
	struct tree* root = NULL;
	while(count)
	{
		int val;
		struct tree* newnode = NULL;
		
		printf("\nEnter the node value");
		scanf("%d",&val);
		newnode = newNode(val);
		if(root==NULL)
		{
			root = newnode;
			printf("\nPrinting inorder");
			inorder(root);
			
		}
		else
		{
			struct tree* rightpos = NULL;
			insertnode(root,val);
//			if(nodeplace->data<val)
//			{
//				printf("\nadding to right of it %d",nodeplace->data);
//				nodeplace->right = newnode;
//			}
//			else if(nodeplace->data>val)
//			{
//				printf("\nadding to left of it %d",nodeplace->data);
//				nodeplace->left = newnode;
//			}
		}
		count--;
	}
	
	return root;
}
	
	


