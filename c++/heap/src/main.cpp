/**
 * @file main.cpp
 * @author Guilherme El Kadri (guilhermeelkadri@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <heap.hpp>

int main()
{
    Heap<int> maxHeap(10);

    // Insert elements into the max heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(15);
    maxHeap.insert(30);

    std::cout << "Max Heap: ";
    while (!maxHeap.isEmpty())
    {
        std::cout << maxHeap.removeRoot() << " ";
    }
    std::cout << std::endl;

    Heap<int> minHeap(8, false);

    // Insert elements into the min heap
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(30);

    std::cout << "Min Heap: ";
    while (!minHeap.isEmpty())
    {
        std::cout << minHeap.removeRoot() << " ";
    }
    std::cout << std::endl;

    return 0;
}