/*
 * Problem: 787. Cheapest Flights Within K Stops
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1941223071/
 * Language: cpp
 * Date: 2026-03-07
 */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> minDist(n, INT_MAX);
        minDist[src] = 0;
        vector<int> minDistCpy(n);
        for (int i = 1; i <= k + 1; i++) {
            minDistCpy = minDist;
            for (auto& side : flights) {
                int from = side[0];
                int to = side[1];
                int price = side[2];
                if (minDistCpy[from] != INT_MAX && minDist[to] > minDistCpy[from] + price) {
                    minDist[to] = minDistCpy[from] + price;    
                }
            }
        }
        if (minDist[dst] == INT_MAX) return -1;
        return minDist[dst];
    }
};
