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
SingleList operator+(const SingleList& lhs, const SingleList& rhs) 
{
    SingleList result(lhs);
    Node* tmp = result._head;
    while (tmp->_next) tmp = tmp->_next;
    
    Node* rtmp = rhs._head;
    
    while (rtmp != nullptr)
    {
        tmp->_next = new Node(rtmp->_val);
        tmp = tmp->_next;
        rtmp = rtmp->_next;
    }
    return result;
}

void SingleList::operator+=(const SingleList& other)
{
    *this = *this + other;
}

bool operator==(const SingleList& lhs, const SingleList& rhs) 
{
    Node* itmp = lhs._head;
    Node* jtmp = rhs._head;
    while(itmp && jtmp)
    {
        if (itmp->_val != jtmp->_val)
        {
            return 0;
        }
        itmp = itmp->_next;
        jtmp = jtmp->_next;
    }
    return jtmp == nullptr && itmp == nullptr;
}

bool operator!=(const SingleList& lhs, const SingleList& rhs) 
{
    return !(lhs == rhs);
}

Node& SingleList::operator[](size_t index) const
{
    Node* tmp = _head;
    for (size_t i = 0; i < index; i++)
    {
        tmp = tmp->_next; 
    }

    if (!tmp) {
        throw std::out_of_range("Index out of bounds");
    }
    return *tmp;
}

bool SingleList::operator!() const
{
    return (_head == nullptr);
}

SingleList& SingleList::operator++() 
{
    push_back(0);
    return *this;
}

SingleList SingleList::operator++(int) 
{
    SingleList copy(*this);
    push_back(0);
    return copy;
}



// Member functions
void SingleList::push_front(int val)
{
    Node* tmp = new Node(val);
    tmp->_next = _head;
    _head = tmp;
}

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

void SingleList::pop_front()
{
    if (_head)
    {
        Node* tmp = _head;
        _head =  _head->_next;
        delete tmp;
    }
}

void SingleList::pop_back()
{
    Node* tmp = _head;
    while(tmp->_next)
    {
        tmp =  tmp->_next;
    }
    delete tmp;
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