

Time - O(n * n!) as there are n! permutations and printing each factorial permutation takes O(n) time.

// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string a, int l, int r)
{
	// Base case
	if (l == r)
		cout << a << endl;
	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l + 1, r);

			//backtrack
			swap(a[l], a[i]);
		}
	}
}