

//bfs solution

class Solution {
public:

	int dx[4] = { -1, +1, 0, 0};
	int dy[4] = {0, 0, +1, -1};
	int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int>>q;
		int r = grid.size();
		int c = grid[0].size();
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (grid[i][j] == 2)
					q.push({i, j});
			}
		}
		q.push({ -1, -1});
		int minutes = 0, flag = 0;
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == -1 &&  y == -1)
			{
				if (flag)
					minutes++;
				flag = 0;
				if (!q.empty())
					q.push({ -1, -1});
				continue;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx > r - 1 || ny < 0 || ny > c - 1 || grid[nx][ny] != 1)
					continue;
				if (grid[nx][ny] == 1)
				{
					flag = 1;
					grid[nx][ny] = 2;
					q.push({nx, ny});

				}

			}

		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (grid[i][j] == 1)
					return -1;
			}
		}
		return minutes;
	}
};
