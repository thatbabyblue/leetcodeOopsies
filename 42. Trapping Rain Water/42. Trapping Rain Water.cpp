/*
 * Problem: 42. Trapping Rain Water
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/trapping-rain-water/submissions/1932429850/
 * Language: cpp
 * Date: 2026-02-27
 */

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int sum = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) st.push(i);
            else if (height[i] == height[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};
