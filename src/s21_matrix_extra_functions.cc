#include "s21_matrix_oop.h"

/* checks if the size of a matrix is ok */
bool S21Matrix::CheckSizeOk() {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::out_of_range("Error. Invalid matrix size.");
  } else
    return true;
}

/* checks if matrices are of equal size */
bool S21Matrix::CheckEqSize(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Error. Matrices are of different size.");
  } else
    return true;
}

/* returns minor-matrix for the input matrix for a certain row and column */
S21Matrix S21Matrix::Minor(int delete_row, int delete_col) {
  if (delete_row >= rows_ || delete_col >= cols_ || delete_row < 0 ||
      delete_col < 0) {
    throw std::invalid_argument("Error. Invalid argument.");
  }
  S21Matrix minor(rows_ - 1, cols_ - 1);
  int res_row = 0;
  for (int i = 0; i < rows_; i++) {
    if (i == delete_row) {
      continue;
    }
    int res_col = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == delete_col) {
        continue;
      }
      minor.matrix_[res_row][res_col] = matrix_[i][j];
      res_col++;
    }
    res_row++;
  }
  return minor;
}

void S21Matrix::PrintMatrix() {
  std::cout << "matrix " << this << std::endl;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (j == cols_ - 1) {
        std::cout << matrix_[i][j] << std::endl;
      } else {
        std::cout << matrix_[i][j] << " ";
      }
    }
  }
}

/* fills a matrix with random integer values */
void S21Matrix::FillMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = rand() % 100;
    }
  }
}