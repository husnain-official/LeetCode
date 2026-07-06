#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H
#include <iostream>
#include "node.h"
template <typename T>
class f_list
{
    // Members to manage the entire list
    static long node_count;
    node *head = nullptr;

public:
    // Constructor/Destructor
    f_list()
    {
        std::cout << "Forward list created. " << std::endl;
    }
    ~f_list()
    {
        node<T> *temp_node = nullptr;
        while (head != nullptr)
        {
            temp_node = head->next;
            head = head->next;
            delete temp_node;
            std::cout << "Node removed ---" << --node_count << std::endl;
        }
        std::cout << "Forward list deleted. " << std::endl;
    }
    // Insertion
    void push_front(const T &data)
    {
        std::cout << "Node created ---" << ++node_count << std::endl;
        //
        node<T> *new_node = new node<T>(data);
        // If the list is empty
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        // else update the new head, and link it with previous head
        new_node->next = head;
        head = new_node;
    }
    void push_back(const T &data)
    {
        std::cout << "Node created ---" << ++node_count << std::endl;
        //
        node<T> *new_data = new node<T>(data);
        // if the list is empty
        if (head == nullptr)
        {
            head = new_data;
            return;
        }
        // else traverse to the end
        node<T> *end = head;
        while (end->next != nullptr)
            end = end->next;
        // now add the new node
        end->next = new_data;
    }
    void insert(const size_t &index, const T &data)
    {
        // exception
        if (index == 0)
        {
            push_front(data);
            return;
        }
        // check if the index is valid
        node<T> *node_to_add = new node<T>(data);
        node<T> *node_to_edit = head;
        int in = 0;
        while (in != index - 1)
        {
            ++in;
            node_to_edit = node_to_edit->next;
            if (node_to_edit == nullptr)
                return; // will do nothing if index is incorrect
        }
        node_to_add->next = node_to_edit->next;
        node_to_edit->next = node_to_add;
        std::cout << "Node created ---" << ++node_count << std::endl;
    }
    void insert_after(node<T> *prev_node, const T &data)
    {
        if (prev_node == nullptr)
            return;
        node<T> *node_to_add = new node<T>(data);
        node<T> *temp_node_ptr = prev_node->next;
        prev_node->next = node_to_add;
        node_to_add->next = temp_node_ptr;
        std::cout << "Node created ---" << ++node_count << std::endl;
    }
    // Deletion
    void pop_front()
    {
        // if the list is empty
        if (head == nullptr)
            return;
        std::cout << "Node removed ---" << --node_count << std::endl;
        // else update the head to head->next and free the previous head
        node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    void pop_back()
    {
        // if the list is empty
        if ((head == nullptr))
            return;
        std::cout << "Node removed ---" << --node_count << std::endl;
        if (head->next == nullptr)
        {
            delete head;
            head == nullptr;
            return;
        }
        // else traverse to the end
        node<T> *end = head;
        while (end->next->next != nullptr)
        {
            end = end->next;
        }
        // now remove the last element
        node<T> *temp = end->next;
        delete temp;
        // update the end.next
        end->next = nullptr;
    }
};
template <typename T>
long f_list<T>::node_count = 0;
#endif
// FORWARD_LIST_H
//
/*
    1. Messages should be displayed after deletion or creation has occured.
*/