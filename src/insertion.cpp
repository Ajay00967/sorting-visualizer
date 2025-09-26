#include "sorting.hpp"

SortSteps insertionSort(const ArrayState& arr) {

    ArrayState state(arr);
    SortSteps steps;

    for (int i = 1; i < (int)state.size(); i++) {

        int curr = state[i];
        int prev = i - 1;

        while (prev >= 0 && state[prev] > curr) {

            state[prev + 1] = state[prev];
            prev--;

            steps.push_back(state);
        }

        state[prev + 1] = curr;
        steps.push_back(state);
    }

    return steps;
}