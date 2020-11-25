
Time - O(n)
Space - O(n)

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
	vector<int>v;
	map<int, Node*>m;
	int hd = 0;
	m[0] = root;
	queue<pair<Node*, int>>q;
	q.push({root, hd});
	while (!q.empty())
	{
		pair<Node*, int> f = q.front();
		q.pop();

		if (f.first->left)
		{
			q.push({f.first->left, f.second - 1});
			m[f.second - 1] = f.first->left;
		}
		if (f.first->right)
		{
			q.push({f.first->right, f.second + 1});
			m[f.second + 1] = f.first->right;
		}
	}
	for (auto x : m)
		v.push_back(x.second->data);
	return v;
}



void bottomView(Node* root)
{
	map<Node*, int>m;
	int hd = 0;
	m[hd] = root;
	queue<pair<Node*, int> >q;
	q.push({root, hd});

	while (!q.empty())
	{
		pair<Node*, int>f = q.front();
		q.pop();

		if (f.first->left)
		{
			q.push({f.first->left, f.second - 1});
			m[f.second - 1] = f.first->left;
		}
		if (f.first->right)
		{
			q.ush({f.firat->right, f.second + 1});
			m[f.second + 1] = f.first->right;
		}
	}

}