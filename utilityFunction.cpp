#include<stdlib.h>
#include<stdio.h>
#include "treeper.h"


void initiateTreeModule(char username[50])
{	

	printf("\nHi %s In Trees we will Cover the following Questions.\n\n",username);
	printf("\n1. Creating a BST.");
	printf("\n2. Printing a INORDER Traversal");
	printf("\n3. Printing a POSTORDER Traversal");
	printf("\n4. Printing a PREORDER Traversal");
	printf("\n5. Checking For Balanced BST");
	printf("\n6. Converting a Binary Tree to Doubly Linked List");
	printf("\n7. Finding a smallest Element of a BST");
	printf("\n8. Finding the First Left of a node in BST");
	printf("\n9. Finding the First Right of a node in a BST");
	printf("\n10. Finding the Inorder Successor of a given node");
	printf("\n11. Finding the Biggest Node in a BST");
	printf("\n12. Finding the Inorder Predecessor of a given node");
	printf("\n13. Finding the Right Place to Insert a given node In BST");
	printf("\n14. Converting the tree into an Array Representation of the same.\n\n");
	
	printf("\nSo Please select one of these by entering the number");
	printf("\nIn order to continue OR");
	printf("Enter '-1' to go back ");
	printf("to Previous section");
	int treeChoice;
	scanf("%d",&treeChoice);
	int count;
	printf("Enter No. of nodes in the tree");
	scanf("%d",&count);
	struct tree* root = NULL;
	root = createTree(count);
			

/*
	//	These functions print Inorder/Preorder/Postorder of a tree
	//	In Order to Run them just Uncomment the following Lines.
	//
	printf("\nPrinting inorder");
	inorder(root);
	printf("\nPrinting preorder");
	preorder(root);
	printf("\nPrinting postorder");
	postorder(root);
	
	
	//	This function finds the smallest element of the tree given.
	//
	int smallst = 999;
	smallest(root,&smallst);
	printf("\n the smallest element is %d",smallst);
	
	//  This function finds the largest element of the tree given.
	//
	int grtst = -999;
	greatest(root,&grtst);
	printf("\n the greatest element is %d",grtst);
	
	//	This function helps in finding the InOrder Successor of a given
	//	node.
	//
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
	
	//	This function helps in finding the InOrder Predecessor of a given
	//	node.
	//
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
*/
	//	int isBalanced = -1;
	//	isHeightBalancedTree(root, &isBalanced);
	//	if(isBalanced)
	//		printf("\nTree seems to be Balanced");
	//	else
	//		printf("\nTree seems not  to be Balanced");
	
	struct tree **serializedArray = (struct tree**)malloc(sizeof(struct tree *)*2*count);
	for(int i=0;i<=2*count;i++)
	{
		serializedArray[i] = NULL;
	}
	serializetheTree(root,serializedArray,0);
	printf("\nPrinting the serialized array:");
	for(int i=0;i<=2*count;i++)
	{
		if(serializedArray[i])
		{
			if(i==0)
				printf("%d",serializedArray[i]->data);
			else	
				printf("-> %d",serializedArray[i]->data);
		}
		else if(!serializedArray[i])
			printf("-> NULL");
	}
}

int main(){
	printf("Welcome to C Data Structures and Alogrithm Self Course...\n\n");
	printf("Please wait while all the Modules are Loaded..\n");
	char username[50];
	printf("Please remind what we should call you?\n");
	scanf("%[^\n]%*c",username);
	printf("\nThe whole Module consists of the following\n");
	printf("\n1. ARRAYS.");
	printf("\n2. Linked List.");
	printf("\n3. Stacks.");
	printf("\n4. Queues.");
	printf("\n5. Trees.");
	printf("\n6. Heaps.\n\n");
	
	int userChoiceModule;
	printf("\nHi %s Enter your choice of Module\n\n",username);
	scanf("%d",&userChoiceModule);
	switch(userChoiceModule)
	{
		case 1:
			printf("AW snap!! this section is under construction.\n");
			break;
		case 2:
			printf("AW snap!! this section is under construction\n");
			break;
		case 3:
			printf("AW snap!! sorry this section is under construction\n");
			break;
		case 4:
			printf("AW snap!! sorry this section is under construction\n");
			break;
		case 5:
			printf("KABOOOM! Get Ready for this section as it is going to be one of the Most\n");
			printf("interesting things for you to learn.\n\n");
			printf("So what you doing ?! Buckle up and Get something to solve it somewhere.");
			printf("\n\n Initiating Tree Module...");
			initiateTreeModule(username);
			break;
		case 6:
			printf("AW snap!! sorry this section is under construction\n");
			break;
	}
}
