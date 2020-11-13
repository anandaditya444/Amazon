
Complexity Analysis:

Time complexity: O(9 ^ (n*n)).
For every unassigned index, there are 9 possible options so the time complexity is O(9 ^ (n*n)).
The time complexity remains the same but there will be some early pruning so the time taken will be
much less than the naive algorithm but the upper bound time complexity remains the same.

Space Complexity: O(n*n).
To store the output array a matrix is needed.



const int N = 9;
int board[N][N];

bool FindUnassignedLocation(int board[N][N], int &row, int &col)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool UsedInRow(int board[N][N], int row, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] == num)
            return true;
    }
    return false;
}

bool UsedInCol(int board[N][N], int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == num)
            return true;
    }
    return false;
}

bool UsedInBox(int board[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + boxStartRow][j + boxStartCol] == num)
                return true;
        }
    }
    return false;
}

bool isSafe(int board[N][N], int row, int col, int num)
{
    return !UsedInRow(board, row, num) && !UsedInCol(board, col, num)
           && !UsedInBox(board, row - row % 3, col - col % 3, num) && board[row][col] == 0;
}

bool isSudoku(int board[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(board, row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if (isSudoku(board))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}

void printSudoku(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
    }
}


if (isSudoku(board))
{
    printSudoku(board);
}
