/*
    Selection Sort
        Runtime: O(n^2) average and worst case.
        Memory: O(1)
        Description: Selection sort is the child's algorithm: simple, but inefficient. Find the smallest element using a linear scan and move it to the front (swapping it with the front element).Then, find the second smallest and move it, again doing a linear scan. Continue doing this until all the elements are in place.
*/

#include <iostream>
#include <limits>

void selectionSort (int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        int min = std::numeric_limits<int>::max();
        int minIndex = -1;
        for (int j = i; j < arraySize; j++) {
            if (min > array[j]) {
                min = array[j];
                minIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
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

    selectionSort(array, arraySize);

    std::cout << "final output: [ ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}
