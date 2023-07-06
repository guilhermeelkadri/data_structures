# Heap Implementation in C++

This is a C++ implementation of a heap data structure, also known as a binary heap. A heap is a complete binary tree where each node satisfies the heap property. In this implementation, the heap can be either a max-heap or a min-heap based on the provided flag.

## Features

- Support for both max-heap and min-heap.
- Dynamic resizing of the underlying array.
- Efficient insertion and removal of elements.
- Heapify operations to maintain the heap property.

## Class Overview

### `Heap<T>`

The `Heap` class is a template class that represents the heap data structure. It has the following private member variables:

- `std::unique_ptr<T[]> data`: A dynamically allocated array to store the elements of the heap.
- `size_t capacity`: The capacity of the heap (maximum number of elements it can hold).
- `size_t size`: The current number of elements in the heap.
- `bool isMaxHeap`: A flag indicating whether the heap is a max-heap (`true`) or a min-heap (`false`).

It provides the following public member functions:

- `Heap(size_t capacity, bool isMaxHeap = true)`: Constructor to initialize the heap with the given capacity and heap type.
- `bool isEmpty() const`: Checks if the heap is empty.
- `void insert(T value)`: Inserts a new element into the heap.
- `T removeRoot()`: Removes and returns the root element of the heap.

### Private Helper Functions

The `Heap` class also includes several private helper functions:

- `size_t parent(size_t index)`: Returns the index of the parent node of a given index.
- `size_t leftChild(size_t index)`: Returns the index of the left child node of a given index.
- `size_t rightChild(size_t index)`: Returns the index of the right child node of a given index.
- `void heapifyUp(size_t index)`: Restores the heap property by moving an element up the heap.
- `void heapifyDown(size_t index)`: Restores the heap property by moving an element down the heap.
- `bool compare(const T& a, const T& b)`: Compares two elements based on the heap type and returns `true` if the comparison condition holds.

**Note:** This is a simplified implementation and does not include error handling for all possible scenarios. It is always recommended to add appropriate error handling and additional functionalities as per your specific requirements.