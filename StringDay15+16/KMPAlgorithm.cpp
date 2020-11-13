
Time - O(N + M)
Space - O(N)
Time to build lps[] - O(N) and space - O(N)

void computeLPSArray(string pattern, int  M, int lps[])
{
	// Length of the previous longest prefix suffix
	int j = 0;

	// It is always 0
	lps[0] = 0;

	int i = 1;
	while (i < M)
	{
		if (pattern[i] == pattern[j])
		{
			j += 1;
			lps[i] = j;
			i++;
		}
		else // If pat[i] != pat[j]
		{
			if (j != 0)
			{
				j = lps[j - 1];

				// Also we do not increment i here
			}
			else  // If j == 0
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string pattern, string text)
{
	int M = pattern.length();
	int N = text.length();

	int lps[M];

	computeLPSArray(pattern, M, lps);

	int i = 0;  // index for text[]
	int j = 0;  // index for pattern[]
	while (i < N)
	{
		if (pattern[j] == text[i])
		{
			j++;
			i++;
		}
		if (j == M)
		{
			cout << "Pattern found at index " << i - j << endl;
			j = lps[j - 1];
		}

		// Mismatch after j matches
		else if (i < N && pattern[j] != text[i])
		{
			// Do not match lps[0...lps[j-1]] characters,
			// they'll match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}