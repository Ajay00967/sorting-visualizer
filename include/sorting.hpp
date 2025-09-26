#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>

using ArrayState = std::vector<int>;
using SortSteps = std::vector<ArrayState>;

SortSteps bubbleSort(const ArrayState& arr);

SortSteps insertionSort(const ArrayState& arr);

SortSteps quickSort(const ArrayState& arr);

SortSteps mergeSort(const ArrayState& arr);

#endif
