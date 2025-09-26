#include "sorting.hpp"

void merge(ArrayState& arr, int start, int mid, int end, SortSteps& steps) {

    // Here in the given array, the region from [start, mid] and [mid+1, end] is sorted
    // we need to merge it 

    ArrayState temp;

    int i = start, j = mid + 1;

    // push the smaller value in the temp arr :)
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // for remaining arr1 (if any)
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // for remaining arr2 (if any)
    while (j <= end) {
        temp.push_back(arr[j++]);
    }

    // copy the sorted array back into the 'arr'
    int k = 0;
    while (k < (int)temp.size()) {
        arr[start + k] = temp[k];
        k++;
    }

    steps.push_back(arr); // add teh state to the steps
}

void sort(ArrayState& arr, int start, int end, SortSteps& steps) {

    if (start >= end) return;

    int mid = start + (end - start) / 2;

    sort(arr, start, mid, steps); // sort the left half

    sort(arr, mid + 1, end, steps); // sort the right half 

    merge(arr, start, mid, end, steps); // merge the both half, in this step only the steps array will be updated
}

SortSteps mergeSort(const ArrayState& arr) {

    ArrayState state(arr);
    SortSteps merge_steps;

    sort(state, 0, (int)state.size() - 1, merge_steps);

    return merge_steps;
}