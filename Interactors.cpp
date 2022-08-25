#include <stdio.h>
#include "const.h"


void BeautifulInput (double* a, double* b, double* c) {
    while (true) {

        printf("Type 3 coefficients: ");

        if (scanf("%lf %lf %lf", &*a, &*b, &*c) == 3)
            break;

        while (getchar() != '\n')
            continue;

        printf("Wrong format of input! Try again!\n\n");
        }
    }

void BeautifulOutput (int n_root, double x1, double x2, double a, double b , double c) {

    printf("Solving equation %lf*x*x + %lf*x + %lf = 0\n", a, b, c);

    switch(n_root) {

        case 0: printf("Equation has no roots...\n");
            break;

        case 1: printf("Equation has only 1 root: x = %lf\n", x1);
            break;

        case 2: printf("Equation has 2 roots: x1 = %.3lf, x2 = %.3lf\n", x1, x2);
            break;

        case INF_R: printf("Equation has infinite number of roots!\n");
            break;
        }
    }
