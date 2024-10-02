#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#define MAX_TASKS 100
#define MAX_QUEUE_LEVEL 3

typedef struct {
    int id;
    char name[50];
    int priority; // 0: high, 1: medium, 2: low
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* queue);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, Task task);
Task dequeue(Queue* queue);
void addTask(Queue* queues[], Task task);
void scheduleTasks(Queue* queues[]);

#endif // TASK_SCHEDULER_H
