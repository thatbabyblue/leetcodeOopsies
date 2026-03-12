/*
 * Problem: 54. Spiral Matrix
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/spiral-matrix/submissions/1945586247/
 * Language: cpp
 * Date: 2026-03-12
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();
        while (left < right && top < bottom) {
            for (int j = left; j < right; j++) {
                res.push_back(matrix[top][j]);
            }
            top++;
            if (top >= bottom) break;
            for (int i = top; i < bottom; i++) {
                res.push_back(matrix[i][right - 1]);
            }
            right--;
            if (left >= right) break;
            for (int j = right - 1; j >= left; j--) {
                res.push_back(matrix[bottom - 1][j]);
            }
            bottom--;
            if (top >= bottom) break;
            for (int i = bottom - 1; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
