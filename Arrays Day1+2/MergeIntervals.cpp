Q. 56

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int> >v;
		int n = intervals.size();
		if (n == 0)
			return v;
		sort(intervals.begin(), intervals.end(), [&](vector<int>&a, vector<int>&b) { if (a[0] == b[0]) return a[1] < b[1]; return a[0] < b[0]; });
		vector<int>res = intervals[0];
		v.push_back(res);
		for (int i = 1; i < n; i++)
		{
			if (intervals[i][0] <= v.back()[1])
				v.back()[1] = max(v.back()[1], intervals[i][1]);
			else
				v.push_back(intervals[i]);
		}
		return v;
	}
};