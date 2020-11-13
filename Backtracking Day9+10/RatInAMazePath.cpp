
bool isSafe(int maze[N][M], int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 1)
		return true;
	return false;
}


bool ratInAMazePathPossibleUtil(int maze[N][M], int x, int y, int solutionMatrix[N][M])
{
	if (x == N - 1 && y == M - 1 && maze[x][y] == 1)
	{
		sol[x][y] = 1;
		return true;
	}
	if (isSafe(maze, x, y))
	{
		// mark x,y as part of solution
		sol[x][y] = 1;

		// Move forward in x direction
		if (ratInAMazePathPossibleUtil(maze, x + 1, y, solutionMatrix))
			return true;

		// If moving forward in x direction doesn't work move in
		// y direction
		if (ratInAMazePathPossibleUtil(maze, x, y + 1, solutionMatrix))
			return true;

		// If configuration fails the backtrack
		sol[x][y] = 0;
	}
	return false;
}


bool ratInAMazePathPossible(int maze[N][M], int solutionMatrix[N][M])
{
	if (ratInAMazePathPossibleUtil(maze, 0, 0, solutionMatrix))
		cout << "Path possible" < endl;
	else
		cout << "Not possible" << endl;
}