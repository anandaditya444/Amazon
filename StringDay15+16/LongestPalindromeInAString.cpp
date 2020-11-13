
Time Complexity - O(N ^ 3)
Space - O(1)

Brute force method

void LongestSubstring(string s)
{
	int n = s.length();

	int mx = 0, i = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int flag = 1;
			for (int k = 0; k < (j - i + 1) / 2; k++)
			{
				if (s[i + k] != s[j - k])
				{
					flag = 0;
					break;
				}
				if (flag == 1 && j - i + 1 > mx_len)
				{
					start = i;
					mx_len = j - i + 1;
				}
			}
		}
	}

}


Dynamic Programming method

Time - O(N ^ 2)
Space - O(N ^ 2)

// This function prints the
// longest palindrome substring
// It also returns the length of
// the longest palindrome
void LongestSubstring(string s)
{
	int n = s.size();

	// table[i][j] will be false if substring
	// str[i..j] is not palindrome.
	// Else table[i][j] will be true
	int table[n][n];

	memset(table, 0, sizeof(table));

	int mx_len = 1;

	// All substrings of length 1
	// are palindromes
	for (int i = 0; i < n; i++)
		table[i][i] = 1;


	// check for sub-string of length 2
	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1])
		{
			table[i][i + 1] = 1;
			mx_len = 2;
			start = i;
		}

	// Check for lengths greater than 2.
	// k is length of substring
	for (int k = 3; k <= n; k++)
	{
		// Fix the starting index
		for (int i = 0; i < n - k + 1; i++)
		{
			// Get the ending index of substring from
			// starting index i and length k
			int j = i + k - 1;

			// checking for sub-string from ith index to
			// jth index iff str[i+1] to str[j-1] is a
			// palindrome
			if (table[i + 1][j - 1] && s[i] == s[j])
			{
				table[i][j] = 1;
				mx_len = k;
				start = i;
			}
		}
	}
}