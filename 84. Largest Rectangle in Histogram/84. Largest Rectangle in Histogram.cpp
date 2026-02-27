/*
 * Problem: 84. Largest Rectangle in Histogram
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1932599095/
 * Language: cpp
 * Date: 2026-02-27
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);

        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) st.push(i);
            else if (heights[i] == heights[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int left = st.top();
                        int right = i;
                        int w = right - left - 1;
                        int h = heights[mid];
                        res = max(res, h * w);
                    }
                }
                st.push(i);
            }
        }
        return res;
    }
};
