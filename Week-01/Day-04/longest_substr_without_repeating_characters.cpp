#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * Problem: 3. Longest Substring Without Repeating Characters
 * * 1. Description:
 * Given a string `s`, find the length of the longest substring without duplicate
 * characters.
 * * 2. Constraints:
 * - 0 <= s.length <= 5 * 10^4
 * - s consists of English letters, digits, symbols and spaces.
 * * 3. Examples:
 * - Example 1: Input: s = "abcabcbb" | Output: 3
 * - Example 2: Input: s = "abcaadefbcbb" | Output: 6
 * - Example 3: Input: s = "bbbbb" | Output: 1
 */
class Solution
{
public:
    // Brute Force Approach:
    int lengthOfLongestSubstring(string s) // Time complexity O(n^2), Space complexity O(k), where k = length of longest substring
    {
        int current_length = 0, max_length = 0;
        std::unordered_map<char, int> letter_frequecncy;
        for (int i = 0; i < s.size(); i++)
        {
            letter_frequecncy.clear();
            letter_frequecncy[s[i]]++;
            current_length = 1;
            for (int j = i + 1; j < s.size(); j++)
            {
                letter_frequecncy[s[j]]++;
                if (letter_frequecncy.size() <= current_length)
                {
                    if (current_length > max_length)
                        max_length = current_length;
                    break;
                }
                current_length++;
                if (current_length > max_length)
                    max_length = current_length;
            }
        }
        if ((max_length == 0) and (current_length == 1))
            return 1;
        return max_length;
    }
    // Sliding Window Approach:
    int lengthOfLongestSubstring(string s) // Time complexity O(n), Space complexity O(k), where k = length of longest substring
    {
        int running_length = 0, max_length = 0;
        std::unordered_map<char, int> char_frequency;
        //  * - Example 2: Input: s = "abc aad efbcbb" | Output: 6
        for (int i = 0; i < s.size(); i++)
        {
            running_length++;
            char_frequency[s[i]]++;
            if (running_length > char_frequency.size()) // if the new element inserted breaks the balance then
            {
                running_length--;
                char_frequency[s[i - running_length]]--;
                if (char_frequency[s[i - running_length]] == 0)
                {
                    char_frequency.erase(s[i - running_length]);
                }
            }
            if (running_length > max_length)
                max_length = running_length;
        }
        return max_length;
    }
};
// Other Approaches:
// 1. Optimized Sliding Window (Array as Frequency Map), Time complexity: O(n), Space complexity: O(1)
// 2. Optimized Sliding Window (Index Mapping / Jumping Left Pointer), Time complexity: O(n), Space complexity: O(1)
// 3. Sliding Window with Hash Set (Adding/Removing from set), Time complexity: O(n), Space complexity: O(k)
int main()
{
    Solution s1 = Solution();
    std::vector<int> array{1, 12, -5, -6, 50, 3};
}
