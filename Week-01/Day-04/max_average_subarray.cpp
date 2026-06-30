#include <iostream>
#include <vector>
using namespace std;
/*
 * Problem: 643. Maximum Average Subarray I
 * * 1. Description:
 * Given an integer array `nums` of `n` elements and an integer `k`, find a
 * contiguous subarray of length `k` that has the maximum average value and
 * return this value.
 * * 2. Constraints:
 * - n == nums.length
 * - 1 <= k <= n <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 * * 3. Examples:
 * - Example 1: Input: nums = [1,12,-5,-6,50,3], k = 4 | Output: 12.75000
 * - Example 2: Input: nums = [5], k = 1 | Output: 5.00000
 */
class Solution
{
public:
    // 1. Brute Force Approach (Even though this can be considered a sliding window)
    double findMaxAverage(vector<int> &nums, int k) // Time Complexity: O(n*k), Space Complexity: O(1)
    {
        // Initial Check
        if (nums.size() < k)
            return 0;
        double average = INT_MIN, sum = INT_MIN;
        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            sum = nums[i];
            for (int j = i + 1; j < k + i; j++)
            {
                sum += nums[j];
            }
            sum = sum / k; // This step should not be here if 'a' > 'b' then 'a/c' > 'b/c' stuppid
            cout << "Sum: " << sum << endl;
            if (sum > average)
                average = sum;
        }
        cout << "Average: " << average << endl;
        return average;
    }
    // 2. Sliding Window Approach
    double findMaxAverage(vector<int> &nums, int k) // Time Complexity: O(n), Space Complexity: O(1)
    {
        // Initial Check
        if (k > nums.size())
            return 0;
        // Calculate the sum of the window, before it starts sliding
        double current_sum = 0;
        for (int i = 0; i < k; i++)
        {
            current_sum += nums[i];
        }
        double max_sum = current_sum;
        // Now we slide the window
        for (int i = 0; i < nums.size() - k; i++)
        {
            current_sum = current_sum - nums[i] + nums[k + i];
            if (current_sum > max_sum)
                max_sum = current_sum;
        }
        double average = (max_sum / k);
        return average;
    }
};
// Other Approaches:
// 1. Prefix Sum Array, Time complexity: O(n), Space complexity: O(n)
// 2. In-Place Prefix Sum (Modifying Input Array), Time complexity: O(n), Space complexity: O(1)
// 3. Binary Search on Average (More common for variable length >= k, but applicable), Time complexity: O(n log(max_val - min_val)), Space complexity: O(1)
int main()
{
    Solution s1 = Solution();
    std::vector<int> array{1, 12, -5, -6, 50, 3};
    s1.findMaxAverage(array, 4);
}