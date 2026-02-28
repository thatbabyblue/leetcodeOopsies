/*
 * Problem: 695. Max Area of Island
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/max-area-of-island/submissions/1933393647/
 * Language: cpp
 * Date: 2026-02-28
 */

class Solution {
public:
    int cnt = 0;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    void bfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});
        visited[x][y] = true;
        cnt++;
        while (!que.empty()) {
            int curx = que.front().first;
            int cury = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
                if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
                    visited[nextx][nexty] = true;
                    cnt++;
                    que.push({nextx, nexty});
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    cnt = 0;
                    bfs(grid, visited, i, j);
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};
