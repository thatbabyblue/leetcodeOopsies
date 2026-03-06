/*
 * Problem: 743. Network Delay Time
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/network-delay-time/submissions/1939479492/
 * Language: cpp
 * Date: 2026-03-06
 */

class Solution {
public:
    struct Edge {
        int to;
        int val;
        Edge(int t, int w): to(t), val(w) {}
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minDist(n + 1, INT_MAX);
        vector<list<Edge>> grid(n + 1);
        for (auto& e : times) {
            grid[e[0]].push_back(Edge(e[1], e[2]));
        }
        int start = k;
        int end = n;
        minDist[start] = 0;
        queue<int> que;
        que.push(start);
        vector<bool> inQueue(n + 1, false);

        while (!que.empty()) {
            int node = que.front();
            que.pop();
            inQueue[node] = false;

            for (auto& edge : grid[node]) {
                int from = node;
                int to = edge.to;
                int delay = edge.val;
                if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + delay) {
                    minDist[to] = minDist[from] + delay;
                    if (inQueue[to] == false) {
                        que.push(to);
                        inQueue[to] = true;
                    }  
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
