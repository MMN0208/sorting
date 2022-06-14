#ifndef SORTING_H
#define SORTING_H

template <class T>
class Sorting {
    void sortSegment(T *start, T *end, int segment_idx, int num_segment);
    T *partition(T *start, T *end);
    void merge(T *left, T *middle, T *right);
    void swap(T *a, T *b);
public:
    void printArray(T *start, T *end);
    void insertionSort(T *start, T *end);
    void shellSort(T *start, T *end, int *seg_array, int n);
    void selectionSort(T *start, T *end);
    void bubbleSort(T *start, T *end);
    void quickSort(T *start, T *end);
    void mergeSort(T *start, T *end);
};

#endif