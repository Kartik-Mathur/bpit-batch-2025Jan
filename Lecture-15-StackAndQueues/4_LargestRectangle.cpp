class Solution {
public:
	int largestRectangleArea(vector<int>& a) {
		int n = a.size();
		stack<int> s;
		// PREVIOUS SMALLER
		vector<int> previousSmaller(n + 1);
		for (int i = n - 1; i >= 0; --i)
		{
			while (!s.empty() and a[i] < a[s.top()]) {
				previousSmaller[s.top()] = i;
				s.pop();
			}

			s.push(i);
		}

		while (!s.empty()) {
			previousSmaller[s.top()] = -1;
			s.pop();
		}

		// NEXT SMALLER
		vector<int> nextSmaller(n + 1);
		for (int i = 0; i < n; ++i)
		{
			while (!s.empty() and a[i] < a[s.top()]) {
				nextSmaller[s.top()] = i;
				s.pop();
			}

			s.push(i);
		}

		while (!s.empty()) {
			nextSmaller[s.top()] = n;
			s.pop();
		}

		// MAX AREA
		int area = 0;
		for (int i = 0; i < n; ++i)
		{
			area = max(area, (nextSmaller[i] - previousSmaller[i] - 1) * a[i]);
		}

		return area;
	}
};