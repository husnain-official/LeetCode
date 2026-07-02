#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * Problem: 56. Merge Intervals
 * * 1. Description:
 * Given an array of intervals where `intervals[i] = [starti, endi]`, merge all
 * overlapping intervals, and return an array of the non-overlapping intervals that
 * cover all the intervals in the input.
 * * 2. Constraints:
 * - 1 <= intervals.length <= 10^4
 * - intervals[i].length == 2
 * - 0 <= starti <= endi <= 10^4
 * * 3. Examples:
 * - Example 1: Input: intervals = [[1,3],[2,6],[8,10],[15,18]] | Output: [[1,6],[8,10],[15,18]]
 * - Example 2: Input: intervals = [[1,4],[4,5]] | Output: [[1,5]]
 */
class Solution
{
public:
    // 1. Pure Brute Force:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int first_left = 0, first_right = 0, sec_left = 0, sec_right = 0;
        std::vector<int> first_interval;
        std::vector<int> sec_interval;
        std::vector<std::vector<int>> result;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            first_left = intervals[i][0];
            first_right = intervals[i][1];
            for (int j = i + 1; j < n; j++)
            {
                sec_left = intervals[j][0];
                sec_right = intervals[j][1];
                result.push_back(intervals[j]);
                if (first_left < sec_left)
                    result[count][0] = first_left;
                if (first_right > sec_right)
                    result[count++][0] = first_right;
            }
        }
        return result;
    }
};
// Other Approaches
// 1. Left and Right Product Arrays , Time complexity O(N), Space complexity O(N)
int main()
{
}
