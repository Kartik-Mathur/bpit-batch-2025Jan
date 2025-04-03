#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int board[][9], int i, int j, int n, int no) {
	// Lets check row and column
	for (int k = 0; k < n; ++k)
	{
		if (board[i][k] == no || board[k][j] == no) return false;
	}

	// Lets make n equals to sqrt(n)
	n = sqrt(n);
	// Box check
	int si = (i / n) * n;
	int sj = (j / n) * n;

	for (int i = si; i < si + n; ++i)
	{
		for (int j = sj; j < sj + n; ++j)
		{
			if (board[i][j] == no) return false;
		}
	}

	return true;
}

bool sudokuSolver(int board[][9], int i, int j, int n) {
	// base case
	if (i == n) {
		// Print the sudoku
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		return true;
	}
	// recursive case
	// What if I fill all the cells of a row
	if (j == n) return sudokuSolver(board, i + 1, 0, n);

	// What is I am on already filled cell
	if (board[i][j]) {
		return sudokuSolver(board, i, j + 1, n);
	}

	// Empty cell ka kaam
	for (int no = 1; no <= n; ++no)
	{
		if (isSafe(board, i, j, n, no)) {
			board[i][j] = no;
			bool kyaBakiSolveHua = sudokuSolver(board, i, j + 1, n);
			if (kyaBakiSolveHua) return true;

			board[i][j] = 0; // backtracking
		}
	}

	return false;
}

int main() {

	int board[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	sudokuSolver(board, 0, 0, 9);

	return 0;
}
















