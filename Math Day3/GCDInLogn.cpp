https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

Time Complexity: O(Log min(a, b))

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

Basic Euclidean Algorithm for GCD
The algorithm is based on below facts.

If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change. So if we keep subtracting
	repeatedly the larger of two, we end up with GCD.
	Now instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0.
