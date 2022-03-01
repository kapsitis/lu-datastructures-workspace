#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Triplet {
    public:
    int num;
    int idx;
    int dist;

    Triplet(int n, int i, int d) {
        num = n;
        idx = i; 
        dist = d;
    }

    void print() {
        cout << "("<< num << ", " << idx << ", " << dist << ")"; 
    }
};


struct compare{
  public:
  bool operator()(Triplet& a,Triplet& b) // overloading both operators 
  {
      if (a.dist > b.dist) {
          return true;
      } 
      else if (a.dist == b.dist && a.idx > b.idx) {
          return true;
      }
      return false;      
   }
};


int main()
{
    std::priority_queue<Triplet, vector<Triplet>, compare> q;
    const auto data = {Triplet(1,2,3), Triplet(1,3,3), Triplet(1,5,3), Triplet(1,2,6)};

    for (Triplet t : data) 
        q.push(t);

    while (q.size() > 0)
    {
        Triplet tt = q.top();
        tt.print();
        cout << endl;
        q.pop();
    }
}