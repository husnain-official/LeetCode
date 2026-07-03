#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    // Brute Force
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix;
        for (int i = 0; i < strs.size(); i++)
        {
            string current = strs[i];
            if (i == 0)
                prefix = current;
            else
            {
                int size = current.size() - 1;
                for (int j = size; j >= 0; j--)
                {
                    if (j > prefix.size() - 1)
                    {
                        current.pop_back();
                        continue;
                    }
                    if (current[j] != prefix[j])
                        prefix.erase(prefix.begin() + j);
                }
            }
        }
        return prefix;
    }
};