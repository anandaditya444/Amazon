

Time - O(m + n)

class Solution
{
public:
	bool searchInA2DMatrix(vector<vector<int> >&mat, int target)
	{
		int r = mat.size();
		if (r == 0)
			return false;
		int c = mat[0].size();
		if (c == 0)
			return false;
		int i = 0, j = c - 1;

		while (i < r && j >= 0)
		{
			if (mat[i][j] == target)
			{
				return true;
			}
			else if (mat[i][j] > target)
				j--;
			else
				i++;
		}
		return false;
	}
};