/*
 * Problem: 743. Network Delay Time
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/network-delay-time/submissions/1937433557/
 * Language: cpp
 * Date: 2026-03-04
 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
        
        for (auto& t : times) {
            int u = t[0], v = t[1], val = t[2];
            grid[u][v] = val;
        }

        vector<int> minDist(n + 1, INT_MAX);
        vector<int> visited(n + 1, false);

        minDist[k] = 0;
        for (int i = 1; i <= n; i++) {
            int cur = -1;
            int minVal = INT_MAX;
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && minDist[j] < minVal) {
                    minVal = minDist[j];
                    cur = j;
                }
            }
            if (cur == -1) break;
            visited[cur] = true;

            for (int j = 1; j <= n; j++) {
                if (!visited[j] && grid[cur][j] < INT_MAX && minDist[cur] + grid[cur][j] < minDist[j]) {
                    minDist[j] = minDist[cur] + grid[cur][j];
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (minDist[i] == INT_MAX) return -1;
            res = max(res, minDist[i]);
        }
        return res;
    }
};
