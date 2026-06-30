#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * Problem: 560. Subarray Sum Equals K
 * * 1. Description:
 * Given an array of integers `nums` and an integer `k`, return the total number of
 * contiguous subarrays whose sum equals to `k`.
 * * 2. Constraints:
 * - 1 <= nums.length <= 2 * 10^4
 * - -1000 <= nums[i] <= 1000
 * - -10^7 <= k <= 10^7
 * * 3. Examples:
 * - Example 1: Input: nums = [1,1,1], k = 2 | Output: 2
 * - Example 2: Input: nums = [1,2,3], k = 3 | Output: 2
 */
class Solution
{
public:
    // 1. Brute Force Approach:
    int subarraySum(vector<int> &nums, int k) // Time complexity O(n^2), Space complexity O(1)
    {
        int running_sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            running_sum = nums[i];
            if (running_sum == k)
                count++;
            for (int j = i + 1; j < nums.size(); j++)
            {
                running_sum += nums[j];
                if (running_sum == k)
                    count++;
            }
        }
        return count;
    }
    //  Incorrect Solution: will only work for all positive vector of integers -> SLIDING WINDOW not valid here
    // WHY? removing oldest element -> does not ensure that the sum will increase or decrease, it could be both a +ve or -ve number that is subracted from the window -> no definite rule
    int subarraySum(vector<int> &nums, int k) // Time complexity O(n), Space complexity O(k)
    {
        //  * - Example 2: Input: nums = [1,1,1], k = 3 | Output: 2
        int running_sum = 0, count = 0;
        int start_ptr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            running_sum += nums[i];
            cout << "i: " << i << " running: " << running_sum << endl;
            if ((running_sum == k) or (nums[i] == k))
            {
                count++;
            }
            if (running_sum >= k)
            {
                running_sum = running_sum - nums[start_ptr++];
            }
            cout << "f     i: " << i << " running: " << running_sum << endl;
        }
        return count;
    }
    // 2. Pre-Fix sum
    int subarraySum(vector<int> &nums, int k) // Time complexity O(), Space complexity O()
    {
        //  * - Example 2: Input: nums = [1,1,1], k = 3 | Output: 2
        // 1. Calculate the pre-fix
        std::vector<int>prefix_sum(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0)
                prefix_sum[i] = prefix_sum[i - 1] + nums[i];
            prefix_sum[i] = nums[i];
        }
        std::unordered_map<int, int> sum_frequency;
        sum_frequency[k] = 0;
        // 2. Double Loop and calculate frequency
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum = prefix_sum[j] - prefix_sum[i];
                sum_frequency[sum]++;
            }
        }
        return sum_frequency[k];
    }
};
// Other Approaches:
// 1. Optimized Sliding Window (Index Mapping / Jumping Left Pointer), Time complexity: O(n), Space complexity: O(1)

int main()
{
    Solution s1 = Solution();
    std::vector<int> array{1, -1, 0};
    s1.subarraySum(array, 2);
}
