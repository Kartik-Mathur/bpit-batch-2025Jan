#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main() {

	queue<int> q[5];
	int entryPoint[5] = {0};
	int cnt = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char ch; cin >> ch;
		if (ch == 'E') {
			int courseNumber, rollNumber;
			cin >> courseNumber >> rollNumber;
			if (entryPoint[courseNumber] == 0) {
				// Yeh course wala banda pehle nhi aya koi
				q[courseNumber].push(rollNumber);
				entryPoint[courseNumber] = cnt++;
			}
			else {
				// Yeh course wale bande ka dost line mei hai
				q[courseNumber].push(rollNumber);
			}
		}
		else {
			// Iska matlab Tshirt deni hai banda bahar nikalo
			int indx;
			int ans = INT_MAX;
			for (int i = 1; i <= 4; ++i)
			{
				if (entryPoint[i] > 0 and entryPoint[i] < ans) {
					ans = entryPoint[i];
					indx = i;
				}
			}

			int courseNumber = indx;
			cout << courseNumber << " " << q[courseNumber].front() << endl;
			q[courseNumber].pop();
			if (q[courseNumber].size() == 0) {
				entryPoint[courseNumber] = 0;
			}
		}
	}

	return 0;
}
















