#include "list.hpp"

// Constructors
SingleList::SingleList() : _head{nullptr} {}
SingleList::SingleList(size_t size, int val)
{
    _head = new Node(val);
    --size;
    Node* tmp = _head;
    for (size_t i = 0; i < size; i++) 
    {
        tmp->_next = new Node(val);
        tmp = tmp->_next;
    }
} 

SingleList::SingleList(std::initializer_list<int> il)
{
    for (auto elem : il) 
    {
        push_back(elem);
    }
}

SingleList::SingleList(const SingleList& other)
{
    _head = other._head;
    Node* tmp = other._head;
    while (!tmp)
    {
        push_back(tmp->_val);
        tmp = tmp->_next;
    }
}

SingleList& SingleList::operator=(const SingleList& other)
{

}

SingleList::SingleList(SingleList&& other) noexcept : _head{other._head}
{
    other._head = 0;
}
// Member functions
void SingleList::push_back(int val)
{
    if (!_head) _head = new Node(val);
    else
    {
        Node* tmp = _head;
        while(tmp->_next != nullptr)
        {
            tmp = tmp->_next;
        }
        tmp->_next = new Node(val);
    }
}