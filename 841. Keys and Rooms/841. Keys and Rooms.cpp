/*
 * Problem: 841. Keys and Rooms
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/keys-and-rooms/submissions/1934499810/
 * Language: cpp
 * Date: 2026-03-01
 */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(0);
        visited[0] = true;
        while (!que.empty()) {
            vector<int> keys = rooms[que.front()];
            que.pop();
            for (int key : keys) {
                if (!visited[key]) {
                    visited[key] = true;
                    que.push(key);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) return false;
        }
        return true;
    }
};
