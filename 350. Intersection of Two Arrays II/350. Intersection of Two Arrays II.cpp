/*
 * Problem: 350. Intersection of Two Arrays II
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/1947608516/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int freq[1001] = {0};
        for (int a : nums1) {
            freq[a]++;
        }
        for (int b : nums2) {
            if (freq[b] > 0) {
                res.push_back(b);
                freq[b]--;
            }
        }
        return res;
    }
};
