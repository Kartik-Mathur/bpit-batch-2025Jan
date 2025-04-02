#include <iostream>
using namespace std;


bool ratInMaze(char maze[][6], int i, int j, int sol[][100], int n, int m) {
	// base case
	if (i == n - 1 and j == m - 1) {
		sol[i][j] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		sol[i][j] = 0; // backtracking for final destination cell
		return false;
	}

	// recursive case
	// Jis i,j par khade hai usse abhi solution ka part maan lo
	sol[i][j] = 1;

	// Choti maze ka kaam recursion se bolna h
	// Check right
	if (j + 1 < m and maze[i][j + 1] != 'X' and sol[i][j + 1] == 0) {
		bool kyaRightSeBaatBani = ratInMaze(maze, i, j + 1, sol, n, m);
		if (kyaRightSeBaatBani) return true;
	}

	// Check down
	if (i + 1 < n and maze[i + 1][j] != 'X' and sol[i + 1][j] == 0) {
		bool kyaDownSeBaatBani = ratInMaze(maze, i + 1, j, sol, n, m);
		if (kyaDownSeBaatBani) return true;
	}

	// Check up
	if (i - 1 >= 0 and maze[i - 1][j] != 'X' and sol[i - 1][j] == 0) {
		bool kyaUparSeBaatBani = ratInMaze(maze, i - 1, j, sol, n, m);
		if (kyaUparSeBaatBani) return true;
	}

	// Check backwards
	if (j - 1 >= 0 and maze[i][j - 1] != 'X' and sol[i][j - 1] == 0) {
		bool kyaPeecheSeBaatBani = ratInMaze(maze, i, j - 1, sol, n, m);
		if (kyaPeecheSeBaatBani) return true;
	}

	// Na toh right se raasta milla, na down se
	sol[i][j] = 0; // Backtracking
	return false;
}

int main() {
	char maze[][6] = {
		"0X000",
		"0X0X0",
		"0X0X0",
		"000X0",
	};

	int sol[100][100] = {0};

	ratInMaze(maze, 0, 0, sol, 4, 5);

	return 0;
}
















