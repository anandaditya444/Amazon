
int memo[N];

int cutRod(int price[], int n)
{
	if (n <= 0)
		return 0;
	int &val = memo[n];
	if (val != -1)
		return val;
	int ans = -1e9;

	for (int i = 0; i < n; i++)
	{
		ans = max(ans, price[i] + cutRod(price, n - i - 1));
		val = ans;
	}
	return val = ans;
}