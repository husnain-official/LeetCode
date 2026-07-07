#include <iostream>
#include <vector>
using namespace std;
/*
 * Problem: 92. Reverse Linked List II
 * * 1. Description:
 * Given the `head` of a singly linked list and two integers `left` and `right`
 * where `left <= right`, reverse the nodes of the list from position `left` to
 * position `right`, and return the reversed list.
 * * 2. Constraints:
 * - The number of nodes in the list is n.
 * - 1 <= n <= 500
 * - -500 <= Node.val <= 500
 * - 1 <= left <= right <= n
 * * 3. Examples:
 * - Example 1: Input: head = [1,2,3,4,5], left = 2, right = 4 | Output: [1,4,3,2,5]
 * - Example 2: Input: head = [5], left = 1, right = 1 | Output: [5]
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        // 1. Find size  2. Create vector   3. Put data in it
        int size = right - left;
        std::vector<int> node_array(size);
        list_to_vector(head, node_array);
        // 4. Reverse data  5. Put data back in list 6. return head
        reverse_vector(node_array);
        vector_to_list(head, node_array);
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
    ListNode *return_tail(ListNode *head)
    {
        ListNode *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        return temp;
    }
};
// Other approaches:
int main()
{
}
