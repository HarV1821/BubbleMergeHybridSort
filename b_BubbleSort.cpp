#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std; 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n - 1; i++) 

		// Last i elements are already 
		// in place 
		for (j = 0; j < n - i - 1; j++) 
			if (arr[j] > arr[j + 1]) 
				swap(arr[j], arr[j + 1]); 
} 

// Function to print an array 
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

int main()
{
    // 1. Read data from file
    ifstream inputFile("SampleDataset_5kE.txt");  // Replace 'data.txt' with your file name
    string line;
    vector<int> arr;

    if (inputFile.is_open()) {
        getline(inputFile, line); 
        inputFile.close();
    } else {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // 2. Parse data into integers
    stringstream ss(line);
    string numStr;

    while (getline(ss, numStr, ',')) {
        arr.push_back(stoi(numStr)); 
    }

    // 3. Convert vector to array for sorting (if needed)
    int* arrPtr = arr.data();
    int N = arr.size();

    // 4. Start timing the sorting
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arrPtr, N);
    auto end = chrono::high_resolution_clock::now();

    // 5. Calculate and display runtime
    chrono::duration<double, milli> elapsed = end - start;
    cout << "Sorting time: " << elapsed.count() << " ms" << endl;

    // 6. Print sorted array (optional)
    // printArray(arrPtr, N);

    return 0;
}