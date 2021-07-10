### 792.Number-of-Matching-Subsequences

题目链接： [link](https://leetcode.com/problems/number-of-matching-subsequences/)

题意：给定一个字符串 s 和 一个 words 的数组。返回 words 数组中是 s 子序列的 word。

思路：把 s 中字符出现的位置预处理成一个 hash map。然后 iterate 每一个 word 判断是否是 s 的子序列。

当寻找 word 中的字符的时候，可以二分去找当前字符出现的最前面的位置。

time complexity: O(m * n),   
m is the number of words in the dictionary,  
n is the length of s.  

**Solution 1**

<details>
<summary>solution</summary>

```C++
// time complexity: O(m*k*log(n)))
// n is the length of s
// k is the length of words, how many words in the vector
// m is the word length

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> positions;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            positions[c].push_back(i);
        }
        int result = 0;
        for (auto word : words) {
            if (isSubsequence(positions, word)) {
                result++;
            }
        }
        return result;
    }
    bool isSubsequence(unordered_map<char, vector<int>>& positions, const string& word) {
        int currentIdx = 0;
        for (char c : word) {
            if (!positions.count(c)) {return false;}
            // 找到有序数组中大于等于当前数的第一个元素
            auto iter = lower_bound(positions[c].begin(), positions[c].end(), currentIdx);
            if (iter == positions[c].end()) {
                return false;
            }
            currentIdx = *iter + 1;
        }
        return true;
    }
};
```

</details>