#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * Problem: 2841. Maximum Sum of Almost Unique Subarray
 * * 1. Description:
 * Given an integer array `nums` and two positive integers `m` and `k`, return the
 * maximum sum of any contiguous subarray of length `k` that contains at least `m`
 * distinct elements. If no such subarray exists, return 0.
 * * 2. Constraints:
 * - 1 <= nums.length <= 2 * 10^4
 * - 1 <= m <= k <= nums.length
 * - 1 <= nums[i] <= 10^9
 * * 3. Examples:
 * - Example 1: Input: nums = [2,6,7,3,1,7], m = 3, k = 4 | Output: 18
 * - Example 2: Input: nums = [5,9,9,2,4,5,4], m = 1, k = 3 | Output: 23
 */
class Solution
{
public:
    // 1. Brute Force Approach:
    long long maxSum(vector<int> &nums, int m, int k) // Time Complexity: O(N*k), Space Complexity: O(k)
    {
        //
        if (k > nums.size())
            return 0;
        // nums = [5,9,9,2,4,5,4], m = 1, k = 3 | Output: 23, size = 7
        std::vector<int> window(k, 0);
        long running_sum = 0, max_sum = 0;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            window = std::vector<int>(nums.begin() + i, nums.begin() + i + k);
            if (!is_almost_unique(window, m))
                continue;
            running_sum = nums[i];
            for (int j = i + 1; j < k + i; j++)
                running_sum += nums[j];
            if (running_sum > max_sum)
                max_sum = running_sum;
        }
        return max_sum;
    }
    bool is_almost_unique(std::vector<int> &arr, int m)
    {
        std::unordered_set<int> unique;
        for (int i = 0; i < arr.size(); i++)
        {
            unique.insert(arr[i]);
        }
        if (unique.size() >= m)
            return true;
        return false;
    }
    // 2. Sliding Window Approach
    long long maxSum(vector<int> &nums, int m, int k) // Time Complexity: O(n), Space Complexity: O(n)
    {
        // Initial-Check
        if ((k > nums.size()) or (m > k))
            return 0;
        // Create the 1st window
        long long running_sum = 0;
        std::unordered_map<int, int> number_frequeny;
        for (int i = 0; i < k; i++)
        {
            running_sum += nums[i];
            number_frequeny[nums[i]]++;
        }
        //
        long long max_sum = 0;
        if ((number_frequeny.size() >= m) and (number_frequeny.size() <= k))
            max_sum = running_sum;
        // Slide the window
        for (int i = k; i < nums.size(); i++)
        {
            // Change the frequencies
            number_frequeny[nums[i - k]]--;
            number_frequeny[nums[i]]++;
            if (number_frequeny[nums[i - k]] == 0)
                number_frequeny.erase(nums[i - k]);
            // Change the running sum
            running_sum = running_sum - nums[i - k] + nums[i];
            // Change the max_sum
            if ((number_frequeny.size() >= m) and (number_frequeny.size() <= k))
                if (running_sum > max_sum)
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
    std::vector<int> array{1, 1, 1, 3};
    s1.maxSum(array, 2, 2);
}
