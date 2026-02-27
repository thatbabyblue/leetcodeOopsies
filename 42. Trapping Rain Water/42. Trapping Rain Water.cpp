/*
 * Problem: 42. Trapping Rain Water
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/trapping-rain-water/submissions/1932416373/
 * Language: cpp
 * Date: 2026-02-27
 */

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int sum = 0;
        int size = height.size();
        vector<int> maxLeft(size, 0);
        vector<int> maxRight(size, 0);

        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }

        maxRight[size - 1] = height[size - 1];
        for (int j = size - 2; j >= 0; j--) {
            maxRight[j] = max(height[j], maxRight[j + 1]);
        }
        for (int i = 0; i < size; i++) {
            int cnt = min(maxLeft[i], maxRight[i]) - height[i];
            if (cnt > 0) sum += cnt;
        }
        return sum;

    }
};
