#include <stdio.h>
#include <math.h>

// Function to calculate the N-th term of a geometric progression
float geometric_term(int n, float a, float r) {
    // a_n = a * r^(n-1)
    if (n < 1) {
        return 0.0f;
    }
    return a * (float)pow(r, n - 1);
}

// Function to calculate the sum of first N terms of a geometric progression
float geometric_sum(int n, float a, float r) {
    // S_n = a * (1 - r^n) / (1 - r)   for r != 1
    // S_n = a * n                     for r == 1
    if (n < 1) {
        return 0.0f;
    }
    if (r == 1.0f) {
        return a * n;
    }
    return a * (1.0f - (float)pow(r, n)) / (1.0f - r);
}

int main() {
    int N;

    printf("Enter number of elements: ");
    if (scanf("%d", &N) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    // Hard-coded first term and ratio
    const float a = 0.5f;   // first term
    const float r = 2.0f;   // common ratio

    // Calculate and print N-th term
    // e.g. for N=5, a=0.5, r=2 -> 0.5, 1.0, 2.0, 4.0, 8.0
    float N_term = geometric_term(N, a, r);
    printf("N-th geometric progression terms: %.3f\n", N_term);

    // Calculate and print sum of first N terms
    // e.g. for N=5, a=0.5, r=2 -> 0.5 + 1.0 + 2.0 + 4.0 + 8.0 = 15.5
    float sum = geometric_sum(N, a, r);
    printf("Sum of first %d terms = %.3f\n", N, sum);

    return 0;
}