Q. Maximum Subarray

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		int cur_sum = 0, max_sum = -1e9;
		for (int i = 0; i < nums.size(); i++)
		{
			cur_sum += nums[i];
			max_sum = max(max_sum, cur_sum);
			if (cur_sum < 0)
				cur_sum = 0;
		}
		return max_sum;
	}
};