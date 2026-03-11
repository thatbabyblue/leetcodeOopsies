/*
 * Problem: 59. Spiral Matrix II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/spiral-matrix-ii/submissions/1944623314/
 * Language: cpp
 * Date: 2026-03-11
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int loop = n / 2;
        int startx = 0, starty = 0;
        int count = 1;
        int offset = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        while (loop--) {
            int i = startx;
            int j = starty;
            for (; j < n - offset; j++) {
                res[i][j] = count++;
            }
            for (; i < n - offset; i++) {
                res[i][j] = count++;
            }
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            for (; i > startx; i--) {
                res[i][j] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        int mid = n / 2;
        if (n % 2) res[mid][mid] = count;
        return res;
    }
};
