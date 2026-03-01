/*
 * Problem: 685. Redundant Connection II
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/redundant-connection-ii/submissions/1935125747/
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
        return father[u] == u ? u : father[u] = find(father[u]);
    }

    bool same(int u, int v) {
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

    vector<int> getRemoveEdge(vector<vector<int>>& edges) {
        init(edges.size());
        for (auto& e : edges) {
            if (same(e[0], e[1])) return e;
            else join(e[0], e[1]);
        }
        return {};
    }

    bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int deleteEdge) {
        init(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            if (i == deleteEdge) continue;
            if (same(edges[i][0], edges[i][1])) return false;
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> vec;
        int n = edges.size();
        vector<int> indegree(n + 1, 0);
        for (auto& e : edges) {
            indegree[e[1]]++;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (indegree[edges[i][1]] == 2) vec.push_back(i);
        }

        if (vec.size() > 0) {
            if (isTreeAfterRemoveEdge(edges, vec[0])) return edges[vec[0]];
            else return edges[vec[1]];
        }

        return getRemoveEdge(edges);
    }
};
