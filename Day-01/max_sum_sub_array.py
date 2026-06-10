class Solution:    
    # -----------------------------------------------------------------------------
    '''                  # time O(n^3) , space O(1)
    def maxSubArray(self, nums: list[int]) -> int:
        sum = 0 
        max_sum = 0    # This is an assumption, a wrong one, if not fixed in the code itself
        sub_arr_len = 0 
        for main_iterations in range(len(nums)):
            sub_arr_len = sub_arr_len+1
            for inner_iterations in range(len(nums)):
                if(inner_iterations > (len(nums)-sub_arr_len)):
                    continue
                sum = 0
                for sum_iterations in range(sub_arr_len):
                    if ((sum_iterations + inner_iterations) >= (len(nums))):
                        continue
                    sum = sum + nums[sum_iterations + inner_iterations]
                    # print(sum)
                    if(sum_iterations == 0 and inner_iterations == 0 and main_iterations == 0):
                        max_sum = sum # a relative max not pre-set
                print(sum)
                if (max_sum < sum):
                    max_sum = sum 
        return max_sum 
    '''
    # -----------------------------------------------------------------------------
    '''                  # time O(n^2) , space O(1)
    def maxSubArray(self, nums: list[int]) -> int: 
        ans = nums[0]
        for i in range(len(nums)):
            cuma_sum = 0 
            for j in range(i,len(nums)):
                cuma_sum += nums[j]
                ans = max(ans,cuma_sum)
        return ans
    '''
    # ------------------------Kadane's Algorithm-----------------------------------
    def maxSubArray(self, nums: list[int]) -> int:  # time O(n) , space O(1) 
        sum = nums[0]
        max_ = nums[0]
        for i in range(1,len(nums)):
            sum = max(nums[i],sum+nums[i])
            max_ = max(sum,max_)
        return max_
    # -----------------------------------------------------------------------------
nums = [-2,1,-3,4,-1,2,1,-5,4]
s1 = Solution()
print(f"Max subarray sum is: {s1.maxSubArray(nums)}")