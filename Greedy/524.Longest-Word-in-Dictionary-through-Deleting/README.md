### 524.Longest-Word-in-Dictionary-through-Deleting

题目链接： [link](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)

题意：给定一个字符串 s 和 一个字典 dictionary。查找字典中最长的并且是 s 子序列的字符串。如果有相同长度的结果，那么返回最小字典序的结果。

思路：遍历字典中的每个字符串，判断是否满足是 s 子序列的条件。如果满足，那么它就是一个可能的结果。

time complexity: O(m * n),   
m is the number of words in the dictionary,  
n is the length of s.  

**Solution 1**

判断一个 target 是否是 s 的子序列。

```C++
// 这个函数很重要，要记下来。
// s 是原来的字符串，target 是需要找的子序列
bool isSubsequence(string& s, string& target) {
    int targetIdx = 0;
    for (int i = 0; i < s.size() && targetIdx < target.size(); ++i) {
        if (s[i] == target[targetIdx]) {
            ++targetIdx;
        }
    }
    return targetIdx == target.size();
}
```


<details>
<summary>solution</summary>

```C++
// time complexity: O(m * n)
// m is the number of words in the dictionary
// n is the length of s
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        for (auto target : dictionary) {
            if (isSubsequence(s, target)) {
                // printf("target = %s\n", target.c_str());
                if (result.size() < target.size()) {
                    result = target;
                } else if (result.size() == target.size()) {
                    result = result > target ? target : result;
                }
            }
        }
        return result;
    }
    // 这个函数很重要，要记下来。
    bool isSubsequence(string& s, string& target) {
        int targetIdx = 0;
        for (int i = 0; i < s.size() && targetIdx < target.size(); ++i) {
            if (s[i] == target[targetIdx]) {
                ++targetIdx;
            }
        }
        return targetIdx == target.size();
    }
};
```

</details>