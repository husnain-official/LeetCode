#include <iostream>
#include <cctype>
using namespace std;
/*
 * Problem: Valid Palindrome
 * * 1. Description:
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase
 * letters and removing all non-alphanumeric characters, it reads the same forward
 * and backward. Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.
 * * 2. Constraints:
 * - 1 <= s.length <= 2 * 10^5
 * - s consists only of printable ASCII characters.
 * * 3. Examples:
 * - Example 1: Input: s = "A man, a plan, a canal: Panama" | Output: true
 * - Example 2: Input: s = "race a car" | Output: false
 */
class Solution
{
public:
    // 1. Two Pointer Approach:
    bool isPalindrome(string s) // Time Complexity: O(n), Space Complexity: O(n)
    {
        // 1. Clean the string
        string cleaned_str;
        for (char ch : s)
        {
            if (isalnum(ch))
                cleaned_str += tolower(ch);
        }
        // 2. Check
        if (cleaned_str.empty())
            return true;
        // 3. Compare from both ends
        int size = cleaned_str.length() - 1;
        for (int i = 0; i <= (size / 2); i++)
        {
            if (cleaned_str[i] != cleaned_str[size - i])
                return false;
        }
        return true;
    }
    // 2. Optimized Two Pointer Approach:
    bool isPalindrome(std::string s) // Time Complexity: O(n), Space Complexity: O(1)
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            // Move left pointer forward if not alphanumeric
            while (left < right and !std::isalnum(static_cast<unsigned char>(s[left])))
            {
                left++;
            }
            // Move right pointer backward if not alphanumeric
            while (left < right and !std::isalnum(static_cast<unsigned char>(s[right])))
            {
                right--;
            }
            // Compare the lowercase versions of the characters
            if (std::tolower(static_cast<unsigned char>(s[left])) !=
                std::tolower(static_cast<unsigned char>(s[right])))
            {
                return false;
            }
            // Move both pointers inward for the next check
            left++;
            right--;
        }
        return true;
    }
};
// Other Approaches: for palindrome
// 1. Brute Force Approach: Reverse the cleaned string and compare it with the original cleaned string. This approach has a time complexity of O(n) and space complexity of O(n).
// 2. Recursive Approach: Use recursion to compare characters from both ends of the cleaned string. This approach has a time complexity of O(n) and space complexity of O(n) due to the recursive call stack.
// 3. Stack Approach: Use a stack to store the first half of the cleaned string and then compare it with the second half. This approach has a time complexity of O(n) and space complexity of O(n).
int main()
{
}