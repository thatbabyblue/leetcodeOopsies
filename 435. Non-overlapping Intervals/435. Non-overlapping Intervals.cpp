/*
 * Problem: 435. Non-overlapping Intervals
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/non-overlapping-intervals/submissions/1931487285/
 * Language: cpp
 * Date: 2026-02-26
 */

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[i - 1][1]) cnt++;
            else {
                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
            }
        }
        return intervals.size() - cnt;
    }
};
