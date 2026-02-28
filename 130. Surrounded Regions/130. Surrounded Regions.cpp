/*
 * Problem: 130. Surrounded Regions
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/surrounded-regions/submissions/1933997910/
 * Language: cpp
 * Date: 2026-02-28
 */

class Solution {
public:
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
    void bfs(vector<vector<char>>& board, int x, int y) {
        queue<pair<int, int>> que;
        board[x][y] = 'y';
        que.push({x, y});
        while (!que.empty()) {
            int curx = que.front().first;
            int cury = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= board.size() || nextx < 0 || nexty >= board[0].size()) continue;
                if (board[nextx][nexty] == 'O') {
                    board[nextx][nexty] = 'y';
                    que.push({nextx, nexty});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][m - 1] == 'O') bfs(board, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') bfs(board, 0, j);
            if (board[n - 1][j] == 'O') bfs(board, n - 1, j);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'y') board[i][j] = 'O';
            }
        }
    }
};
