

Time - (2 ^ N) - Exponential becoz of multiple recursive calls

void O1Knapsack(int n, int wt[], int val[], int W)
{
	if (n == 0 || wt == 0)
		return 0;
	if (wt[n] > W)
		return O1Knapsack(n - 1, wt, val, W);
	return max(val[n] + O1Knapsack(n - 1, wt, val, W - wt[n]), O1Knapsack(n - 1, wt, val, W));
}


Time - O(N*W)
Space - O(N*W)


int wt[N], val[N];
int dp[N][N];

int O1Knapsack(int n, int W)
{
	if (n == 0 || W == 0)
		return 0;
	int &ans = dp[n][W];
	if (ans != -1)
		return ans;
	if (wt[n] > W)
		return ans = O1Knapsack(n - 1, W);
	return ans = max(val[n] + O1Knapsack(n - 1, W - wt[n]), O1Knapsack(n - 1, W));
}