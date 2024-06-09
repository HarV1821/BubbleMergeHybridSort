#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, 
		int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] 
	// and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	// Initial index of first sub-array
	// Initial index of second sub-array
	auto indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 

	// Initial index of merged array
	int indexOfMergedArray = left; 

	// Merge the temp arrays back into 
	// array[left..right]
	while (indexOfSubArrayOne < subArrayOne && 
		indexOfSubArrayTwo < subArrayTwo) 
	{
		if (leftArray[indexOfSubArrayOne] <= 
			rightArray[indexOfSubArrayTwo]) 
		{
			array[indexOfMergedArray] = 
			leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else
		{
			array[indexOfMergedArray] = 
			rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) 
	{
		array[indexOfMergedArray] = 
		leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) 
	{
		array[indexOfMergedArray] = 
		rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], 
			int const begin, 
			int const end)
{
	// Returns recursively
	if (begin >= end)
		return; 

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

vector<int> readDataFromFile(const string& filename) {
    vector<int> data;
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string value;
            while (getline(ss, value, ',')) { // Split by ','
                data.push_back(stoi(value));  // Convert string to int
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
    return data;
}

int main() {
    using namespace std::chrono;
    time_point<system_clock> start, end;
    
    // 1. Read data from file
    string filename = "SampleDataset_25kE.txt"; // Replace with your file name
    vector<int> arr = readDataFromFile(filename);

    // 2. Start timing after conversion
    start = system_clock::now(); 

    // 3. Perform mergeSort
    mergeSort(&arr[0], 0, arr.size() - 1); // Use &arr[0] to pass underlying array

    // 4. End timing
    end = system_clock::now();

    // ... (Output sorted array and time calculations)
    duration<double, milli> elapsed_milliseconds = end - start;
    time_t end_time = system_clock::to_time_t(end);

    cout << "Sorting time: " << elapsed_milliseconds.count() << " ms\n";

    return 0;
}