#include <iostream>
using namespace std;

bool ratInMaze(char maze[][5], int i, int j, int sol[][100], int n, int m) {
	// base case
	if (i == n - 1 and j == m - 1) {
		sol[i][j] = 1; // n-1 and m-1 bhi solution ka part honge
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return false;
	}

	// recursive case
	// Jis i,j par khade hai usse abhi solution ka part maan lo
	sol[i][j] = 1;

	// Choti maze ka kaam recursion se bolna h
	// Check right
	if (j + 1 < m and maze[i][j + 1] != 'X') {
		bool kyaRightSeBaatBani = ratInMaze(maze, i, j + 1, sol, n, m);
		if (kyaRightSeBaatBani) return true;
	}

	// Check down
	if (i + 1 < n and maze[i + 1][j] != 'X') {
		bool kyaDownSeBaatBani = ratInMaze(maze, i + 1, j, sol, n, m);
		if (kyaDownSeBaatBani) return true;
	}

	// Na toh right se raasta milla, na down se
	sol[i][j] = 0; // Backtracking
	return false;
}

int main() {

	char maze[][5] = {
		"0000",
		"00XX",
		"0000",
		"XX00",
	};

	int sol[100][100] = {0};

	ratInMaze(maze, 0, 0, sol, 4, 4);

	return 0;
}
















