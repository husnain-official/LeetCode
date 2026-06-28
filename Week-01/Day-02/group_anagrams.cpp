#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
 * Problem: Group Anagrams
 * * 1. Description:
 * Given an array of strings `strs`, group the anagrams together.
 * You can return the answer in any order.
 * * 2. Constraints:
 * - 1 <= strs.length <= 10^4
 * - 0 <= strs[i].length <= 100
 * - strs[i] consists of lowercase English letters.
 * * * 3. Examples:
 * - Example 1: Input: strs = ["eat","tea","tan","ate","nat","bat"] | Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * - Example 2: Input: strs = [""] | Output: [[""]]
 */
class Solution
{
public:
    // 1. Sort and Hashing Approach
    vector<vector<string>> groupAnagrams(vector<string> &strs) // Time Complexity: O(n * k log k), where n is the number of strings and k is the maximum length of a string. Sorting each string takes O(k log k) time.
    {                                                          // Space Complexity: O(n * k), where n is the number of strings and k is the maximum length of a string. We store all the strings in the hash map.
        vector<vector<string>> result;
        std::unordered_map<string, vector<string>> map;
        string original_word, sorted_word;
        for (int i = 0; i < strs.size(); i++)
        {
            original_word = strs[i]; // Store original and sorted copies
            sorted_word = original_word;
            std::sort(sorted_word.begin(), sorted_word.end());
            // Storing the anagrams
            if (map.find(sorted_word) != map.end())
                map[sorted_word].push_back(original_word);
            else
                map.insert({sorted_word, {original_word}});
        }
        for (auto element : map)
            result.push_back(element.second);
        return result;
    }
    // 2. Count and Hashing Approach
    vector<vector<string>> groupAnagrams(vector<string> &strs) // Time Complexity: O(n * k), where n is the number of strings and k is the maximum length of a string. Counting the frequency of characters takes O(k) time for each string.
    {                                                          // Space Complexity: O(n * k), where n is the number of strings and k is the maximum length of a string. We store all the strings in the hash map.
        vector<vector<string>> result;
        std::unordered_map<string, vector<string>> map;
        string key, original_word = "";
        for (int i = 0; i < strs.size(); i++)
        {
            key = "";
            original_word = strs[i];
            int frequency[26]{};
            for (char char_ : original_word) // Calc the frequency for specific word
                frequency[char_ - 'a']++;
            for (int freq : frequency) // Convert frequency into a string
                key += to_string(freq) + "~";
            // Now we have a valid, comparable, hashable key
            map[key].push_back(original_word);
        }
        // Finally extract anagrams lists form the map into 2D vector
        for (auto element : map)
            result.push_back(element.second);
        return result;
    }
};
// Other Approaches:
// 1. Brute Force Approach: Compare each string with every other string to check if they are anagrams. This approach has a time complexity of O(n^2 * k log k) and is not efficient for large inputs.
// 2. Prime Number Multiplication Approach: Assign a unique prime number to each character and calculate the product of the prime numbers for each string. Anagrams will have the same product. This approach has a time complexity of O(n * k) but may suffer from integer overflow for long strings.
// 3. Bit Manipulation Approach: Use bit manipulation to represent the frequency of characters in a string. This approach has a time complexity of O(n * k) but may be less intuitive and harder to implement correctly.
int main()
{
}