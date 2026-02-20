/*
 * Problem: 216. Combination Sum III
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/combination-sum-iii/submissions/1925008846/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void backtracking(int k, int n, int startIndex) {
        if (path.size() == k) {
            if (sum == n) res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i);
            sum += i;
            backtracking(k, n, i + 1);
            sum -= i;
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        path.clear();
        sum = 0;
        backtracking(k, n, 1);
        return res;
    }
};
