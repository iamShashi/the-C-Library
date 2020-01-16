#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree* left;
	struct tree* right;
};


void printDLL(struct tree* node)
{
	while(node)
	{
		printf("\n%d",node->data);
		node = node->right;
	}
}

int findmax(int h1, int h2){
	return h1>=h2?h1:h2;
}

int findHeight(struct tree* node){
	if(!node) return 0;
	return (findmax(1+findHeight(node->left),1+findHeight(node->right)));
}

void reverseDLL(struct tree* head, struct tree* &headSt){
	struct tree* p = head;
	struct tree* q = head->right;
	while(q)
	{
//		printf("\nHere%d",p->data);
		struct tree* a;
		a = q->right;
		p->left = q;
		headSt = q;
		q->right  = p;
		q->left  = NULL;
		p = q;
		q = a;
	}
	head->right = NULL;
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

int main(){
	int count;
	printf("Enter No. of nodes in the tree");
	scanf("%d",&count);
	struct tree* root = NULL;
	while(count)
	{
		int val;
		struct tree* newnode = NULL;
//		struct tree* root = NULL;
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
	
//	struct tree *root  = newNode(1); 
//     root->left             = newNode(2); 
//     root->right           = newNode(3); 
//     root->left->left     = newNode(4); 
//     root->left->right   = newNode(5);
	
	printf("\nPrinting inorder");
	inorder(root);
	printf("\nPrinting preorder");
	preorder(root);
	printf("\nPrinting postorder");
	postorder(root);
	
	
	
//	smallest = 999;
	
	int smallst = 999;
	smallest(root,&smallst);
	printf("\n the smallest element is %d",smallst);
	
	int grtst = -999;
	greatest(root,&grtst);
	printf("\n the greatest element is %d",grtst);
	int wil=1;
	while(wil==1)
	{
		int valtoStore = -888;
		int succ;	
		printf("\nEnter the node whose succesor is wanted");
		scanf("%d",&succ);
		inorderSuccesor(root,succ,&valtoStore,root);
		printf("\nthe node succesor is %d",valtoStore);
		printf("\nEnter the will");
		scanf("%d",&wil);
	}
	
	int het = findHeight(root);
	printf("\nThe Height of the tree is %d",het);
	
	struct tree* heads = NULL;
	
	binaryTreeToDLL(root,heads);
	
	
	printf("\nprinting it initially");
	printDLL(heads);
	
	struct tree* headst = NULL;
	
	reverseDLL(heads,headst);
	
	printf("\nprinting it finally");
	printDLL(headst);
	
	
	return 0;
}
