#include "sorting.h"
#include <iostream>
using namespace std;

template <class T>
void Sorting<T>::swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>
void Sorting<T>::printArray(T *start, T *end) {
    long length = end - start;
    if(length > 0) {
        for(long i = 0; i < length; i++) {
            cout << start[i] << " ";
        }
        cout << endl;
    }
    return;
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end) {
    long length = end - start;
    if(length > 1) {
        for(long i = 1; i < length; i++) {
            T temp = start[i];
            int walker = i - 1;
            while(walker >= 0 && temp < start[walker]) {
                start[walker + 1] = start[walker];
                walker--;
            }
            start[walker + 1] = temp;
        }
    }
    return;
}

template <class T>
void Sorting<T>::sortSegment(T *start, T *end, int segment_idx, int num_segment) {
    long length = end - start;
    long current = segment_idx + num_segment;
    for(; current < length; current += num_segment) {
        T temp = start[current];
        int walker = current - num_segment;
        while(walker >= 0 && temp < start[walker]) {
            start[walker + num_segment] = start[walker];
            walker -= num_segment;
        }
        start[walker + num_segment] = temp;
    }
}

template <class T>
void Sorting<T>::shellSort(T *start, T *end, int *seg_array, int n) {
    long length = end - start;
    if(length > 1) {
        for(int i = n - 1; i >= 0; i --) {
            int k = seg_array[i];
            for(int j = 0; j < k; j++) {
                sortSegment(start, end, j, k);
            }
        }
    }
    return;
}

template <class T>
void Sorting<T>::selectionSort(T *start, T *end) {
    long length = end - start;
    if(length > 1) {
        for(long i = 0; i < length - 1; i++) {
            int smallest = i;
            for(long j = i + 1; j < length; j++) {
                if(start[smallest] > start[j]) {
                    smallest = j;
                }
            }
            if(smallest != i) {
                swap(&start[i], &start[smallest]);
            }
        }
    }
    return;
}

template <class T>
void Sorting<T>::bubbleSort(T *start, T *end) {
    long length = end - start;
    if(length > 1) {
        bool flag = false;
        for(long i = 0; i < length - 1 && !flag; i++) {
            flag = true;
            for(long j = length - 1; j > i; j--) {
                if(start[j - 1] > start[j]) {
                    flag = false;
                    swap(&start[j - 1], &start[j]);
                }
            }
        }
    }
    return;
}

template <class T>
T *Sorting<T>::partition(T *start, T *end) {
    T pivot = start[0];
    T *left = start - 1;
    T *right = end + 1;
    while(true) {
        do {
            right--;
        } while(*right > pivot);
        do {
            left++;
        } while(*left < pivot);
        if(left < right) {
            swap(&left[0], &right[0]);
        }
        else return right;
    }
}

template <class T>
void Sorting<T>::quickSort(T *start, T *end) {
    long length = end - start;
    if(length > 1) {
        T *pivot = partition(start, end - 1);
        quickSort(start, pivot + 1);
        quickSort(pivot + 1, end);
    }
    return;
}

template <class T>
void Sorting<T>::merge(T *left, T *middle, T *right) {
    long subArrL = middle - left + 1;
    long subArrR = right - middle;
    T *arrL = new T[subArrL];
    T *arrR = new T[subArrR];
    for(long i = 0; i < subArrL; i++) {
        arrL[i] = *(left + i);
    }
    for(long j = 0; j < subArrR; j++) {
        arrR[j] = *(middle + 1 + j);
    }
    long indexOfL = 0, indexOfR = 0, indexOfMerged = 0;
    while(indexOfL < subArrL && indexOfR < subArrR) {
        if(arrL[indexOfL] <= arrR[indexOfR]) {
            left[indexOfMerged] = arrL[indexOfL];
            indexOfL++;
        }
        else {
            left[indexOfMerged] = arrR[indexOfR];
            indexOfR++;
        }
        indexOfMerged++;
    }
    while(indexOfL < subArrL) {
        left[indexOfMerged] = arrL[indexOfL];
        indexOfL++;
        indexOfMerged++;
    }
    while(indexOfR < subArrR) {
        left[indexOfMerged] = arrR[indexOfR];
        indexOfR++;
        indexOfMerged++;
    }
    return;
}

template <class T>
void Sorting<T>::mergeSort(T *start, T *end) {
    long length = end - start;
    if(length > 1) {
        T *mid = start + (length - 1) / 2;
        mergeSort(start, mid + 1);
        mergeSort(mid + 1, end);
        merge(start, mid, end - 1);
    }
    return;
}

template class Sorting<int>;
template class Sorting<float>;
template class Sorting<double>;