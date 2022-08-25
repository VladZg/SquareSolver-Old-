#ifndef SOLVERS_H
#define SOLVERS_H

#include "Consts.h"

int CompareDoubleWithZero (double a);

int LinearSolver (double b, double c, double* x1);

int SquareSolver (double a, double b, double c, double* x1, double* x2);

#endif
