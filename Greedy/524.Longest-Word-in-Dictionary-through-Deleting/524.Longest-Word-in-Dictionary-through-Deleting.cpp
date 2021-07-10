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
