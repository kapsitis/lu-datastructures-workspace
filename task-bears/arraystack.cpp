#include <iostream>
#include <string>

#include "arraystack.h"

using namespace std;
ArrayStack::ArrayStack()
{
    count = 0;
}

void ArrayStack::push(string s)
{
    elements[count] = s;
    count++;
}

void ArrayStack::print()
{
    cout << "Stack size is " << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "stack[" << i << "] = " + elements[i] << endl;
    }
}

// POP operation on a stack is possible iff count > 0.
// If stack size <= 0, print message and ignore
string ArrayStack::pop()
{
    string result = "";
    if (count <= 0)
    {
        cout << "ERROR: Popping and empty stack!!" << endl;
    }
    else {
        // KAP: These two lines need to be in correct order!
        count--;
        result = elements[count];
    }
    return result;
}

bool ArrayStack::empty()
{
    return (count == 0);
}

int ArrayStack::size()
{
    return count;
}
