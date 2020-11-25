

int merge(vector<int>&nums, int lo, int mid, int hi)
{
	int inv_cnt = 0;

	vector<int>temp(nums.size());
	int j = mid + 1;
	for (int i = lo; i <= mid; i++)
	{
		while (j <= hi && nums[i] > 2 * nums[j])
			j++;
		inv_cnt += j - mid + 1;
	}
	int i = lo, k = lo, j = mid + 1;
	while (i < mid && j <= hi)
	{
		if (nums[i] <= nums[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i < mid)
		temp[k++] = nums[i++];
	while (j <= hi)
		temp[k++] = nums[j++];
	for (int i = lo; i <= hi; i++)
		nums[i] = temp[i];

	return inv_cnt;
}

int mergeSort(vector<int>&nums, int lo, int hi)
{
	if (lo >= hi)
		return 0;
	int mid = (lo + hi) / 2;
	int inv_cnt = 0;
	inv_cnt += mergeSort(nums, lo, mid);
	inv_cnt += mergeSort(nums, mid + 1, hi);
	inv_cnt += merge(nums, lo, mid, hi);

	return inv_cnt;
}

int reversePairs(vector<int>&nums)
{
	return mergeSort(nums, 0, nums.size() - 1);

}