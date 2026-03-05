/*
 * Problem: 743. Network Delay Time
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/network-delay-time/submissions/1938446110/
 * Language: cpp
 * Date: 2026-03-05
 */

class Solution {
public:
    class mycomparison {
    public:
        bool operator()(const pair<int, int> lhs, const pair<int, int> rhs) {
            return lhs.second > rhs.second;
        }
        
    };

    struct Edge {
        int to;
        int val;

        Edge(int t, int w): to(t), val(w) {}
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<list<Edge>> grid(n + 1);
        
        for (auto& t : times) {
            int u = t[0], v = t[1], val = t[2];
            grid[u].push_back(Edge(v, val));
        }

        vector<int> minDist(n + 1, INT_MAX);
        vector<int> visited(n + 1, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;
        
        pq.push(pair<int, int>(k, 0));

        minDist[k] = 0;

        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();

            if (visited[cur.first]) continue;
            visited[cur.first] = true;

            for (Edge e : grid[cur.first]) {
                if (!visited[e.to] && minDist[cur.first] + e.val < minDist[e.to]) {
                    minDist[e.to] = minDist[cur.first] + e.val;
                    pq.push(pair<int, int>(e.to, minDist[e.to]));
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
