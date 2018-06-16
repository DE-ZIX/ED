#include<stdio.h>
#include<stdlib.h>

/* A Binary Tree node */
struct TNode
{
	int data, lvl;
	struct TNode* left;
	struct TNode* right;
};

struct TNode* newNode(int data);

/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct TNode* sortedArrayToBST(int arr[], int start, int end)
{
	/* Base Case */
	if (start > end)
	return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	struct TNode *root = newNode(arr[mid]);

	/* Recursively construct the left subtree and make it
	left child of root */
	root->left = sortedArrayToBST(arr, start, mid-1);

	/* Recursively construct the right subtree and make it
	right child of root */
	root->right = sortedArrayToBST(arr, mid+1, end);

	return root;
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct TNode* newNode(int data)
{
	struct TNode* node = (struct TNode*)
						malloc(sizeof(struct TNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* A utility function to print preorder traversal of BST */
void preOrder(struct TNode* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

void in(struct TNode * n){
	if(n->left) in(n->left);
	printf("%d ", n->data);
	if(n->right) in(n->right);
}

// [ left, right, visit ]
void post(struct TNode * n){
	if(n->left) post(n->left);
	if(n->right) post(n->right);
	printf("%d(%d) ", n->data, n->lvl);
}

void posordem (struct TNode *n){
  if (!n->left && !n->right) {   //é folha??
		n->lvl = -1;
		return;
	}
	if(n->left) posordem(n->left);  //tem filho a esqueda?
	if(n->right) posordem(n->right);  // tem filho a direita??
	if(n->left && n->right) {
		if(n->left->lvl > n->right->lvl) n->lvl = n->left->lvl+1;
		else  n->lvl = n->right->lvl+1;
	}
	else{
		if(n->left) n->lvl = n->left->lvl + 1;
		else n->lvl = n->right->lvl + 1;
	}
}

/* Driver program to test above functions */
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int n = sizeof(arr)/sizeof(arr[0]);

	/* Convert List to BST */
	struct TNode *root = sortedArrayToBST(arr, 0, n-1);
  posordem(root);
	printf("PreOrder Traversal of constructed BST ");
	preOrder(root);
  printf("\n > IN ORDER -> ");
	in(root);
	printf("\n\n > POST ORDER -> ");
	post(root);
	return 0;
}
