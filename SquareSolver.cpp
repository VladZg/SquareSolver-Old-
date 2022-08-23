//Solver of quadratic equations
//Vladislav Zagorodniuk 2022

#include <stdio.h>
#include <math.h>
#define INF_ROOTS 'infinite number of roots'

int SquareSolver (float a, float b, float c, float* x1, float* x2)
    {
    if (a==0)
        {
        if (b==0) return INF_ROOTS;
        else
            {
            *x1 = -c / b;
            return 1;
            }
        }
    else
        {
        float d = b*b - 4*a*c;

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

main( )
    {

    float a=0, b=0, c=0, x1, x2;
    int n_roots;

    printf ("Type coefficients: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Solving square equation %.3f*x*x + %.3f*x + %.3f = 0\n", a, b, c);

    n_roots = SquareSolver(a, b, c, &x1, &x2);
    switch(n_roots)
        {
        case 0: printf("Equation has no roots");
            break;

        case 1: printf("Equation has only 1 root: x = %f", x1);
            break;

        case 2: printf("Equation has 2 roots: x1 = %.3f, x2 = %.3f", x1, x2);
            break;

        case INF_ROOTS: printf("Equation has infinite number of roots");
            break;
        }
    }


