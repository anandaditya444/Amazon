
N - size of the array
arr[N] - array
memo[N] - forr memoization purpose


Time - O(N*N)

LIS(0, -1e12)  -- Function Call

memset(memo, -1, sizeof(memo));

void LIS(int cur, int prev)
{
	if (cur > n)
		return 0;
	int &ans = memo[cur];

	if (ans != -1)
		return ans;

	if (arr[cur] > prev)
		return ans = 1 + LIS(cur + 1, arr[cur]);
	return ans = LIS(cur + 1, prev);
}