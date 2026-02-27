/*
 * Problem: 503. Next Greater Element II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/next-greater-element-ii/submissions/1932390590/
 * Language: cpp
 * Date: 2026-02-27
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        st.push(0);
        for (int i = 1; i < 2 * nums.size(); i++) {
            if (nums[i % nums.size()] <= nums[st.top()]) st.push(i % nums.size());
            else {
                while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
                    res[st.top()] = nums[i % nums.size()];
                    st.pop();
                }
                st.push(i % nums.size());
            }
        }
        return res;
    }
};
