#include <heap.hpp>

int main()
{
    Heap<int> heap(10);
    heap.insert(5);
    heap.insert(10);
    heap.insert(40);
    heap.insert(8);
    heap.insert(3);
    heap.insert(30);

    while (!heap.isEmpty())
    {
        std::cout << heap.extractMax() << " ";
    }

    return 0;
}