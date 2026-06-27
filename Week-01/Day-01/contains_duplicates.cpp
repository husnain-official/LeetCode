#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
 * Problem: Contains Duplicate
 * * 1. Description:
 * Given an integer array `nums`, return `true` if any value appears at least twice
 * in the array, and return `false` if every element is distinct.
 * * 2. Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 */
class Solution
{
public:
    // 1. Brute Force Approach
    bool containsDuplicate(vector<int> &nums) // Time Complexity: O(n^2) Space Complexity: O(1)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
    // 2. Sorting Approach
    bool containsDuplicate(vector<int> &nums) // Time Complexity: O(nlogn) Space Complexity: O(1)
    {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if ((i != nums.size() - 1) and (nums[i] == nums[i + 1]))
                return true;
        }
        return false;
    }
    // 3. Hash-Map Approach
    bool containsDuplicate(vector<int> &nums) // Time Complexity: O(n) Space Complexity: O(n)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) != map.end())
                return true;
            else
                map[nums[i]] = i;
        }
        return false;
    }
    // 4. Hash-Set Approach
    bool containsDuplicate(vector<int> &nums) // Time Complexity: O(n) Space Complexity: O(n)
    {
        std::unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++)
        {
            if (set.find(nums[i]) != set.end())
                return true;
            else
                set.emplace(nums[i]);
        }
        return false;
    }
};
// Other Approaches:
// 1. Hash-Set Approach.                    Time Complexity: O(n) Space Complexity: O(n)
// explanation: Use a hash set to store the elements of the array. If an element is already in the set, return true. Otherwise, add it to the set. If no duplicates are found, return false.
// 2. Bit Manipulation Approach.            Time Complexity: O(n) Space Complexity: O(1)
// explanation: Use bit manipulation to track the presence of elements in the array. This approach is only applicable if the range of numbers is limited and can be represented using bits.
// 3. Floyd's Tortoise and Hare Approach.    Time Complexity: O(n) Space Complexity: O(1)
// explanation: This approach is used to detect cycles in a sequence of numbers. It can be applied to the problem of finding duplicates by treating the array as a linked list and using two pointers to detect cycles.
int main()
{
}