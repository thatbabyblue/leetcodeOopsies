/*
 * Problem: 200. Number of Islands
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/number-of-islands/submissions/1933279037/
 * Language: cpp
 * Date: 2026-02-28
 */

class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') {
                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    visited[i][j] = true;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return res;
    }
};
