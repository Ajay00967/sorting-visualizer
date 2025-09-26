#include "sorting.hpp"

int partition(ArrayState& arr, int start, int end, SortSteps& steps) {

    int pivot = arr[end];
    int idx = start - 1;

    for (int i = start; i < end; i++) {

        if (arr[i] <= pivot) {
            idx++;
            std::swap(arr[i], arr[idx]);
            steps.push_back(arr); // add the state to the steps
        }

    }

    idx++;
    std::swap(arr[end], arr[idx]);
    steps.push_back(arr);

    return idx;
}

// Recursive quick sort to the array
void quick(ArrayState& arr, int start, int end, SortSteps& steps) {
    if (start >= end) return;

    int pivot_Index = partition(arr, start, end, steps);

    quick(arr, start, pivot_Index - 1, steps); // sort the half before the Pivot

    quick(arr, pivot_Index + 1, end, steps); // sor teh half after the Pivot
}


SortSteps quickSort(const ArrayState& arr) {

    ArrayState state = arr;
    SortSteps quick_steps;

    quick(state, 0, state.size() - 1, quick_steps);

    return quick_steps;
}