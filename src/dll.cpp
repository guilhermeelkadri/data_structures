
#include <iostream>
#include "dll.hpp"

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() 
{
    std::shared_ptr<Node> current = head;
    
    while (current != nullptr) 
    {
        std::shared_ptr<Node> next = current->next;
        current->prev.reset();
        current->next.reset();
        current.reset();
        current = next;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertAtBeginning(const T& data)
{
    std::shared_ptr<Node> newNode = std::make_shared<Node>();
    
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = head;

    if(head != nullptr)
    {
        head->prev = newNode;
    }

    head = newNode;
    std::cout << "Node with data " << data << " inserted at the beginning.";
}

template <typename T>
void DoublyLinkedList<T>::insertAtEnd(const T& data)
{
    std::shared_ptr<Node> newNode = std::make_shared<Node>();

    newNode->data = data;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        newNode->prev = nullptr;
        head = newNode;
    }
    else
    {
        std::shared_ptr<Node> temp = head;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->prev = temp;
    }

    std::cout << "Node with data " << data << " inserted at the end." << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::display() const 
{
    if (head == nullptr) 
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    std::shared_ptr<Node> temp = head;
    std::cout << "The list elements are: ";
    
    while (temp != nullptr) 
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

int main() 
{
    DoublyLinkedList<int> intList;
    DoublyLinkedList<double> doubleList;
    DoublyLinkedList<std::string> stringList;

    // Insert nodes in the integer list
    intList.insertAtBeginning(3);
    intList.insertAtBeginning(2);
    intList.insertAtBeginning(1);

    // Insert nodes in the double list
    doubleList.insertAtEnd(1.23);
    doubleList.insertAtEnd(4.56);
    doubleList.insertAtEnd(7.89);

    // Insert nodes in the string list
    stringList.insertAtEnd("Hello");
    stringList.insertAtEnd("World");

    // Display the lists
    std::cout << "Integer List:" << std::endl;
    intList.display();
    std::cout << "Double List:" << std::endl;
    doubleList.display();
    std::cout << "String List:" << std::endl;
    stringList.display();

    return 0;
}