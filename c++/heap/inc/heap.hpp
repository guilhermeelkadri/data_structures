/**
 * @file heap.hpp
 * @author Guilherme El Kadri (guilhermeelkadri@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <iostream>
#include <memory>

template <typename T>
class Heap
{
private:
    std::unique_ptr<T[]> data;
    size_t capacity;
    size_t size;
    bool isMaxHeap;

public:
    Heap(size_t capacity, bool isMaxHeap = true);

    bool isEmpty() const;
    void insert(T value);
    T removeRoot();

private:
    size_t parent(size_t index);
    size_t leftChild(size_t index);
    size_t rightChild(size_t index);

    void heapifyUp(size_t index);
    void heapifyDown(size_t index);
    bool compare(const T& a, const T& b);
};

template <typename T>
bool Heap<T>::compare(const T& a, const T& b) 
{
    return isMaxHeap ? (a > b) : (a < b);
}

template <typename T>
size_t Heap<T>::parent(size_t index)
{
    if (index == 0)
    {
        return 0;
    }

    return (index - 1) / 2;
}

template <typename T>
size_t Heap<T>::leftChild(size_t index)
{
    return (index * 2 + 1);
}

template <typename T>
size_t Heap<T>::rightChild(size_t index)
{
    return (index * 2 + 2);
}

template <typename T>
Heap<T>::Heap(size_t capacity, bool isMaxHeap) : capacity(capacity), size(0), isMaxHeap(isMaxHeap)
{
    data = std::make_unique<T[]>(capacity);
}

template <typename T>
bool Heap<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
void Heap<T>::insert(T value)
{
    if (size == capacity)
    {
        std::cout << "Heap is full. Cannot insert more elements." << std::endl;
        return;
    }

    data[size] = value;
    size++;

    heapifyUp(size - 1);
}

template <typename T>
T Heap<T>::removeRoot()
{
    if (isEmpty())
    {
        throw std::out_of_range("Heap is empty. Cannot extract maximum element.");
    }

    T maxElement = data[0];

    data[0] = data[size - 1];
    size--;
    heapifyDown(0);

    return maxElement;
}

template <typename T>
void Heap<T>::heapifyUp(size_t index)
{
    if (index <= 0)
    {
        return;
    }

    if (compare(data[index], data[parent(index)]))
    {
        std::swap(data[index], data[parent(index)]);

        heapifyUp(parent(index));
    }
}

template <typename T>
void Heap<T>::heapifyDown(size_t index)
{
    size_t largestElementIndex = index;

    if ((leftChild(index) < size) && compare(data[leftChild(index)], data[index]))
    {
        largestElementIndex = leftChild(index);
    }

    if ((rightChild(index) < size) && compare(data[rightChild(index)], data[index]))
    {
        largestElementIndex = rightChild(index);
    }

    if (largestElementIndex != index)
    {
        std::swap(data[index], data[largestElementIndex]);
        heapifyDown(largestElementIndex);
    }
};