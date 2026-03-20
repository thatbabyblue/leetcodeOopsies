/*
 * Problem: 238. Product of Array Except Self
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/product-of-array-except-self/submissions/1953547777/
 * Language: cpp
 * Date: 2026-03-20
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[nums.size() - i - 1] = suffix[nums.size() - i] * nums[nums.size() - i];
        }
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prefix[i] * suffix[i];
        }
        return res;
    }
};
