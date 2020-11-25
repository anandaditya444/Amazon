
Time = O(N*M)
       Space = O(M)

class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		for (int i = 2; i <= n; i++)
		{
			int cnt = 1;
			int pos = 0;
			string ans = "";
			while (pos < s.size())
			{
				cnt = 1;
				while (s[pos] == s[pos + 1])
				{
					pos++, cnt++;
				}
				ans += to_string(cnt);
				ans += s[pos];
				pos++;
			}
			s = ans;
		}
		return s;
	}
};