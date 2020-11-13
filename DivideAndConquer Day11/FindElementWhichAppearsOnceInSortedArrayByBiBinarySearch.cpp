

Time - O(LogN)
Space - O(1)

Approach:
A Simple Solution is to traverse the array from left to right. Since the array is sorted, we can easily
figure out the required element.

An Efficient Solution can find the required element in O(Log n) time. The idea is to use Binary Search.
Below is an observation in the input array.
All elements before the required have the first occurrence at even index (0, 2, ..) and next occurrence
at odd index (1, 3, …). And all elements after the required elements have the first occurrence at odd index
and next occurrence at even index.

1) Find the middle index, say ‘mid’.


2) If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are the same, then the required
element after ‘mid’ else before mid.

	3) If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are the same, then the required
	element after ‘mid’ else before mid.

		const int N = 1e7 + 5;
		int a[N];

		void binsearch(int a[], int lo, int hi)
	{
		if (lo > hi)
			return;
		if (lo == hi)
		{
			cout << a[lo] << endl;
			return;
		}

		int mid = lo + (hi - lo) / 2;
		if (mid % 2 == 0)
		{
			if (a[mid] == a[mid + 1])
				binsearch(a, mid + 2, hi);
			else
				binsearch(a, lo, mid);
		}
		else
		{
			if (a[mid] == a[mid - 1])
				binsearch(a, mid + 1, hi);
			else
				binsearch(a, lo, mid);
		}

	}

