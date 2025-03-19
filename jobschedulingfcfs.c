#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    char name[10];
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} p;



int main() {
    int n;
    

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p* parr = (p*) malloc(n * sizeof(p));

    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d\n", i + 1);
        printf("Enter process name: ");
        scanf("%s", parr[i].name);
        printf("Enter arrival time: ");
        scanf("%d", &parr[i].arrivalTime);
        printf("Enter execution time: ");
        scanf("%d", &parr[i].burstTime);
    }



    
    int cumulativeCompletionTime = 0;  

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            parr[i].waitingTime = 0;
        } else {
            parr[i].waitingTime = cumulativeCompletionTime- parr[i].arrivalTime;
        }
        cumulativeCompletionTime = cumulativeCompletionTime + parr[i].burstTime;
        parr[i].turnaroundTime = parr[i].waitingTime + parr[i].burstTime;
    }

    int avgwaiting=0;
    int avgturnaround=0;


    printf("\n");
    printf("FCFS Schedule: \n\n");

    printf("Name\tArrival\tExecution      Waiting      Turnaround\n");
    
    for (int i = 0; i < n; i++) {
        printf("%s \t  %d  \t%d  \t\t  %d  \t\t%d  \n", parr[i].name, parr[i].arrivalTime,
               parr[i].burstTime, parr[i].waitingTime, parr[i].turnaroundTime);

        avgwaiting+= parr[i].waitingTime;
        avgturnaround+= parr[i].turnaroundTime;

    }

    printf("The average waiting time is: %d\n", avgwaiting/n);
    printf("The average turnaround time is: %d", avgturnaround/n);

    
    free(parr);
    return 0;
}
