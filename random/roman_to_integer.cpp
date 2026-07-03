#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    // Method-01 -> No thinking just brute force, nested if-else
    int romanToInt(string s) // Time complexity O(n), Space Complexity O(1)
    {
        int size = s.size();
        int temp = 0;
        int result = 0;
        while (temp < size)
        {
            if (s[temp] == 'M')
                result += 1000;
            else if (s[temp] == 'D')
                result += 500;
            else if (s[temp] == 'C')
            {
                temp++;
                if (s[temp] == 'D')
                    result += 400;
                else if (s[temp] == 'M')
                    result += 900;
                else
                {
                    temp--;
                    result += 100;
                }
            }
            else if (s[temp] == 'L')
                result += 50;
            else if (s[temp] == 'X')
            {
                temp++;
                if (s[temp] == 'L')
                    result += 40;
                else if (s[temp] == 'C')
                    result += 90;
                else
                {
                    temp--;
                    result += 10;
                }
            }
            else if (s[temp] == 'V')
                result += 5;
            else if (s[temp] == 'I')
            {
                temp++;
                if (s[temp] == 'V')
                    result += 4;
                else if (s[temp] == 'X')
                    result += 9;
                else
                {
                    temp--;
                    result += 1;
                }
            }
            temp++;
        }
        return result;
    }
    // Method:2 Hash table
    int romanToInt(string s) // Time complexity O(n), Space Complexity O(1)
    {
        std::unordered_map<char, int> roman_value = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int value = 0;
        int current = 0, next = 0;
        for (int i = 0; i < s.size(); i++)
        {
            current = roman_value[s[i]];
            next = (i + 1 < s.size()) ? roman_value[s[i + 1]] : 0;
            if (current < next)
                value -= current;
            else
                value += current;
        }
        return value;
    }
};