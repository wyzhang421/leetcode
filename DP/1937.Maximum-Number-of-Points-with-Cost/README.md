### 1937.Maximum-Number-of-Points-with-Cost

题目链接： [link](https://leetcode.com/problems/maximum-number-of-points-with-cost/)

思路：本题的dp方程需要优化，不然TLE     
dp[i][j] represents the max score you can get if you pick up the points[i][j] on the i th row      

dp[0][j] = points[0][j]      
dp[i][j] = max(dp[i-1][k] + points[i][j] - abs(j-k)), (0 <= j,k < cols)

time complextity: O(n\*m\*m)

这个思路可以继续优化成为拆开绝对值，然后分类讨论。

time complextity: O(n\*m)

```
if (k <= j)    
dp[i][j] = max(dp[i-1][k] + points[i][j] - j + k) 
         = max(dp[i-1][k] + k) + points[i][j] - j


if (k > j) 
dp[i][j] = max(dp[i-1][k] + points[i][j] - k + j)
         = max(dp[i-1][k] - k) + points[i][j] + j

we can use a rollingMax to represent the max(dp[i-1][k] + k) or max(dp[i-1][k] - k)
```

**Solution**

<details>
<summary>solution</summary>

```C++
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int m = points.size(), n = points[0].size();
        vector<long long> dp1(n, 0L), dp2(n, 0L);
        long long ans = 0L;
        for (int i = 0; i < n; ++i) {
            dp1[i] = points[0][i];
        }
        for (int i = 1; i < m; ++i) {
            long long rollingMax = LLONG_MIN;
            for (int j = 0; j < n; ++j) {
                rollingMax = max(dp1[j] + j, rollingMax);
                dp2[j] = max(rollingMax + points[i][j] - j, dp2[j]);
            }
            rollingMax = LLONG_MIN;
            for (int j = n-1; j >= 0; --j) {
                rollingMax = max(dp1[j] - j, rollingMax);
                dp2[j] = max(rollingMax + points[i][j] + j, dp2[j]);
            }
            swap(dp1, dp2);
            fill(dp2.begin(), dp2.end(), 0L); 
        }
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp1[i]);
        }
        return ans;
    }
};
```

</details>