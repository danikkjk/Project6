#define _CRT_SECURE_NO_WARNINGS
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define EPSILON 0.0001
#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001

double exact_function(double x) {
    return 0.5 - (M_PI / 4) * fabs(sin(x));
}

double series_function(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += cos(2 * i * x) / (4 * i * i - 1);
    }
    return sum;
}

double series_with_precision(double x, double epsilon) {
    double sum = 0.0, term;
    int n = 1;
    do {
        term = cos(2 * n * x) / (4 * n * n - 1);
        sum += term;
        n++;
    } while (fabs(term) > epsilon);
    return sum;
}

int main() {
    double a, b, h;
    int k, n, choice;


    printf("Enter the interval bounds [a, b]:\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);

    printf("Enter the number of points k: ");
    scanf("%d", &k);

    h = (b - a) / (k - 1);

    printf("Choose the method:\n");
    printf("1 - Series expansion with specified n\n");
    printf("2 - Series expansion with precision epsilon = %.4f\n", EPSILON);
    printf("Your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the number of series terms n: ");
        scanf("%d", &n);
    }

    printf("\nResults:\n");
    printf("x\t\tExact Value\t\tApprox. Value\t\tDifference\n");
    for (int i = 0; i < k; i++) {
        double x = a + i * h;
        double exact = exact_function(x);
        double approx = (choice == 1) ? series_function(x, n) : series_with_precision(x, EPSILON);
        printf("%.6lf\t%.6lf\t\t%.6lf\t\t%.6lf\n", x, exact, approx, fabs(exact - approx));
    }

    return 0;
}
