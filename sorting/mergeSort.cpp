/*
    Merge Sort
        Runtime: O( n log (n) ) average and worst case.
        Memory: Depends.
        Merge sort divides the array in half, sorts each of those halves, and then merges them back together. Each of those halves has the same sorting algorithm applied to it. Eventually, you are merging just two single- element arrays. It is the "merge" part that does all the heavy lifting.
*/

#include <iostream>
#include <limits>

void merge (int array[], int helper[], int startIndex, int middleIndex, int endIndex) {
    for (int i = startIndex; i <= endIndex; i++) {
        helper[i] = array[i];
    }

    int leftHelperIndex = startIndex;
    int rightHelperIndex = middleIndex + 1;
    int currentIndex = startIndex;

    while (leftHelperIndex <= middleIndex && rightHelperIndex <= endIndex) {
        if (helper[leftHelperIndex] < helper[rightHelperIndex]) {
            array[currentIndex] = helper[leftHelperIndex];
            leftHelperIndex++;
        } else {
            array[currentIndex] = helper[rightHelperIndex];
            rightHelperIndex++;
        }
        currentIndex++;
    }

    int remaining = middleIndex - leftHelperIndex;
    for (int i = 0; i <= remaining; i++) {
        array[currentIndex + i] = helper[leftHelperIndex + i];
    }
}

void mergeSort (int array[], int helper[], int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int middleIndex = (startIndex + endIndex) / 2;
        mergeSort(array, helper, startIndex, middleIndex);
        mergeSort(array, helper, middleIndex + 1, endIndex);
        merge(array, helper, startIndex, middleIndex, endIndex);
    }
}

void mergeSort (int array[], int arraySize) {
    mergeSort(array, new int[arraySize], 0, arraySize - 1);
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

    mergeSort(array, arraySize);

    std::cout << "final output: [ ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}
