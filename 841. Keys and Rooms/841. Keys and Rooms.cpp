/*
 * Problem: 841. Keys and Rooms
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/keys-and-rooms/submissions/1934493043/
 * Language: cpp
 * Date: 2026-03-01
 */

class Solution {
public:
    void dfs(const vector<vector<int>>& rooms, int key, vector<bool>& visited) {
        if (visited[key]) return;
        visited[key] = true;
        for (int k : rooms[key]) {
            dfs(rooms, k, visited);
        } 
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, 0, visited);
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) return false;
        }
        return true;
    }
};
