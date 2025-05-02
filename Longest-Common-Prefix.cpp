class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        for (int n = 0; n < strs[0].length(); n++) {
            for (auto& s : strs) {
                if (n == s.length() || s[n] != strs[0][n]) {
                    return result;
                }
            }
            result += strs[0][n];
        }
        return result;
    }
};