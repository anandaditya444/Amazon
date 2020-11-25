

Time - O(N ^ 2) on average


bool findFour(int arr[], int n, int target)
{
	unordered_map<int, vector<pair<int, int> > >m;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int sum = arr[i] + arr[j];
			if (m.find(target - sum) != m.end())
			{
				auto it = m.find(target - sum);
				vector<pair<int, int> >v = it->second;

				for (int k = 0; k < v.size(); k++)
				{
					if ((i != v[k].first && j != v[k].second) && (i != v[k].second && j != v[k].first))
						return true;
				}
			}
			m[sum].push_back({i, j});
		}
	}
	m.clear();
	return false;
}