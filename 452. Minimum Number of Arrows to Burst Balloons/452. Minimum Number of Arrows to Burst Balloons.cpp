/*
 * Problem: 452. Minimum Number of Arrows to Burst Balloons
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/1931473908/
 * Language: cpp
 * Date: 2026-02-26
 */

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int res = 1;
        for (int i = points.size() - 2; i >= 0; i--) {
            if (points[i][1] < points[i + 1][0]) res++;
            else {
                points[i][0] = max(points[i][0], points[i + 1][0]);
            }
        }
        return res;

    }
};
