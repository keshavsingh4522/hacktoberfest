#ifndef H_INTERFACE_STACK
#define H_INTERFACE_STACK

template <typename Type>
class stack_interface
{
public:
    virtual void push(const Type &val) = 0;
    virtual void push(Type &&val) = 0;
    virtual Type &top() = 0;
    virtual const Type &top() const = 0;
    virtual void pop() = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
};

#endif