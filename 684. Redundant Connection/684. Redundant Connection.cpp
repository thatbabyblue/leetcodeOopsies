/*
 * Problem: 684. Redundant Connection
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/redundant-connection/submissions/1935098175/
 * Language: cpp
 * Date: 2026-03-01
 */

class Solution {
public:
    vector<int> father;
    void init(int n) {
        father.resize(1001);
        for (int i = 1; i <= n; i++) {
            father[i] = i;
        }
    }

    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init(1000);
        for (auto& e : edges) {
            if (isSame(e[0], e[1])) return e;
            else join(e[0], e[1]);
        }
        return {};
    }
};
