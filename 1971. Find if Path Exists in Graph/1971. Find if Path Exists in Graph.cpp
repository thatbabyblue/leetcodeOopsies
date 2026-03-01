/*
 * Problem: 1971. Find if Path Exists in Graph
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/1935051179/
 * Language: cpp
 * Date: 2026-03-01
 */

class Solution {
public:
    vector<int> father;

    void init(int n) {
        father.resize(n);
        for (int i = 0; i < n; i++) {
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init(n);
        for (auto& e : edges) {
            join(e[0], e[1]);
        }
        return isSame(source, destination);
    }
};
