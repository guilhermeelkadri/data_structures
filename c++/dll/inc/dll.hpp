/**
 * @file dll.hpp
 * @author Guilherme El Kadri Ribeiro (guilhermeelkadri@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <memory>

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
    };

    std::shared_ptr<Node> head;

public:
    DoublyLinkedList() : head(nullptr) {}
    ~DoublyLinkedList();

    void createNode(const T& data);
    void insertAtEnd(const T& data);
    void insertAtBeginning(const T& data);
    void deleteNode(const T& data);
    std::shared_ptr<Node> getHead() const;

    void display() const;

};