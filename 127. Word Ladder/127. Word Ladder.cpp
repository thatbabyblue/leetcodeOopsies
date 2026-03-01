/*
 * Problem: 127. Word Ladder
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/word-ladder/submissions/1934167527/
 * Language: cpp
 * Date: 2026-03-01
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> visitMap;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> que;
        que.push(beginWord);
        visitMap.insert({beginWord, 1});
        while (!que.empty()) {
            string word = que.front();
            que.pop();
            int path = visitMap[word];

            for (int i = 0; i < word.size(); i++) {
                string newword = word;
                
                for (int j = 0; j < 26; j++) {
                    newword[i] = j + 'a';
                    if (wordSet.find(newword) != wordSet.end() && visitMap.find(newword) == visitMap.end()) {
                        if (newword == endWord) {
                            return path + 1;
                        }
                        que.push(newword);
                        visitMap.insert({newword, path + 1});
                    }
                }
            }
        }
        return 0;
    }
};
