
/*

    Time Complexity : O(2^N), Given a string of length N, there are N+1 ways to split it into two parts. At each
    step, we have a choice: to split or not to split. In the worse case, when all choices are to be checked, that
    results in O(2^N).

    Space Complexity : O(N), The depth of the recursion tree can go upto N.
    
    Solved using String + Backtracking + Hash Table.

*/


/***************************************** Approach 1 First Code *****************************************/

class Solution {
private:
    bool wordBreak(string s, unordered_set<string> &set){
        if(s.size() == 0){
            return true;
        }
        for(int i=0; i<s.size(); i++){
            if(set.count(s.substr(0, i+1)) && wordBreak(s.substr(i+1), set)){
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreak(s, set);
    }
};





/*

    Time Complexity : O(N^3), There are two nested loops, and substring computation at each iteration. Overall
    that results in O(N^3) time complexity.

    Space Complexity : O(N), Length of dp array is N+1.
    
    Solved using String + DP(Tabulation) + Hash Table.

*/


/***************************************** Approach 3 *****************************************/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, 0);
        dp[0] = true;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                if(dp[j] && set.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};




// We have a set of words in a dictionary.

void wordBreakUtil(string s, int n, string result)
{
	// Check for every prefix of the string
	for (int i = 1; i <= n; i++)
	{
		string prefix = s.substr(0, i);
		if (dictionary.count(prefix))
		{
			if (i == n)
			{
				result += prefix;
				cout << result << endl;
				return;
			}
			// Check for remaining string and concatenate results upto now i.e. result + prefix + " "
			wordBreakUtil(s.substr(i, n - i), n - i, result + prefix + " ");
		}
	}
}


void wordBreak(string s)
{
	int n = s.length();

	wordBreakUtil(s, n, "");
}
