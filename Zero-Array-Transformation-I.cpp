class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> difference(n+1, 0);

        for (const auto& i: queries) {
            int l = i[0], r = i[1];
            difference[l]++;
            if (r+1<n) difference[r+1]--;
        }

        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += difference[i];
            nums[i] = max(0, nums[i] - curr);
        }

        
        return all_of(nums.begin(), nums.end(), [](int x) {return x==0;});
    }
};