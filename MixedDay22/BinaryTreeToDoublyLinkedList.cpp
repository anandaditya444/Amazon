
METHOD 1


The idea is to do inorder traversal of the binary tree. While doing inorder traversal, keep track of the
	previously visited node in a variable say prev. For every visited node, make it next of prev and previous
	of this node as prev.

// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
	void BinaryTree2DoubleLinkedList(node *root, node **head)
{
	// Base case
	if (root == NULL) return;

	// Initialize previously visited node as NULL. This is
	// static so that the same value is accessible in all recursive
	// calls
	static node* prev = NULL;

	// Recursively convert left subtree
	BinaryTree2DoubleLinkedList(root->left, head);

	// Now convert this node
	if (prev == NULL)
		*head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	// Finally convert right subtree
	BinaryTree2DoubleLinkedList(root->right, head);
}

Note that use of static variables like above is not a recommended practice (we have used static for simplicity).
	Imagine a situation where same function is called for two or more trees, the old value of prev would be used in
	next call for a different tree. To avoid such problems, we can use double pointer or reference to a pointer.

Time Complexity : The above program does a simple inorder traversal, so time complexity is O(n) where n is the
			number of nodes in given binary tree.





			METHOD 2






			In the following implementation, we traverse the tree in inorder fashion. We add nodes at the beginning of
			current linked list and update head of the list using pointer to head pointer. Since we insert at the beginning,
			        we need to process leaves in reverse order. For reverse order, we first traverse the right subtree before the
			        left subtree. i.e. do a reverse inorder traversal.

// A simple recursive function to convert a given
// Binary tree to Doubly Linked List
// root    --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
				        void BToDLL(Node* root, Node*& head)
			{
				// Base cases
				if (root == NULL)
					return;

				// Recursively convert right subtree
				BToDLL(root->right, head);

				// insert root into DLL
				root->right = head;

				// Change left pointer of previous head
				if (head != NULL)
					head->left = root;

				// Change head of Doubly linked list
				head = root;

				// Recursively convert left subtree
				BToDLL(root->left, head);
			}


Time Complexity: O(n), as the solution does a single traversal of given Binary Tree.