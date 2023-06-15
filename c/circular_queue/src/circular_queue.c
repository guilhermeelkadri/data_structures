/**
 * @file circular_queue.c
 * @author Guilherme El Kadri Ribeiro (guilhermeelkadri@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "circular_queue.h"

bool queueIsFull(Queue *queue)
{
   return (queue->size == queue->capacity);
}

bool queueIsEmpty(Queue *queue)
{
   return (queue->size == 0);
}

bool dequeue(Queue *queue, dataType *event)
{
   if (queue->isEmpty(queue))
   {
      return false;
   }

   memcpy(event, &queue->data[queue->front], queue->dataSize);

   queue->front = (queue->front + 1) % queue->capacity;

   queue->size--;

   return true;
}

void enqueue(Queue *queue, dataType *data)
{
   if (queue->isFull(queue))
   {
      dataType draft;
      queue->dequeue(queue, &draft);
   }

   queue->rear = (queue->rear + 1) % queue->capacity;

   memcpy(&queue->data[queue->rear], data, queue->dataSize);

   queue->size++;
}

bool queueGetFront(Queue *queue, dataType *event)
{
   if (queue->isEmpty(queue) || event == NULL)
   {
      return false;
   }

   *event = queue->data[queue->front];

   return true;
}

bool queueGetRear(Queue *queue, dataType *event)
{
   if (queue->isEmpty(queue) || event == NULL)
   {
      return false;
   }

   *event = queue->data[queue->front];

   return true;
}

/**
 * @brief Create a Queue object
 *
 * @param capacity  the maximum number of elements the queue can hold
 * @param dataSize the size of each element in the queue
 * @return Queue*   a pointer to the newly created queue
 */
Queue *createQueue(uint8_t capacity, uint8_t dataSize)
{
   Queue *queue = (Queue *)malloc(sizeof(Queue) + (capacity * dataSize));

   queue->capacity = capacity;
   queue->front = 0;
   queue->size = 0;
   queue->rear = capacity - 1;

   queue->isFull = queueIsFull;
   queue->isEmpty = queueIsEmpty;
   queue->enqueue = enqueue;
   queue->dequeue = dequeue;
   queue->getFront = queueGetFront;
   queue->getRear = queueGetRear;

   queue->dataSize = dataSize;
   memset(queue->data, 0, (capacity * dataSize));

   return queue;
}

int main()
{
   // Example usage
   Queue *queue = createQueue(5, sizeof(dataType));

   dataType event1 = 10;
   dataType event2 = 20;
   dataType event3 = 30;

   // Enqueue events
   queue->enqueue(queue, &event1);
   queue->enqueue(queue, &event2);
   queue->enqueue(queue, &event3);

   // Dequeue events
   dataType dequeuedEvent;
   if (queue->dequeue(queue, &dequeuedEvent))
   {
      printf("Dequeued event: %d\n", dequeuedEvent);
   }

   // Get front and rear events
   dataType frontEvent;
   if (queue->getFront(queue, &frontEvent))
   {
      printf("Front event: %d\n", frontEvent);
   }

   dataType rearEvent;
   if (queue->getRear(queue, &rearEvent))
   {
      printf("Rear event: %d\n", rearEvent);
   }

   // Additional test cases

   // Try to enqueue an event when the queue is full
   dataType event4 = 40;
   queue->enqueue(queue, &event4);
   printf("Enqueued event: %d\n", event4);

   // Dequeue all events from the queue
   while (!queue->isEmpty(queue))
   {
      if (queue->dequeue(queue, &dequeuedEvent))
      {
         printf("Dequeued event: %d\n", dequeuedEvent);
      }
   }

   // Try to dequeue an event from an empty queue
   if (queue->dequeue(queue, &dequeuedEvent))
   {
      printf("Dequeued event: %d\n", dequeuedEvent);
   }
   else
   {
      printf("Queue is empty. Cannot dequeue event.\n");
   }

   // Try to get the front and rear events from an empty queue
   if (queue->getFront(queue, &frontEvent))
   {
      printf("Front event: %d\n", frontEvent);
   }
   else
   {
      printf("Queue is empty. Cannot get front event.\n");
   }

   if (queue->getRear(queue, &rearEvent))
   {
      printf("Rear event: %d\n", rearEvent);
   }
   else
   {
      printf("Queue is empty. Cannot get rear event.\n");
   }

   return 0;
}