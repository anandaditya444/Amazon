Time - O(n)
Space - O(n)

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int>m;
		int n = nums.size();
		vector<int>v;
		if (n < 2)
			return v;
		for (int i = 0; i < n; i++)
		{
			int rem = target - nums[i];
			if (m[rem] > 0)
			{
				v.push_back(m[rem] - 1);
				v.push_back(i);
				return v;
			}
			m[nums[i]] = i + 1;
		}
		return v;
	}
};