class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int C = INT_MIN; // C se chota dhoondhna padega, therefore make it MINIMUM
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < C) {
                return true;
            }

            // Bump aane par C ko update kardo
            while (!st.empty() && st.top() < nums[i] ) {
                C = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};