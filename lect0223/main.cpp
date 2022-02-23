//#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Point {
public:
    int x, y;
    string name;
    list<int> myList;
    Point(int x1, int y1) { x = x1; y = y1; }
    void print() {
        cout << "(" << x << ", " << y << ", " << name << "," << myList.front() << ")" << endl;
    }
};


class vector
{
private:
    int sz;
    double *elem;

public:
    // overriding the default constructor.
    vector()
    {
        sz = 100;
        elem = new double[sz];
    }

    vector(int s) // non-default constructor (specify initial size)
        : sz{s}, elem{new double[s]}
    {
        for (int i = 0; i < sz; ++i)
            elem[i] = 0;
    }

    void assign(int pos, double val) {
        elem[pos] = val;
    }

    ~vector() { delete[] elem; }

    // initializer-list constructor
    vector::vector(std::initializer_list<double> lst) 
        : sz{static_cast<int>(lst.size())}, elem{new double[sz]}
    {
        std::copy(lst.begin(), lst.end(), elem); // copy lst to elem
    }

    void print()
    {
        cout << "[";
        for (int i = 0; i < sz; i++)
        {
            cout << elem[i];
            if (i < sz - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main()
{
    vector v; // empty vector v;
    vector w = v;
    vector v1(20); // vector with 20 elements [0.0, 0.0, ...., 0.0]
    v1.print();

    vector v2{1.0, 2.0, 3.0};
    v2.print();
 
    vector v3; 		
	v3 = v2; 
    v3.assign(2, 113.0); // 3.0 -> 113
    v3.print();

    v2.print(); // did this change as well?



    // Point p1(3, 4);
    // p1.name = "Name1";
    // p1.myList = list<int>{1,2};
    // Point p2 = p1;  // p2 = (3,4)
    // p2.y = 17; // does this also change p1 - NO! p1 still = (3,4)
    // p2.name[3] = 'Z';
    // p2.myList.front() = 117;  // it's deep copy. 

    // p1.print(); // (3,4) 
    // p2.print(); // (3, 17) - for sure
}