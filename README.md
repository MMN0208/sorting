# sorting
Sorting algorithms

The following sorting algorithms are available: 

template <class T>
class Sorting {
public:
    void printArray(T *start, T *end);
    void insertionSort(T *start, T *end);
    void shellSort(T *start, T *end, int *seg_array, int n);
    void selectionSort(T *start, T *end);
    void bubbleSort(T *start, T *end);
    void quickSort(T *start, T *end);
    void mergeSort(T *start, T *end);
}

Note:
- T *start is the first element of the array, T *end is the element after the last element of the array.
- int *seg_array is an array of the size of a segment in increasing order.
- int n is the number of elements in seg_array.