/*
 * Problem: 941. Valid Mountain Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-mountain-array/description/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int left = 0;
        int right = arr.size() - 1;
        while (left < arr.size() - 1 && arr[left] < arr[left + 1]) left++;
        while (right > 0 && arr[right - 1] > arr[right]) right--;
        if (left == right && left != 0 && right != arr.size() - 1) return true;
        return false;
    }
};
