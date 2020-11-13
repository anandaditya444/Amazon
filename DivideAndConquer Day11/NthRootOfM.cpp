

Time - O(LogM)



int binsearch(int n, int m)
{
	int lo = 1, hi = m / 2;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		int val = pow(mid, n);
		if (val == m)
			return mid;
		else if (val < m)
			lo++;
		else
			hi--;
	}
	return -1;
}


while (t--)
{
	cin >> n >> m;
	int ans = binsearch(n, m);
	cout << ans << endl;
}


