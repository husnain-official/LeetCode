#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * Problem: 2461. Maximum Sum of Distinct Subarrays With Length K
 * * 1. Description:
 * Given an integer array `nums` and an integer `k`, find the maximum sum among all
 * contiguous subarrays of length `k` where all elements in the subarray are distinct.
 * Return the maximum sum, or 0 if no such subarray exists.
 * * 2. Constraints:
 * - 1 <= k <= nums.length <= 10^5
 * - 1 <= nums[i] <= 10^5
 * * 3. Examples:
 * - Example 1: Input: nums = [1,5,4,2,9,9,9], k = 3 | Output: 15
 * - Example 2: Input: nums = [4,4,4], k = 3 | Output: 0
 */
class Solution
{
public:
    // 1. Brute Force Approach (Simplest):
    long long maximumSubarraySum(vector<int> &nums, int k) // Time Complexity O(n*k^2), Space Complexity: O(k)
    {
        //
        if (k > nums.size())
            return 0;
        // nums = [1,5,4,3,2,9,9,9] ; {Refrence} size = 8 , k = 3 , size - k = 5, when i = 5, k+i = 8
        long long max_sum = 0;
        long long sum = 0;
        std::vector<int> window;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            window = std::vector<int>(nums.begin() + i, nums.begin() + (i + k));
            if (duplicates_exist(window))
                continue;
            sum = nums[i];
            for (int j = i + 1; j < k + i; j++)
            {
                sum += nums[j];
            }
            if (sum > max_sum)
                max_sum = sum;
        }
        return max_sum;
    }
    bool duplicates_exist(std::vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == arr[j])
                    return true;
            }
        }
        return false;
    }
    // 2. Sliding Window Approach
    long long maximumSubarraySum(vector<int> &nums, int k) // Time Complexity O(n), Space Complexity: O(unique_elements_in_nums)
    {
        // Initial check
        if (k > nums.size())
            return 0;
        // Create the 1st window;
        long long running_sum = 0;
        std::unordered_map<int, int> num_frequency;
        for (int i = 0; i < k; i++)
        {
            running_sum += nums[i];
            num_frequency[nums[i]]++;
        }
        long long max_sum = 0;
        if (num_frequency.size() == k)
            max_sum = running_sum;
        // Now move this window forward
        for (int i = k; i < nums.size(); i++)
        {
            // Readjust the frequencies
            num_frequency[nums[i - k]]--;
            num_frequency[nums[i]]++;
            if (num_frequency[nums[i - k]] == 0)
                num_frequency.erase(nums[i - k]);
            // Change the sum
            running_sum = running_sum - nums[i - k] + nums[i];
            if (num_frequency.size() == k)
                if (max_sum < running_sum)
                    max_sum = running_sum;
        }
        return max_sum;
    }
};
// Other Approaches:
// 1. Sliding Window with Frequency Array (Direct Indexing), Time complexity: O(n), Space complexity: O(max_val)
// 2. Sliding Window with Hash Set and Two Pointers (Dynamic Left Pointer), Time complexity: O(n), Space complexity: O(k)
// 3. Sliding Window Tracking Last Seen Indices, Time complexity: O(n), Space complexity: O(n)
int main()
{
    Solution s1 = Solution();
    std::vector<int> array{1, 12, -5, -6, 50, 3};
}

