

// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
int count( int S[], int m, int n )
{
	// If n is 0 then there is 1 solution
	// (do not include any coin)
	if (n == 0)
		return 1;

	// If n is less than 0 then no
	// solution exists
	if (n < 0)
		return 0;

	// If there are no coins and n
	// is greater than 0, then no
	// solution exist
	if (m <= 0 && n >= 1)
		return 0;

	// count is sum of solutions (i)
	// including S[m-1] (ii) excluding S[m-1]
	return count( S, m - 1, n ) + count( S, m, n - S[m - 1] );
}


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