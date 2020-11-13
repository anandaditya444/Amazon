class Solution {
public:
    int titleToNumber(string s) {
        int n  = s.size();
        int ans = 0;
        int pos = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            ans += pow(26, pos++) * (s[i] - 'A' + 1);
        }
        return ans;
    }
};

count combination for every charater
like :
forr A B C
C needs = pow(26, 0) + s[i] - 'A' + 1
              B needs = pow(26, 1) + s[i] - 'A' + 1
                        A needs = pow(26, 2) + s[i] - 'A' + 1