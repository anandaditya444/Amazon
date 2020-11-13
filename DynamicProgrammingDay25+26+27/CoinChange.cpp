
Time - O(M*N)
Space - O(M*N)


long long int dp[1005][1005];
long long int countUtil( int s[], int m, int n )
{
	if (n == 0)
		return dp[m][n] = 1;
	if (n < 0)
		return dp[m][n] = 0;
	if (m <= 0 && n >= 1)
		return dp[m][n] = 0;
	long long int &ans = dp[m][n];
	if (ans != -1)
		return ans;

	return ans = count(s, m, n - s[m - 1]) + count(s, m - 1, n);
}