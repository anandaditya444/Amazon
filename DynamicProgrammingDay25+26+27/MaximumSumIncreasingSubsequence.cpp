
Time - O(Exponential)
Space - O(1)

int maximumSumIncSubseq(int arr[], int prev, int i, int n, int sum)
{
	if (i == n)
		return sum;
	int excl = maximumSumIncSubseq(arr, prev, i + 1, n, sum);

	int incl = sum;

	if (arr[i] > prev)
	{
		incl = maximumSumIncSubseq(arr, arr[i], i + 1, n, sum + arr[i]);
	}
	return max(incl, excl);
}


Time - O(N*N)
Space - O(N*N)

int dp[N][1e5];

int maximumSumIncSubseq(int arr[], int prev, int i, int n, int sum)
{
	if (i == n)
		return sum;
	int &ans = dp[i][sum];
	if (ans != -1)
		return ans;
	int excl = maximumSumIncSubseq(arr, prev, i + 1, n, sum);

	int incl = sum;

	if (arr[i] > prev)
	{
		incl = maximumSumIncSubseq(arr, arr[i], i + 1, n, sum + arr[i]);
	}
	return ans = max(incl, excl);
}