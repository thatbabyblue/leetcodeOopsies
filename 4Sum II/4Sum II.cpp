/*
 * Problem: 4Sum II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/4sum-ii/submissions/1948319688/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        int res = 0;
        for (int a : nums1) {
            for (int b : nums2) {
                map[a + b]++;
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {
                if (map.find(0 - (c + d)) != map.end()) res += map[0 - (c + d)];
            }
        }
        return res;
    }
};
