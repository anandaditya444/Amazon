
Time - O(N ^ 2)


/* A binary tree node has data, pointer to left
   child and a pointer to right child */
struct Node {
  int data;
  Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data);

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value);

/* Recursive function to construct binary of size n
   from  Inorder traversal in[] and Postorder traversal
   post[].  Initial values of inStrt and inEnd should
   be 0 and n -1.  The function doesn't do any error
   checking for cases where inorder and postorder
   do not form a tree */
Node* buildUtil(int in[], int post[], int inStrt,
                int inEnd, int* pIndex)
{
  // Base case
  if (inStrt > inEnd)
    return NULL;

  /* Pick current node from Postorder traversal using
     postIndex and decrement postIndex */
  Node* node = newNode(post[*pIndex]);
  (*pIndex)--;

  /* If this node has no children then return */
  if (inStrt == inEnd)
    return node;

  /* Else find the index of this node in Inorder
     traversal */
  int iIndex = search(in, inStrt, inEnd, node->data);

  /* Using index in Inorder traversal, construct left and
     right subtress */
  node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
  node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);


  return node;
}

// This function mainly initializes index of root
// and calls buildUtil()
Node* buildTree(int in[], int post[], int n)
{
  int pIndex = n - 1;
  return buildUtil(in, post, 0, n - 1, &pIndex);
}

/* Function to find index of value in arr[start...end]
   The function assumes that value is postsent in in[] */
int search(int arr[], int strt, int end, int value)
{
  int i;
  for (i = strt; i <= end; i++) {
    if (arr[i] == value)
      break;
  }
  return i;
}

/* Helper function that allocates a new node */
Node* newNode(int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = node->right = NULL;
  return (node);
}

int search(Node* root, int inorder[], int start, int end)
{
  for (int i = start; i <= end; i++)
    if (inorder[i] == root->val)
      return i;
}

Node* constructTree(int postorder[], int inorder[], int start, int end)
{
  if (start > end)
    return NULL;

  static int idx = n - 1;

  Node* node = new Node(postorder[idx--]);

  if (start == end)
    return node;

  int idxInorder = search(node, inorder, start, end);

  constructTree(postorder, inorder, start, idxInorder - 1);
  constructTree(postorder, inorder, idxInorder + 1, end);

  return node;
}