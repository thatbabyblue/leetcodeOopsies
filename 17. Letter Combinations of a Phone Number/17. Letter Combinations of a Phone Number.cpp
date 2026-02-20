/*
 * Problem: 17. Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1925027274/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    vector<string> res;
    string s;
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        res.clear();
        s.clear();
        backtracking(digits, 0);
        return res;
    }
};
