#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * Problem: Two Sum II - Input Array Is Sorted
 * * 1. Description:
 * Given a 1-indexed array of integers `numbers` that is sorted in non-decreasing
 * order, find two numbers that add up to a specific `target` number. Return the
 * 1-based indices of these two numbers. You must use only constant extra space,
 * and exactly one solution exists.
 * * 2. Constraints:
 * - 2 <= numbers.length <= 3 * 10^4
 * - -1000 <= numbers[i] <= 1000
 * - numbers is sorted in non-decreasing order.
 * - -1000 <= target <= 1000
 * - The tests are generated such that there is exactly one solution.
 * * 3. Examples:
 * - Example 1: Input: numbers = [2,7,11,15], target = 9 | Output: [1,2]
 * - Example 2: Input: numbers = [2,3,4], target = 6 | Output: [1,3]
 */
class Solution
{
public:
    // 1. Brute Force Approach: -> Too Slow
    vector<int> twoSum(vector<int> &numbers, int target) // O(n^2) time complexity, O(1) space complexity
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            for (int j = i; j < numbers.size(); j++)
            {
                if (numbers[i] + numbers[j] == target)
                    return vector<int>{i + 1, j + 1};
            }
        }
        return {};
    }
    // 2. Hashmap approach  -> The array is sorted for a reason, so think, a better solution exists.
    vector<int> twoSum(vector<int> &numbers, int target) // Time complexity: O(n), Space complexity: O(n)
    {
        int complement = 0;
        std::unordered_map<int, int> numbers_map;
        for (int i = 0; i < numbers.size(); i++)
        {
            complement = target - abs(numbers[i]);
            if (numbers_map.find(complement) != numbers_map.end())
            {
                return vector{numbers_map[complement] + 1, i + 1};
            }
            numbers_map.insert({numbers[i], i});
        }
        return {};
    }
    // 3. Two Pointer Approach: -> The best solution
    vector<int> twoSum(vector<int> &numbers, int target) // Time complexity: O(n), Space complexity: O(1)
    {
        int complement = 0;
        int right_pointer = numbers.size() - 1;
        int left_pointer = 0;
        while (left_pointer < right_pointer)
        {
            if ((numbers[left_pointer] + numbers[right_pointer]) == target)
                return vector<int>{left_pointer + 1, right_pointer + 1};
            else if ((numbers[left_pointer] + numbers[right_pointer]) > target)
                right_pointer--;
            else // (numbers[left_pointer] + numbers[right_pointer]) < target)
                left_pointer++;
        }
        return {}; // useless as it will never reach this point
    }
};
// Other Approaches:
// 1. Binary Search Approach: -> Time complexity: O(nlogn), Space complexity: O(1)
// 2. Using STL: -> Time complexity: O(n), Space complexity: O(1)
int main()
{
}