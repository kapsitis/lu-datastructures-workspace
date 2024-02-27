#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <chrono>
#include <sstream>
#include <algorithm> //For std::min_element and std::max_element
#include "list.h"

using namespace std;
using namespace std::chrono;

using namespace std;

void printSet(set<int> ss) {
    cout << "{";
    for (int s: ss) {
        cout << s << ",";
    }
    cout << "}";
}

void printVector(vector<int> ss) {
    cout << "[";
    for (int s: ss) {
        cout << s << ",";
    }
    cout << "]";
}

int getAllFragments(const vector<int>& input, vector<int>& output) {
    int len = input.size(); 
    int left = 0; 
    int right = 0;
    int result = 0; 
    set<int> current; 
    while (left <= len - 1) {
        if (right <= len - 1 && current.find(input[right]) == current.end()) {
            current.insert(input[right]);
            if ((right + 1) - left > result) {
                output.clear();
                output.push_back(left+1);
                result = (right+1) - left;
            }
            else if ((right + 1) - left == result) {
                if (output.size() > 0 && output.back() <= left) {
                    output.push_back(left+1);
                }
            }
            right += 1; 
            
            // cout << "(" << left << "," << right << "," << result << ")"; 
            // printSet(current);
            // cout << endl;
        }
        else {
            current.erase(input[left]);
            left += 1;
            // cout << "(" << left << "," << right << "," << result << ")"; 
            // printSet(current);
            // cout << endl;
        }
    }
    return result;
}



int main() {
    auto clockStart = high_resolution_clock::now();

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    int numIntegers;
    inputFile >> numIntegers;
    vector<int> numbers;
    for (int i = 0; i < numIntegers; ++i) {
        int number;
        inputFile >> number;
        numbers.push_back(number);
    }
    inputFile.close();

    vector<int> output; 
    int maxLength = getAllFragments(numbers, output);

    if (!numbers.empty()) { 
        ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            outputFile << maxLength << '\n';
            int fragmentCount = output.size(); 
            outputFile << fragmentCount << '\n';
            int fragment = 0; 
            for (int o: output) {
                outputFile << o;
                if (fragment++ != fragmentCount - 1) {
                    outputFile << " ";
                }
            }
            outputFile << '\n'; 
            outputFile.close();
        }
        else {
            cerr << "Error opening output file" << endl;
            return 1;
        }
    }
    else {
        cerr << "No numbers to process" << endl;
        return 1;
    }

    auto clockStop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(clockStop - clockStart);
    cout << "Execution time: " << duration.count() << " microseconds\n";
    return 0;
}
