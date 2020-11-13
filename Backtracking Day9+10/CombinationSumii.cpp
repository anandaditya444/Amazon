

class Solution {
public:
	vector<vector<int> >v;
	vector<int>res;

	void combSum(vector<int> candidates, int target, int n, int start)
	{
		if (target == 0)
		{
			v.push_back(res);
			return;
		}
		if (target < 0)
			return;
		for (int i = start; i < n; i++)
		{
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			res.push_back(candidates[i]);
			combSum(candidates, target - candidates[i], n, i + 1);
			res.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		int n = candidates.size();
		combSum(candidates, target, n, 0);

		return v;
	}
};