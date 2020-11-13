

class Solution {
public:
	void rotateMatrix(vector<vector<int> >&mat)
	{
		int N = mat.size();

		// Transpose of the matrix
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				swap(mat[i][j], mat[j][i]);
			}
		}

		for (int i = 0; i < N; i++)
			reverse(mat[i].begin(), mat[i].end());
	}
}

different dimesnisons ?
empty vector ?
type of data ?
