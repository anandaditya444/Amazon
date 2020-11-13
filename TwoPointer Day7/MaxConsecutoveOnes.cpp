
Time - O(n)
Space - O(1)


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt_ones = 0;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                while (i < n && nums[i] == 1)
                {
                    cnt_ones++;
                    i++;
                }
                ans = max(ans, cnt_ones);
                cnt_ones = 0;
            }
        }
        return ans;
    }
};