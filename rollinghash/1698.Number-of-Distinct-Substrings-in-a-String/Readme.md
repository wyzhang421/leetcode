### 1698.Number-of-Distinct-Substrings-in-a-String

题目链接： [link](https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/)

题意：给定一个字符串，返回不同的子串数目。

思路：找出每个子串，然后放进 set 里面去重。 O(n^2) + set去重的时间

**Solution 1**

Rolling Hash

我们可以遍历substring的长度 len，然后用 len 来控制一个滑动窗口，然后计算每个子串在 sliding window 的哈希值。（相当于 encode 当前的字符串，如何 encode 就是吧当前字符串看成一个 base 26 进制的数。）

因为这是一个 sliding window, 所以计算下一个子串的 hash 的时候，可以使用当前的 hash 用 O(1) 的时间复杂度加上新字符，减去老字符，可以得到新的编码。











