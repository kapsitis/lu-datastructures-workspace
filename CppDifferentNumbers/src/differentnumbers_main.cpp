#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "list.h"

using namespace std;
string toHex(const unsigned char* exported, const unsigned int exported_size) {
    std::stringstream hexStream;
    for (unsigned int i = 0; i < exported_size; ++i) {
        hexStream << std::hex << std::setfill('0') << std::setw(2) << (unsigned int)exported[i];
    }
    return hexStream.str();
}


int main() {
  List mylist;
  cout << mylist.f() << endl;
	
  const unsigned char* testString = (unsigned char*)"hello";
  //char* hex = NULL;
  //toHex(testString, &hex);
  size_t len = strlen((const char*)testString);

  string result = toHex(testString, (unsigned int)len);
  cout << "Result = " << hex << endl; 
  return 0;
}