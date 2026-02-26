/*
 * Problem: 406. Queue Reconstruction by Height
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/queue-reconstruction-by-height/submissions/1931299210/
 * Language: cpp
 * Date: 2026-02-26
 */

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int pos = people[i][1];
            que.insert(que.begin() + pos, people[i]);
        }
        return que;
    }
};
