#include "s21_matrix_oop.h"

/* default constructor, creates 2x2 matrix by default */
S21Matrix::S21Matrix() : rows_(2), cols_(2) { InitMatrix(); }

/* parametrized constructor */
S21Matrix::S21Matrix(int row_val, int col_val)
    : rows_(row_val), cols_(col_val) {
  CheckSizeOk();
  InitMatrix();
}

/* copy constructor */
S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  InitMatrix();
  CopyMatrix(other);
}

/* move constructor */
S21Matrix::S21Matrix(S21Matrix &&other) {
  matrix_ = other.matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

/* destructor */
S21Matrix::~S21Matrix() { FreeMatrix(); }

/* allocates memory, initializes elements with zeros */
void S21Matrix::InitMatrix() {
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

/* frees memory */
void S21Matrix::FreeMatrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

/* copies other matrix */
void S21Matrix::CopyMatrix(const S21Matrix &other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

/* accessors and mutators */
int S21Matrix::get_row() { return rows_; }

int S21Matrix::get_col() { return cols_; }

void S21Matrix::set_row(int new_row_value) {
  if (new_row_value <= 0) {
    throw std::invalid_argument("Error. Invalid size value.");
  }
  S21Matrix temp(new_row_value, cols_);
  int new_row = new_row_value < rows_ ? temp.rows_ : rows_;
  for (int i = 0; i < new_row; i++) {
    for (int j = 0; j < temp.cols_; j++) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(temp);
}

void S21Matrix::set_col(int new_col_value) {
  if (new_col_value <= 0) {
    throw std::invalid_argument("Error. Invalid size value.");
  }
  S21Matrix temp(rows_, new_col_value);
  int new_col = new_col_value < cols_ ? temp.cols_ : cols_;
  for (int i = 0; i < temp.rows_; i++) {
    for (int j = 0; j < new_col; j++) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(temp);
}