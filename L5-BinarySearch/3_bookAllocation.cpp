#include <iostream>
using namespace std;
int n, totalStudents;
int books[100005];

bool kyaBooksDistributeHoPaai(int allowedPages) {
	int pages = 0;
	int studentsCnt = 1;

	for (int i = 0; i < n; ++i)
	{
		if (pages + books[i] <= allowedPages) {
			pages += books[i];
		}
		else {
			studentsCnt++;
			pages = books[i];
		}
	}

	if (studentsCnt <= totalStudents) return true;
	else return false;
}

int bookAllocation() {
	// Finding search space
	int s = 0, e = 0;
	for (int i = 0; i < n; ++i)
	{
		s = max(s, books[i]);
		e += books[i];
	}
	int ans = 0;

	while (s <= e) {
		int mid = s + (e - s) / 2;

		if (kyaBooksDistributeHoPaai(mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	return ans;
}

int main() {

	int t; cin >> t;
	while (t--) {
		cin >> n >> totalStudents;
		for (int i = 0; i < n; ++i)
		{
			cin >> books[i];
		}

		cout << bookAllocation() << endl;
	}


	return 0;
}
















