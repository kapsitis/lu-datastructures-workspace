#include "arraystack.h"

class StackSet
{
private:
    ArrayStack stack1; // contains all the elements
    ArrayStack stack2; // temporary area for storing the elements

public:
    StackSet();
    // return true iff there was no duplicate
    bool insert(std::string s);
    int size();
    void print();
};
