if (n < 4)
{
	cout << 0 << endl;
	continue;
}
sort(arr + 1, arr + n + 1);
int a = 1, b = 2, c = n - 1, d = n;
int flag = 0;
while (a < b && b < c && c < d)
{
	int sum = arr[a] + arr[b] + arr[c] + arr[d];
	if (sum == x)
	{
		cout << 1 << endl;
		flag = 1;
		break;
	}
	else if (sum < x)
	{
		if (b < c - 1)
			b++;
		else
			a++;
	}
	else
	{
		if (c > b + 1)
			c--;
		else
			d--;
	}
}
if (flag)
	continue;
else
	cout << 0 << endl;



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