

Problem Statement - Given a set of distinct integers, nums, return all possible subsets (the power set).

        Note: The solution set must not contain duplicate subsets.

        Time - O(N * 2 ^ N) to generate all subsets and copy them back into output list.
        Space - O(N * 2 ^ N) to keep all the subsets of length N.

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
			res.push_back(nums[i]);
			backtrack(nums, n, k, i + 1);
			res.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {

		int n = nums.size();
		// Finding answers for all size of subsets starting from 0 to n.
		for (int k = 0; k <= n; k++)
		{
			res.clear();
			backtrack(nums, n, k, 0);
		}
		// int no_of_ps = (1 << n);
		// for(int i=0;i<no_of_ps;i++)
		// {
		//     res.clear();
		//     for(int j=0;j<n;j++)
		//     {
		//         if(i & (1 << j))
		//             res.push_back(nums[j]);
		//     }
		//     v.push_back(res);
		// }
		return v;
	}
};