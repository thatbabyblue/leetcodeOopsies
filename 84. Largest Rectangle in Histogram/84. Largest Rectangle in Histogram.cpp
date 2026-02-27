/*
 * Problem: 84. Largest Rectangle in Histogram
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1932580165/
 * Language: cpp
 * Date: 2026-02-27
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> minLeftIndex(size);
        vector<int> minRightIndex(size);

        minLeftIndex[0] = -1;
        for (int i = 1; i < size; i++) {
            int t = i - 1;
            while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];
            minLeftIndex[i] = t;
        }

        minRightIndex[size - 1] = size;
        for (int i = size - 2; i >= 0; i--) {
            int t = i + 1;
            while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
            minRightIndex[i] = t;
        }

        int res = 0;
        for (int i = 0; i < size; i++) {
            int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
            res = max(res, sum);
        }
        return res;
    }
};
