#include <stdio.h>
#include <math.h>
#include "Solvers.h"
#include "Consts.h"
#include "ColourConsts.h"


int OneTestSquareSolver (int test_n, double a, double b, double c, int n_r_exp, double x1_exp, double x2_exp) {   /*n_r_exp - expected number of roots*/

    double x1=0, x2=0;
    int n_roots=SquareSolver(a, b, c, &x1, &x2);

    if (n_roots==n_r_exp && ((x1 == x1_exp && x2 == x2_exp) || (x1 == x2_exp && x2 == x1_exp))) {
            printf("\nTEST #%d: (%lg, %lg, %lg)\n%sIT WORKED CORRECTLY!%s\n", test_n, a, b, c, KGRN, KNRM);

            return 1;
        }

    else {
        printf("\nTEST #%d: (%lg, %lg, %lg)\n%sFAILED:   n_roots = %d, x1 = %lg, x2 = %lg\n"
               "EXPECTED: n_roots = %d, x1 = %lg, x2 = %lg%s\n", test_n, a, b, c, KRED, n_roots, x1, x2, n_r_exp, x1_exp, x2_exp, KNRM);

            return 0;
        }
    }

void TestSquareSolver () {

    int n_right_tests = 0;
    int n_tests = 8;
    FILE *file_test_info = fopen("TestInfo.txt", "r");
    double a = 0, b = 0, c = 0, n_r_exp = 0, x1_exp = 0, x2_exp = 0;

    int i = 1;
    while (!feof(file_test_info)) {
        fscanf(file_test_info, "%lg %lg %lg %lg %lg %lg", &a, &b, &c, &n_r_exp, &x1_exp, &x2_exp);
        n_right_tests += OneTestSquareSolver(i, a, b, c, n_r_exp, x1_exp, x2_exp);
        n_tests = i;
        i++;
        }

    printf("\nNumber of right tests: %d from %d\n\n", n_right_tests, n_tests);
    }


int main () {

    TestSquareSolver();

    return 0;
    }
