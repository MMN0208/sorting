#include "./main/sorting.h"
#include <iostream>
using namespace std;

int main() {
    Sorting<int> s;
    int array[] = {10, 12, 4, 5, -2, 3, 9, 1, 0, 22};
    int n = sizeof(array) / sizeof(array[0]);
    int seg_array[] = {1, 3, 5};
    int n_seg = sizeof(seg_array) / sizeof(seg_array[0]);
    s.mergeSort(&array[0], &array[n]);
    s.printArray(&array[0], &array[n]);
    return 0;
}