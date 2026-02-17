/*
 * Problem: 239. Sliding Window Maximum
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/sliding-window-maximum/submissions/1921628846/
 * Language: cpp
 * Date: 2026-02-17
 */

class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;
        void pop(int value) {
            if (!que.empty() && value == que.front()) que.pop_front();
        }
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};
