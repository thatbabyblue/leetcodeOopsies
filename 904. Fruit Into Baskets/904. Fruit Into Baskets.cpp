/*
 * Problem: 904. Fruit Into Baskets
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/fruit-into-baskets/submissions/1943595773/
 * Language: cpp
 * Date: 2026-03-10
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        int type1 = -1;
        int type2 = -1;
        int res = 0;
        int cur = 0;
        int length = 0;
        for (int right = 0; right < fruits.size(); right++) {
            cur = fruits[right];
            if (type1 == -1 || cur == type1) {
                type1 = cur;
                cnt1++;
            } else if (type2 == -1 || cur == type2) {
                type2 = cur;
                cnt2++;
            } else {
                while (cnt1 > 0 && cnt2 > 0) {
                    if (fruits[left] == type1) cnt1--;
                    else cnt2--;
                    left++;
                }
                if (cnt1 == 0) {
                    type1 = cur;
                    cnt1++;
                } else {
                    type2 = cur;
                    cnt2++;
                }
            }
            length = right - left + 1;
            res = length > res ? length : res;
        }
        return res;
    }
};
