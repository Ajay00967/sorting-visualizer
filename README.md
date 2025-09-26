# Sorting Visualizer

A **C++/SFML project** to visualize popular sorting algorithms in action. The visualizer animates each step of the algorithm, allowing you to **see how the array elements move and get sorted**.  

---

## Features

- **Multiple Sorting Algorithms**  
  - Bubble Sort  
  - Insertion Sort  
  - Quick Sort  
  - Merge Sort  

- **Customizable Array**  
For this you need to change the `main.cpp`
  - Generate a random array of any size
  - Option to shuffle a sequential array  

---

## Requirements

- **C++20 (or later)**  
- **SFML** (Graphics, Window, System)  

---

## Directory Structure

sorting-visualizer/
│
├── include/
│ ├── sorting.hpp
│ └── visualizer.hpp
│
├── src/
│ ├── main.cpp
│ ├── bubble.cpp
│ ├── insertion.cpp
│ ├── merge.cpp
│ ├── quick.cpp
│ └── visualizer.cpp
│
├── Makefile
└── README.md

---

## Build Instructions

1. **Clone the repository**
```bash
git clone https://github.com/Ajay00967/sorting-visualizer.git
cd sorting-visualizer
```
2. **Build the executables**
```bash
make
```
3. **Run the visualization**
```bash
./run
```
Future versions may include interactive options to select:

Algorithm type

Array type (random or shuffled)

