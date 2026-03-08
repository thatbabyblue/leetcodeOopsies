/*
 * Problem: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/submissions/1941261869/
 * Language: cpp
 * Date: 2026-03-08
 */

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<vector<int>>> grid(n, vector<vector<int>>(n, vector<int>(n + 1,INF)));
        for (int i = 0; i < edges.size(); i++) {
            grid[edges[i][0]][edges[i][1]][0] = edges[i][2];
            grid[edges[i][1]][edges[i][0]][0] = edges[i][2];
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j][k] = min(grid[i][j][k - 1], grid[i][k - 1][k - 1] + grid[k - 1][j][k - 1]);
                }
            }
        }

        int rescity = -1;
        int mincnt = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && grid[i][j][n] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= mincnt) {
                mincnt = cnt;
                rescity = i;
            }
        }
        return rescity;
    }
};
