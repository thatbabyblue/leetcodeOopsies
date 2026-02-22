/*
 * Problem: 797. All Paths From Source to Target
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/all-paths-from-source-to-target/submissions/1927873093/
 * Language: cpp
 * Date: 2026-02-22
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(const vector<vector<int>>& graph, int x, int n) {
        if (x == n) {
            res.push_back(path);
            return;
        }
        for (int i : graph[x]) {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        path.clear();
        path.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return res;
    }
};
