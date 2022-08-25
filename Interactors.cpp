#include <stdio.h>
#include "Consts.h"
#include "ColourConsts.h"


void BeautifulInput (double* a, double* b, double* c) {
    while (true) {

        printf("Type 3 coefficients: ");

        if (scanf("%lg %lg %lg", a, b, c) == 3)
            break;

        while (getchar() != '\n')
            continue;

        printf("%sWrong format of input! Try again!%s\n\n", KRED, KNRM);
        }
    }

void BeautifulOutput (int n_root, double x1, double x2, double a, double b , double c) {

    printf("\n%sSolving equation %lg*x*x + %lg*x + %lg = 0%s\n\n", KBLU, a, b, c, KNRM);

    switch(n_root) {

        case 0: printf("%sEquation has no roots...%s\n", KGRN, KNRM);
            break;

        case 1: printf("%sEquation has only 1 root: x = %lg%s\n", KGRN, x1, KNRM);
            break;

        case 2: printf("%sEquation has 2 roots: x1 = %lg, x2 = %lg%s\n", KGRN, x1, x2, KNRM);
            break;

        case INF_R: printf("%sEquation has infinite number of roots!%s\n", KGRN, KNRM);
            break;
        }
    }
