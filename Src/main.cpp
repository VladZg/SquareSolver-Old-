// Solver of quadratic equations
// Vladislav Zagorodniuk 2022

#include <stdio.h>
#include <math.h>

#include "../Include/ColourConsts.h"
#include "../Include/Consts.h"
#include "../Include/Assert.h"
#include "../Include/Solvers.h"
#include "../Include/Interactors.h"

//! @brief Основная функция программы, решающей квадратное уравнение
//! @version 1.0.0

int main ()
{
    int n_root = 0;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    BeautifulInput(&a, &b, &c);

    n_root = SquareSolver(a, b, c, &x1, &x2);

    BeautifulOutput(n_root, x1, x2, a, b, c);

    return 0;
}
