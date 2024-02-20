#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <sstream>
#include <algorithm> //For std::min_element and std::max_element
#include "list.h"

using namespace std;
using namespace std::chrono;


string toHex(const unsigned char* exported, const unsigned int exported_size) {
    std::stringstream hexStream;
    for (unsigned int i = 0; i < exported_size; ++i) {
        hexStream << std::hex << std::setfill('0') << std::setw(2) << (unsigned int)exported[i];
    }
    return hexStream.str();
}


int main() {
  auto start = high_resolution_clock::now();

    // Open the input file
    ifstream inputFile("input.txt");
    
    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file" << endl;
        return 1; // Return error code 1
    }
    
    int numIntegers;
    inputFile >> numIntegers; // Read the first number from the file, which indicates the number of integers
    
    vector<int> numbers; // Declare a vector to store the integers
    for (int i = 0; i < numIntegers; ++i) {
        int number;
        inputFile >> number; // Read each integer
        numbers.push_back(number); // Add the integer to the vector
    }
    
    inputFile.close(); // Close the input file

    // Print "Hello world\n"
    cout << "Hello world\n";




// Processing to find min and max
    if (!numbers.empty()) { // Ensure the vector is not empty
        int minValue = *min_element(numbers.begin(), numbers.end());
        int maxValue = *max_element(numbers.begin(), numbers.end());

        // Write the results to an output file
        ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            outputFile << minValue << '\n';
            outputFile << maxValue;
            outputFile.close();
        } else {
            cerr << "Error opening output file" << endl;
            return 1; // Return error code 1
        }
    } else {
        cerr << "No numbers to process" << endl;
        return 1; // Return error code 1
    }


    

    auto stop = high_resolution_clock::now();

    // Calculate the duration in milliseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Output the duration in milliseconds
    cout << "Execution time: " << duration.count() << " microseconds\n";

  return 0;
}
