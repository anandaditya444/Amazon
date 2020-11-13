

Time - O(Logn)

Approach:
1. Calculate the medians m1 and m2 of the input arrays ar1[]
and ar2[] respectively.
2. If m1 and m2 both are equal then we are done.
return m1 ( or m2)
       3. If m1 is greater than m2, then median is present in one
       of the below two subarrays.
       a.  From first element of ar1 to m1 (ar1[0... | _n / 2_ | ])
       b.  From m2 to last element of ar2  (ar2[ | _n / 2_ | ...n - 1])
       4. If m2 is greater than m1, then median is present in one
       of the below two subarrays.
       a.  From m1 to last element of ar1  (ar1[ | _n / 2_ | ...n - 1])
       b.  From first element of ar2 to m2 (ar2[0... | _n / 2_ | ])
       5. Repeat the above process until size of both the subarrays
       becomes 2.
       6. If size of the two arrays is 2 then use below formula to get
       the median.
       Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2

                int median(int arr[], int n)
{
	// 0 based indexing
	return n % 2 == 0 ? (arr[n / 2] + arr[n / 2 - 1]) / 2 : arr[n / 2];
}

int getMedian(int arr1[], int arr2[], int n)
{
	// Invalid input
	if (n <= 0)
		return -1;
	if (n == 1)
		return (arr1[0] + arr2[0]) / 2;
	if (n == 2)
		return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;

	// Get median of the first array
	int m1 = median(arr1, n);

	// Getmedian of the second array
	int m2 = median(arr2, n);

	// If both medians are equal the return
	// either of them
	if (m1 == m2)
		return m1;

	//if m1 < m2 then median must exist between
	// arr1[m1...] to arr2[...m2]
	if (m1 < m2)
	{
		if (n % 2 == 0)
		{
			return getMedian(arr1 + n / 2 - 1, arr2, n - n / 2 + 1);
		}
		else
		{
			return getMedian(arr1 + n / 2, arr2, n - n / 2);
		}
	}

	// If m1 > m2 then median must exist between
	// arr1[...m1] to arr2[m2...]

	if (n % 2 == 0)
	{
		return getMedian(arr2 + n / 2 - 1, arr1, n - n / 2 + 1);
	}
	else
	{
		return getMedian(arr2 + n / 2, arr1, n - n / 2);
	}

}