

Time = O(n)
       Space = O(n)

               int count_subarray_with_given_xor(int a[], int n, int m)
{
	int xorArray[n];
	unordered_map<int, int>m;

	xorArray[0] = a[0];

	for (int i = 1; i < n; i++)
		xorArray[i] = xorArray[i - 1] ^ a[i];
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int temp = m ^ xorArray[i];

		ans += m[temp];

		if (temp == m)
			ans++;

		m[xorArray[i]]++;
	}
	return ans;
}