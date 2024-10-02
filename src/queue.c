#include <stdio.h>
#include <stdlib.h>
#include "task_scheduler.h"

void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int isFull(Queue* queue) {
    return queue->size == MAX_TASKS;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, Task task) {
    if (!isFull(queue)) {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_TASKS;
        queue->tasks[queue->rear] = task;
        queue->size++;
    } else {
        printf("Queue is full!\n");
    }
}

Task dequeue(Queue* queue) {
    Task task = {0};
    if (!isEmpty(queue)) {
        task = queue->tasks[queue->front];
        queue->front = (queue->front + 1) % MAX_TASKS;
        queue->size--;
    } else {
        printf("Queue is empty!\n");
    }
    return task;
}

void addTask(Queue* queues[], Task task) {
    enqueue(queues[task.priority], task);
}

void scheduleTasks(Queue* queues[]) {
    for (int i = 0; i < MAX_QUEUE_LEVEL; i++) {
        while (!isEmpty(queues[i])) {
            Task task = dequeue(queues[i]);
            printf("Executing Task: %s with Priority: %d\n", task.name, task.priority);
        }
    }
}
