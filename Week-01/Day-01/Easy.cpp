#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // --------------- Two Sum ---------------
    // 1. Brute Force Approach
    vector<int> twoSum(vector<int> &nums, int target) // Time Complexity: O(n^2) Space Complexity: O(1)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum = nums[i] + nums[j];
                if (sum == target)
                {
                    return vector<int>{i, j};
                }
            }
        }
        return {};
    }
    // 2. Hash Map Approach (One-Pass)
    // vector<int> twoSum(vector<int> &nums, int target) // Time Complexity: O(n) Space Complexity: O(n)
    // {
    //     std::unordered_map<int, int> map;
    //     int complement = 0;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         complement = target - nums[i];
    //         if (map.find(complement) != map.end())
    //         {
    //             int start = map[complement];
    //             int end = i;
    //             return std::vector<int>{start, end};
    //         }
    //         else
    //             map[nums[i]] = i;
    //     }
    //     return {};
    // }
    // 3. Hash Map Approach (Two-Pass)
    // vector<int> twoSum(vector<int> &nums, int target) // Time Complexity: O(n) Space Complexity: O(n)
    // {
    //     std::unordered_map<int, int> map;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         map[nums[i]] = i;
    //     }
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int complement = target - nums[i];
    //         if (map.count(complement) and (map[complement] != i)) // One value must not be added twice
    //         {
    //             int start = map[complement];
    //             int end = i;
    //             return std::vector<int>{start, end};
    //         }
    //     }
    //     return {};
    // }
    // --------------- Contains Duplicate ---------------
    // 1. Brute Force Approach
    bool containsDuplicate(vector<int> &nums) // Time Complexity: O(n^2) Space Complexity: O(1)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int target = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == target)
                    return true;
            }
        }
        return false;
    }
    // 2. Hash-Map (One-Pass)
    // bool containsDuplicate(vector<int> &nums) // Time Complexity: O(n) Space Complexity: O(n)
    // {
    //     std::unordered_map<int, int> map;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (map.count(nums[i]))
    //             return true;
    //         else
    //             map[nums[i]] = i;
    //     }
    //     return false;
    // }

    // --------------- Is Anagram ---------------
    // 1. Brute Force Approach
    // bool isAnagram(std::string s, std::string t) // Time Complexity: O(n^2) Space Complexity: O(n)
    // {
    //     // 1st Check
    //     if (s.length() != t.length())
    //         return false;
    //     std::vector<char> matching;
    //     char temp = '.';
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         char target = s[i];
    //         for (int j = 0; j < s.length(); j++)
    //         {
    //             if (target == t[j])
    //             {
    //                 t[j] = temp;
    //                 matching.push_back(target);
    //                 break;
    //             }
    //         }
    //     }
    //     if (matching.size() == s.length())
    //         return true;
    //     return false;
    // }
    // 2. Sorting Approach
    // bool isAnagram(std::string s, std::string t) // Time Complexity: O(nlogn) Space Complexity: O(1)
    // {
    //     // 1st Check
    //     if (s.length() != t.length())
    //         return false;
    //     std::sort(s.begin(), s.end());
    //     std::sort(t.begin(), t.end());
    //     return (s == t);
    // }
    // 3. Hash Map Approach
    bool isAnagram(std::string s, std::string t) // Time Complexity : O(n) Space Complexity: O(n)
    {
        // 1. Check
        if (s.length() != t.length())
            return false;
        std::unordered_map<char, int> map;
        // 2. Calculate the frequency of alphabets in 's'
        for (int i = 0; i < s.length(); i++)
        {
            map[s[i]]++;
        }
        // 3. Decrement the frequency for alphabets in 't'
        for (int i = 0; i < s.length(); i++)
        {
            if (map.count(t[i]) == 0 or map[t[i]] == 0)
                return false;
            map[t[i]]--;
        }
        return true;
    }
    // 4. Simple Frequency Calculation
    bool isAnagram(std::string s, std::string t) // Time Complexity : O(n) Space Complexity: O(1)
    {
        // 1. Check
        if (s.length() != t.length())
            return false;
        // 2. Calculate the frequency of alphabets in 's'
        int frequency[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            frequency[s[i] - 'a']++;
            frequency[t[i] - 'a']--;
        }
        // 3. Verify all frequencies are zero
        for (int &freq : frequency)
            if (freq != 0)
                return false;
        return true;
    }
};
;

int main()
{
    Solution s1 = Solution();
    string s = "anagram";
    string t = "nagaram";
    bool results = s1.isAnagram(s, t);
    cout << "Is Anagram ? " << results << endl;
    //
    // vector<int> nums{3, 2, 4};
    // int target = 6;
    // vector<int> result = s1.twoSum(nums, target);
    // cout << "Start: " << result[0] << " End: " << result[1];
    //
}