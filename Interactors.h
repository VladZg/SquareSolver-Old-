#ifndef INTERACTORS_H
#define INTERACTORS_H


//! @brief Функция, осуществляющая ввод параметров квадратного ур-я
//! @param[in] a Указатель на коэффицент квадратного ур-я перед x*x
//! @param[in] b Указатель на коэффицент квадратного ур-я перед x
//! @param[in] c Указатель на свободный член квадратного ур-я

void BeautifulInput (double* a, double* b, double* c);


//! @brief Функция, осуществляющая вывод решений квадратного ур-я
//! @param[in] n_root Количество найденных решений квадратного ур-я
//! @param[in] x1 Первый корень квадратного ур-я (если нет, то 0)
//! @param[in] x2 Второй корень квадратного ур-я (если нет, то 0)
//! @param[in] a Коэффицент квадратного ур-я перед x*x
//! @param[in] b Коэффицент квадратного ур-я перед x
//! @param[in] c Свободный член квадратного ур-я

void BeautifulOutput (int n_root, double x1, double x2, double a, double b , double c);

#endif
