//Solver of quadratic equations
//Vladislav Zagorodniuk 2022

#include <stdio.h>
#include <math.h>
#define INF_ROOTS 'infinite number of roots'

int SquareSolver (double a, double b, double c, double* x1, double* x2) {

    if (a==0)
        {
        if (b==0) {
            return INF_ROOTS;
        }
        else {
            *x1 = -c / b;
            return 1;
            }
        }

    else {
        double d = b*b - 4*a*c;

        if (d > 0)
            {
            *x1 = (-b + sqrt (d) ) / (2*a);
            *x2 = (-b - sqrt (d) ) / (2*a);
            return 2;
            }

        else if (d == 0)
            {
            *x1 = *x2 = -b / (2*a);
            return 1;
            }

        else return 0;
        }
    }

int main( ) {

    double a=NULL, b=NULL, c=NULL, x1=NULL, x2=NULL;
    int n_roots;

    printf ("Type coefficients: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Solving square equation %lf*x*x + %lf*x + %lf = 0\n", a, b, c);

    n_roots = SquareSolver(a, b, c, &x1, &x2);
    switch(n_roots) {
        case 0: printf("Equation has no roots");
            break;

        case 1: printf("Equation has only 1 root: x = %lf", x1);
            break;

        case 2: printf("Equation has 2 roots: x1 = %.3lf, x2 = %.3lf", x1, x2);
            break;

        case INF_ROOTS: printf("Equation has infinite number of roots");
            break;
        }
    return 0;
    }
