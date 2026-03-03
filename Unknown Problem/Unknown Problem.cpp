/*
 * Problem: Unknown Problem
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/course-schedule-ii/submissions/1936485526/
 * Language: cpp
 * Date: 2026-03-03
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> umap;
        vector<int> indegree(numCourses, 0);
        int n = numCourses;

        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            umap[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) que.push(i);
        }

        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            res.push_back(cur);
            vector<int> courses = umap[cur];
            if (courses.size()) {
                for (int i = 0; i < courses.size(); i++) {
                    indegree[courses[i]]--;
                    if (indegree[courses[i]] == 0) que.push(courses[i]);
                }
            }
        }
        if (res.size() == n) return res;
        return {};

    }
};
