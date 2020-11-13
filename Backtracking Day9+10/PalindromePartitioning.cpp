

Backtracking approach to print all palindromic partitions.

// A utility function to check if str is palindroem
bool isPalindrome(string str, int low, int high)
{
	while (low < high)
	{
		if (str[low] != str[high])
			return false;
		low++;
		high--;
	}
	return true;
}

// Recursive function to find all palindromic partitions of str[start..n-1]
// allPart --> A vector of vector of strings. Every vector inside it stores
//             a partition
// currPart --> A vector of strings to store current partition
void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart,
                    int start, int n, string str)
{
	// If 'start' has reached len
	if (start >= n)
	{
		allPart.push_back(currPart);
		return;
	}

	// Pick all possible ending points for substrings
	for (int i = start; i < n; i++)
	{
		// If substring str[start..i] is palindrome
		if (isPalindrome(str, start, i))
		{
			// Add the substring to result
			currPart.push_back(str.substr(start, i - start + 1));

			// Recur for remaining remaining substring
			allPalPartUtil(allPart, currPart, i + 1, n, str);

			// Remove substring str[start..i] from current
			// partition
			currPart.pop_back();
		}
	}
}



DP Solution to count all palindromic partitions


// User function Template for C++

class Solution {
public:
	int memo[505][505];
	bool isPalin(string s)
	{
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
	int cuts_Palpartition(string s, int start, int end)
	{
		if (start == end)
			return 0;
		if (isPalin(s))
			return 0;
		int &ans = memo[start][end];
		if (ans != -1)
			return ans;
		//int cuts = 1e9;
		for (int k = start; k < end; k++)
		{
			ans = min(ans, cuts_Palpartition(s, start, k) + 1 + cuts_Palpartition(s, k + 1, end));
		}
		return ans;
	}

	int palindromicPartition(string str)
	{
		memset(memo, -1, sizeof(memo));
		int ans = cuts_Palpartition(str, 0, str.size() - 1);
		return ans;
	}
};