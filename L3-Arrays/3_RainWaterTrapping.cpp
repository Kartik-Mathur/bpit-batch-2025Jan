#include <iostream>
using namespace std;

int main() {

	int a[] = {0, 2, 0};
	int n = sizeof(a) / sizeof(int);

	int leftMax[100], rightMax[100];

	int ans = a[0];
	leftMax[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		leftMax[i] = ans;
		ans = max(ans, a[i]);
	}

	ans = a[n - 1];
	rightMax[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i)
	{
		rightMax[i] = ans;
		ans = max(ans, a[i]);
	}

	int totalWater = 0;
	for (int i = 0; i < n; ++i)
	{
		int minLR = min(leftMax[i], rightMax[i]);
		if (minLR - a[i] > 0) {
			totalWater += (minLR - a[i]);
		}
	}

	cout << totalWater << endl;

	return 0;
}



/*
// Leetcode Submission:

class Solution {
public:
    int trap(vector<int>& a) {
        int leftMax[50001], rightMax[50001];
        int n = a.size();
        int ans = a[0];
        leftMax[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            leftMax[i] = ans;
            ans = max(ans, a[i]);
        }

        ans = a[n - 1];
        rightMax[n-1] = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            rightMax[i] = ans;
            ans = max(ans, a[i]);
        }

        int totalWater = 0;
        for (int i = 0; i < n; ++i)
        {
            int minLR = min(leftMax[i], rightMax[i]);
            if (minLR - a[i] > 0) {
                totalWater += (minLR - a[i]);
            }
        }

        return totalWater;
    }
};
*/














