

we need to count total combinations so in case of mere counting we can use DP solution like below as
	backtracking solution leads to TLE.

	class Solution {
	public:
		int combinationSum4(vector<int>& nums, int target) {
			vector<unsigned long long int>result(target + 1);
			int n = nums.size();
			result[0] = 1;
			for (int i = 1; i <= target; i++)
			{
				for (auto x : nums)
				{
					if (i >= x)
						result[i] += result[i - x];
				}
			}
			return result[target];
		}
	};