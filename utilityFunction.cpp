#include<stdlib.h>
#include<stdio.h>
#include "treeper.h"









int main(){
	int count;
	printf("Enter No. of nodes in the tree");
	scanf("%d",&count);
	struct tree* root = NULL;
	root = createTree(count);
	
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
	wil = 1;
	while(wil==1)
	{
		int valtoStore = -888;
		int pred;	
		printf("\nEnter the node whose Predecessor is wanted");
		scanf("%d",&pred);
		inorderPredecessor(root,&valtoStore,root,pred);
		printf("\nthe node Predeccessor is %d",valtoStore);
		printf("\nEnter the will");
		scanf("%d",&wil);
	}
}
