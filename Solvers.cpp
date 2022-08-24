#include <math.h>

int CompareDoubleWithZero (double a) {

    if (a == 0.0)
        return 1;
    else
        return 0;
    }

int LinearSolver (double b, double c, double* x1) {

    if (CompareDoubleWithZero(b)) {

        return INF_R;
    }

    else {
        *x1 = -c / b;

        return 1;
        }
    }

int SquareSolver (double a, double b, double c, double* x1, double* x2) {

    if (CompareDoubleWithZero(a))
        return LinearSolver(b, c, x1);

    else {

        double d = b*b - 4*a*c;

        if (d > 0.0)
            {
            *x1 = (-b + sqrt (d) ) / 2 / a;
            *x2 = (-b - sqrt (d) ) / 2 / a;

            return 2;
            }

        else if (CompareDoubleWithZero(d))
            {
            *x1 = *x2 = -b / 2 / a;

            return 1;
            }

        else return 0;
        }
    }
