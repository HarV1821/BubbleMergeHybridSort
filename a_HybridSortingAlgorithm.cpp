#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>

// Threshold for Bubble Sort
const int THRESHOLD = 100;

// Function for merging two halves
void merge(std::vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);
    
    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; ++i)
        leftArray[i] = array[left + i];
    for (int i = 0; i < n2; ++i)
        rightArray[i] = array[mid + 1 + i];
    
    // Merge temporary arrays back into array[left right]
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            ++i;
        } else {
            array[k] = rightArray[j];
            ++j;
        }
        ++k;
    }
    
    // Copy remaining elements of leftArray[], if any
    while (i < n1) {
        array[k] = leftArray[i];
        ++i;
        ++k;
    }
    
    // Copy remaining elements of rightArray[], if any
    while (j < n2) {
        array[k] = rightArray[j];
        ++j;
        ++k;
    }
}

// Bubble Sort Function
void bubbleSort(std::vector<int>& array, int left, int right) {
    for (int i = left; i < right; ++i) {
        for (int j = left; j < right - (i - left); ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

// Hybrid Merge Sort function
void hybridMergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        if ((right - left + 1) <= THRESHOLD) {
            // Use Bubble Sort for small sub-arrays
            bubbleSort(array, left, right);
        } else {
            // Find the middle point
            int mid = left + (right - left) / 2;
            
            // Sort first and second halves
            hybridMergeSort(array, left, mid);
            hybridMergeSort(array, mid + 1, right);
            
            // Merge the sorted halves
            merge(array, left, mid, right);
        }
    }
}

int main() {
    std::vector<int> array;
    std::ifstream inputFile("data_set_150000.txt");  // Replace with filename
    std::string line, numStr;

    // Read the line from the file
    if (getline(inputFile, line)) {
        std::stringstream ss(line);

        // Read the comma-separated integers
        while (getline(ss, numStr, ' ')) {
            int num = std::stoi(numStr);
            array.push_back(num);
        }
    }
    inputFile.close();

    using namespace std::chrono;
    time_point<system_clock> start, end;

    // Start Recording of Time
    start = system_clock::now();

    int arraySize = array.size();
    std::cout << "Array size: " << arraySize << std::endl;

    hybridMergeSort(array, 0, arraySize - 1);

    // End Recording of Time
    end = system_clock::now();

    duration<double, std::milli> elapsed_milliseconds = end - start;
    time_t end_time = system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_milliseconds.count() << " ms\n";

    return 0;
}
