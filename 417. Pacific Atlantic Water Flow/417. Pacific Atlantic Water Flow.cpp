/*
 * Problem: 417. Pacific Atlantic Water Flow
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/pacific-atlantic-water-flow/submissions/1934064128/
 * Language: cpp
 * Date: 2026-02-28
 */

class Solution {
public:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
    void bfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        queue<pair<int, int>> que;
        que.push({x, y});
        while (!que.empty()) {
            int curx = que.front().first;
            int cury = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()) continue;
                if (visited[nextx][nexty]) continue;
                if (heights[curx][cury] <= heights[nextx][nexty]) {
                    visited[nextx][nexty] = true;
                    que.push({nextx, nexty});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
        vector<vector<bool>> secondBorder(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            bfs(heights, firstBorder, i, 0);
            bfs(heights, secondBorder, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            bfs(heights, firstBorder, 0, j);
            bfs(heights, secondBorder, n - 1, j);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (firstBorder[i][j] && secondBorder[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};
