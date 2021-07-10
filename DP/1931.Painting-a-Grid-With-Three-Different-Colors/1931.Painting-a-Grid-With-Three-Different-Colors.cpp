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