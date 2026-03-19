/*
 * Problem: 303. Range Sum Query - Immutable
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/range-sum-query-immutable/submissions/1952618330/
 * Language: cpp
 * Date: 2026-03-19
 */

class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for (int i = 1; i < prefix.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
