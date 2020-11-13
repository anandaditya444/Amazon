

Complexity Analysis

The average and best case running time of the Rabin-Karp algorithm is O(n+m),
    but its worst - case time is O(nm). Worst case of Rabin-Karp algorithm occurs when
			    all characters of pattern and text are same as the hash values of all the substrings
			    of txt[] match with hash value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.

			            void search(string pat, string txt, int q)
		{

			// d is the number of characters in the input alphabet
#define d 256

			/* pat -> pattern
			    txt -> text
			    q -> A prime number
			*/
			int m = pat.length();
			int n = txt.length();
			int p = 0; // hash value for pattern
			int t = 0; // hash value for text
			int h = 1;
			int q = 11; // Any prime number to avoid overflow

			// The value of h would be pow(d,m-1)
			for (int i = 0; i < m; i++)
				h = (h * d) % q;

			for (int i = 0; i < m; i++)
			{
				// calculating hash value for pattern and first window of txt
				p = (d * p + pat[i]) % q;
				t = (d * t + txt[i]) % q;
			}

			// Slide the pattern over text one by one
			// check for every window if size m
			for (int i = 0; i + m < n; i++)
			{
				// Check the hash values of current window of text
				// and pattern. If the hash values match then only
				// check for characters one by one
				// if hash values of pattern and text are same
				if (p == t)
				{
					// check for every character whether same or not
					for (int j = 0; j < m; j++)
					{
						if (pat[j] != txt[i + j])
							break;
					}

					// if same print occurence index
					if (j == m)
						cout << "Pattern found at index " << i << endl;
				}

				// Calculate hash value for next window of text: Remove
				// leading digit, add trailing digit
				// calculate hash value for next window of text
				if (i < n - m)
				{
					t = (d * (t - txt[i] * h) + txt[i + m]) % q;

					// doing modulo arithmetic
					if (t < 0)
						t = t + q;
				}
			}

		}