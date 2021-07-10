### 1931.Painting-a-Grid-With-Three-Different-Colors

题目链接： [link](https://leetcode.com/problems/painting-a-grid-with-three-different-colors/)

思路：我们可以把每一列当作一个状态，因为 m <= 5, 每一列的状态数是 3^m <= 243, 其中符合条件的数量 <=48 (3\*2\*2\*2\*2)。 我们可以用一个三进制数来表示每一列的颜色，e.g. [01010]。    

所以第一步的思路是给定m，找出所有可能的状态。比如，[11011] 就不是一个有效的状态。    

第二步的就是状态转移方程，如何从 i-1 转移到 i。注意到，当我们计算第i列的某个状态s的时候，唯一的条件就是从i-1状态的不冲突的状态进行状态转移。所以我们需要遍历i-1的所有的状态，从中找出和当前状态不冲突的状态。相邻的位置如果颜色相同就是状态冲突。

状态转移方程:dp[i][s]=dp[i][s]+dp[i-1][t], t是和s不冲突的状态，

time complextity: O(n\*m\*m)

**Solution 1**

<details>
<summary>solution</summary>

```C++
// time complexity: O(n * m * m)
// space complexity: O(n)
class Solution {
public:
    const long long MOD = 1e9+7;
    int colorTheGrid(int m, int n) {
        // step 1: find all valid states
        vector<int> states;
        for (int i = 0; i < pow(3, m); ++i) {
            if (isValidState(i, m)) {
                states.push_back(i);
            }
        }
        // step 2: dp
        const int k = states.size();
        vector<long long> dp(k, 1L);
        for (int i = 1; i < n; ++i) {
            vector<long long> dpNew(k, 0L); //注意这个如果放在外面的话，每次都要清零...
            for (int s = 0; s < states.size(); ++s) {
                int curState = states[s];
                for (int t = 0; t < states.size(); ++t) {
                    int oldState = states[t];
                    if (isValidStateTransfer(oldState, curState, m)) {
                        dpNew[s] = (dpNew[s] + dp[t]) % MOD;
                    }
                }
            }
            swap(dp, dpNew);
        }
        long long result = 0L;
        for (int i = 0; i < k; ++i) {
            result = (dp[i] + result) % MOD;
        }
        return (int)result;
    }
    
private:
    bool isValidState(int state, int m) {
        vector<int> colors;
        for (int i = 0; i < m; ++i) {
            int color = state % 3;
            if (!colors.empty() && colors.back() == color) {
                return false;
            }
            colors.push_back(color);
            state = state / 3;
        }
        return true;
    }
    
    bool isValidStateTransfer(int oldState, int newState, int m) {
        for (int i = 0 ; i < m; ++i) {
            if (oldState % 3 == newState % 3) {
                return false;
            }
            oldState /= 3;
            newState /= 3;
        }
        return true;
    }
};
```

</details>