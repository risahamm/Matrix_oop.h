#include "s21_matrix_oop.h"

/* checks matrices for equality with each other */
bool S21Matrix::EqMatrix(const S21Matrix &other) {
  if (!CheckEqSize(other)) {
    return false;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
        return false;
      }
    }
  }
  return true;
}

/* adds the second matrix to the current one */
void S21Matrix::SumMatrix(const S21Matrix &other) {
  CheckEqSize(other);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

/* subtracts another matrix from the current one */
void S21Matrix::SubMatrix(const S21Matrix &other) {
  CheckEqSize(other);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

/* multiplies the current matrix by a number */
void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

/* multiplies the current matrix by the second matrix */
void S21Matrix::MulMatrix(const S21Matrix &other) {
  /* The number of columns of the first matrix
  must be equal to the number of rows of the second matrix. */
  if (cols_ != other.rows_) {
    throw std::range_error("Error. Incompatible matrices size.");
  }
  S21Matrix temp(rows_, other.cols_);
  for (int k = 0; k < other.cols_; k++) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.rows_; j++) {
        temp.matrix_[i][k] += matrix_[i][j] * other.matrix_[j][k];
      }
    }
  }
  *this = std::move(temp);
}

/* creates a new transposed matrix from the current one and returns it */
S21Matrix S21Matrix::Transpose() {
  S21Matrix temp(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      temp.matrix_[i][j] = matrix_[j][i];
    }
  }
  return *this = std::move(temp);
}

/* calculates and returns the determinant of the current matrix */
double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::logic_error("Error. The matrix has to be square.");
  }
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = (matrix_[0][0] * matrix_[1][1]) - (matrix_[1][0] * matrix_[0][1]);
  } else {
    for (int i = 0; i < cols_; i++) {
      S21Matrix minor = Minor(0, i);
      double temp = minor.Determinant();
      result += matrix_[0][i] * temp * pow(-1, i);
    }
  }
  return result;
}

/* calculates the algebraic addition matrix of the current one and returns it */
S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::logic_error("Error. The matrix has to be square.");
  }
  S21Matrix result_matrix(rows_, cols_);
  if (rows_ == 1) {
    result_matrix = *this;
  }
  if (rows_ > 1) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix minor = Minor(i, j);
        double determinant = minor.Determinant();
        result_matrix.matrix_[i][j] = determinant * pow(-1, (i + j));
      }
    }
  }
  return result_matrix;
}

/* calculates and returns the inverse matrix */
S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::logic_error("Error. The matrix has to be square.");
  }
  S21Matrix result_matrix(rows_, cols_);
  double determinant = 0;
  if (rows_ == 1) {
    result_matrix.matrix_[0][0] = 1 / matrix_[0][0];
  }
  if (rows_ > 1) {
    determinant = Determinant();
    S21Matrix complements = CalcComplements();
    if (determinant != 0) {
      S21Matrix transposed = complements.Transpose();
      transposed *= (1 / determinant);
      result_matrix = transposed;
    } else {
      throw std::logic_error(
          "Error. Determinant equals zero. "
          "Impossible to calculate.");
    }
  }
  return result_matrix;
}