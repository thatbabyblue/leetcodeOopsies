/*
 * Problem: 1047. Remove All Adjacent Duplicates In String
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/1921562431/
 * Language: cpp
 * Date: 2026-02-16
 */

class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for (char c : s) {
            if (st.empty() || c != st.top()) {
                st.push(c);
            } else {
                st.pop();
            }
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
