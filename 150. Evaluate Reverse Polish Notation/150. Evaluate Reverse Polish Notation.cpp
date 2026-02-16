/*
 * Problem: 150. Evaluate Reverse Polish Notation
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/1921567968/
 * Language: cpp
 * Date: 2026-02-16
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num1 + num2);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num1 * num2);
                if (tokens[i] == "/") st.push(num2 / num1);
            }
            else {
                st.push(stoll(tokens[i]));
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};
