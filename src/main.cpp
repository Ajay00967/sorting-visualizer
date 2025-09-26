#include "sorting.hpp"
#include "visualizer.hpp"
#include <random>
#include <algorithm>

std::vector<int> generateRandomArray(int size, int minVal = 10, int maxVal = 500) {
    std::vector<int> arr(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }

    return arr;
}


int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualizer");

    // ArrayState arr = {50, 200, 150, 300, 100};
    // ArrayState arr = generateRandomArray(100, 350, 500);
    ArrayState arr(10);
    // std::iota(arr.begin(), arr.end(), 1);             // fill 1..50
    for (int i = 0; i < (int)arr.size(); i++) arr[i] = 2 * i + 5;
    std::shuffle(arr.begin(), arr.end(), std::mt19937{std::random_device{}()});


    // SortSteps steps = bubbleSort(arr);
    // SortSteps steps = insertionSort(arr);
    // SortSteps steps = quickSort(arr);
    SortSteps steps = mergeSort(arr);

    showSortingSteps(window, steps, 20);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}