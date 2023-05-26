#include <stdio.h>

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int weights[], int values[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build the K[][] table in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int i, n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    printf("Enter the values and weights of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d:\n", i + 1);
        printf("Value: ");
        scanf("%d", &values[i]);
        printf("Weight: ");
        scanf("%d", &weights[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    int max_value = knapsack(W, weights, values, n);

    printf("The maximum value that can be obtained is: %d\n", max_value);

    return 0;
}

