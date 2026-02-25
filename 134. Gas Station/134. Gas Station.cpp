/*
 * Problem: 134. Gas Station
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/gas-station/submissions/1931067311/
 * Language: cpp
 * Date: 2026-02-25
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int start = 0;
        int totalSum = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {
                curSum = 0;
                start = i + 1;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};
