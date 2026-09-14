#include <stdio.h>
#include <math.h>

float geometric_sum(int n, float a, float r) {
    if (n < 1) {
        return 0.0f;
    }
    if (r == 1.0f) {
        return a * n;
    }
    return a * (1.0f - (float)pow(r, n)) / (1.0f - r);
}

double geometric_sum_double(int n, double a, double r) {
    if (n < 1) {
        return 0.0;
    }
    if (r == 1.0) {
        return a * n;
    }
    return a * (1.0 - pow(r, n)) / (1.0 - r);
}

int main(void) {
    const int FLOAT_FRACTION_BITS = 23;
    const int DOUBLE_FRACTION_BITS = 52;

    float max_mantissa_float = geometric_sum(FLOAT_FRACTION_BITS + 1, 1.0f, 0.5f);
    double max_mantissa_double = geometric_sum_double(DOUBLE_FRACTION_BITS + 1, 1.0, 0.5);

    printf("Max mantissa for float  (32 bits): %.23f\n", max_mantissa_float);
    printf("Max mantissa for double (64 bits): %.52f\n", max_mantissa_double);

    return 0;
}