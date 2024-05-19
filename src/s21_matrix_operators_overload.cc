#include "s21_matrix_oop.h"

/* = overload, copy assignment */
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  FreeMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  InitMatrix();
  CopyMatrix(other);
  return *this;
}

/* = overload, move assignment */
S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  FreeMatrix();
  matrix_ = other.matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
  return *this;
}

/* == overload */
bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

/* != overload */
bool S21Matrix::operator!=(const S21Matrix &other) { return !EqMatrix(other); }

/* + overload */
S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result_matrix(*this);
  result_matrix.SumMatrix(other);
  return result_matrix;
}

/* - overload */
S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result_matrix(*this);
  result_matrix.SubMatrix(other);
  return result_matrix;
}

/* += overload */
S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

/* -= overload */
S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

/* * overload, multiplication by number */
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result_matrix(*this);
  result_matrix.MulNumber(num);
  return result_matrix;
}

/* * overload, multiplication by other matrix */
S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result_matrix(*this);
  result_matrix.MulMatrix(other);
  return result_matrix;
}

/* *= overload, multiplication by number assignment */
S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

/* *= overload, multiplication by other matrix assignment */
S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

/* indexation by matrix elements (row, column) */
double &S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || row < 0 || col >= cols_ || col < 0) {
    throw std::range_error("Error. Invalid matrix index.");
  }
  return matrix_[row][col];
}