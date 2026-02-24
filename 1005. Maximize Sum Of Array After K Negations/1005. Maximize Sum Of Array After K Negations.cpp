/*
 * Problem: 1005. Maximize Sum Of Array After K Negations
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/submissions/1929357952/
 * Language: cpp
 * Date: 2026-02-24
 */

class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -1 * nums[i];
                k--;
            }
        }
        if (k % 2) nums[nums.size() - 1] *= -1;
        int res = 0;
        for (int a : nums) res += a;
        return res;
    }
};
