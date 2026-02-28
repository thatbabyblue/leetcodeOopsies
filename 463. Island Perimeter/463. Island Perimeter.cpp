/*
 * Problem: 463. Island Perimeter
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/island-perimeter/submissions/1934130535/
 * Language: cpp
 * Date: 2026-02-28
 */

class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int nextx = i + dir[k][0];
                        int nexty = j + dir[k][1];
                        if (nextx < 0 
                                    || nextx >= n
                                    || nexty < 0
                                    || nexty >= m
                                    || grid[nextx][nexty] == 0)
                                    {
                                        res++;
                                    }
                    }
                }
            }
        }
        return res;
    }
};
