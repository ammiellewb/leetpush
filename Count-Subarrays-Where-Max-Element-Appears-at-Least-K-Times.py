class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        max_num = max(nums)
        count = 0
        max_freq = 0
        left = 0
        for right in range(len(nums)):
            if nums[right] == max_num:
                max_freq += 1
            while max_freq >= k:
                count += len(nums) - right
                if nums[left] == max_num:
                    max_freq -= 1
                left += 1

        return count
        
        return len(result)
