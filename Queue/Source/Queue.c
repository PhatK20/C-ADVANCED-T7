/*
 * File Name: Queue.c
 * Author: Phat Bui Gia
 * Date: 20/08/2023
 * Description: This file provides the function definitions for queue operations
 * using an array-based data structure.
 */

#include "Queue.h"

/*
 * Function: initializeQueue
 * Description: Initializes the queue by setting both front and rear pointers to -1.
 * Input:
 *   queue - A pointer to the Queue structure.
 * Output:
 *   None
 */
void initializeQueue(Queue *queue)
{
  queue->front = -1;
  queue->rear = -1;
}

/*
 * Function: isFull
 * Description: Checks if the queue is full.
 * Input:
 *   queue - A pointer to the Queue structure.
 * Output:
 *   Returns 1 if the queue is full, otherwise returns 0.
 */
int isFull(Queue *queue)
{
  return (queue->rear == SIZE - 1);
}

/*
 * Function: isEmpty
 * Description: Checks if the queue is empty.
 * Input:
 *   queue - A pointer to the Queue structure.
 * Output:
 *   Returns 1 if the queue is empty, otherwise returns 0.
 */
int isEmpty(Queue *queue)
{
  return (queue->front == -1);
}

/*
 * Function: enqueue
 * Description: Inserts an element at the rear of the queue.
 * Input:
 *   queue - A pointer to the Queue structure.
 *   value - The value to be inserted.
 * Output:
 *   None
 */
void enqueue(Queue *queue, int value)
{
  if (isFull(queue))
  {
    printf("Queue is full. Cannot enqueue.\n");
  }
  else
  {
    if (isEmpty(queue))
      queue->front = 0;
    queue->items[++queue->rear] = value;
    printf("\n Inserted -> %d", value);
  }
}

/*
 * Function: dequeue
 * Description: Removes an element from the front of the queue.
 * Input:
 *   queue - A pointer to the Queue structure.
 * Output:
 *   Returns the value removed from the queue, or -1 if the queue is empty.
 */
int dequeue(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1;
  }
  else
  {
    int value = queue->items[queue->front];
    if (queue->front == queue->rear)
    {
      // Last item in the queue, reset the queue
      initializeQueue(queue);
    }
    else
    {
      queue->front++;
    }
    printf("\n Deleted value -> %d \n", value);
    return value;
  }
}

/*
 * Function: printQueue
 * Description: Prints the elements of the queue.
 * Input:
 *   queue - A pointer to the Queue structure.
 * Output:
 *   None
 */
void printQueue(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty.\n");
  }
  else
  {
    printf("\n queue->front -> %d ", queue->front);
    printf("\n Items -> ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
      printf("%d ", queue->items[i]);
    }
    printf("\n Rear -> %d \n", queue->rear);
  }
}
