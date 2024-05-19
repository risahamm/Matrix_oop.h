#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  /* constructors */
  S21Matrix();  // default constructor, creates 2x2 matrix by default
  S21Matrix(int row_val, int col_val);  // parametrized constructor
  S21Matrix(const S21Matrix &other);    // copy constructor
  S21Matrix(S21Matrix &&other);         // move constructor
  ~S21Matrix();                         // destructor

  /* operators overload */
  S21Matrix &operator=(const S21Matrix &other);  // copy assignment operator
  S21Matrix &operator=(S21Matrix &&other);       // move assignment operator
  bool operator==(const S21Matrix &other);       // == overload
  bool operator!=(const S21Matrix &other);       // != overload
  S21Matrix operator+(const S21Matrix &other);   // + overload
  S21Matrix operator-(const S21Matrix &other);   // - overload
  S21Matrix operator+=(const S21Matrix &other);  // += overload
  S21Matrix operator-=(const S21Matrix &other);  // -= overload
  S21Matrix operator*(const double num);         // multiplication by number
  S21Matrix operator*(const S21Matrix &other);   // mult by other matrix
  S21Matrix operator*=(const double num);        // mult by number assignment
  S21Matrix operator*=(const S21Matrix &other);  // mult by other matrix assign
  double &operator()(int row, int col);  // matrix indexation (row, column)

  /* helper functions */
  void PrintMatrix();
  void FillMatrix();  // fills a matrix with random integer values

  /* accessors and mutators */
  int get_row();
  int get_col();
  void set_row(int new_row_value);
  void set_col(int new_col_value);

  /* class methods */
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

 private:
  // attributes
  int rows_, cols_;  // rows and columns
  double **matrix_;  // pointer to the memory where the matrix is allocated

  /* additional functions */
  void InitMatrix();                        // memory allocation
  void CopyMatrix(const S21Matrix &other);  // copies other matrix
  void FreeMatrix();                        // memory free
  bool CheckSizeOk();  // checks if the size of a matrix is ok
  bool CheckEqSize(const S21Matrix &other);  // checks if matrices are of equal
                                             // size
  S21Matrix Minor(int delete_row,
                  int delete_col);  // returns minor for a matrix
};

#endif  // S21_MATRIX_OOP_H