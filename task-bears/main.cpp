#include <iostream>
#include <fstream>
#include <string>

#include "arraystack.h"
#include "stackset.h"

using namespace std;
int main() {

/*
    ArrayStack as;
    as.push("aaa");
    as.push("bbb");
    as.push("ccc");
    as.print();
    cout << "POP" << as.pop() << endl; // ccc
    as.print();

    cout << "POP" << as.pop() << endl; // bbb
    cout << "POP" << as.pop() << endl; // aaa
*/

    
    ifstream input("bears.in");
    int N;
    input >> N;
    StackSet urls;
    for (int i =0 ; i < N; i++) {
        string line;
        input >> line;
        // add new element to the set (ignore, if it exists)
        urls.insert(line);
    }
    input.close();

    urls.print();
    ofstream output("bears.out");
    output << urls.size() << endl;  // ask the size of the set. 
    output.close();
    
}