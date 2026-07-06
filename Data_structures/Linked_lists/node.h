#ifndef NODE_H
#define NODE_H
template <typename T>
class node
{
public:
    T *data;
    node *next;
    // Constructor/Destructor
    node(T data)
    {
        this->data = new T(data);
        this->next = nullptr;
    }
    ~node()
    {
        delete (this->data);
    }
};
#endif // NODE_H