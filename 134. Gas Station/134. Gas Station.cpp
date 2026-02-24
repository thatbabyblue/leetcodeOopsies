/*
 * Problem: 134. Gas Station
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/gas-station/submissions/1929371824/
 * Language: cpp
 * Date: 2026-02-24
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < cost.size(); i++) {
            int rest = gas[i] - cost[i];
            int index = (i + 1) % cost.size(); 
            while (rest > 0 && index != i) {
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            if (rest >= 0 && index == i) return i;
        }
        return -1;
    }
};
