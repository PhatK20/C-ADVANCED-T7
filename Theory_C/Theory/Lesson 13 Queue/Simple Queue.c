// Simple Queue implementation in C
#include <stdio.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(Queue *queue) {
    return (queue->rear == SIZE - 1);
}

int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    }   
    else {
      if (isEmpty(queue)) 
        queue->front = 0;
      queue->items[++queue->rear] = value;
      printf("\n Inserted -> %d", value);    
    }  
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else {
      int value = queue->items[queue->front];
      if (queue->front == queue->rear) {
        // Last item in the queue, reset the queue
        initializeQueue(queue);
      } 
      else {
        queue->front++;
      }
      printf("\n Deleted value -> %d \n", value);
      return value;
    }   
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
      printf("\n queue->front -> %d ", queue->front);
      printf("\n Items -> ");
      for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
      }
     printf("\n Rear -> %d \n", queue->rear);
    } 
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);
    dequeue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printQueue(&myQueue);

    dequeue(&myQueue);
    dequeue(&myQueue);

    enqueue(&myQueue, 40);

    printQueue(&myQueue);

    return 0;
}
