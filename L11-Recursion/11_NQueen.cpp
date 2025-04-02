#include <iostream>
using namespace std;

bool safeHai(int board[][100], int i, int j, int n) {
	int oi = i, oj = j;
	// Left diagonal
	while (i >= 0 and j >= 0) {
		if (board[i][j] == 1) { // Queen hai already is diagonal pr
			return false;
		}
		i--;
		j--;
	}

	// Right diagonal
	i = oi; j = oj; // wapis reset kara i and j ko unki original pos par
	while (i >= 0 and j < n) {
		if (board[i][j] == 1) { // Queen hai already is diagonal pr
			return false;
		}
		i--;
		j++;
	}

	// Columns
	i = oi;
	j = oj;
	for (int k = 0; k < i; ++k)
	{
		if (board[k][j] == 1) { // Queen hai already is column pr
			return false;
		}
	}

	return true; // Agar upar kahi bhi queen nhi hai toh safe hai
}

bool nQueen(int board[][100], int n, int i) {
	// base case
	if (i == n) {
		// We have placed n queens on board
		// print the board
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return false;
	}
	// recursive case
	for (int j = 0; j < n; ++j)
	{
		if (safeHai(board, i, j, n)) {
			board[i][j] = 1;
			bool kyaBakiQueenPlaceHui = nQueen(board, n, i + 1);
			if (kyaBakiQueenPlaceHui) return true;

			board[i][j] = 0; // Backtracking
		}
	}

	return false;
}

int main() {

	int board[100][100] = {0};
	int n = 4;

	nQueen(board, n, 0);

	return 0;
}
















