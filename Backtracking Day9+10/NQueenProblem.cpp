Backtracking Algorithm
The idea is to place queens one by one in different columns, starting from the leftmost column.
When we place a queen in a column, we check for clashes with already placed queens. In the current
column, if we find a row for which there is no clash, we mark this row and column as part of the solution.
		If we do not find such a row due to clashes then we backtrack and return false.



// N Queen problem is the problem of finding configurations of placing N queens on an NxN chessboard so that
// no queen can attack each other

			        bool isSafe(int board[N][N], int row, int col)
			{
				// Check for the row on left side
				for (int i = 0; i < col; i++)
				{
					if (board[row][i] == 1)
						return false;
				}

				// Check upper diagonal on left side
				for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
				{
					if (board[i][j] == 1)
						return false;
				}

				// Check lower diagonal on left side
				for (int i = row, j = col; i < N && j >= 0; i++, j--)
				{
					if (board[i][j] == 1)
						return false;
				}

				return true;
			}

bool NQueen(int board[N][N], int col)
{
	if (col >= N)
		return true;

	// Consider this column and check for all the rows for this column
	for (int i = 0; i < N; i++)
	{
		if (isSafe(board, i, col))
		{
			board[i][col] = 1;

			if (NQueen(board, col + 1))
				return true;

			board[i][col] = 0;  //Backtrack
		}
	}
	return false;
}