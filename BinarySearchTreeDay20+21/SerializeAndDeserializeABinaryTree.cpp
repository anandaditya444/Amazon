Serialization is to store tree in a file so that it
can be later restored. The structure of tree must
be maintained. Deserialization is reading tree back
from file.

How to store a general Binary Tree ?
A simple solution is to store both Inorder and Preorder traversals. This solution requires requires space
twice the size of Binary Tree.
We can save space by storing Preorder traversal and a marker for NULL pointers.

void serialize(Node* root, FILE* fp)
{
	if (root == NULL)
	{
		// If current node is NULL, store NULL
		fprintf(fp, "%d", NULL);
		return;
	}

	// Else, store current node and recur for its children
	fprintf(fp, "%d", root->val);
	serialize(root->left, fp);
	serialize(root->right, fp);
}

void deserialize(Node* root, FILE* fp)
{
	int val;
	// Read next item from file. If there are no more items or next
	// item is marker, then return
	if (!fscanf(fp, "%d", &val) || val == NULL)
		return;
	root = new Node(val);
	deserialize(root->left, fp);
	deserialize(root->right, fp);
}