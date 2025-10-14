#include <iostream>
#include <initializer_list>

class SingleList
{
private:
    struct Node 
    {
        int _val;
        Node* _next;
        Node(int val) : _val{val}, _next{nullptr} {}
        Node(int val, Node* next) : _val{val}, _next{next} {}
    };
    Node* _head;

public:
    // Constructors
    SingleList();
    SingleList(size_t size, int val);
    SingleList(std::initializer_list<int> il);
    SingleList(const SingleList& other);
    SingleList& operator=(const SingleList& other);
    SingleList(SingleList&& other) noexcept;
    // Member functions
    void push_back(int val);

    // Helper functions
    void copy(const SingleList& other);

};