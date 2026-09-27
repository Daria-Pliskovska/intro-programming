#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double square_root_exhaustive(double x, double epsilon, long long *iterations) {
    double step = epsilon * epsilon;
    double ans = 0.0;
    long long count = 0;

    while (fabs(ans * ans - x) >= epsilon && ans * ans <= x) {
        ans += step;
        ++count;
    }
    *iterations = count;

    if (ans * ans > x) {
        printf("Error: No solution found, the current answer: %f\n", ans);
        return -1.0;
    }
    return ans;
}

double square_root_bisection(double x, double epsilon, long long *iterations) {
    double low = 0.0;
    double high = (x > 1.0) ? x : 1.0;
    double mid = (low + high) / 2.0;
    long long count = 0;

    while (fabs(mid * mid - x) >= epsilon) {
        if (mid * mid > x) {
            high = mid;
        } else {
            low = mid;
        }
        mid = (low + high) / 2.0;
        ++count;
    }
    *iterations = count;
    return mid;
}

void compare(double x, double epsilon) {
    long long iterations;
    clock_t start, end;
    double answer;

    printf("x = %g, epsilon = %g\n", x, epsilon);

    start = clock();
    answer = square_root_exhaustive(x, epsilon, &iterations);
    end = clock();
    printf("  exhaustive: answer = %f, iterations = %lld, time = %.6f s\n",
           answer, iterations, (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    answer = square_root_bisection(x, epsilon, &iterations);
    end = clock();
    printf("  bisection:  answer = %f, iterations = %lld, time = %.6f s\n\n",
           answer, iterations, (double)(end - start) / CLOCKS_PER_SEC);
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        double x = atof(argv[1]);
        double epsilon = atof(argv[2]);

        if (x < 0.0 || epsilon <= 0.0) {
            printf("Usage: %s <x >= 0> <epsilon > 0>\n", argv[0]);
            return 1;
        }
        compare(x, epsilon);
        return 0;
    }

    double inputs[][2] = {
        {10.0, 0.01},
        {1000.0, 0.01},
        {1000.0, 0.001},
        {1000.0, 0.0001},
        {2.0, 0.0001},
        {1000000.0, 0.01}
    };
    int count = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < count; ++i) {
        compare(inputs[i][0], inputs[i][1]);
    }

    return 0;
}