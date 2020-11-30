

If the two nodes are in different subtrees of root nodes. That is one in the left subtree and the other in the
right subtree. In this case it is clear that root node will lie in between the path from node1 to node2. So,
	      print path1 in reverse order and then path 2.


      If the nodes are in the same subtree. That is either in the left subtree or in the right subtree. In this case
		      you need to observe that path from root to the two nodes will have an intersection point before which the path
		      is common for the two nodes from the root node. Find that intersection point and print nodes from that point in
		      a similar fashion of the above case.


		      // Function to check if there is a path from root
// to the given node. It also populates
// 'arr' with the given path
		      bool getPath(Node* root, vector<int>& arr, int x)
		{
			// if root is NULL
			// there is no path
			if (!root)
				return false;

			// push the node's value in 'arr'
			arr.push_back(root->data);

			// if it is the required node
			// return true
			if (root->data == x)
				return true;

			// else check whether the required node lies
			// in the left subtree or right subtree of
			// the current node
			if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
				return true;

			// required node does not lie either in the
			// left or right subtree of the current node
			// Thus, remove current node's value from
			// 'arr'and then return false
			arr.pop_back();
			return false;
		}

// Function to print the path between
// any two nodes in a binary tree
void printPathBetweenNodes(Node* root, int n1, int n2)
{
	// vector to store the path of
	// first node n1 from root
	vector<int> path1;

	// vector to store the path of
	// second node n2 from root
	vector<int> path2;

	getPath(root, path1, n1);
	getPath(root, path2, n2);

	int intersection = -1;

	// Get intersection point
	int i = 0, j = 0;
	while (i != path1.size() || j != path2.size()) {

		// Keep moving forward until no intersection
		// is found
		if (i == j && path1[i] == path2[j]) {
			i++;
			j++;
		}
		else {
			intersection = j - 1;
			break;
		}
	}

	// Print the required path
	for (int i = path1.size() - 1; i > intersection; i--)
		cout << path1[i] << " ";

	for (int i = intersection; i < path2.size(); i++)
		cout << path2[i] << " ";
}