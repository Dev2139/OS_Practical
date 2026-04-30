#include <stdio.h>

int main() {
    int n, tq, i, total = 0, x, counter = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    x = n;

    // Input burst times
    for(i = 0; i < n; i++) {
        printf("Enter burst time of process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // remaining time = burst time initially
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    // Round Robin logic
    for(total = 0, i = 0; x != 0; ) {
        if(rt[i] <= tq && rt[i] > 0) {
            total += rt[i];
            rt[i] = 0;
            counter = 1;
        }
        else if(rt[i] > 0) {
            rt[i] -= tq;
            total += tq;
        }

        if(rt[i] == 0 && counter == 1) {
            x--;
            tat[i] = total;
            wt[i] = tat[i] - bt[i];

            printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);

            counter = 0;
        }

        if(i == n - 1)
            i = 0;
        else
            i++;
    }

    // Calculate averages
    float avg_wt = 0, avg_tat = 0;

    for(i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}