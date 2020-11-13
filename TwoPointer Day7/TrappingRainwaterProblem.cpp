
Brute force Solution will take around O(N*N) time as for every ith index check its left and right for maximum
	and take minimum from that and subtract a[i] from it.



		DP Solution

		Time - O(n)
		Space - O(n)

		void traapedRainWater()
	{
		int left[n], right[n];
		memset(left, 0, sizeof(left));
		memset(right, 0, sizeof(right));

		left[0] = a[0];
		for (int i = 1; i < n; i++)
			left[i] = max(left[i - 1], a[i]);
		right[n - 1] = a[n - 1];
		for (int j = n - 2; j >= 0; j--)
			right[j] = max(right[j + 1], a[j]);

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += min(left[i], right[i]) - a[i];
		}
		cout << ans << endl;
	}


Time - O(N)
Space - O(1)

Space Optimization for above Solution : Instead of maintaing two arrays of size n for storing left and right max
	of each element, maintain two variables to store the maximum till that point. Since water trapped at any
	element = min(max_left, max_right) – arr[i]. Calculate water trapped on smaller element out of A[lo] and A[hi]
		          first and move the pointers till lo doesn’t cross hi.


		          int findWater(int arr[], int n)
	{
		// initialize output
		int result = 0;

		// maximum element on left and right
		int left_max = 0, right_max = 0;

		// indices to traverse the array
		int lo = 0, hi = n - 1;

		while (lo <= hi) {
			if (arr[lo] < arr[hi]) {
				if (arr[lo] > left_max)
					// update max in left
					left_max = arr[lo];
				else
					// water on curr element = max - curr
					result += left_max - arr[lo];
				lo++;
			}
			else {
				if (arr[hi] > right_max)
					// update right maximum
					right_max = arr[hi];
				else
					result += right_max - arr[hi];
				hi--;
			}
		}

		return result;
	}