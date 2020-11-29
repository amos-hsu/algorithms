#include <stdio.h>
#define QUEUE_SIZE 6
typedef struct TagQueue
{
    int queue[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

int IsEmpty(Queue *q)
{
    return q->front == q->rear;
}

int IsFull(Queue *q)
{
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

void Enqueue(Queue *q, int v)
{
    if (IsFull(q)) {
        printf("full queue, enqueue failed\n");
        return;
    }
    if (IsEmpty(q)) {
        q->queue[q->front] = v;
    }
    q->queue[q->rear] = v;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
}

int Dequeue(Queue *q)
{
    if (IsEmpty(q)) return -1;
    int ans = q->queue[q->front];
    q->queue[q->front] = 0;
    q->front = (q->front + 1) % QUEUE_SIZE;
    return ans;
}

int QueueSize(Queue *q) {
    return (q->rear + QUEUE_SIZE - q->front) % QUEUE_SIZE;
}

void DumpQueue(Queue *q)
{
    for (int i = 0; i < QUEUE_SIZE; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main()
{
    Queue q = { { 0 }, 0, 0 };
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    Enqueue(&q, -1);
    DumpQueue(&q);
    Dequeue(&q);
    Enqueue(&q, 6);
    DumpQueue(&q);
    Dequeue(&q);
    Enqueue(&q, 7);
    DumpQueue(&q);
    printf("size=%d\n", QueueSize(&q));
}
