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
