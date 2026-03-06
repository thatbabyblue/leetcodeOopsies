/*
 * Problem: 743. Network Delay Time
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/network-delay-time/description/
 * Language: cpp
 * Date: 2026-03-06
 */

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minDist(n + 1, INT_MAX);
        int start = k;
        int end = n;
        minDist[start] = 0;
        for (int i = 1; i < n; i++) {
            for (auto& side : times) {
                int from = side[0];
                int to = side[1];
                int delay = side[2];

                if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + delay) {
                    minDist[to] = minDist[from] + delay;
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
