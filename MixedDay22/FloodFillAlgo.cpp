

void floodFill(int x, int y)
{
	if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
		return;
	if (mat[x][y] == newC)
		return;
	if (mat[x][y] != prevC)
		return;
	mat[x][y] = newC;

	floodFill(x + 1, y);
	floodFill(x, y + 1);
	floodFill(x - 1, y);
	floodFill(x, y - 1);
}