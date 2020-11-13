
Problem Statement - Given two strings str1 and str2 and below operations that can performed on str1.
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace

All of the above operations are of equal cost.

N - length of string1
M - length of string2

Brute force approach Time in worst case - O(3^m)

	Time - O(N*M)
	Space - O(N*M)


	const int N = 105;
int memo[N][N];

int editDistance(string s1, string s2, int m, int n)
{
	if (m == 0)
		return n;
	if (n == 0)
		return m;
	int &ans = memo[m][n];
	if (ans != -1)
		return ans;
	if (s1[m - 1] == s2[n - 1])
		return ans = editDistance(s1, s2, m - 1, n - 1);
	return ans = 1 + min(editDistance(s1, s2, m, n - 1), min(editDistance(s1, s2, m - 1, n), editDistance(s1, s2, m - 1, n - 1)));
}