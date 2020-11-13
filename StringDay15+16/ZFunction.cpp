

Time - O(N*N)

Approach - The idea is to concatenate pattern and text, and create a string “P$T” where P is pattern, $ is a
special character should not be present in pattern and text, and T is text. Build the Z array for concatenated
string. In Z array, if Z value at any point is equal to pattern length, then pattern is present at that point.

Example:
	Pattern P = "aab",  Text T = "baabaa"

	                             The concatenated string is = "aab$baabaa"

	                                     Z array for above concatenated string is {x, 1, 0, 0, 0,
		                                                                               3, 1, 0, 2, 1} .
		                                     Since length of pattern is 3, the value 3 in Z array
		                                     indicates presence of pattern.



		                                     vector<int> Z_function(string s)
		{
			vector<int>z(n);
			for (int i = 1; i < n; i++)
			{
				while (i + z[i] < n && s[z[i]] == s[i + z[i]])
					z[i]++;
			}
			return z;
		}