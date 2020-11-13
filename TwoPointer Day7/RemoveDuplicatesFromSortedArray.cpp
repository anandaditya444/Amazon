
Time - O(n)
Space - O(n)

int remove_duplicate(int a[], int N)
{
	int idx = 1;
	for (int i = 1; i < N; i++)
	{
		if (a[i] != a[i - 1])
		{
			a[idx++] = a[i];
		}
	}
	return idx;
}