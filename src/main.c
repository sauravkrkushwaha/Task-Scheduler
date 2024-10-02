#include <stdio.h>
#include <stdlib.h>  // Required for malloc and free
#include "task_scheduler.h"

int main() {
    Queue* queues[MAX_QUEUE_LEVEL];
    for (int i = 0; i < MAX_QUEUE_LEVEL; i++) {
        queues[i] = (Queue*)malloc(sizeof(Queue));  // Allocate memory for queues
        initQueue(queues[i]);
    }

    // Adding 15 tasks with different priorities
    Task tasks[] = {
        {1, "Task 1", 0},   // High priority
        {2, "Task 2", 1},   // Medium priority
        {3, "Task 3", 2},   // Low priority
        {4, "Task 4", 0},   // High priority
        {5, "Task 5", 1},   // Medium priority
        {6, "Task 6", 2},   // Low priority
        {7, "Task 7", 0},   // High priority
        {8, "Task 8", 1},   // Medium priority
        {9, "Task 9", 2},   // Low priority
        {10, "Task 10", 0}, // High priority
        {11, "Task 11", 1}, // Medium priority
        {12, "Task 12", 2}, // Low priority
        {13, "Task 13", 0}, // High priority
        {14, "Task 14", 1}, // Medium priority
        {15, "Task 15", 2}  // Low priority
    };

    // Add all tasks to the appropriate queues based on their priority
    for (int i = 0; i < 15; i++) {
        addTask(queues, tasks[i]);
    }

    // Schedule the tasks based on multilevel queue scheduling
    printf("Scheduling tasks...\n");
    scheduleTasks(queues);

    // Free the allocated memory for queues
    for (int i = 0; i < MAX_QUEUE_LEVEL; i++) {
        free(queues[i]);
    }

    return 0;
}
