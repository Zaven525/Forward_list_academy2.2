#include "list.hpp"

// Constructors
SingleList::SingleList() : _head{nullptr} {}
SingleList::SingleList(size_t size, int val)
{
    Node dummy;
    Node* tmp = &dummy;
    for (size_t i = 0; i < size; i++) 
    {
        tmp->_next = new Node(val);
        tmp = tmp->_next;
    }
    _head = dummy._next;
} 

SingleList::SingleList(std::initializer_list<int> il)
{
    Node dummy;
    Node* tmp = &dummy;

    for (auto elem : il) 
    {
        tmp->_next = new Node(elem);;
        tmp = tmp->_next;
    }
    _head = dummy._next;
}

SingleList::SingleList(const SingleList& other) : _head(nullptr)
{
    copy(other);
}

SingleList& SingleList::operator=(const SingleList& other)
{
    if (this != &other)
    {
        copy(other);
    }
    *this;
}

SingleList::SingleList(SingleList&& other) noexcept : _head{other._head}
{
    other._head = 0;
}

SingleList& SingleList::operator=(SingleList && other) noexcept
{
    if (this != &other)
    {
        clear();
        _head = other._head;
        other._head = 0;
    }
    return *this;
}

SingleList::~SingleList() 
{
    clear();
}


// Operator overlosding
SingleList operator+(SingleList& lhs, SingleList& rhs) 
{
    SingleList Nlhs(lhs);
    SingleList Nrhs = rhs;
    SingleList::Node* tmp = Nlhs._head;
    while (tmp->_next) tmp = tmp->_next;
    tmp->_next = Nrhs._head;
    return Nlhs;
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



// Helper functions
void SingleList::copy(const SingleList& other)
{
    clear();
    Node dummy;
    Node* tmp = &dummy;
    Node* tmp2 = other._head;
    while(tmp2)
    {
        tmp->_next = new Node(tmp2->_val);
        tmp = tmp->_next;
        tmp2 = tmp2->_next;
    }  
    _head = dummy._next; 
}

void SingleList::clear() 
{
    Node* tmp;
    while(_head)
    {
        tmp = _head;
        _head =  _head->_next;
        delete tmp;
    }
}