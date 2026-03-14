/*
 * Problem: 349. Intersection of Two Arrays
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/intersection-of-two-arrays/submissions/1947599995/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res_set;
        int freq[1001] = {0};
        for (int a : nums1) {
            freq[a] = 1;
        }
        for (int b : nums2) {
            if (freq[b] == 1) res_set.insert(b);
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};
