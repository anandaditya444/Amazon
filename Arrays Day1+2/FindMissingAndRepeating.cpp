

int find_missing(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			return i + 1;
}

int find_repeating(int a[], int n)
{
	int ans = 1e9;
	for (int i = 0; i < n; i++)
	{
		if (a[abs(a[i]) - 1] < 0)
		{
			ans = min(ans, abs(a[i]));
			continue;
		}
		a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
	}
	return ans;
}

