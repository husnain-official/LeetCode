#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
 * Problem: Valid Anagram
 * * 1. Description:
 * Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`,
 * and `false` otherwise.
 * * 2. Constraints:
 * - 1 <= s.length, t.length <= 5 * 10^4
 * - s and t consist of lowercase English letters.
 * * * 3. Examples:
 * - Example 1: Input: s = "anagram", t = "nagaram" | Output: true
 * - Example 2: Input: s = "rat", t = "car" | Output: false

*/
class Solution
{
public:
    // 1. Brute Force Approach
    bool isAnagram(string s, string t) // Time Complexity: O(n^2) Space Complexity: O(1)
    {
        if (s.size() != t.size())
            return false;
        int count = 0;
        int matched = 0;
        for (int i = 0; i < s.size(); i++)
        {
            count = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if ((s[i] == t[j]) and (count < 1))
                {
                    matched++;
                    t[j] = '.';
                }
            }
        }
        if (matched == s.size())
            return true;
        return false;
    }
    // 2. Sorting Approach
    bool isAnagram(string s, string t) // Time Complexity: O(nlogn) Space Complexity: O(1)
    {
        if (s.size() != t.size())
            return false;
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return (s == t);
    }
    // 3. Frequency Calculation Approach
    bool isAnagram(string s, string t) // Time Complexity: O(n) Space Complexity: O(1)
    {
        if (s.size() != t.size())
            return false;
        int frequency[26]{};
        for (int i = 0; i < s.size(); i++)
        {
            frequency[s[i] - 'a']++;
            frequency[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (frequency[i] != 0)
                return false;
        }
        return true;
    }
    // 4. Hash Map Approach
    bool isAnagram(string s, string t) // Time Complexity: O(n) Space Complexity: O(1)
    {
        if (s.size() != t.size())
            return false;
        std::unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (map.count(t[i]) == 0 or map[t[i]] == 0)
                return false;
            map[t[i]]--;
        }
        return true;
    }
};
// Other apporaches include:
int main()
{

    return 0;
}