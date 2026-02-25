/*
 * Problem: 860. Lemonade Change
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/lemonade-change/submissions/1931239224/
 * Language: cpp
 * Date: 2026-02-25
 */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {
            if (bill == 5) five++;
            if (bill == 10) {
                if (five) {
                    five--;
                    ten++;
                } else return false;
            }
            if (bill == 20) {
                if (ten && five) {
                    ten--;
                    five--;
                    twenty++;
                } else if (five >= 3) {
                    five -= 3;
                    twenty++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
