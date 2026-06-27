#include <iostream>
#include <vector>
#include <unordered_map> // for hashmap
#include <queue>         // for min/max-heap, A balanced binary tree DS (Prioriry Queue) that allows for efficient retrieval of the minimum or maximum element.
#include <algorithm>     // for sort()
using namespace std;
/*
 * Problem: Top K Frequent Elements
 * * 1. Description:
 * Given an integer array `nums` and an integer `k`, return the `k` most frequent
 * elements. You may return the answer in any order.
 * * 2. Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 * - k is in the range [1, the number of unique elements in the array].
 * - It is guaranteed that the answer is unique.
 */
class Solution
{
public:
    // 1. Hashmap and Sorting Approach      --- Took 0ms
    vector<int> topKFrequent(vector<int> &nums, int k) // Time Complexity: O(n log n), where n is the number of unique elements in the array. Sorting the frequency vector takes O(n log n) time.
    {                                                  // Space Complexity: O(n), where n is the number of unique elements in the array. We store the frequency of each element in a hash map.
        // Initial check
        if (k > nums.size())
            return {};
        // Calculate frequency using a hashmap
        std::unordered_map<int, int> word_frequency;
        for (int i = 0; i < nums.size(); i++)
        {
            word_frequency[nums[i]]++;
        }
        // Create a vector, so we can sort it
        std::vector<std::pair<int, int>> word_frequency_vector;
        for (auto pair : word_frequency)
        {
            word_frequency_vector.push_back({pair.second, pair.first});
        }
        std::sort(word_frequency_vector.begin(), word_frequency_vector.end());
        // Transfer the 'k' frequent into another vector
        std::vector<int> result(k, 0);
        int size = word_frequency_vector.size() - 1;
        for (int i = 0; i < k; i++)
        {
            result[i] = word_frequency_vector[size - i].second;
        }
        return result;
    }
    // 2. Hashmap and Max-Heap Approach     --- Took 7ms
    vector<int> topKFrequent(vector<int> &nums, int k) // Time Complexity: O(n log n), where n is the number of unique elements in the array. Inserting elements into the max-heap takes O(log n) time, and we do this for each unique element, resulting in a total time complexity of O(n log n).
    {                                                  // Space Complexity: O(n), where n is the number of unique elements in the array. We store the frequency of each element in a hash map and also maintain a max-heap to store the frequencies.
        // Initial-Check
        if (k > nums.size())
            return {};
        // We caculate the frequency of each 'element'
        std::unordered_map<int, int> element_frequency;
        for (int i = 0; i < nums.size(); i++) // O(n)
        {
            element_frequency[nums[i]]++;
        }
        // We store the frequency in a max-heap so we can sort it.
        std::priority_queue<std::pair<int, int>> element_frequency_tree;
        for (auto pair : element_frequency)
        {
            element_frequency_tree.push({pair.second, pair.first}); // O(log n) but 'n' times total effect = O(n log n)
        }
        // Now we return the top 'k' elements
        std::vector<int> result(k, 0);
        for (int i = 0; i < k; i++)
        {
            result[i] = element_frequency_tree.top().second;
            element_frequency_tree.pop(); // O(log n) but 'k' times total effect = O(k log n)
        }
        return result;
    }
    // 3. Hashmap and Min-Heap Approach     --- Took 2ms
    vector<int> topKFrequent(vector<int> &nums, int k) // Time Complexity: O(n log n), where n is the number of unique elements in the array. Inserting elements into the min-heap takes O(log n) time, and we do this for each unique element, resulting in a total time complexity of O(n log n).
    {                                                  // Space Complexity: O(n), where n is the number of unique elements in the array. We store the frequency of each element in a hash map and also maintain a max-heap to store the frequencies.
        // Initial-Check
        if (k > nums.size())
            return {};
        // We caculate the frequency of each 'element'
        std::unordered_map<int, int> element_frequency;
        for (int i = 0; i < nums.size(); i++) // O(n)
        {
            element_frequency[nums[i]]++;
        }
        // We store the frequency in a min-heap so we can sort it.
        std::priority_queue<std::pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> element_frequency_tree;
        for (auto pair : element_frequency)
        {
            element_frequency_tree.push({pair.second, pair.first}); // O(log n) but 'n' times total effect = O(n log n)
            if (element_frequency_tree.size() > k)
            {
                element_frequency_tree.pop(); // O(log n) but 'n-k' times total effect = O((n-k) log n)
            }
        }
        // Now we return the top 'k' elements
        std::vector<int> result(k, 0);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = element_frequency_tree.top().second;
            element_frequency_tree.pop(); // O(log n) but 'k' times total effect = O(k log n)
        }
        return result;
    }
};
// Other Approaches:
// 1. Hashmap and Bucket Sort Approach.        Time Complexity: O(n) Space Complexity: O(n)
// 2. Hashmap and Quickselect Approach.        Time Complexity: O(n) Space Complexity: O(n)
int main()
{
}