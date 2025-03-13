#include <iostream>
using namespace std;

int requiredParanthas;
int n;
int cook[100005];

bool kyaSaareBanPaye(int timeAvailable) {
	int paranthasCooked = 0;

	for (int i = 0; i < n; ++i)
	{
		int r = cook[i];
		int timeTaken = 0;
		int pranathaNumber = 1;
		while (timeTaken + pranathaNumber * r <= timeAvailable) {
			timeTaken += pranathaNumber * r;
			paranthasCooked++;

			pranathaNumber++;
		}
	}

	if (paranthasCooked >= requiredParanthas) return true;
	else return false;
}

int murthalParantha() {
	int s = 0, e = 1e9;
	int ans;
	while (s <= e) {
		int mid = s + (e - s) / 2; // Integer ki range overflow na krey

		if (kyaSaareBanPaye(mid)) {
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

	cin >> requiredParanthas;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> cook[i];

	cout << murthalParantha() << endl;


	return 0;
}
















