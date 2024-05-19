#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

/* по дефолту создается матрица 2x2 */
TEST(constructor, Default) {
  S21Matrix a;
  int i = a.get_row();
  int j = a.get_col();
  EXPECT_EQ(i, 2);
  EXPECT_EQ(j, 2);
}

/* создаем матрицу 3x5 */
TEST(constructor, parametrized) {
  S21Matrix a(3, 5);
  int i = a.get_row();
  int j = a.get_col();
  EXPECT_EQ(i, 3);
  EXPECT_EQ(j, 5);
}

/* при попытке создать матрицу с 0 rows получаем предупреждение */
TEST(constructor, exeption) { ASSERT_ANY_THROW(S21Matrix a(0, 3)); }

/* создаем матрицу А и матрицу B по образу A, сравниваем A и B,
 * должны быть равными */
TEST(constructor, copy) {
  S21Matrix a(3, 4);
  a.FillMatrix();
  S21Matrix b(a);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_EQ(a(i, j), b(i, j));
    }
  }
}

/* создаем матрицу А, матрицу B, переносим значения из В в А.
 * Матрица А должна обнулиться */
TEST(constructor, move) {
  S21Matrix a(3, 4);
  a.FillMatrix();
  S21Matrix b(std::move(a));
  EXPECT_EQ(b.get_row(), 3);
  EXPECT_EQ(b.get_col(), 4);
  EXPECT_EQ(a.get_row(), 0);
  EXPECT_EQ(a.get_col(), 0);
}

/* создаем матрицу А, по умолчанию 2х2, устанавливаем rows на 4. Теперь
 * матрица А имеет размер 4х2 */
TEST(mutators, set_row_1) {
  S21Matrix a;
  a.set_row(4);
  EXPECT_EQ(a.get_row(), 4);
  EXPECT_EQ(a.get_col(), 2);
}

/* создаем матрицу А размером 4х5, устанавливаем rows на 2. Теперь
 * матрица А имеет размер 2х5 */
TEST(mutators, set_row_2) {
  S21Matrix a(4, 5);
  a.set_row(2);
  EXPECT_EQ(a.get_row(), 2);
  EXPECT_EQ(a.get_col(), 5);
}

/* создаем матрицу А размером 3х3, при попытке установить rows на 0
 * получаем предупреждение */
TEST(mutators, set_row_3) {
  S21Matrix a(3, 3);
  ASSERT_ANY_THROW(a.set_row(0););
}

/* создаем матрицу А размером 3х3, при попытке установить rows на отрицательное
 * значение получаем предупреждение */
TEST(mutators, set_row_4) {
  S21Matrix a(3, 3);
  ASSERT_ANY_THROW(a.set_row(-3););
}

/* создаем матрицу А, по умолчанию 2х2, устанавливаем cols на 4. Теперь
 * матрица А имеет размер 2х4 */
TEST(mutators, set_col_1) {
  S21Matrix a;
  a.set_col(4);
  EXPECT_EQ(a.get_row(), 2);
  EXPECT_EQ(a.get_col(), 4);
}

/* создаем матрицу А размером 4х5, устанавливаем cols на 2. Теперь
 * матрица А имеет размер 4х2 */
TEST(mutators, set_col_2) {
  S21Matrix a(4, 5);
  a.set_col(2);
  EXPECT_EQ(a.get_row(), 4);
  EXPECT_EQ(a.get_col(), 2);
}

/* создаем матрицу А размером 3х3, при попытке установить cols на 0
 * получаем предупреждение */
TEST(mutators, set_col_3) {
  S21Matrix a(3, 3);
  ASSERT_ANY_THROW(a.set_col(0););
}

/* создаем матрицу А размером 3х3, при попытке установить cols на отрицательное
 * значение получаем предупреждение */
TEST(mutators, set_col_4) {
  S21Matrix a(3, 3);
  ASSERT_ANY_THROW(a.set_col(-2););
}

/* создаем матрицу размером 5х3, берем значение из get_row, должно вернуть 5 */
TEST(getters, get_row) {
  S21Matrix a(5, 3);
  EXPECT_EQ(a.get_row(), 5);
}

/* создаем матрицу размером 3х5, берем значение из get_col, должно вернуть 5 */
TEST(getters, get_col) {
  S21Matrix a(3, 5);
  EXPECT_EQ(a.get_col(), 5);
}

/* создаем матрицу A, матрицу В приравневаем к А через оператор =,
 * матрицы должны быть равны */
TEST(overload, equal_1) {
  S21Matrix a(3, 3);
  a.FillMatrix();
  S21Matrix b = a;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(a(i, j), b(i, j));
    }
  }
}

/* создаем матрицу A, матрицу В приравневаем к А через оператор =,
 * а матрицу С приравневаем к В, все матрицы должны быть равны */
TEST(overload, equal_2) {
  S21Matrix a(3, 3);
  a.FillMatrix();
  S21Matrix b;
  S21Matrix c = b = a;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(a(i, j), b(i, j));
      EXPECT_EQ(b(i, j), c(i, j));
    }
  }
}

/* создаем матрицу A, копируем значения в матрицу B через оператор переноса =,
 * затем переносим значения из B в C и сравниваем с матрицей A.
 * Матрицы A и C должны быть равны, а матрица B должна быть обнулена */
TEST(overload, equal_move) {
  S21Matrix a(3, 3);
  a.FillMatrix();
  S21Matrix b(a);
  S21Matrix c = std::move(b);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(a(i, j), c(i, j));
    }
  }
  EXPECT_EQ(b.get_row(), 0);
  EXPECT_EQ(b.get_col(), 0);
}

/* создаем матрицу A, матрицу В по образу А. Сравниваем матрицы
 * через оператор ==, должно вернуть true */
TEST(overload, is_equal_1) {
  S21Matrix a(3, 3);
  a.FillMatrix();
  S21Matrix b(a);
  EXPECT_TRUE(a == b);
}

/* создаем матрицу A и матрицу В, заполняем их разными значениями.
 * Сравниваем матрицы через оператор ==, должно вернуть false */
TEST(overload, is_equal_2) {
  S21Matrix a(3, 3);
  a.FillMatrix();
  S21Matrix b(3, 3);
  b.FillMatrix();
  EXPECT_FALSE(a == b);
}

/* создаем разноразмерные матрицы A и В.
 * Сравниваем матрицы через оператор ==, получаем предупреждение */
TEST(overload, is_equal_3) {
  S21Matrix a(3, 3);
  a.FillMatrix();
  S21Matrix b(2, 4);
  b.FillMatrix();
  EXPECT_ANY_THROW(a == b);
}

/* создаем матрицы A и В, заполняем разными значениями. Складываем матрицы через
 * оператор +. Сравнивваем с матрицей correct, должно вернуть true */
TEST(overload, sum_1) {
  S21Matrix a(3, 3);
  double k = 1.0;
  double g = 2.5;
  double f = 3.5;
  S21Matrix b(3, 3);
  S21Matrix correct(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      b(i, j) = g;
      correct(i, j) = f;
      k++;
      f++;
    }
  }
  S21Matrix c = a + b;
  EXPECT_TRUE(correct == c);
}

/* создаем разноразмерные матрицы A и В. При попытке сложения матриц через
 * оператор + получаем предупреждение */
TEST(overload, sum_2) {
  S21Matrix a(3, 3);
  S21Matrix b(5, 5);
  EXPECT_ANY_THROW(S21Matrix c = a + b);
}

/* создаем матрицы A и В, заполняем разными значениями. Вычитаем матрицу B из А
 * через оператор +. Сравниваем с матрицей correct, должно вернуть true */
TEST(overload, sub_1) {
  S21Matrix a(3, 3);
  double k = 2.5;
  double g = 1.3;
  double f = 1.2;
  S21Matrix b(3, 3);
  S21Matrix correct(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      b(i, j) = g;
      correct(i, j) = f;
      k++;
      f++;
    }
  }
  S21Matrix c = a - b;
  EXPECT_TRUE(correct == c);
}

/* создаем разноразмерные матрицы A и В. При попытке вычитания одной матрицы из
 * другой через оператор - получаем предупреждение */
TEST(overload, sub_2) {
  S21Matrix a(3, 3);
  S21Matrix b(5, 5);
  EXPECT_ANY_THROW(S21Matrix c = a - b);
}

/* создаем матрицы A и В, заполняем разными значениями. Прибавляем значения
 * матрицы B к матрице А через оператор +=.
 * Сравнивваем А с матрицей correct, должно вернуть true */
TEST(overload, sum_assign_1) {
  S21Matrix a(3, 3);
  double k = 1.0;
  double g = 2.5;
  double f = 3.5;
  S21Matrix b(3, 3);
  S21Matrix correct(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      b(i, j) = g;
      correct(i, j) = f;
      k++;
      f++;
    }
  }
  a += b;
  EXPECT_TRUE(correct == a);
}

/* создаем разноразмерные матрицы A и В. При попытке сложения прибавления
 * значений матрицы В к А через оператор += получаем предупреждение */
TEST(overload, sum_assign_2) {
  S21Matrix a(3, 3);
  S21Matrix b(5, 5);
  EXPECT_ANY_THROW(a += b);
}

/* создаем матрицы A и В, заполняем разными значениями. Вычитаем значения
 * матрицы B из матрицы А через оператор -=.
 * Сравнивваем А с матрицей correct, должно вернуть true */
TEST(overload, sub_assign_1) {
  S21Matrix a(3, 3);
  double k = 2.5;
  double g = 1.3;
  double f = 1.2;
  S21Matrix b(3, 3);
  S21Matrix correct(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      b(i, j) = g;
      correct(i, j) = f;
      k++;
      f++;
    }
  }
  a -= b;
  EXPECT_TRUE(correct == a);
}

/* создаем разноразмерные матрицы A и В. При попытке вычитания значений
 * матрицы В из А через оператор -= получаем предупреждение */
TEST(overload, sub_asssign_2) {
  S21Matrix a(3, 3);
  S21Matrix b(5, 5);
  EXPECT_ANY_THROW(a -= b);
}

/* создвем матрицу А, умножаем ее на значение х через оператор *.
 * Сравниваем с матрицей correct, должно вернуь true */
TEST(overload, mult_num) {
  S21Matrix a(3, 3);
  S21Matrix correct(3, 3);
  double x = 1.3;
  double k = 2.5;
  double f = 3.25;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      correct(i, j) = f;
      k++;
      f += 1.3;
    }
  }
  EXPECT_TRUE(correct == (a * x));
}

/* создаем две квадратные матрицы А и В, перемножаем с помощью
 * оператора *. Сравниваем с матрицей correct, должно вернуть true */
TEST(overload, mult_matrix_1) {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  S21Matrix correct(3, 3);
  double k = 2.5;
  double g = 1.3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      b(i, j) = g;
      k++;
      g++;
    }
  }
  correct(0, 0) = 51.1500000;
  correct(0, 1) = 61.6500000;
  correct(0, 2) = 72.1500000;
  correct(1, 0) = 89.8500000;
  correct(1, 1) = 109.3500000;
  correct(1, 2) = 128.8500000;
  correct(2, 0) = 128.5500000;
  correct(2, 1) = 157.0500000;
  correct(2, 2) = 185.5500000;
  EXPECT_TRUE(correct == (a * b));
}

/* при перемножении матриц кол-во колонок 1й матрцы должно быть равно
 * кол-ву рядов 2й матрицы. Cоздаем матрицу А размером 3х2 и матрицу В
 * размером 2х4. Правило выпоолняется, перемножаем с помощью
 * оператора *. Сравниваем с матрицей correct, должно вернуть true */
TEST(overload, mult_matrix_2) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 4);
  S21Matrix correct(3, 4);
  double k = 2.5;
  double g = 1.3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      a(i, j) = k;
      k++;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      b(i, j) = g;
      g++;
    }
  }
  correct(0, 0) = 21.8000000;
  correct(0, 1) = 27.8000000;
  correct(0, 2) = 33.8000000;
  correct(0, 3) = 39.8000000;
  correct(1, 0) = 35.0000000;
  correct(1, 1) = 45.0000000;
  correct(1, 2) = 55.0000000;
  correct(1, 3) = 65.0000000;
  correct(2, 0) = 48.2000000;
  correct(2, 1) = 62.2000000;
  correct(2, 2) = 76.2000000;
  correct(2, 3) = 90.2000000;
  EXPECT_TRUE(correct == (a * b));
}

/* при перемножении матриц кол-во колонок 1й матрцы должно быть равно
 * кол-ву рядов 2й матрицы. Создаем матрицу А размером 3х3 и матрицу В
 * размером 4х5. Правило не соблюдается, при попытке перемножить матрицы
 * с помощью оператора * получаем предупреждение */
TEST(overload, mult_matrix_3) {
  S21Matrix a(3, 3);
  S21Matrix b(4, 5);
  EXPECT_ANY_THROW(S21Matrix c = a * b);
}

/* создвем матрицу А, умножаем ее на значение х через оператор присваивания *=.
 * Сравниваем с матрицей correct, должно вернуь true */
TEST(overload, mult_num_assign) {
  S21Matrix a(3, 3);
  S21Matrix correct(3, 3);
  double x = 1.3;
  double k = 2.5;
  double f = 3.25;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      correct(i, j) = f;
      k++;
      f += 1.3;
    }
  }
  EXPECT_TRUE(correct == (a *= x));
}

/* создаем две квадратные матрицы А и В, перемножаем с помощью оператора
 * присваивания *=. Сравниваем А с матрицей correct, должно вернуть true */
TEST(overload, mult_matrix_assign_1) {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  S21Matrix correct(3, 3);
  double k = 2.5;
  double g = 1.3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      b(i, j) = g;
      k++;
      g++;
    }
  }
  correct(0, 0) = 51.1500000;
  correct(0, 1) = 61.6500000;
  correct(0, 2) = 72.1500000;
  correct(1, 0) = 89.8500000;
  correct(1, 1) = 109.3500000;
  correct(1, 2) = 128.8500000;
  correct(2, 0) = 128.5500000;
  correct(2, 1) = 157.0500000;
  correct(2, 2) = 185.5500000;
  EXPECT_TRUE(correct == (a *= b));
}

/* при перемножении матриц кол-во колонок 1й матрцы должно быть равно
 * кол-ву рядов 2й матрицы. Cоздаем матрицу А размером 3х2 и матрицу В
 * размером 2х4. Правило выпоолняется, перемножаем с помощью
 * оператора присваивания *=.
 * Сравниваем с матрицей correct, должно вернуть true */
TEST(overload, mult_matrix_assign_2) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 4);
  S21Matrix correct(3, 4);
  double k = 2.5;
  double g = 1.3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      a(i, j) = k;
      k++;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      b(i, j) = g;
      g++;
    }
  }
  correct(0, 0) = 21.8000000;
  correct(0, 1) = 27.8000000;
  correct(0, 2) = 33.8000000;
  correct(0, 3) = 39.8000000;
  correct(1, 0) = 35.0000000;
  correct(1, 1) = 45.0000000;
  correct(1, 2) = 55.0000000;
  correct(1, 3) = 65.0000000;
  correct(2, 0) = 48.2000000;
  correct(2, 1) = 62.2000000;
  correct(2, 2) = 76.2000000;
  correct(2, 3) = 90.2000000;
  EXPECT_TRUE(correct == (a *= b));
}

/* при перемножении матриц кол-во колонок 1й матрцы должно быть равно
 * кол-ву рядов 2й матрицы. Создаем матрицу А размером 3х3 и матрицу В
 * размером 4х5. Правило не соблюдается, при попытке перемножить матрицы
 * с помощью оператора присваивания *= получаем предупреждение */
TEST(overload, mult_matrix_assign_3) {
  S21Matrix a(3, 3);
  S21Matrix b(4, 5);
  EXPECT_ANY_THROW(a *= b);
}

/* создаем матрицу размером 3х4, по умолчанию все элементы инициализированы
 * нулями.Берем значение с индексом [2][2] с помощью оператора индексирования(),
 * должно вернуть ноль. */
TEST(overload, get_index_1) {
  S21Matrix a(3, 4);
  EXPECT_TRUE(a(2, 2) == 0);
}

/* создаем матрицу размером 3х4, по умолчанию все элементы инициализированы
 * нулями. При попытке обратиться к значению с индексом [5][2] с помощью
 * оператора индексирования(), получаем предупреждение, так как индекс ряда
 * выходит за рамки матрицы */
TEST(overload, get_index_2) {
  S21Matrix a(3, 4);
  EXPECT_ANY_THROW(a(5, 2));
}

/* создаем матрицу размером 3х4, по умолчанию все элементы инициализированы
 * нулями. При попытке обратиться к значению с индексом [2][-2] с помощью
 * оператора индексирования(), получаем предупреждение, так как индекс
 * не может быть отрицательным */
TEST(overload, get_index_3) {
  S21Matrix a(3, 4);
  EXPECT_ANY_THROW(a(2, -2));
}

/* создаем матрицу A, матрицу В приравневаем к А через оператор =,
 * матрицы должны быть равны */
TEST(functions, eq_matrix_1) {
  S21Matrix a(3, 3);
  a.FillMatrix();
  S21Matrix b = a;
  EXPECT_TRUE(b.EqMatrix(a));
}

/* создаем матрицу A и матрицу В, заполняем из разными значениями.
 * Сравниваем матрицы через оператор ==, должно вернуть false */
TEST(functions, eq_matrix_2) {
  S21Matrix a(3, 3);
  a.FillMatrix();
  S21Matrix b(3, 3);
  b.FillMatrix();
  EXPECT_FALSE(b.EqMatrix(a));
}

/* создаем разноразмерные матрицы A и В.
 * Сравниваем матрицы через оператор ==, получаем предупреждение */
TEST(functions, eq_matrix_3) {
  S21Matrix a(3, 3);
  a.FillMatrix();
  S21Matrix b(2, 4);
  b.FillMatrix();
  EXPECT_ANY_THROW(b.EqMatrix(a));
}

/* создаем матрицы A и В, заполняем разными значениями.Прибавляем матрицу B к А.
 * Сравниваем с матрицей correct, должно вернуть true */
TEST(functions, sum_matrix_1) {
  S21Matrix a(3, 3);
  double k = 1.0;
  double g = 2.5;
  double f = 3.5;
  S21Matrix b(3, 3);
  S21Matrix correct(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      b(i, j) = g;
      correct(i, j) = f;
      k++;
      f++;
    }
  }
  a.SumMatrix(b);
  EXPECT_TRUE(correct == a);
}

/* создаем разноразмерные матрицы A и В. При попытке сложения матриц
 * получаем предупреждение */
TEST(functions, sum_matrix_2) {
  S21Matrix a(3, 3);
  S21Matrix b(5, 5);
  EXPECT_ANY_THROW(a.SumMatrix(b));
}

/* создаем матрицы A и В, заполняем разными значениями. Вычитаем матрицу B из А.
 * Сравниваем с матрицей correct, должно вернуть true */
TEST(functions, sub_matrix_1) {
  S21Matrix a(3, 3);
  double k = 2.5;
  double g = 1.3;
  double f = 1.2;
  S21Matrix b(3, 3);
  S21Matrix correct(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      b(i, j) = g;
      correct(i, j) = f;
      k++;
      f++;
    }
  }
  a.SubMatrix(b);
  EXPECT_TRUE(correct == a);
}

/* создаем разноразмерные матрицы A и В. При попытке вычитания одной матрицы из
 * другой через оператор - получаем предупреждение */
TEST(functions, sub_matrix_2) {
  S21Matrix a(3, 3);
  S21Matrix b(5, 5);
  EXPECT_ANY_THROW(a.SubMatrix(b));
}

/* создвем матрицу А, умножаем ее на значение х .
 * Сравниваем с матрицей correct, должно вернуь true */
TEST(functions, mult_num) {
  S21Matrix a(3, 3);
  S21Matrix correct(3, 3);
  double x = 1.3;
  double k = 2.5;
  double f = 3.25;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      correct(i, j) = f;
      k++;
      f += 1.3;
    }
  }
  a.MulNumber(x);
  EXPECT_TRUE(correct == a);
}

/* создаем две квадратные матрицы А и В, перемножаем.
 * Сравниваем с матрицей correct, должно вернуть true */
TEST(functions, mult_matrix_1) {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  S21Matrix correct(3, 3);
  double k = 2.5;
  double g = 1.3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      b(i, j) = g;
      k++;
      g++;
    }
  }
  correct(0, 0) = 51.1500000;
  correct(0, 1) = 61.6500000;
  correct(0, 2) = 72.1500000;
  correct(1, 0) = 89.8500000;
  correct(1, 1) = 109.3500000;
  correct(1, 2) = 128.8500000;
  correct(2, 0) = 128.5500000;
  correct(2, 1) = 157.0500000;
  correct(2, 2) = 185.5500000;
  a.MulMatrix(b);
  EXPECT_TRUE(correct == a);
}

/* при перемножении матриц кол-во колонок 1й матрцы должно быть равно
 * кол-ву рядов 2й матрицы. Cоздаем матрицу А размером 3х2 и матрицу В
 * размером 2х4. Правило выпоолняется, перемножаем матрицы.
 * Сравниваем с матрицей correct, должно вернуть true */
TEST(functions, mult_matrix_2) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 4);
  S21Matrix correct(3, 4);
  double k = 2.5;
  double g = 1.3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      a(i, j) = k;
      k++;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      b(i, j) = g;
      g++;
    }
  }
  correct(0, 0) = 21.8000000;
  correct(0, 1) = 27.8000000;
  correct(0, 2) = 33.8000000;
  correct(0, 3) = 39.8000000;
  correct(1, 0) = 35.0000000;
  correct(1, 1) = 45.0000000;
  correct(1, 2) = 55.0000000;
  correct(1, 3) = 65.0000000;
  correct(2, 0) = 48.2000000;
  correct(2, 1) = 62.2000000;
  correct(2, 2) = 76.2000000;
  correct(2, 3) = 90.2000000;
  a.MulMatrix(b);
  EXPECT_TRUE(correct == a);
}

/* при перемножении матриц кол-во колонок 1й матрцы должно быть равно
 * кол-ву рядов 2й матрицы. Создаем матрицу А размером 3х3 и матрицу В
 * размером 4х5. Правило не соблюдается, при попытке перемножить матрицы
 * получаем предупреждение */
TEST(functions, mult_matrix_3) {
  S21Matrix a(3, 3);
  S21Matrix b(4, 5);
  EXPECT_ANY_THROW(a.MulMatrix(b));
}

/* создаем матрицу размером 2х3, транспонируем. Должна получиться матрица В
 * размером 3х2. Сравниваем с матрицей correct, должно вернуть true */
TEST(functions, transpose_1) {
  S21Matrix a(2, 3);
  S21Matrix correct(3, 2);
  double k = 2.5;
  double f = 2.5;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = k;
      k++;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      correct(j, i) = f;
      f++;
    }
  }
  S21Matrix b = a.Transpose();
  EXPECT_TRUE(correct == b);
}

/* создаем квадратную матрицу по умолчанию размером 2х2, транспонируем.
 * Должна получиться матрица В размером 2х2. Сравниваем с матрицей correct,
 * должно вернуть true */
TEST(functions, transpose_2) {
  S21Matrix a;
  S21Matrix correct;
  double k = 2.5;
  double f = 2.5;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a(i, j) = k;
      correct(j, i) = f;
      k++;
      f++;
    }
  }
  S21Matrix b = a.Transpose();
  EXPECT_TRUE(correct == b);
}

/* создаем квадратную матрицу размером 1х1, транспонируем.
 * Должна получиться матрица В размером 1х1. Сравниваем с матрицей correct,
 * должно вернуть true */
TEST(functions, transpose_3) {
  S21Matrix a;
  S21Matrix correct;
  double k = 2.5;
  double f = 2.5;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 1; j++) {
      a(i, j) = k;
      correct(j, i) = f;
      k++;
      f++;
    }
  }
  S21Matrix b = a.Transpose();
  EXPECT_TRUE(correct == b);
}

/* проверяем детерминант матрицы, должен быть равен нулю */
TEST(functions, determinant_1) {
  S21Matrix a(3, 3);
  double k = 2.5;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 1; j++) {
      a(i, j) = k;
      k++;
    }
  }
  EXPECT_TRUE(a.Determinant() == 0);
}

/* проверяем детерминант матрицы, должен быть равен 204 */
TEST(functions, determinant_2) {
  S21Matrix a(3, 3);
  a(0, 0) = 1;
  a(0, 1) = -2;
  a(0, 2) = 3;
  a(1, 0) = 4;
  a(1, 1) = 0;
  a(1, 2) = 6;
  a(2, 0) = -7;
  a(2, 1) = 8;
  a(2, 2) = 9;
  EXPECT_TRUE(a.Determinant() == 204);
}

/* проверяем детерминант матрицы, должен быть равен -60 */
TEST(functions, determinant_3) {
  S21Matrix a(4, 4);
  a(0, 0) = 5;
  a(0, 1) = 8;
  a(0, 2) = 0;
  a(0, 3) = -4;
  a(1, 0) = 0;
  a(1, 1) = 1;
  a(1, 2) = 10;
  a(1, 3) = 1;
  a(2, 0) = 0;
  a(2, 1) = 0;
  a(2, 2) = -4;
  a(2, 3) = 0;
  a(3, 0) = 0;
  a(3, 1) = 0;
  a(3, 2) = 0;
  a(3, 3) = 3;
  EXPECT_TRUE(a.Determinant() == -60);
}

/* проверяем детерминант матрицы размером 1х1, должен быть равен
 * единственному элементу матрицы */
TEST(functions, determinant_4) {
  S21Matrix a(1, 1);
  a(0, 0) = 85.656;
  EXPECT_TRUE(a.Determinant() == 85.656);
}

/* определитель матрицы можно найти только если матрица квадратная.
 * При попытке получить детерминант неквадратной матрицы
 * получаем предупреждение */
TEST(functions, determinant_5) {
  S21Matrix a(1, 2);
  EXPECT_ANY_THROW(a.Determinant());
}

/* детерминант матрицы размером 2х2 вычисляется по формуле
 * (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]) */
TEST(functions, determinant_6) {
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 1;
  a(1, 1) = 2;
  EXPECT_TRUE(a.Determinant() == 0);
}

TEST(functions, calc_complements_1) {
  S21Matrix a(3, 3);
  S21Matrix correct(3, 3);
  a(0, 0) = 1;
  a(0, 1) = -2;
  a(0, 2) = 3;
  a(1, 0) = 4;
  a(1, 1) = 0;
  a(1, 2) = 6;
  a(2, 0) = -7;
  a(2, 1) = 8;
  a(2, 2) = 9;

  correct(0, 0) = -48;
  correct(0, 1) = -78;
  correct(0, 2) = 32;
  correct(1, 0) = 42;
  correct(1, 1) = 30;
  correct(1, 2) = 6;
  correct(2, 0) = -12;
  correct(2, 1) = 6;
  correct(2, 2) = 8;
  EXPECT_TRUE(correct == a.CalcComplements());
}

TEST(functions, calc_complements_2) {
  S21Matrix a(4, 4);
  S21Matrix correct(4, 4);
  a(0, 0) = 5;
  a(0, 1) = 8;
  a(0, 2) = 0;
  a(0, 3) = -4;
  a(1, 0) = 0;
  a(1, 1) = 1;
  a(1, 2) = 10;
  a(1, 3) = 1;
  a(2, 0) = 0;
  a(2, 1) = 0;
  a(2, 2) = -4;
  a(2, 3) = 0;
  a(3, 0) = 0;
  a(3, 1) = 0;
  a(3, 2) = 0;
  a(3, 3) = 3;

  correct(0, 0) = -12;
  correct(0, 1) = -0;
  correct(0, 2) = 0;
  correct(0, 3) = -0;
  correct(1, 0) = 96;
  correct(1, 1) = -60;
  correct(1, 2) = -0;
  correct(1, 3) = 0;
  correct(2, 0) = 240;
  correct(2, 1) = -150;
  correct(2, 2) = 15;
  correct(2, 3) = -0;
  correct(3, 0) = -48;
  correct(3, 1) = 20;
  correct(3, 2) = -0;
  correct(3, 3) = -20;
  EXPECT_TRUE(correct == a.CalcComplements());
}

/* матрицу алгебраических дополнений можно получить только
 * из квадратной матрицы. При попытке получить матрицу алгебраических дополнений
 * из матрицы размером 4х3 получаем предупреждение */
TEST(functions, calc_complements_3) {
  S21Matrix a(4, 3);
  EXPECT_ANY_THROW(a.CalcComplements());
}

/*  матрицa алгебраических дополнений для матрицы размером 1х1 будет
 * равняться единственному элементу этой матрицы */
TEST(functions, calc_complements_4) {
  S21Matrix a(1, 1);
  S21Matrix correct(1, 1);
  a(0, 0) = -48;
  correct(0, 0) = -48;
  EXPECT_TRUE(correct == a.CalcComplements());
}

TEST(functions, inverse_1) {
  S21Matrix a(3, 3);
  S21Matrix correct(3, 3);
  a(0, 0) = 1;
  a(0, 1) = -2;
  a(0, 2) = 3;
  a(1, 0) = 4;
  a(1, 1) = 0;
  a(1, 2) = 6;
  a(2, 0) = -7;
  a(2, 1) = 8;
  a(2, 2) = 9;

  correct(0, 0) = -0.2352941;
  correct(0, 1) = 0.2058824;
  correct(0, 2) = -0.0588235;
  correct(1, 0) = -0.3823529;
  correct(1, 1) = 0.1470588;
  correct(1, 2) = 0.0294118;
  correct(2, 0) = 0.1568627;
  correct(2, 1) = 0.0294118;
  correct(2, 2) = 0.0392157;
  EXPECT_TRUE(correct == a.InverseMatrix());
}

TEST(functions, inverse_2) {
  S21Matrix a(4, 4);
  S21Matrix correct(4, 4);
  a(0, 0) = 5;
  a(0, 1) = 8;
  a(0, 2) = 0;
  a(0, 3) = -4;
  a(1, 0) = 0;
  a(1, 1) = 1;
  a(1, 2) = 10;
  a(1, 3) = 1;
  a(2, 0) = 0;
  a(2, 1) = 0;
  a(2, 2) = -4;
  a(2, 3) = 0;
  a(3, 0) = 0;
  a(3, 1) = 0;
  a(3, 2) = 0;
  a(3, 3) = 3;

  correct(0, 0) = 0.2;
  correct(0, 1) = -1.6;
  correct(0, 2) = -4;
  correct(0, 3) = 0.8;
  correct(1, 0) = 0;
  correct(1, 1) = 1;
  correct(1, 2) = 2.5;
  correct(1, 3) = -0.3333333;
  correct(2, 0) = 0;
  correct(2, 1) = 0;
  correct(2, 2) = -0.25;
  correct(2, 3) = 0;
  correct(3, 0) = 0;
  correct(3, 1) = 0;
  correct(3, 2) = 0;
  correct(3, 3) = 0.3333333;
  EXPECT_TRUE(correct == a.InverseMatrix());
}

/* обратную матрицу можно получить только
 * из квадратной матрицы. При попытке получить обратную матрицу
 * из матрицы размером 4х3 получаем предупреждение */
TEST(functions, inverse_3) {
  S21Matrix a(4, 3);
  EXPECT_ANY_THROW(a.CalcComplements());
}

/* обратная матрица для матрицы размером 1х1 вычисляется
 * по формуле (1 / а[0][0]) */
TEST(functions, inverse_4) {
  S21Matrix a(1, 1);
  S21Matrix correct(1, 1);
  a(0, 0) = 48;
  correct(0, 0) = 0.0208333;
  EXPECT_TRUE(correct == a.InverseMatrix());
}

/* если определитель матриц равен нулю, найти обратную матрицу невозможно.
 * Создем матрицу А, для которой определитель равен нулю.
 * При попытке получить обратную матрицу получаем предупреждение*/
TEST(functions, inverse_5) {
  S21Matrix a(2, 2);
  S21Matrix correct(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 1;
  a(1, 1) = 2;

  EXPECT_TRUE(a.Determinant() == 0);
  EXPECT_ANY_THROW(a.InverseMatrix());
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}