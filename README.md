# sorting
Sorting algorithms

The following sorting algorithms are available: 

template "class T"\
<<<<<<< HEAD
class Sorting 

=======
class Sorting {

public:
>>>>>>> 1c3055d6bcb677a4220e638fffb005a72dcb7148
1.    void printArray(T *start, T *end);
2.    void insertionSort(T *start, T *end);
3.    void shellSort(T *start, T *end, int *seg_array, int n);
4.    void selectionSort(T *start, T *end);
5.    void bubbleSort(T *start, T *end);
6.    void quickSort(T *start, T *end);
7.    void mergeSort(T *start, T *end);
<<<<<<< HEAD
=======

}
>>>>>>> 1c3055d6bcb677a4220e638fffb005a72dcb7148

Note:
- T *start is the first element of the array, T *end is the element after the last element of the array.
- int *seg_array is an array of the size of a segment in increasing order.
- int n is the number of elements in seg_array.
