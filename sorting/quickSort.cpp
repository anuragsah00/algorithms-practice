/*
    Merge Sort
        Runtime: O( n log (n) ) average and worst case.
        Memory: Depends.
        Merge sort divides the array in half, sorts each of those halves, and then merges them back together. Each of those halves has the same sorting algorithm applied to it. Eventually, you are merging just two single- element arrays. It is the "merge" part that does all the heavy lifting.
*/

#include <iostream>
#include <limits>

int getPartitions (int array[], int leftIndex, int rightIndex) {
    int pivotValue = array[(leftIndex + rightIndex) / 2];
    while (leftIndex <= rightIndex) {
        while (array[leftIndex] < pivotValue) {
            leftIndex++;
        }

        while (array[rightIndex] > pivotValue) {
            rightIndex--;
        }

        if (leftIndex <= rightIndex) {
            int temp = array[leftIndex];
            array[leftIndex] = array[rightIndex];
            array[rightIndex] = temp;
            leftIndex++;
            rightIndex--;
        }
    }
    return leftIndex;
}

void quickSort (int array[], int leftIndex, int rightIndex) {
    int pivotIndex = getPartitions(array, leftIndex, rightIndex);
    if (leftIndex < pivotIndex - 1) {
        quickSort(array, leftIndex, pivotIndex - 1);
    }
    if (rightIndex > pivotIndex) {
        quickSort(array, pivotIndex, rightIndex);
    }
}

void quickSort (int array[], int arraySize) {
    quickSort(array, 0, arraySize - 1);
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

    quickSort(array, arraySize);

    std::cout << "final output: [ ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}
