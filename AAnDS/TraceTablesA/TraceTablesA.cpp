// TraceTablesA.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Include Stuff and declare namespace
#include <iostream>
#include <sstream>
#include <istream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include "MethodMadness.h"
using namespace std;

// Instantiate Method Holder Class
MethodMadness Memes =  MethodMadness();

////////////////////////////////////////////////////////////////////////
// Declare Functions

int LessEfficientSearchMain();
int EfficientSearchMain();
int LessEfficientSortMain();
int EfficientSortMain();
int MoreEfficientSumMain();
int LessEfficientSumMain();
int SimpleChronoMain();
int QuickSortMain();
int MergeSortMain();
int InsertionSortMain();
int BubbleSortMain();
int ChronoRawMain();

////////////////////////////////////////////////////////////////////////

// True Program Main
int main() {
    // Console Welcome
    cout << "\n\t\tHello World!" << endl;
    // AAAAAAAAAAAAAAAAA
    cout << "\tEnter the number to run the corresponding module." << endl;
    cout << "\t1 - Less Efficient Search Main" << endl << "\t2 - Efficient Search Main" << endl << "\t3 - Less Efficient Sort Main" << endl;
    cout << "\t4 - Efficient Sort Main" << endl << "\t5 - More Efficient Sum Main" << endl << "\t6 - Less Efficient Sum Main" << endl;
    cout << "\t7 - Simple Chrono Main" << endl << "\t8 - Quick Sort Main" << endl << "\t9 - Merge Sort Main" << endl;
    cout << "\t10 - Insertion Sort Main" << endl << "\t11 - Bubble Sort Main" << endl << "\t12 - Chrono Main" << endl;
    cout << "\tAll other inputs will exit out." << endl;
    
    // Switch Case
    try {
        int userChoice;
        cout << "\n\tChoice: ";
        cin >> userChoice;
        cout << endl;
        switch (userChoice) 
        {
            case 1:
                LessEfficientSearchMain();
                break;
            case 2:
                EfficientSearchMain();
                break;
            case 3:
                LessEfficientSortMain();
                break;
            case 4:
                EfficientSortMain();
                break;
            case 5:
                MoreEfficientSumMain();
                break;
            case 6:
                LessEfficientSumMain();
                break;
            case 7:
                SimpleChronoMain();
                break;
            case 8:
                QuickSortMain();
                break;
            case 9:
                MergeSortMain();
                break;
            case 10:
                InsertionSortMain();
                break;
            case 11:
                BubbleSortMain();
                break;
            case 12:
                // Chrono Raw main now does bubble sort 5 times
                // and takes an average of the time taken per sort.
                ChronoRawMain();
                break;
            default:
                break;
        }
    }
    catch (...)
    {} // Generic Catch
    

    return 0;
}

// Less Efficient Search Main           # 1
int LessEfficientSearchMain() {
    const int SIZE = 1000000;
    int* arr = new int[SIZE]; // Allocate memory dynamically

    // Initialize array with random values
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % SIZE;
    }

    int key = rand() % SIZE; // Random key to search for

    auto start = chrono::high_resolution_clock::now();
    int result = Memes.lessEfficientLinearSearch(arr, SIZE, key);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    if (result != -1) {
        cout << "Key found at index " << result << endl;
    }
    else {
        cout << "Key not found" << endl;
    }

    cout << "Time taken for less efficient search: " << duration.count() << " seconds" << endl;

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

// Efficient Search Main                # 2
int EfficientSearchMain() {
    const int SIZE = 1000000;
    int* arr = new int[SIZE]; // Allocate memory dynamically

    // Initialize array with sorted values
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i;
    }

    int key = rand() % SIZE; // Random key to search for

    auto start = chrono::high_resolution_clock::now();
    int result = Memes.efficientBinarySearch(arr, SIZE, key);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    if (result != -1) {
        cout << "Key found at index " << result << endl;
    }
    else {
        cout << "Key not found" << endl;
    }

    cout << "Time taken for efficient search: " << duration.count() << " seconds" << endl;

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

// Less Efficient Sort Main             # 3
int LessEfficientSortMain() {
    const int SIZE = 1000; // Reduced size for demonstration
    int* arr = new int[SIZE]; // Allocate memory dynamically

    // Initialize array with random values
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 1000;
    }

    auto start = chrono::high_resolution_clock::now();
    Memes.lessEfficientSort(arr, SIZE);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Time taken for less efficient sort: " << duration.count() << " seconds" << endl;

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

// Efficient Sort Main                  # 4
int EfficientSortMain() {
    const int SIZE = 1000000;
    int* arr = new int[SIZE]; // Allocate memory dynamically

    // Initialize array with random values
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 1000;
    }

    auto start = chrono::high_resolution_clock::now();
    Memes.efficientSort(arr, SIZE);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Time taken for efficient sort: " << duration.count() << " seconds" << endl;

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

// More Efficient Sum Main              # 5
int MoreEfficientSumMain() {
    const int SIZE = 1000000;
    int* arr = new int[SIZE]; // Allocate memory dynamically

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i;
    }

    auto start = chrono::high_resolution_clock::now();
    int result = Memes.efficientSum(arr, SIZE);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sum: " << result << endl;
    cout << "Time taken by efficient algorithm: " << duration.count() << " seconds" << endl;

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

// Less Efficient Sum Main              # 6
int LessEfficientSumMain() {
    const int SIZE = 1000000;
    int* arr = new int[SIZE]; // Allocate memory dynamically

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i;
    }

    auto start = chrono::high_resolution_clock::now();
    int result = Memes.lessEfficientSum(arr, SIZE);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sum: " << result << endl;
    cout << "Time taken by less efficient algorithm (iterative): " << duration.count() << " seconds" << endl;

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

// Simple Chrono Main                   # 7
int SimpleChronoMain() {
    // Start measuring time
    auto start = chrono::high_resolution_clock::now();

    // Call the algorithm
    Memes.myAlgorithm();

    // Stop measuring time and calculate duration
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Output the duration
    cout << "Time taken by the algorithm: " << duration.count() << " seconds" << endl;

    return 0;
}

// Chrono Raw Main                      # 12
int ChronoRawMain() {
    float total = 0;
    vector<int> arr2 = { 69, 420, 42, 64, 32, 9, 11, 8, 5 };
    for (int i = 0; i < 5; i++) {
        auto countStart = chrono::steady_clock::now();
        // Sort goes here
        Memes.bubbleSort(arr2);
        //
        auto countEnd = chrono::steady_clock::now();
        chrono::duration<double, std::milli> countDur = countEnd - countStart;
        total += countDur.count();
    }
    
    cout << "Time taken " << total/5 << endl;

    return 0;
}

// Quick Sort Main                      # 8
int QuickSortMain() {
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    Memes.quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Merge Sort Main                      # 9
int MergeSortMain() {
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    Memes.mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Insertion Sort Main                  # 10
int InsertionSortMain() {
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    Memes.insertionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Bubble Sort Main                     # 11
int BubbleSortMain() {
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    Memes.bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
