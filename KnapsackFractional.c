#include <stdio.h>
#include <time.h>

struct Item {
    int value, weight;
    float ratio;
};
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                swap(&items[i], &items[j]);
            }
        }
    }
}
float fractionalKnapsack(int W, struct Item items[], int n) {
    sortItems(items, n);

    int curWeight = 0;
    float finalValue = 0.0;

    printf("\nItems selected:\n");

    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            finalValue += items[i].value;
            printf("Item %d: Taken completely (value=%d, weight=%d)\n", i+1, items[i].value, items[i].weight);
        } else {
            int remain = W - curWeight;
            finalValue += items[i].value * ((float)remain / items[i].weight);
            printf("Item %d: Taken %.2f fraction (value=%d, weight=%d)\n", i+1, (float)remain/items[i].weight, items[i].value, items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i+1);
        scanf("%d", &items[i].value);
    }

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i+1);
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    float result = fractionalKnapsack(W, items, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nMaximum value in Knapsack = %.2f\n", result);
    printf("Time taken to execute: %f seconds\n", cpu_time_used);

    return 0;
}
