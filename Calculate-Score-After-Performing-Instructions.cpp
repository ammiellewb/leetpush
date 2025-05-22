class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long score = 0;
        int n = instructions.size();
        int i = 0;
        unordered_set<int> idxSet;
        while (i < n && i >= 0 && (idxSet.find(i) == idxSet.end())) {
            if(instructions[i] == "add") {
                score += values[i];
                idxSet.insert(i);
                i++;
                //cout << i << ", ";
            } else {
                idxSet.insert(i);
                i += values[i];
            }
        }

        return score;

    }
};