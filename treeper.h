#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



	/*	A structure to create a tree. Its been assumed this the
		most used structure of a node of a tree. Also tree structure
		may vary from end to end.
	*/
	
	struct tree{
		int data;
		struct tree* left;
		struct tree* right;
	};


	/*	This Function prints a doubly linked list also called
		as DLL inorder to call this function just pass the
		address of the root node as an argument.
	*/
	
	void printDLL(struct tree* node)
	{
		while(node->right)
		{
			printf("\n%d",node->data);
			node = node->right;
		}
	}


	/* This function Reverses a DLL or also called as doubly
		Linked List. In Order to call this function just pass
		head of the DLL and an address where to store the new
		Head after reversal.
	*/
	
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


	/*
		This Function is meant to check whether a given tree
		is balanced or not.In order to call this function
		you need to pass the root node and a variables
		address which will contain in binary whether the
		given tree is balanced or not.
	*/
	
	int isHeightBalancedTree(struct tree* node, int* isBalanced)
	{
		if(!node) return 0;
		int LHeight = isHeightBalancedTree(node->left,isBalanced)+1;
		int RHeight = isHeightBalancedTree(node->right,isBalanced)+1;
		LHeight+1 == RHeight ? *isBalanced = 1 : LHeight == RHeight +1 ? *isBalanced = 1 : LHeight == RHeight ? *isBalanced = 1 : *isBalanced = 0;
		return LHeight>=RHeight ? LHeight : RHeight;
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

	/*	This function is designed in order to create a Doubly Linked
		List or a DLL from a binary tree.Things to note here are:
		1. It is a simple Inorder traversal of a tree.
		2. You will have to reverse the DLL to get the final real DLL.
	*/
	
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


	/*	This Function finds the smallest Value in a tree
		It traverses each node and compares with the value
		stored in each node with the value in the head
		Pointer.
	*/
	
	void smallest(struct tree* node,int* head)
	{
		if(!node) return;
		
		if(*head>=node->data)
			*head = node->data;
			
	
			smallest(node->left,head);
			smallest(node->right,head);
	}


	/*	This function helps in finding the first left of a
		element in a binary Tree in order to call the same
		pass the root node, an address pointer to an integer
		and the elem.
	*/
	
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
	
	/*	This function finds the first InOrder Successor of 
		an element that is passed.To call this function
		pass the root node, the element itself,a pointer
		to an integer which will have the Successor at last
		, and also the node.
	*/
	
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
	
	/*	This Function finds the biggest Node of a given
		tree. In order to call this function pass the
		root node, the pointer to the integer where
		the data will be stored at last.
	*/
	
	void findBiggestNodeTree(struct tree* node,int *bgt){
		if(!node) return;
		
		if(node->data>=*bgt)
		{
			*bgt = node->data;
		}
		findBiggestNodeTree(node->left,bgt);
		findBiggestNodeTree(node->right,bgt);
		
	}
	
	/*	This Function finds the first Right element of a given
		node in a tree. In order to call this function pass
		the root node , the element whose right element is
		to be found, the pointer to integer which will have
		the node value.
	*/
	
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
	

	/*	This function finds the first InOrder Predecessor of 
		an element that is passed.To call this function
		pass the root node, the element itself,a pointer
		to an integer which will have the Predecessor at last
		, and also the node.
	*/
	
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
	
	/*	This function helps in creating a new node and
		also allocating a space for the tree at runtime
		call this function with data value and it will
		return the address of the node.
	*/
	
	struct tree* newNode(int data) 
	{ 
	     struct tree* node = (struct tree*) 
	                                  malloc(sizeof(struct tree)); 
	     node->data = data; 
	     node->left = NULL; 
	     node->right = NULL; 
	  
	     return(node); 
	} 
	
	/*	This function helps in finding the greatest
		node value in a given tree. In order to call
		this function pass the root node and also
		the pointer to integer where value will be
		kept.
	*/
	
	void greatest(struct tree* node,int* head)
	{
		if(!node) return;
		
		if(*head<=node->data)
			*head = node->data;
			
	
			greatest(node->left,head);
			greatest(node->right,head);
	}
	
	/*	This function helps in printing the PREorder
		form of a tree in order to call the same
		pass the root node of the tree.
	*/
	void preorder(struct tree* node)
	{
		if(node==NULL)
			return;
		
		printf("\n%d",node->data);
		preorder(node->left);
		preorder(node->right);
	}
	
	/*	This function helps in printing the POST order
		form of a tree in order to call the same
		pass the root node of the tree.
	*/
	
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
	
	/*	This function helps in inserting a new node in a
		BST it traverses the tree and finds the right spot
		for the same. In order to call the function
		pass the root node and the value to be inserted.
	*/
	
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
	
	/*	This function helps in printing the INorder
		form of a tree in order to call the same
		pass the root node of the tree.
	*/
	
	void inorder(struct tree* node){
		if(node==NULL)
		return;
		
			inorder(node->left);
		
		printf("\n%d ->",node->data);
		
			inorder(node->right);
		
		
	}
	
	/*	This function helps in creating a binary
		search tree in order to call the same
		pass count of the nodes to be kept in the
		tree. It asks for the value next to be 
		inserted in the tree after inserting one
		untill all the values are inserted.
		It returns the root node of the tree
		Created.
	*/
	
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
	
	/*	This function is to serialize a binary tree.
		Serialize as the name suggests it will convert
		and save the whole tree in an array. In order
		to call the same pass the root node , the
		base address of array of pointers that will
		keep the pointer to a node and index which will
		help in traversing the array during recursion.
		Initially pass 0 as index.
	*/

	void serializetheTree(struct tree* node, struct tree** &arr,int index){
		if(!node)
		{
			arr[index] = NULL;
			return;
		}
		if(node)
		arr[index] = node;
		serializetheTree(node->left, arr,index*2+1);
		serializetheTree(node->right,arr,index*2+2);
		
	}
