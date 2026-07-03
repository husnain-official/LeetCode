#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // Method-01
    bool isPalindrome(int x) // Time complexity: O(n) and Space Complexity: O(n)
    {
        int size = 0;
        std::vector<int> digits;
        while (x > 0) // Calculate the number of
        {
            digits.push_back(x % 10);
            x = x / 10;
        }
        size = digits.size();
        for (int i = 0; i < size / 2; i++)
        {
            if (digits[i] != digits[size - i - 1])
                return false;
        }
        return true;
    }
    // Method-02
    bool isPalindrome(int x) // Time complexity: O(n) and Space Complexity: O(1)
    {
        // Initial Check
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        // Logic
        // Method-02
        long rev = 0;
        int rem = 0;
        int x_copy = x;
        while (x > 0)
        {
            rem = x % 10;
            x = x / 10;
            rev = (rev * 10) + rem;
        }
        if (x_copy == rev)
            return true;
        return false;
    }
};