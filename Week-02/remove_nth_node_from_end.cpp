#include <iostream>
using namespace std;
/*
 * Problem: 19. Remove Nth Node From End of List
 * * 1. Description:
 * Given the `head` of a linked list, remove the `n`th node from the end of the
 * list and return its head.
 * * 2. Constraints:
 * - The number of nodes in the list is `sz`.
 * - 1 <= sz <= 30
 * - 0 <= Node.val <= 100
 * - 1 <= n <= sz
 * * 3. Examples:
 * - Example 1: Input: head = [1,2,3,4,5], n = 2 | Output: [1,2,3,5]
 * - Example 2: Input: head = [1], n = 1 | Output: []
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
    // 1. Two Pass - Find size and then index from start
    ListNode *removeNthFromEnd(ListNode *head, int index) // Time complexity O(n), Space complexity O(1)
    {
        ListNode *head_saved = head;
        if (head == nullptr)
            return head_saved;
        int node_count = list_size(head);
        // Now find the index to remove from the start
        if (index > node_count)
        {
            return nullptr;
        }
        index = node_count - index;
        //
        if (index > node_count - 1)
            return nullptr;
        if (index == 0)
        {
            ListNode *old_head = head;
            head = head->next;
            delete old_head;
            // std::cout << "Node removed ---" << --node_count << std::endl;
            return head;
        }
        //
        ListNode *node_to_delete;
        ListNode *node_ptr = head;
        size_t count = 0;
        while (count != index - 1)
        {
            count++;
            node_ptr = node_ptr->next;
            if (node_ptr == nullptr)
                return nullptr; // quitely return, as index entered in invalid
        }
        node_to_delete = node_ptr->next;
        if (node_to_delete == nullptr)
            return nullptr;
        node_ptr->next = node_to_delete->next;
        delete node_to_delete;
        // std::cout << "Node removed ---" << --node_count << std::endl;
        return head_saved;
    }
    // 2. One pass solution - Slow and Fast Pointers
    ListNode *removeNthFromEnd(ListNode *head, int n) // Time complexity O(n), Space complexity O(1)
    {
        ListNode *fast_ptr = head, *slow_ptr = head;
        // Step:1   Move the fast_ptr 'n' steps ahead of start/head
        for (int i = 0; i < n; i++)
        {
            fast_ptr = fast_ptr->next;
        }
        // Edge Case, We remove the first node
        if (fast_ptr == nullptr)
        {
            head = head->next;
            return head;
        }
        // Step:2 Move both pointers
        while (fast_ptr->next != nullptr)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        // Step:3 Remvoe the node after the slow ptr
        ListNode *temp = slow_ptr->next;
        if (slow_ptr->next != nullptr)
        {
            slow_ptr->next = slow_ptr->next->next;
            delete temp;
        }
        return head;
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
};
// Other approaches:
// 1. Recursion Approach, Time complexity O(n+m), Space complexity O(n+m)

int main()
{
}
