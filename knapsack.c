include <stdio.h>
struct Item {
    int value;
    int weight;
    float ratio;
};
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].ratio < arr[j].ratio) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
float fractionalKnapsack(struct Item arr[], int n, int capacity) {
    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= arr[i].weight) {
            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        } else {
            totalValue += arr[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, capacity;
 ");
    scanf("%d", &n);
    struct Item arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);
    sortItems(arr, n);
    float maxValue = fractionalKnapsack(arr, n, capacity);
    printf("Maximum value in knapsack = %.2f\n", maxValue);
    return 0;
}
