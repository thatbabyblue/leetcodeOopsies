/*
 * Problem: 40. Combination Sum II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/combination-sum-ii/submissions/1925120374/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, vector<bool> used, int startIndex) {
        if (target == sum) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            used[i] = true;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, used, i + 1);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sum = 0;
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, used, 0);
        return res;
    }
};
