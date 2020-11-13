

struct Node
{
	int data;
	Node* left;
	Mode* right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class BSTIt {
private:
	stack<Node*>st;
public:
	BSTIt(Node* root)
	{
		Node* cur = root;
		while (cur != NULL)
			st.push(cur), cur = cur->left;
	}

	// Function to return pointer to
	// current element
	// Time complexity - O(1)
	Node* curr()
	{
		return st.top();
	}

	// Function to iterate to next element
	// of BST
	// Time complexity - O(1) on all aaverage calls
	// O(h) for a single call in worst case
	Node* isNext()
	{
		Node* temp = st.top()->right;
		st.pop();
		while (temp != NULL)
		{
			st.push(temp);
			temp = temp->left;
		}
	}

	// Function to check if stack is empty
	// Time complexity - O(1)
	bool isEnd()
	{
		return st.empty();
	}
}