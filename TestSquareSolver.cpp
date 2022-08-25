#include <stdio.h>
#include <math.h>
#define INF_R -1

int SquareSolver (double a, double b, double c, double* x1, double* x2) {

    if (a==0)
        {
        if (b==0) {
            return INF_R;
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


void TestSquareSolver(double a, double b, double c, int n_r_exp, double x1_exp, double x2_exp) {   /*n_r_exp - expected number of roots*/

    double x1=0, x2=0;
    int n_roots=SquareSolver(a, b, c, &x1, &x2);

    if (n_roots==n_r_exp && x1==x1_exp && x2==x2_exp) {
            printf("It worked correctly!\n\n");
        }
    else
        printf("FAILED:   n_roots=%d, x1=%lf, x2=%lf\n"
               "EXPECTED: n_roots=%d, x1=%lf, x2=%lf\n\n", n_roots, x1, x2, n_r_exp, x1_exp, x2_exp);
    }


int main() {
    TestSquareSolver(1, 1, -2, 2, 1, -2);
    TestSquareSolver(1, 1, -7, 2, 7, 13);
    return 0;
    }







