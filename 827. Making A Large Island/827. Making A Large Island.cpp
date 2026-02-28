/*
 * Problem: 827. Making A Large Island
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/making-a-large-island/submissions/1934103674/
 * Language: cpp
 * Date: 2026-02-28
 */

class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int count;
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, int mark) {
        if (visited[x][y] || grid[x][y] == 0) return;
        visited[x][y] = true;
        count++;
        grid[x][y] = mark;
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            dfs(grid, visited, nextx, nexty, mark);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, false));
        unordered_map<int, int> gridNum;
        int mark = 2;
        bool allGrid = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) allGrid = false;
                if (!visited[i][j] && grid[i][j] == 1) {
                    count = 0;
                    dfs(grid, visited, i, j, mark);
                    gridNum[mark] = count;
                    mark++;
                }
            }
        }

        if (allGrid) return n * m;

        int res = 0;
        unordered_set<int> visitedGrid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count = 1;
                visitedGrid.clear();
                if (grid[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int neari = i + dir[k][0];
                        int nearj = j + dir[k][1];
                        if (neari < 0 || neari >= n || nearj < 0 || nearj >= m) continue;
                        if (visitedGrid.count(grid[neari][nearj])) continue;
                        count += gridNum[grid[neari][nearj]];
                        visitedGrid.insert(grid[neari][nearj]);
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
