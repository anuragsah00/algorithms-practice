/*
    Bubble Sort
        Runtime: O(n^2) average and worst case
        Memory: O(1)
        Description: In bubble sort, we start at the beginning of the array and swap the first two elements if the first is greater than the second. Then, we go to the next pair, and so on, continuously making sweeps of the array until it is sorted. In doing so, the smaller items slowly"bubble" up to the beginning of the list.
*/

#include <iostream>

void bubbleSortOpt (int array[], int arraySize) {
    bool sorted = false;
    int temp;
    int largestIndex = arraySize - 1;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < largestIndex; i++) {
            if (array[i] > array[i + 1]) {
                sorted = false;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        largestIndex--;
    }
}

void bubbleSort (int array[], int arraySize) {
    bool sorted = false;
    int temp;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < arraySize - 1; i++) {
            if (array[i] > array[i + 1]) {
                sorted = false;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main (int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Please input space seperated integers" << std::endl;
        return -1;
    }
    int arraySize = argc - 1;
    int array[arraySize];
    for (int i = 1; i < argc; i++) {
        array[i - 1] = std::atoi(argv[i]);
    }

    bubbleSortOpt(array, arraySize);

    std::cout << "final output: [ ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}
