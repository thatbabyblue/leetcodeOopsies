/*
 * Problem: 1020. Number of Enclaves
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/number-of-enclaves/submissions/1933432893/
 * Language: cpp
 * Date: 2026-02-28
 */

class Solution {
public:
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        grid[x][y] = 0;
        queue<pair<int, int>> que;
        que.push({x, y});
        while (!que.empty()) {
            int curx = que.front().first;
            int cury = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
                if (grid[nextx][nexty] == 0) continue;
                if (!visited[nextx][nexty]) {
                    que.push({nextx, nexty});
                    grid[nextx][nexty] = 0;
                    visited[nextx][nexty] = true;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++) {
            if (grid[i][0] == 1) bfs(grid, visited, i, 0);
            if (grid[i][m - 1] == 1) bfs(grid, visited, i, m - 1);
        }
        
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) bfs(grid, visited, 0, j);
            if (grid[n - 1][j] == 1) bfs(grid, visited, n - 1, j);
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 1) res++;
            }
        }
        return res;
    }
};
