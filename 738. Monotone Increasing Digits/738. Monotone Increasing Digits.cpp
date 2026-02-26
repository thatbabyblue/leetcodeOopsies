/*
 * Problem: 738. Monotone Increasing Digits
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/monotone-increasing-digits/submissions/1931551514/
 * Language: cpp
 * Date: 2026-02-26
 */

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i]) {
                strNum[i - 1]--;
                flag = i;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
