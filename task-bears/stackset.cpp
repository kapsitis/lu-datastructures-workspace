#include <iostream>
#include <string>
#include "arraystack.h"
#include "stackset.h"

using namespace std;
// create an empty set
// make 2 empty stacks
StackSet::StackSet() { 
}

// return true iff there was no duplicate
bool StackSet::insert(string s) {
    // transfer all from stack1 to stack2, look for duplicates (==s)
    bool result = true; // assume there will be no duplicate

    while(!stack1.empty()) {
        string tmp = stack1.pop();
        if (tmp == s) {                
            result = false;
            break; // at this point you did not push this "s" to stack2. 
        }
        stack2.push(tmp);
    }

    // transfer everything back from stack2 to stack1
    while (!stack2.empty()) {
        string tmp = stack2.pop();
        stack1.push(tmp);
    }
    stack1.push(s);
    return result;
}

int StackSet::size() {
    // return the size
    return stack1.size();
}

void StackSet::print() {
    stack1.print();
}

