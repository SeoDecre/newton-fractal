#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define DIM 1000

// Function used to evaluate a polynomial using Horner's method
double complex evaluatePolynomial(double complex coefficients[], int degree, double complex x) {
    double complex result = coefficients[0];
    for (int i = 1; i < degree; i++) {
        result = result * x + coefficients[i];
    }
    return result;
}

// Function used to compute the derivative of a polynomial
double complex* computeDerivative(double complex coefficients[], int degree) {
    if (degree <= 1) {
        double complex* derivative = (double complex*)malloc(sizeof(double));
        *derivative = 0.0;
        return derivative;
    }

    // Array to store the derivative coefficients
    double complex* derivative = (double complex*)malloc((degree - 1) * sizeof(double));
    for (int i = 0; i < degree - 1; i++) {
        derivative[i] = coefficients[i] * (degree - i - 1);
    }

    return derivative;
}

// Function used to find a root of the polynomial using Newton's method
// This function also takes the derivative of the polynomial (since we don't want to compute it DIMxDIM times)
double complex newtonMethod(double complex* polynomial, double complex* derivative, int degree, double complex x0) {
    double complex x = x0;
    double complex px = evaluatePolynomial(polynomial, degree, x0);

    while (cabs(px) > 1E-12) {
        x = x - evaluatePolynomial(polynomial, degree, x) / evaluatePolynomial(derivative, degree - 1, x);
        px = evaluatePolynomial(polynomial, degree, x);
    }
    return x;
}

// Function used to decide which root a complex value x belongs to
double decideRoot(double complex x) {
    // double distance1 = cabs(x + 1);
    // double distance2 = cabs(x - (0.5 - sqrt(3)/2 * I));
    // double distance3 = cabs(x - (0.5 + sqrt(3)/2 * I));
    double distance1 = cabs(x - 1);
    double distance2 = cabs(x + 1);
    double distance3 = cabs(x - (1 * I));
    double distance4 = cabs(x - (-1 * I));
    double minDistance = fmin(distance1, fmin(distance2, fmin(distance3, distance4)));

    return (minDistance == distance1) ? 1 : (minDistance == distance2) ? 2 : (minDistance == distance3) ? 3 : 4;
}

// Main function used to create the Newton fractal and write it to a file
void generateNewtonFractal(double complex* polynomial, int degree, FILE *fp) {
    double* image = (double*)malloc(DIM * DIM * sizeof(double));
    double complex z0;
    double complex root;

    // Computing derivative so that it's not calculated DIMxDIM times
    double complex *derivative = computeDerivative(polynomial, degree);

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            z0 = (-2 + (4.0 * i) / (DIM - 1)) + (-2 + (4.0 * j) / (DIM - 1)) * I;
            root = newtonMethod(polynomial, derivative, degree, z0);
            image[i * DIM + j] = decideRoot(root);
            fprintf(fp, "%d ", (int)image[i * DIM + j]);
        }
        fprintf(fp, "\n");
    }

    free(image);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Incorrect input\n");
        return 1;
    }

    FILE *fp;
    int degree = argc - 1;
    double complex polynomial[degree];

    // Building the polynomial
    for (int i = 1; i < argc; i++) polynomial[i - 1] = atof(argv[i]);

    fp = fopen("matrix.txt", "w");
    if (fp == NULL) {
        printf("Error opening the file");
        return 1;
    }

    generateNewtonFractal(polynomial, degree, fp);
    fclose(fp);

    return 0;
}
