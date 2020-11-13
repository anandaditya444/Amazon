class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int>dp(128,-1);
        int len = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            if(i-dp[s[i]] <= len)
                len = i-dp[s[i]];
            else
                len++;
            dp[s[i]] = i;
            ans = max(ans,len);
        }
        return ans;
    }
};