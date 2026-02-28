/*
 * Problem: 417. Pacific Atlantic Water Flow
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/pacific-atlantic-water-flow/submissions/1934056120/
 * Language: cpp
 * Date: 2026-02-28
 */

class Solution {
public:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()) continue;
            if (heights[x][y] > heights[nextx][nexty]) continue;
            dfs(heights, visited, nextx, nexty);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
        vector<vector<bool>> secondBorder(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            dfs(heights, firstBorder, i, 0);
            dfs(heights, secondBorder, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, firstBorder, 0, j);
            dfs(heights, secondBorder, n - 1, j);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (firstBorder[i][j] && secondBorder[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};
