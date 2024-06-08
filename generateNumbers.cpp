#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int main() {
    const int NUM_ELEMENTS = 6000;
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 100;

    vector<int> randomNumbers(NUM_ELEMENTS); // Create a vector to store the numbers

    // Seed the random number generator with the current time
    srand(time(0)); 

    // Generate random numbers and store them in the vector
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        randomNumbers[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    cout << "Generated numbers:\n";
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        cout << randomNumbers[i];
        if (i < NUM_ELEMENTS - 1) { // Check if it's not the last element
            cout << ", "; // Print comma and space
        }
    }
    cout << endl; // Add a newline at the end for formatting

    return 0;
}