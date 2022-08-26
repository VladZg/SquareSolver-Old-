#include <stdio.h>
#include <math.h>

#include "Consts.h"
#include "Assert.h"


#define __attribute__(a)

int CompareDoubles (double a, double b) __attribute__ ((vvzsr))
{
    if (fabs(a - b) < EPS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#undef __attribute__


int LinearSolver (double b, double c, double* x)
{
    ASSERT(x != NULL);

    if (CompareDoubles(b, 0))
    {
        return INF_R;
    }

    else
    {
        *x = -c / b;

        return 1;
    }
}


int SquareSolver (double a, double b, double c, double* x1, double* x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);

    if (CompareDoubles(a, 0))

        return LinearSolver(b, c, x1);

    else if (CompareDoubles(c, 0))
    {
        int linear_solver_res = LinearSolver(a, b, x2);
        *x1 = 0;

        if (CompareDoubles(*x2, 0))
        {
            return 1;
        }

        else
        {
            return 1 + linear_solver_res;
        }
    }

    else
    {
        double d = b*b - 4*a*c;

        if (d > 0)
        {
            double sqrt_d = sqrt(d);

            *x1 = (-b + sqrt_d ) / 2 / a;
            *x2 = (-b - sqrt_d ) / 2 / a;

            return 2;
        }

        else if (CompareDoubles(d, 0))
        {
            *x1 = *x2 = -b / 2 / a;

            return 1;
        }

        else return 0;
    }
}
