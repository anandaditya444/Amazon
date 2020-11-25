

Time - O(N * LogN)
Auxiliary Space : O(N)



void verticalOrder(Node *root)
{
	if (root == NULL)
		return;
	int hd = 0;
	queue<pair<Node*, int> >q;
	map<int, Node*>mp;
	q.push({root, hd});
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		if (mp[temp.second] == 0)
			mp[temp.second] = temp.first;

		if (temp.first->left)
			q.push({temp.first->left, temp.second - 1});
		if (temp.first->right)
			q.push({temp.first->right, temp.second + 1});
	}
	for (auto x : mp)
	{
		cout << mp[x.first]->data << " ";
	}
	cout << endl;
}