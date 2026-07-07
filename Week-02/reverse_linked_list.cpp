#include <iostream>
#include <vector>
using namespace std;
/*
 * Problem: 206. Reverse Linked List
 * * 1. Description:
 * Given the `head` of a singly linked list, reverse the list, and return the
 * reversed list.
 * * 2. Constraints:
 * - The number of nodes in the list is in the range [0, 5000].
 * - -5000 <= Node.val <= 5000
 * * 3. Examples:
 * - Example 1: Input: head = [1,2,3,4,5] | Output: [5,4,3,2,1]
 * - Example 2: Input: head = [1,2] | Output: [2,1]
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    // 1. Use vector
    ListNode *reverseList(ListNode *head) // Time complexity O(n), Space complxity O(n)
    {
        // 1. Find size  2. Create vector   3. Put data in it
        int size = list_size(head);
        std::vector<int> node_array(size);
        list_to_vector(head, node_array);
        // 4. Reverse data  5. Put data back in list 6. return head
        reverse_vector(node_array);
        vector_to_list(head, node_array);
        return head;
    }
    // 2. Use pointers
    ListNode *reverseList(ListNode *head) // Time complexity O(n), Space complxity O(1)
    {
        int size = list_size(head);
        ListNode *next = nullptr, *prev = nullptr, *curr = head;
        for (int i = 0; i < size; i++)
        {
            next = curr->next;
            curr->next = prev;
            // for next node changes
            prev = curr;
            curr = next;
        }
        return prev;
    }
    //----------------------------------------------------------------
    int list_size(ListNode *head)
    {
        int size = 0;
        while (head != nullptr)
        {
            size++;
            head = head->next;
        }
        std::cout << "Size is --- " << size << " ---" << endl;
        return size;
    }
    void list_to_vector(ListNode *head, std::vector<int> &node_array)
    {
        int index = 0;
        while (head != nullptr)
        {
            node_array[index] = head->val;
            std::cout << node_array[index] << " -> ";
            index++;
            head = head->next;
        }
        std::cout << endl;
    }
    void vector_to_list(ListNode *head, std::vector<int> &node_array)
    {
        int size = node_array.size();
        for (int i = 0; i < size; i++)
        {
            head->val = node_array[i];
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std::cout << endl;
    }
    void reverse_vector(std::vector<int> &node_array)
    {
        int size = node_array.size();
        int temp = 0;
        for (int i = 0; i < size / 2; i++)
        {
            temp = node_array[i];
            node_array[i] = node_array[size - i - 1];
            node_array[size - 1 - i] = temp;
        }
        for (int i = 0; i < size; i++)
            std::cout << node_array[i] << " -> ";
        std::cout << endl;
    }
};
// Other approaches:
// 1. Recursion time complexity O(n), Space complexity O(n)
// 2. Stack time complexity O(n), Space complexity O(n)
int main()
{
}
