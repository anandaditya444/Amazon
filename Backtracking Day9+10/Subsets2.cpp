

Problem statement - Given a collection of integers that might contain duplicates, nums, return
    all possible subsets (the power set).

    Note: The solution set must not contain duplicate subsets.

    Time - O(N * LogN + N * 2 ^ N)
    Space - O(N * 2 ^ N)


class Solution {
public:
	vector<vector<int> >v;
	vector<int>res;

	void backtrack(vector<int>nums, int n, int k, int start)
	{
		if (res.size() == k)
		{
			v.push_back(res);
		}
		for (int i = start; i < n; i++)
		{
			if (i > start && nums[i] == nums[i - 1])
				continue;
			res.push_back(nums[i]);
			backtrack(nums, n, k, i + 1);
			res.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());   //sort to arrange duplicate elements together
		for (int k = 0; k <= n; k++)
		{
			backtrack(nums, n, k, 0);
		}
		return v;
	}
};