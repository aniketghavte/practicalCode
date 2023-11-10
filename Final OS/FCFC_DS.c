#include <stdio.h>

int main() {
  int request_queue[100];
  int head_position, total_head_movement = 0;
  int n;

  printf("Enter the number of requests: ");
  scanf("%d", &n);

  printf("Enter the request queue: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &request_queue[i]);
  }

  printf("Enter the initial head position: ");
  scanf("%d", &head_position);

  // FCFS algorithm
  for (int i = 0; i < n; i++) {
    int seek_time = abs(head_position - request_queue[i]);
    total_head_movement += seek_time;
    head_position = request_queue[i];
  }

  printf("Total head movement: %d\n", total_head_movement);

  return 0;
}