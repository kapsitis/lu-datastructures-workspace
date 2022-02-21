#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <string>

class ArrayStack
{
private:
    std::string elements[100];
    int count;

public:
    ArrayStack();
    void push(std::string s);
    void print();
    std::string pop();
    bool empty();
    int size();
};

#endif