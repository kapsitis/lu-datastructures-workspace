//#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Point {
public:
    int x, y;
    string name;
    Point(int x1, int y1) { x = x1; y = y1; }
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
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


    Point p1(3, 4);
    p1.name = "Name1";
    Point p2 = p1; 
    p2.y = 17; // does this also change p1? 
    p2.name[3] = '7';

    p1.print(); // (3,4) or (3,17)? 
    p2.print(); // (3, 17) - for sure
}