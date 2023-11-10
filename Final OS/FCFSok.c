#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} process;

void FCFS(process *processes, int n) {
    int current_time = 0;
    int ready_queue[n];
    int front = 0;
    int rear = -1;

    for (int i = 0; i < n; i++) {
        ready_queue[++rear] = i;
    }

    while (front <= rear) {
        int process_id = ready_queue[front++];
        process *process = &processes[process_id];
        process->start_time = current_time;
        current_time += process->burst_time;
        process->completion_time = current_time;
        process->waiting_time = process->start_time - process->arrival_time;
        process->turnaround_time = process->completion_time - process->arrival_time;
    }
}

float calculate_average_waiting_time(process *processes, int n) {
    float total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
    }
    return total_waiting_time / n;
}

float calculate_average_turnaround_time(process *processes, int n) {
    float total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += processes[i].turnaround_time;
    }
    return total_turnaround_time / n;
}

void print_gantt_chart(process *processes, int n) {
    printf("\nGantt Chart:\n");
    printf("+---------------------------+\n");
    printf("| Time | Process ID | Burst Time |\n");
    printf("+---------------------------+\n");

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        printf("| %3d | %11d | %10d |\n", current_time, processes[i].pid, processes[i].burst_time);
        current_time += processes[i].burst_time;
    }

    printf("+---------------------------+\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the PID, arrival time, and burst time for process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time);
    }

    FCFS(processes, n);

    float average_waiting_time = calculate_average_waiting_time(processes, n);
    float average_turnaround_time = calculate_average_turnaround_time(processes, n);

    printf("\nAverage waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);

    print_gantt_chart(processes, n);

    return 0;
}