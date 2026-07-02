#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * Problem: 238. Product of Array Except Self
 * * 1. Description:
 * Given an integer array `nums`, return an array `answer` such that `answer[i]`
 * is equal to the product of all the elements of `nums` except `nums[i]`.
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 * * 2. Constraints:
 * - 2 <= nums.length <= 10^5
 * - -30 <= nums[i] <= 30
 * - The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 * * 3. Examples:
 * - Example 1: Input: nums = [1,2,3,4] | Output: [24,12,8,6]
 * - Example 2: Input: nums = [-1,1,0,-3,3] | Output: [0,0,9,0,0]
 */
class Solution
{
public:
    // 1. Pure Brute Force:
    vector<int> productExceptSelf(vector<int> &nums) // Time complexity O(n^2), Space complexity O(n)
    {
        std::vector<int> output(nums.size(), 0);
        int product = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            product = 1;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                    continue;
                product *= nums[j];
            }
            output[i] = product;
        }
        return output;
    }
    // 2. Optimized Brute Force: (Also ignoring rules of the problem, '/' operator usage)
    vector<int> productExceptSelf(vector<int> &nums) // Time complexity O(n), Space complexity O(n)
    {
        int product = 1;
        std::vector<int> output(nums.size(), 0);
        int zero_count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero_count++;
                continue;
            }
            product *= nums[i];
        }
        if (zero_count > 1)
            return output;
        cout << "product: " << product << endl;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                output[i] = product;
                continue;
            }
            if (zero_count == 0)
                output[i] = product / nums[i];
        }
        return output;
    }
    // 3. Prefix-Suffix-Product
    vector<int> productExceptSelf(vector<int> &nums) // Time complexity O(n), Space complexity O(n)
    {
        //  * - Example 1: Input: nums = [1,2,3,4] | Output: [24,12,8,6]
        //                               [1,1,2,6]  [24,12,4,1]
        int size = nums.size();
        std::vector<int> prefix(size, 1);
        std::vector<int> suffix(size, 1);
        for (int i = 1; i < size; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];
        for (int i = size - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];
        // std::vector<int> output(size, 0);
        // for (int i = 0; i < size; i++)
        //     output[i] = prefix[i] * suffix[i];
        // Space complexity: O(n)
        for (int i = 0; i < size; i++)
            nums[i] = prefix[i] * suffix[i];
        return nums;
    }
};
// Other Approaches
// 1. Left and Right Product Arrays , Time complexity O(N), Space complexity O(N)
// 2. Constant Space Approach (Optimized Left/Right) , Time complexity O(N), Space complexity O(1)
// 3. Recursive Approach , Time complexity O(N), Space complexity O(N)
int main()
{
}
