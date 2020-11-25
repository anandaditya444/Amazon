
Time - O(N ^ 2)

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
	char data;
	node* left;
	node* right;
};

/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value);
node* newNode(char data);

/* Recursive function to construct binary
of size len from Inorder traversal in[]
and Preorder traversal pre[]. Initial values
of inStrt and inEnd should be 0 and len -1.
The function doesn't do any error checking
for cases where inorder and preorder do not
form a tree */
node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder
	traversal using preIndex
	and increment preIndex */
	node* tNode = newNode(pre[preIndex++]);

	/* If this node has no children then return */
	if (inStrt == inEnd)
		return tNode;

	/* Else find the index of this node in Inorder traversal */
	int inIndex = search(in, inStrt, inEnd, tNode->data);

	/* Using index in Inorder traversal, construct left and
	right subtress */
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

	return tNode;
}

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value)
{
	int i;
	for (i = strt; i <= end; i++)
	{
		if (arr[i] == value)
			return i;
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(char data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}



Efficient Approach :
We can optimize the above solution using hashing (unordered_map in C++ or HashMap in Java).
We store indexes of inorder traversal in a hash table. So that search can be done O(1) time.

Time Complexity : O(n)


/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(char data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* Recursive function to construct binary of size
len from Inorder traversal in[] and Preorder traversal
pre[]. Initial values of inStrt and inEnd should be
0 and len -1. The function doesn't do any error
checking for cases where inorder and preorder
do not form a tree */
struct Node* buildTree(char in[], char pre[], int inStrt,
                       int inEnd, unordered_map<char, int>& mp)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder traversal using preIndex
	and increment preIndex */
	char curr = pre[preIndex++];
	struct Node* tNode = newNode(curr);

	/* If this node has no children then return */
	if (inStrt == inEnd)
		return tNode;

	/* Else find the index of this node in Inorder traversal */
	int inIndex = mp[curr];
}






struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}


int searchInorder(char in[], int ele, int start, int end)
{
	int i;
	for (i = start; i <= end; i++)
		if (in[i] == ele)
			return i;
}

Node* constructTree(char pre[], char in[], int start, int end)
{
	if (start > end)
		return NULL;
	static int index = 0;
	char ele = pre[index++];

	index = searchInorder(in, ele, start, end);

	Node* tnode = new Node;
	tnode->data = ele;


	if (start == end)
		return tnode;

	tnode->left = constructTree(pre, in, start, index - 1);
	tnode->right = constructTree(pre, in, index + 1, end);

	return tnode;
}