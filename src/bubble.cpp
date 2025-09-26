#include "sorting.hpp"

SortSteps bubbleSort(const ArrayState& arr) {

    int n = arr.size();
    ArrayState state = arr;
    SortSteps steps;

    for (int i = 0; i < n - 1; i++) { // loop for pushing every ith big element to the end (it's correct postion basically)
        for (int j = 0; j < n - i - 1; j++) {
            if (state[j] > state[j + 1]) {
                std::swap(state[j], state[j + 1]);
                steps.push_back(state); // push the state into the states
            }
        }
    }

    return steps;
}