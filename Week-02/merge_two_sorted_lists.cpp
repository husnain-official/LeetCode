#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * Problem: 21. Merge Two Sorted Lists
 * * 1. Description:
 * You are given the heads of two sorted linked lists `list1` and `list2`.
 * Merge the two lists into one sorted list by splicing together the nodes
 * of the first two lists. Return the head of the merged linked list.
 * * 2. Constraints:
 * - The number of nodes in both lists is in the range [0, 50].
 * - -100 <= Node.val <= 100
 * - Both list1 and list2 are sorted in non-decreasing order.
 * * 3. Examples:
 * - Example 1: Input: list1 = [1,2,4], list2 = [1,3,4] | Output: [1,1,2,3,4,4]
 * - Example 2: Input: list1 = [], list2 = [] | Output: []
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
    // 1. Use vector/ Pure Brute Force
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) // Time complexity O((n+m)^2), Space complexity O(n+m)
    {
        // Turn both lists into vectors
        int size1 = list_size(list1);
        int size2 = list_size(list2);
        std::vector<int> list_arr_1(size1);
        std::vector<int> list_arr_2(size2);
        list_to_vector(list1, list_arr_1);
        list_to_vector(list2, list_arr_2);
        // Now sort it in a singular vector
        std::vector<int> output_vector(size1 + size2);
        for (int i = 0; i < size1; i++)
            output_vector[i] = list_arr_1[i];
        for (int i = 0; i < size2; i++)
            output_vector[i + size1] = list_arr_2[i];
        std::sort(output_vector.begin(), output_vector.end());
        // Finally convert it into a list
        ListNode *output_list = nullptr;
        for (int i = 0; i < (size1 + size2); i++)
        {
            if (output_list == nullptr)
                output_list = push_back(output_list, output_vector[i]);
            else
                push_back(output_list, output_vector[i]);
        }
        return output_list;
    }
    // 2. Pointer Approach
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) // Time complexity O(n+m), Space complexity O(1)
    {
        // Initial checks
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        //
        ListNode *output_list = nullptr;
        //  First we determine the head
        if (list1->val < list2->val)
        {
            output_list = list1;
            list1 = list1->next;
        }
        else
        {
            output_list = list2;
            list2 = list2->next;
        }
        //
        ListNode *output_tail = output_list;
        while (true)
        {
            // Cases where the lists end
            if ((list1 == nullptr) and (list2 == nullptr))
                break;
            if (list1 == nullptr)
            {
                output_tail->next = list2;
                return output_list;
            }
            else if (list2 == nullptr)
            {
                output_tail->next = list1;
                return output_list;
            }
            //
            else if (list1->val < list2->val)
            {
                output_tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                output_tail->next = list2;
                list2 = list2->next;
            }
            output_tail = output_tail->next;
        }
        return output_list;
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
// 1. Recursion Approach, Time complexity O(n+m), Space complexity O(n+m)
// 2. Dummy Node Approach (Best Practice Iterative), Time complexity O(n+m), Space complexity O(1)
// 3. Min-Heap / Priority Queue Approach, Time complexity O(n+m), Space complexity O(1) auxiliary

int main()
{
}
