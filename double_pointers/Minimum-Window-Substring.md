2026-Jan-10

Minimum Window Substring

![alt text](<Screenshot 2026-01-10 at 8.03.40 PM.png>)

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0 || s.size() < t.size()) {
            return "";
        }
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
        for (int i = 0; i < t.size(); i++) {
            mapT[t[i]]++;
        }  
        int tCnt = mapT.size();  
        int have = 0;
        int resStart = 0, resLen = INT_MAX;
        int left = 0, right = 0;
        while (right < s.size()) {
            if (mapT.count(s[right])) {
                mapS[s[right]]++;
                if (mapT[s[right]] == mapS[s[right]]) {
                    have++;
                }
            }
            while (have == tCnt) {
                if (right - left + 1 < resLen) {
                    resLen = right - left + 1;
                    resStart = left;
                }
                if (mapT.count(s[left])) {
                    mapS[s[left]]--;
                    if (mapT[s[left]] > mapS[s[left]]) {
                        have--;
                    }
                }
                left++;
            }
            right++;
        }
        if (resLen == INT_MAX) {
            return "";
        }
        return s.substr(resStart, resLen);

    }
};
```

Takeaway:
1. Still the sliding window.
2. Use hashtable