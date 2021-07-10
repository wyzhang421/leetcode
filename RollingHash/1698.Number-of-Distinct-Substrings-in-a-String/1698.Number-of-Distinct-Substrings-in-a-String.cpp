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