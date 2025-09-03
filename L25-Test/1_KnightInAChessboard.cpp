#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, si, sj, ei, ej;
// bool visited[1001][1001] = {0};

int x[] = { -2, -2, -1, -1, 2, 2, 1, 1};
int y[] = { -1, 1, 2, -2, 1, -1, 2, -2};

class Data {
public:
	int cost, i, j;
};

bool isValid(int i, int j) {
	if (i < 1 || j < 1 || i > n || j > n) return false;

	return true;
}


int main() {

	queue<Data> q;

	cin >> n >> ei >> ej >> si >> sj;

	vector< vector<bool > > visited(n + 1, vector<bool>(n + 1, false));

	q.push({0, si, sj});
	visited[si][sj] = true;

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		int cc = f.cost;
		int ci = f.i;
		int cj = f.j;

		if (ci == ei and cj == ej) {
			cout << cc << endl;
			return 0; // exit
		}

		for (int i = 0; i < 8; ++i)
		{
			int ni = ci + x[i];
			int nj = cj + y[i];

			if (isValid(ni, nj) and visited[ni][nj] == false) {
				q.push({cc + 1, ni, nj});
				visited[ni][nj] = true;
			}
		}
	}

	cout << -1 << endl;


	return 0;
}
















