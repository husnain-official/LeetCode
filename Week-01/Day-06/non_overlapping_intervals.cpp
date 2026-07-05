#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * Problem: 435. Non-overlapping Intervals
 * * 1. Description:
 * Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`,
 * return the minimum number of intervals you need to remove to make the rest of
 * the intervals non-overlapping. Note that intervals which only touch at a point
 * are non-overlapping.
 * * 2. Constraints:
 * - 1 <= intervals.length <= 10^5
 * - intervals[i].length == 2
 * - -5 * 10^4 <= starti < endi <= 5 * 10^4
 * * 3. Examples:
 * - Example 1: Input: intervals = [[1,2],[2,3],[3,4],[1,3]] | Output: 1
 * - Example 2: Input: intervals = [[1,2],[1,2],[1,2]] | Output: 2
 */
class Solution
{
public:
    // Pure Brute Force:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) // Time complexity O(n^2), Space complexity O(1)
    {
        int s1, s2, e1, e2, count = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            s1 = intervals[i][0], e1 = intervals[i][1];
            for (int j = i + 1; j < intervals.size(); j++)
            {
                // The two conditions for overlap:
                // 1. s1 <= e2 and 2. s2 <= e1, since for this specific question border elements are not considered as a overlapp we ignore '=' in conditional
                s2 = intervals[j][0], e2 = intervals[j][1];
                if ((s1 < e2) and (s2 < e1))
                {
                    cout << s1 << " " << e1 << " -- " << s2 << " " << e2 << endl;
                    count++;
                }
            }
        }
        return count;
    }
};
// Other approaches:
