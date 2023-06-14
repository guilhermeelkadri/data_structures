
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

    void display() const;

};