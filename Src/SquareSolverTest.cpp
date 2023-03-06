#ifndef SQUARE_SOLVER_TEST_CPP
#define SQUARE_SOLVER_TEST_CPP

#include <stdio.h>
#include <math.h>

#include "./Include/Solvers.h"
#include "./Include/Consts.h"
#include "./Include/ColourConsts.h"

//! @brief Функция, проводящая одиночное тестирования функции, решающей квадратные ур-я
//! @param[in] test_n Количество найденных решений квадратного ур-я
//! @param[in] a Коэффицент квадратного ур-я перед x*x
//! @param[in] b Коэффицент квадратного ур-я перед x
//! @param[in] c Свободный член квадратного ур-я
//! @param[in] n_r_exp Ожидаемое кол-во корней квадратного ур-я
//! @param[in] x1_exp Первый ожидаемый корень квадратного ур-я (если нет, то 0)
//! @param[in] x2_exp Второй ожидаемый корень квадратного ур-я (если нет, то 0)
//! @return 1 - если тестируемая функция сработала правильно, 0 - в ином случае

int OneTestSquareSolver (int test_n, double a, double b, double c,
                         int n_r_exp, double x1_exp, double x2_exp)
{
    double x1=0, x2=0;
    int n_roots=SquareSolver(a, b, c, &x1, &x2);

    if (n_roots==n_r_exp && ((x1 == x1_exp && x2 == x2_exp) || (x1 == x2_exp && x2 == x1_exp)))
    {
        printf("\nTEST #%d: (%lg, %lg, %lg)\n" KGRN "IT WORKED CORRECTLY!\n" KNRM, test_n, a, b, c);

        return 1;
    }

    else
    {
        printf("\nTEST #%d: (%lg, %lg, %lg)\n" KRED "FAILED:   n_roots = %d, x1 = %lg, x2 = %lg\n"
               "EXPECTED: n_roots = %d, x1 = %lg, x2 = %lg\n" KNRM,
               test_n, a, b, c, n_roots, x1, x2, n_r_exp, x1_exp, x2_exp);

        return 0;
    }
}


//! @brief Функция, осуществляющая множественное тестирование функции, решающей квадратные ур-я

void TestSquareSolver ()
{
    int n_right_tests = 0;
    int n_tests = 0;
    double a = 0, b = 0, c = 0, n_r_exp = 0, x1_exp = 0, x2_exp = 0;
    int i = 1;
    FILE *file_test_info = fopen("TestInfo.txt", "r");

    while (!feof(file_test_info))
    {
        fscanf(file_test_info, "%lg %lg %lg %lg %lg %lg", &a, &b, &c, &n_r_exp, &x1_exp, &x2_exp);

        n_right_tests += OneTestSquareSolver(i, a, b, c, n_r_exp, x1_exp, x2_exp);
        n_tests = i;
        i++;
    }

    printf("\nNumber of successful tests: %d from %d\n\n", n_right_tests, n_tests);
}


//! @brief Основная функция, запускающая процесс тестирования
//! @return 0

int main ()
{
    TestSquareSolver();

    return 0;
}

#endif
