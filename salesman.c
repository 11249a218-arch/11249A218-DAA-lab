#include <stdio.h>
#define MAX 10
#define INF 9999
int main() {
    int n, i, j;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int current = 0, next;
    int totalCost = 0;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;  // Avoid self loops
        }
    }
    visited[current] = 1;
    printf("Tour: %d ", current);
    for(i = 0; i < n - 1; i++) {
        int min = INF;
        next = -1;
        for(j = 0; j < n; j++) {
            if(!visited[j] && cost[current][j] < min) {
                min = cost[current][j];
                next = j;
            }
        }
        visited[next] = 1;
        printf("-> %d ", next);
        totalCost += min;
        current = next;
    }
    totalCost += cost[current][0];  // Return to start
    printf("-> 0");
    printf("\nMinimum Cost = %d\n", totalCost);
    return 0;
}
