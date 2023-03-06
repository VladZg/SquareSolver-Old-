#ifndef SOLVERS_CPP
#define SOLVERS_CPP

#include <stdio.h>

#include "../Include/Consts.h"
#include "../Include/ColourConsts.h"
#include "../Include/Assert.h"

int a;

void BeautifulInput (double* a, double* b, double* c)
{
    while (true)
    {

        printf("Type 3 coefficients: ");

        if (scanf("%lg %lg %lg", a, b, c) == 3)
        {
            ASSERT(a != NULL);
            ASSERT(b != NULL);
            ASSERT(c != NULL);

            break;
        }

        while (getchar() != '\n')
            continue;

        printf(KRED "Wrong format of input! Try again!\n\n" KNRM);
    }
}


void BeautifulOutput (int n_root, double x1, double x2, double a, double b , double c)
{
    printf(KBLU "\nSolving equation %lg*x*x + %lg*x + %lg = 0...\n\n" KNRM, a, b, c);

    switch (n_root)
    {
        case 0:     printf(KGRN "Equation has no roots...\n" KNRM);
            break;

        case 1:     printf(KGRN "Equation has only 1 root: x = %lg ...\n" KNRM, x1);
            break;

        case 2:     printf(KGRN "Equation has 2 roots: x1 = %lg, x2 = %lg ...\n" KNRM, x1, x2);
            break;

        case INF_R: printf(KGRN "Congratulations! Equation has infinite number of roots!..\n" KNRM);
            break;
    }

    printf ("...and I am Groot.\n");
}

#endif
