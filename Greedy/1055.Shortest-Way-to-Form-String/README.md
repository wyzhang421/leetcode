### 1055.Shortest-Way-to-Form-String

题目链接： [link](https://leetcode.com/problems/shortest-way-to-form-string/)

题意：给定一个字符串 source 和 一个 target 字符串。

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

思路：贪心法，每次都要匹配最前面能匹配的那个字符。注意，这个代码应该可以更加优雅。

**Solution 1**

<details>
<summary>solution</summary>

```C++
// time complexity: O(max(n, m))
class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_set<char> sourceSet;
        
        for (auto c : source) {
            sourceSet.insert(c);
        }
        const int n = source.size();
        int result = 1;
        int curIdx = 0;
        
        for (auto c : target) {
            if (!sourceSet.count(c)) {return -1;}
            bool find = false, isNewSource = false;
            int lastPos = curIdx; 
            
            while (curIdx < n || isNewSource && curIdx < lastPos) {
                if (c == source[curIdx]) {
                    find = true;
                }
                ++curIdx;
                if (curIdx == n && !isNewSource) {
                    isNewSource = true;
                    curIdx = 0;
                    result++;
                }
                if (find) { break; }
            }
        }
        
        if (curIdx == 0) {result--;}
        return result;
    }
};
```

</details>