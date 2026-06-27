#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * Problem: Two Sum
 * * 1. Description:
 * Given an array of integers `nums` and an integer `target`, return the indices of the
 * two numbers that add up to the target. Each input has exactly one valid solution,
 * and you cannot use the same element twice.
 * * 2. Constraints:
 * - 2 <= nums.length <= 10^4
 * - -10^9 <= nums[i] <= 10^9
 * - -10^9 <= target <= 10^9
 * - Only one valid answer exists.
 */
class Solution
{
public:
    //
    // 1. Brute Force Approach
    vector<int> twoSum(vector<int> &nums, int target) // Time Complexity O(n^2)  Space Complexity O(1)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    return std::vector<int>{nums[i], nums[j]};
                }
            }
        }
        return {};
    }
    // 2. Hash Map Approach (One-Pass)
    vector<int> twoSum(vector<int> &nums, int target) // Time Complexity O(n)  Space Complexity O(n)
    {
        std::unordered_map<int, int> map;
        int difference{};
        for (int i = 0; i < nums.size(); i++)
        {
            difference = target - nums[i];
            if (map.find(difference) != map.end())
                return std::vector<int>{map[difference], i};
            else
                map[nums[i]] = i;
        }
        return {};
    }
    // 3. Hash Map Approach (Two-Pass)
    vector<int> twoSum(vector<int> &nums, int target) // Time Complexity: O(n) Space Complexity: O(n)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.count(complement) and (map[complement] != i)) // One value must not be added twice
            {
                int start = map[complement];
                int end = i;
                return std::vector<int>{start, end};
            }
        }
        return {};
    }
};
// Other apporaches include:
// 1. Sorting and Two-Pointer Technique: Sort the array and use two pointers to find the two numbers that add up to the target.
//       This approach has a time complexity of O(n log n) due to sorting, but it can be efficient in certain scenarios.
// 2. Binary Search: After sorting the array, for each element, use binary search to find if the complement (target - current element) exists in the array.
//       This approach also has a time complexity of O(n log n) due to sorting and binary search.
int main()
{

    return 0;
}