class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long leftSum = 0;
        int validCount = 0;
        
        for (int i = 0; i<(n-1); ++i) {
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            if (leftSum >= rightSum) validCount++;
        }
        return validCount;
    }
};