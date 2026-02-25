/*
 * Problem: 135. Candy
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/candy/submissions/1931234985/
 * Language: cpp
 * Date: 2026-02-25
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> vec(ratings.size(), 1);
        int res = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) vec[i] = vec[i - 1] + 1;
        }
        for (int j = ratings.size() - 2; j >= 0; j--) {
            if (ratings[j] > ratings[j + 1]) vec[j] = max(vec[j], vec[j + 1] + 1);
        }
        for (int i = 0; i < ratings.size(); i++) {
            res += vec[i];
        }
        return res;

    }
};
