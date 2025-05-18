class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int currIdx = groups[0];
        vector<string> output = {words[0],};
        for (int i = 1; i < groups.size(); ++i) {
            if (groups[i] != currIdx) {
                output.push_back(words[i]);
                currIdx = groups[i];
            }
            
        }
        return output;
    }
};