/**
 * @file dll.cpp
 * @author Guilherme El Kadri Ribeiro (guilhermeelkadri@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-15
 * 
 * @note This implementation supports insertion, deletion, and display operations.
 *       It also includes a test suite using Google Test framework.
 *       This file contains the implementation of the DoublyLinkedList class and its member functions.
 *       The main() function runs all the unit tests. 
 * 
 */

#include <iostream>
#include <gtest/gtest.h>
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
    std::cout << "Node with data " << data << " inserted at the beginning." << std::endl;
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
void DoublyLinkedList<T>::deleteNode(const T& data)
{
    if(head == nullptr)
    {
        std::cout << "The list is empty. Cannot delete node." << std::endl;
        return;
    }

    std::shared_ptr current = head;

    while(current != nullptr)
    {
        if(current->data == data)
        {
            if(current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            else
            {
                // Deleting the first node (head)
                head = current->next;
                head->prev = nullptr;
            }

            if(current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            else
            {
                // Deleting the last node
                current->prev->next = nullptr;
            }

            current->prev.reset();
            current->next.reset();
            current.reset();

            std::cout << "Node with data " << data << " deleted." << std::endl;
            return;
        }

        current = current->next;
    }

    std::cout << "Node with data " << data << " not found in the list." << std::endl;
}

template <typename T>
std::shared_ptr<typename DoublyLinkedList<T>::Node> DoublyLinkedList<T>::getHead() const
{
    return head;
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

// Test fixture for DoublyLinkedList
class DoublyLinkedListTest : public ::testing::Test
{
protected:
    DoublyLinkedList<int> intList;
    DoublyLinkedList<double> doubleList;
    DoublyLinkedList<std::string> stringList;
};

// Test case for insertAtBeginning function
TEST_F(DoublyLinkedListTest, InsertAtBeginning)
{
    intList.insertAtBeginning(3);
    intList.insertAtBeginning(2);
    intList.insertAtBeginning(1);

    // Assert the contents of the list after insertion
    // Use EXPECT_* for non-fatal failures
    EXPECT_EQ(1, intList.getHead()->data);
    EXPECT_EQ(2, intList.getHead()->next->data);
    EXPECT_EQ(3, intList.getHead()->next->next->data);
}

// Test case for insertAtEnd function
TEST_F(DoublyLinkedListTest, InsertAtEnd)
{
    doubleList.insertAtEnd(1.23);
    doubleList.insertAtEnd(4.56);
    doubleList.insertAtEnd(7.89);

    // Assert the contents of the list after insertion
    EXPECT_EQ(1.23, doubleList.getHead()->data);
    EXPECT_EQ(4.56, doubleList.getHead()->next->data);
    EXPECT_EQ(7.89, doubleList.getHead()->next->next->data);
}

// Test case for deleteNode function
TEST_F(DoublyLinkedListTest, DeleteNode)
{
    intList.insertAtBeginning(3);
    intList.insertAtBeginning(2);
    intList.insertAtBeginning(1);
    intList.insertAtEnd(4);

    intList.deleteNode(4);

    // Assert the contents of the list after deletion
    EXPECT_EQ(1, intList.getHead()->data);
    EXPECT_EQ(2, intList.getHead()->next->data);
    EXPECT_EQ(3, intList.getHead()->next->next->data);
    EXPECT_EQ(nullptr, intList.getHead()->next->next->next);
}

// Test case for display function
TEST_F(DoublyLinkedListTest, Display)
{
    // Prepare the list with some data
    stringList.insertAtEnd("Hello");
    stringList.insertAtEnd("World");

    // Redirect the cout output to a stringstream to capture the output
    std::stringstream output;
    std::streambuf *originalCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Call the display function
    stringList.display();

    // Restore the cout buffer
    std::cout.rdbuf(originalCoutBuffer);

    // Assert the output of the display function
    EXPECT_EQ("The list elements are: Hello World \n", output.str());
}

int main() 
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}