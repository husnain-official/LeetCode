#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * Problem: 15. 3Sum
 * * 1. Description:
 * Given an integer array `nums`, return all unique triplets `[nums[i], nums[j], nums[k]]`
 * such that the indices are distinct (`i != j`, `i != k`, and `j != k`) and their sum
 * equals 0. The solution set must not contain duplicate triplets.
 * * 2. Constraints:
 * - 3 <= nums.length <= 3000
 * - -10^5 <= nums[i] <= 10^5
 * * 3. Examples:
 * - Example 1: Input: nums = [-1,0,1,2,-1,-4] | Output: [[-1,-1,2],[-1,0,1]]
 * - Example 2: Input: nums = [0,1,1] | Output: []
 */
class Solution
{
public:
    // 1. Brute Force Approach:
    vector<vector<int>> threeSum(vector<int> &nums) // Time Complexity: O(n^3), Space Complexity O(1)
    {
        // [-3 , -3 , 2 , 6 , 6 , 7 , 7]   {Refrence}
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if ((i > 0) and (nums[i] == nums[i - 1]))
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((j > i + 1) and (nums[j] == nums[j - 1]))
                    continue;
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if ((k > j + 1) and (nums[k] == nums[k - 1]))
                        continue;
                    if (nums[i] + nums[j] + nums[k] == 0)
                        result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return result;
    }
    // 2. Two loops and a hash table
    vector<vector<int>> threeSum(vector<int> &nums) // Time Complexity: O(n^2), Space Complexity O(n)
    {
        std::vector<std::vector<int>> result;
        // hast table implemntation will be difficult as we have to remove identicle triplets
    }
    // 3. Two Pointer Approach
    vector<vector<int>> threeSum(vector<int> &nums) // Time Complexity: O(n^2), Space Complexity O(1)
    {
        // [-3 , -3 , 2 , 6 , 6 , 7 , 7]   {Refrence}
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        int left, target = 0;
        int right = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            target = -nums[i];
            right = nums.size() - 1;
            left = i + 1;
            if ((i > 0) and (nums[i] == nums[i - 1]))
                continue;
            while (left < right)
            {
                if (nums[left] + nums[right] == target)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while ((left < right) and (nums[left] == nums[left - 1]))
                        left++;
                    while ((left < right) and (nums[right] == nums[right + 1]))
                        right--;
                }
                else if (nums[left] + nums[right] > target)
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};
// Other Approaches:
// 1. Hash Set without Sorting:              -> Time complexity: O(n^2), Space complexity: O(n)
// 2. Hash Map with Element Frequencies:     -> Time complexity: O(n^2), Space complexity: O(n)
// 3. Sorting + Binary Search:               -> Time complexity: O(n^2 log n), Space complexity: O(1)
int main()
{
}