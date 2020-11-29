

m - length of string1
n - length of string2

Time - (M*N)

LCS(m, n)  --  Function Call

// We have 2 strings

void LCS(int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	int &ans = memo[m][n];

	if (ans != -1)
		return ans;

	if (s1[m - 1] == s2[n - 1])
		return ans = 1 + LCS(m - 1, n - 1);

	return ans = max(LCS(m, n - 1), LCS(m - 1, n));
}