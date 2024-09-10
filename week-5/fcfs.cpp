#include <stdio.h>
struct Process
{
    int processID;      
    int arrivalTime;   
    int burstTime;     
    int completionTime; 
    int turnaroundTime; 
    int waitingTime;    
};
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++)
	{
        processes[i].processID = i + 1; 
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }
    processes[0].completionTime = processes[0].arrivalTime + processes[0].burstTime;
    processes[0].turnaroundTime = processes[0].burstTime; 
    processes[0].waitingTime = 0;                        
    for (int i = 1; i < n; i++)
    {
        processes[i].completionTime = processes[i - 1].completionTime + processes[i].burstTime; 
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;  
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;       
    }
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    printf("\nProcessID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n",
               processes[i].processID,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].completionTime,
               processes[i].turnaroundTime,
               processes[i].waitingTime);
    }
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);

    return 0;
}
