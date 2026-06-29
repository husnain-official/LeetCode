#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * Problem: 121. Best Time to Buy and Sell Stock
 * * 1. Description:
 * Given an array `prices` where `prices[i]` is the price of a given stock on the
 * `i`th day, maximize your profit by choosing a single day to buy one stock and
 * choosing a different day in the future to sell it. Return the maximum profit
 * achievable, or 0 if no profit can be achieved.
 * * 2. Constraints:
 * - 1 <= prices.length <= 10^5
 * - 0 <= prices[i] <= 10^4
 * * 3. Examples:
 * - Example 1: Input: prices = [7,1,5,3,6,4] | Output: 5
 * - Example 2: Input: prices = [7,6,4,3,1] | Output: 0
 */
class Solution
{
public:
    // 1. Brute Force Approach
    int maxProfit(vector<int> &prices) // Time complexity O(n^2), Space complexity O(1)
    {
        // Initial Check
        if (prices.size() < 2)
            return 0;
        int purchase_index = 0, purchase_price = INT_MAX;
        int sale_index = 0, sale_price = 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if ((purchase_price > prices[i]) and (i < sale_index))
            {
                purchase_price = prices[i];
                purchase_index = i;
            }
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (sale_price < prices[j])
                {
                    sale_price = prices[j];
                    sale_index = j;
                }
            }
        }
        if (purchase_price == INT_MAX)
            return 0;
        cout << "Purchase: " << purchase_price << " Sale: " << sale_price << endl;
        profit = sale_price - purchase_price;
        return profit;
    }
};
// Other Approaches:
int main()
{
    Solution s1 = Solution();
    vector<int> pro = {1, 2};
    s1.maxProfit(pro);
}