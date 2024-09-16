#include <stdio.h>
#include <limits.h>

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int isCompleted;
};

void calculateTimes(struct Process proc[], int n) {
    int currentTime = 0, completed = 0;
    float totalTAT = 0, totalWT = 0;
    int shortest = -1, minRemainingTime = INT_MAX;
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].arrivalTime <= currentTime && !proc[i].isCompleted && proc[i].remainingTime < minRemainingTime) {
                minRemainingTime = proc[i].remainingTime;
                shortest = i;
            }
        }
        if (shortest == -1) {
            currentTime++;
        } else {
            proc[shortest].remainingTime--;
            currentTime++;
            if (proc[shortest].remainingTime == 0) {
                proc[shortest].completionTime = currentTime;
                proc[shortest].turnAroundTime = proc[shortest].completionTime - proc[shortest].arrivalTime;
                proc[shortest].waitingTime = proc[shortest].turnAroundTime - proc[shortest].burstTime;
                totalTAT += proc[shortest].turnAroundTime;
                totalWT += proc[shortest].waitingTime;
                proc[shortest].isCompleted = 1;
                completed++;
                minRemainingTime = INT_MAX;
            }
        }
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].arrivalTime, proc[i].burstTime, proc[i].completionTime, proc[i].turnAroundTime, proc[i].waitingTime);
    }
    printf("\nAverage Turnaround Time: %.2f", totalTAT / n);
    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrivalTime, &proc[i].burstTime);
        proc[i].remainingTime = proc[i].burstTime;
        proc[i].isCompleted = 0;
    }
    calculateTimes(proc, n);
    return 0;
}

