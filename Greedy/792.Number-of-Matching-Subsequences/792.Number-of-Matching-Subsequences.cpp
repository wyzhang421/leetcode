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