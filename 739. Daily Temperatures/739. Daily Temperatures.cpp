/*
 * Problem: 739. Daily Temperatures
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/daily-temperatures/submissions/1932295845/
 * Language: cpp
 * Date: 2026-02-27
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int len = temperatures.size();
        vector<int> answer(len, 0);
        if (len == 1) return answer;
        st.push(0);
        for (int i = 1; i < len; i++) {
            if (temperatures[i] <= temperatures[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                    int day = st.top();
                    st.pop();
                    answer[day] = i - day;
                }
                st.push(i);
            }
        }
        return answer;
    }
};
