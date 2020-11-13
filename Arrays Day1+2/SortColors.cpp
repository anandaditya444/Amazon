Q. 75

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int i = 0, lo = 0, hi = nums.size() - 1;
		while (i <= hi)
		{
			if (nums[i] == 0)
				swap(nums[i++], nums[lo++]);
			else if (nums[i] == 2)
				swap(nums[i], nums[hi--]);     here i is not incrementing
			else
				i++;
		}
	}
};