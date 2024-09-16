#include <stdio.h>
struct Task {
    int taskId;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    int response;
    int isDone;
};
void sortByArrival(struct Task tasks[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (tasks[i].arrival > tasks[j].arrival) {
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}
void calculateMetrics(struct Task tasks[], int count) {
    int currentTime = 0, finishedTasks = 0;
    float totalTurnaround = 0, totalWaiting = 0;
    while (finishedTasks != count) {
        int shortestTask = -1;
        int minBurst = 1e9;
        for (int i = 0; i < count; i++) {
            if (tasks[i].arrival <= currentTime && !tasks[i].isDone && tasks[i].burst < minBurst) {
                minBurst = tasks[i].burst;
                shortestTask = i;
            }
        }
        if (shortestTask == -1) {
            currentTime++;
        } else {
            tasks[shortestTask].completion = currentTime + tasks[shortestTask].burst;
            tasks[shortestTask].turnaround = tasks[shortestTask].completion - tasks[shortestTask].arrival;
            tasks[shortestTask].waiting = tasks[shortestTask].turnaround - tasks[shortestTask].burst;
            tasks[shortestTask].response = currentTime - tasks[shortestTask].arrival;
            totalTurnaround += tasks[shortestTask].turnaround;
            totalWaiting += tasks[shortestTask].waiting;
            tasks[shortestTask].isDone = 1;
            finishedTasks++;
            currentTime = tasks[shortestTask].completion;
        }
    }
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", tasks[i].taskId, tasks[i].arrival, tasks[i].burst, tasks[i].completion, tasks[i].turnaround, tasks[i].waiting, tasks[i].response);
    }
    printf("\nAverage Turnaround Time: %.2f", totalTurnaround / count);
    printf("\nAverage Waiting Time: %.2f\n", totalWaiting / count);
}
int main() {
    int count;
    printf("Enter the number of tasks: ");
    scanf("%d", &count);
    struct Task tasks[count];
    for (int i = 0; i < count; i++) {
        tasks[i].taskId = i + 1;
        printf("Enter arrival time and burst time for task %d: ", i + 1);
        scanf("%d %d", &tasks[i].arrival, &tasks[i].burst);
        tasks[i].isDone = 0;
    }
    sortByArrival(tasks, count);
    calculateMetrics(tasks, count);
    return 0;
}

