
N - size of the array
arr[N] - array
memo[N] - forr memoization purpose


Time - O(N*N)


int LIS(vector<int>&nums, int* lis, int n)
{
	//int n = nums.size();
	for (int i = 0; i < n; i++)
		lis[i] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	int max = lis[0];
	for (int i = 1; i < n; i++)
		if (max < lis[i])
			max = lis[i];

	return max;

}
