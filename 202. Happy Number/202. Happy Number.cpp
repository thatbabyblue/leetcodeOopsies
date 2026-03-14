/*
 * Problem: 202. Happy Number
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/happy-number/submissions/1948297202/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    int sum(int a) {
        int sum = 0;
        while (a) {
            sum += (a % 10) * (a % 10);
            a = a / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while (true) {
            n = sum(n);
            if (n == 1) return true;
            if(set.find(n) != set.end()) break;
            else set.insert(n);
        }
        return false;
    }
};
