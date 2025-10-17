#include <iostream>
#include <initializer_list>

struct Node 
    {
        int _val;
        Node* _next;
        Node() : _val(0), _next(nullptr) {}
        Node(int val) : _val{val}, _next{nullptr} {}
        Node(int val, Node* next) : _val{val}, _next{next} {}
};

class SingleList
{
private:
    
    Node* _head;

public:
    // Constructors
    SingleList();
    SingleList(size_t size, int val);
    SingleList(std::initializer_list<int> il);
    SingleList(const SingleList& other);
    SingleList& operator=(const SingleList& other);
    SingleList(SingleList&& other) noexcept;
    SingleList& operator=(SingleList&& other) noexcept;
    ~SingleList();

    // Operator overloading
    friend SingleList operator+(const SingleList& lhs, const SingleList& rhs);
    void operator+=(const SingleList& other);
    friend bool operator==(const SingleList& lhs, const SingleList& rhs);
    friend bool operator!=(const SingleList& lhs, const SingleList& rhs);
    Node& operator[](size_t index) const;
    bool operator!() const;
    SingleList& operator++();
    SingleList operator++(int);
    
    // Member functions
    void push_front(int val);
    void push_back(int val);
    void pop_front();
    void pop_back();
    // Helper functions
    void copy(const SingleList& other);
    void clear();
};