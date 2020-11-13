

// We have a set of words in a dictionary.

void wordBreakUtil(string s, int n, string result)
{
	// Check for every prefix of the string
	for (int i = 1; i <= n; i++)
	{
		string prefix = s.substr(0, i);
		if (dictionary.count(prefix))
		{
			if (i == n)
			{
				result += prefix;
				cout << result << endl;
				return;
			}
			// Check for remaining string and concatenate results upto now i.e. result + prefix + " "
			wordBreakUtil(s.substr(i, n - i), n - i, result + prefix + " ");
		}
	}
}


void wordBreak(string s)
{
	int n = s.length();

	wordBreakUtil(s, n, "");
}