#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * Problem: 2. Add Two Numbers
 * * 1. Description:
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single
 * digit. Add the two numbers and return the sum as a linked list. You may assume
 * the two numbers do not contain any leading zero, except the number 0 itself.
 * * 2. Constraints:
 * - The number of nodes in each linked list is in the range [1, 100].
 * - 0 <= Node.val <= 9
 * - It is guaranteed that the list represents a number that does not have leading zeros.
 * * 3. Examples:
 * - Example 1: Input: l1 = [2,4,3], l2 = [5,6,4] | Output: [7,0,8]
 * - Example 2: Input: l1 = [0], l2 = [0] | Output: [0]
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
    // 1.      This solution is incorrect and fails certail test cases .
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool l1_greater_l2 = true;
        ListNode *l1_head = l1;
        ListNode *l2_head = l2;
        int value = 0;
        int carry = 0;
        while ((l1 != nullptr) or (l2 != nullptr))
        {
            // End cases
            if (l1 == nullptr)
            {
                l1_greater_l2 = false;
                // Update values
                value = ((l2->val + carry) % 10);
                carry = (l2->val + carry) / 10;
                l2->val = value;
                if (l2->next == nullptr)
                {
                    // Check if carry is still > 0
                    if (carry > 0)
                    {
                        ListNode *final_carry = new ListNode(carry);
                        l2->next = final_carry;
                    }
                    return l2_head;
                }
                l2 = l2->next;
                continue;
            }
            else if (l2 == nullptr)
            {
                // Update values
                value = ((l1->val + carry) % 10);
                carry = (l1->val + carry) / 10;
                l1->val = value;
                l1 = l1->next;
                if (l1->next == nullptr)
                {
                    // Check if carry is still > 0
                    if (carry > 0)
                    {
                        ListNode *final_carry = new ListNode(carry);
                        l1->next = final_carry;
                    }
                    return l1_head;
                }
                continue;
            }
            // Update values
            value = ((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            l1->val = value;
            l2->val = value;
            if ((l1 == nullptr) and (l2 == nullptr))
            {
                // Check if carry is still > 0
                if (carry > 0)
                {
                    ListNode *final_carry = new ListNode(carry);
                    l1->next = final_carry;
                }
                return l1_head;
            }
            // Move pointers
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (l1_greater_l2)
            return l1_head;
        return l2_head;
    }
    // 2.       Creating a new output list
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *current = head;
        int value = 0, carry = 0;
        while ((l1 != nullptr) or (l2 != nullptr) or (carry != 0))
        {
            value = carry;
            if (l1 != nullptr)
            {
                value += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                value += l2->val;
                l2 = l2->next;
            }
            carry = value / 10;
            value = value % 10;
            // Add node to the output list
            ListNode *temp = new ListNode(value);
            current->next = temp;
            current = current->next;
        }
        current = head->next;
        delete head;
        return current;
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
    ListNode *return_tail(ListNode *head)
    {
        ListNode *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        return temp;
    }
    ListNode *push_back(ListNode *head, int data)
    {
        // std::cout << "Node created ---" << ++node_count << std::endl;
        //
        ListNode *new_data = new ListNode(data);
        // if the list is empty
        if (head == nullptr)
        {
            head = new_data;
            return head;
        }
        // else traverse to the end
        ListNode *end = head;
        while (end->next != nullptr)
            end = end->next;
        // now add the new node
        end->next = new_data;
        return head;
    }
};
// Other approaches:

int main()
{
}
