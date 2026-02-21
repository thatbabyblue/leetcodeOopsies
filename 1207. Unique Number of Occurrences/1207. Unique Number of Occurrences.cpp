/*
 * Problem: 1207. Unique Number of Occurrences
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/unique-number-of-occurrences/submissions/1925944415/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count[2001] = {0};
        for (int i = 0; i < arr.size(); i++) {
            count[arr[i] + 1000]++;
        }
        bool freq[1001] = {false};
        for (int i = 0; i <= 2000; i++) {
            if (count[i]) {
                if (freq[count[i]] == false) freq[count[i]] = true;
                else return false;
            }
        }
        return true; 
    }
};
