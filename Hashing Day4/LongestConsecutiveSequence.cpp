Q. 128

Time - O(N*logN)
Space - O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();
        sort(nums.begin(), nums.end());
        int len = 1;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
                continue;
            if (i < nums.size() && abs(nums[i] - nums[i - 1]) == 1)
                len++;
            else
                len = 1;
            ans = max(ans, len);
        }
        return max(ans, len);
    }
};