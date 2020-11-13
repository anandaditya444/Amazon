

Time - O(N*K*K)
Space - O(N*K)

// we have n eggs and k floors

const int N = 55;
int memo[N][N];

int dp_eggBreaking(int n, int k)
{
	if (k == 0 || k == 1)
		return k;
	if (n == 1)
		return k;
	int &val = memo[n][k];
	if (val != -1)
		return val;
	int ans = INT_MAX;
	for (int i = 1; i <= k; i++)  // check for every floor
	{
		// Either egg breaks or doesn't breaks
		int cur = max(dp_eggBreaking(n - 1, i - 1), dp_eggBreaking(n, k - i));  consider both cases either egg breaks or doesnt break
		if (cur < ans)
			ans = cur;
	}
	return val = ans + 1;
}