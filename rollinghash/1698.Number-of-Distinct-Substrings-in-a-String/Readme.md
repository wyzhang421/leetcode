### 1698.Number-of-Distinct-Substrings-in-a-String

题目链接： [link](https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/)

题意：给定一个字符串，返回不同的子串数目。

思路：找出每个子串，然后放进 set 里面去重。 O(n^2) + set去重的时间

**Solution 1**

Rolling Hash

我们可以遍历substring的长度 len，然后用 len 来控制一个滑动窗口，然后计算每个子串在 sliding window 的哈希值。（相当于 encode 当前的字符串，如何 encode 就是吧当前字符串看成一个 base 26 进制的数。）

因为这是一个 sliding window, 所以计算下一个子串的 hash 的时候，可以使用当前的 hash 用 O(1) 的时间复杂度加上新字符，减去老字符，可以得到新的编码。

<details>
<summary>solution</summary>

```C++
// time complexity: O(n^2)
// 技巧 uint_64 的溢出取模 

typedef uint64_t ULL;

class Solution {
public:
    int countDistinct(string s) {
        const int n = s.size();
        int count = 0;
        ULL power = 1;
        // iterate substring length
        for (int len = 1; len <= n; ++len) {
            unordered_set<ULL> hashSet;
            ULL hash = 0;
            // calculate first hash 
            for (int i = 0; i < len; ++i) {
                hash = hash * 26 + (s[i] - 'a');
            }
            // continue rolling
            hashSet.insert(hash);
            for (int i = len; i < n; ++i) {
                hash = 26 * (hash - power * (s[i-len] - 'a')) + (s[i] - 'a');
                hashSet.insert(hash);
            }
            power *= 26;
            count += hashSet.size();
        }
        return count;
    }
};
```

</details>










