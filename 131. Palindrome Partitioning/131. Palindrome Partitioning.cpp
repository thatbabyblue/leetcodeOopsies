/*
 * Problem: 131. Palindrome Partitioning
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/palindrome-partitioning/submissions/1925141701/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    void backtracking(string& s, int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    bool isPalindrome(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        backtracking(s, 0);
        return res;
    }
};
