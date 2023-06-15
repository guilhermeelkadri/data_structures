/**
 * @file circular_queue.h
 * @author Guilherme El Kadri Ribeiro (guilhermeelkadri@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __CIRCULAR_QUEUE__H__
#define __CIRCULAR_QUEUE__H__

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t dataType;

typedef struct Queue Queue; // Forward declaration

typedef struct Queue
{
   // Queue control variables
   uint8_t front;
   uint8_t rear;
   uint8_t size;
   uint8_t capacity;

   // Queue functions
   bool (*isFull)(Queue *queue);
   bool (*isEmpty)(Queue *queue);
   void (*enqueue)(Queue *queue, dataType *event);
   bool (*dequeue)(Queue *queue, dataType *event);
   bool (*getFront)(Queue *queue, dataType *event);
   bool (*getRear)(Queue *queue, dataType *event);

   // Queue data events
   uint8_t dataSize;
   dataType data[]; // Flexible array member, extended with malloc

} Queue;

Queue *createQueue(uint8_t capacity, uint8_t dataSize);

#endif
