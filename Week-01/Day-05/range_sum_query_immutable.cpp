#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * Problem: 303. Range Sum Query - Immutable
 * * 1. Description:
 * Implement the `NumArray` class that initializes with an integer array `nums`.
 * It must handle multiple queries to calculate the sum of the elements between
 * indices `left` and `right` inclusive.
 * * 2. Constraints:
 * - 1 <= nums.length <= 10^4
 * - -10^5 <= nums[i] <= 10^5
 * - 0 <= left <= right < nums.length
 * - At most 10^4 calls will be made to sumRange.
 * * 3. Examples:
 * - Example 1: Input: ["NumArray", "sumRange", "sumRange"], [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5]] | Output: [null, 1, -1]
 * - Example 2: Input: ["NumArray", "sumRange"], [[[1, 2, 3, 4]], [1, 3]] | Output: [null, 9]
 */
// 1. Brute Force Approach: -> 110ms on leetcode
class NumArray
{
    std::vector<int> new_nums;
    std::vector<int> prefix_sum;

public: // Time complexity O(k), k = right - left, Space complexity (n)
    NumArray(vector<int> &nums)
    {
        new_nums = move(nums);
    }
    int sumRange(int left, int right)
    {
        int sum = 0;
        for (int i = left; i <= right; i++)
            sum += new_nums[i];
        return sum;
    }
};
// 2. Pre-fix sum approach: -> 0ms on leetcode
class NumArray
{
    std::vector<int> prefix_sum;

public: // Time complexity O(n), Space complexity (n)
    NumArray(vector<int> &nums)
    {
        prefix_sum.reserve(nums.size());
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefix_sum[i] = sum;
        }
    }
    int sumRange(int left, int right)
    {
        if (left == 0)
            return (prefix_sum[right]);
        return (prefix_sum[right] - prefix_sum[left - 1]);
    }
};
// Other Approaches:

int main()
{
}
