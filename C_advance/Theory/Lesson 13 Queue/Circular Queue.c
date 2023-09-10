// Circular Queue implementation in C

#include <stdio.h>

#define SIZE 5

typedef struct
{
  int front;
  int rear;
  int items[SIZE];
} Queue;

void initializeQueue(Queue *queue)
{
  queue->front = -1;
  queue->rear = -1;
}

// Check if the queue is full
int isFull(Queue *queue)
{
  return ((queue->front == queue->rear + 1) || (queue->front == 0 && queue->rear == SIZE - 1));
}

// Check if the queue is empty
int isEmpty(Queue *queue)
{
  return (queue->front == -1);
}

// Adding an element
void enQueue(Queue *queue, int element)
{
  if (isFull(queue))
    printf("\n Queue is full!! \n");
  else
  {
    if (queue->front == -1)
      queue->front = 0;
    queue->rear = (queue->rear + 1) % SIZE;
    queue->items[queue->rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

// Removing an element
int deQueue(Queue *queue)
{
  int element;
  if (isEmpty(queue))
  {
    printf("\n Queue is empty !!! \n");
    return (-1);
  }
  else
  {
    element = queue->items[queue->front];
    if (queue->front == queue->rear)
    {
      queue->front = -1;
      queue->rear = -1;
    }
    // Q has only one element, so we reset the
    // queue after dequeueing it. ?
    else
    {
      queue->front = (queue->front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// Display the queue
void display(Queue *queue)
{
  int i;
  if (isEmpty(queue))
    printf(" \n Empty Queue\n");
  else
  {
    printf("\n Front -> %d ", queue->front);
    printf("\n Items -> ");
    for (i = queue->front; i != queue->rear; i = (i + 1) % SIZE)
    {
      printf("%d ", queue->items[i]);
    }
    printf("%d ", queue->items[i]);
    printf("\n Rear -> %d \n", queue->rear);
  }
}

int main()
{
  Queue queue;
  initializeQueue(&queue);
  // Fails because queue->front = -1
  deQueue(&queue);

  enQueue(&queue, 1);
  enQueue(&queue, 2);
  enQueue(&queue, 3);
  enQueue(&queue, 4);
  enQueue(&queue, 5);

  // Fails to enqueue because queue->front == 0 && rear == SIZE - 1
  enQueue(&queue, 6);

  display(&queue);
  deQueue(&queue);

  display(&queue);

  enQueue(&queue, 7);
  display(&queue);

  // Fails to enqueue because queue->front == rear + 1
  enQueue(&queue, 8);

  return 0;
}