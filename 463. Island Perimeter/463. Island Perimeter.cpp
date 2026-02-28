/*
 * Problem: 463. Island Perimeter
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/island-perimeter/description/
 * Language: cpp
 * Date: 2026-02-28
 */

class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        int cover = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    sum++;
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) cover++;
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) cover++;
                }
            }
        }
        return 4 * sum - 2 * cover;
    }
};
