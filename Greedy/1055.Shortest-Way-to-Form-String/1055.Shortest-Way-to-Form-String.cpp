// time complexity: O(max(n, m))
class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_set<char> sourceSet;
        
        for (auto c : source) {
            sourceSet.insert(c);
        }
        const int n = source.size();
        int result = 1;
        int curIdx = 0;
        
        for (auto c : target) {
            if (!sourceSet.count(c)) {return -1;}
            bool find = false, isNewSource = false;
            int lastPos = curIdx; 
            
            while (curIdx < n || isNewSource && curIdx < lastPos) {
                if (c == source[curIdx]) {
                    find = true;
                }
                ++curIdx;
                if (curIdx == n && !isNewSource) {
                    isNewSource = true;
                    curIdx = 0;
                    result++;
                }
                if (find) { break; }
            }
        }
        
        if (curIdx == 0) {result--;}
        return result;
    }
};