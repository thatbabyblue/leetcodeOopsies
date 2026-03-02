/*
 * Problem: 1584. Min Cost to Connect All Points
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/1935257035/
 * Language: cpp
 * Date: 2026-03-02
 */

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inTree(n, false);
        int res = 0;

        minDist[0] = 0;
        for (int i = 0; i < n; i++) {
            int cur = -1;
            int minVal = INT_MAX;

            // find the closedt point that's not in the tree
            for (int j = 0; j < n; j++) {
                if (!inTree[j] && minDist[j] < minVal) {
                    minVal = minDist[j];
                    cur = j;
                }
            }

            // add it to tree
            inTree[cur] = true;

            //update the minDist

            for (int j = 0; j < n; j++) {
                if (!inTree[j]) {
                    int dis = abs(points[j][0] - points[cur][0]) + abs(points[j][1] - points[cur][1]);
                    minDist[j] = min(dis, minDist[j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            res += minDist[i];
        }
        return res;
        
    }
};
