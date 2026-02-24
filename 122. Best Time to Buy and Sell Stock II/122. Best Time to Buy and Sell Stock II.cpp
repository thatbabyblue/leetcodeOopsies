/*
 * Problem: 122. Best Time to Buy and Sell Stock II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/1929261995/
 * Language: cpp
 * Date: 2026-02-24
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};
