# s21_matrix+

Implementation of the s21_matrix_oop.h library. Study project.

The russian version of the task can be found in the repository.

Implementation of basic operations with matrices: comparison, addition, subtraction, multiplication, multiplication by number, transpose, calculation of determinant, calculation of matrix of algebraic complements, finding inverse of the matrix.

- The program is developed in C++ language of C++17 standard using gcc compiler;
- The program code is located in the src folder;
- The code of the program is written in accordance with Google style;
- Implemented: S21Matrix class, default constructor, parametrized constructor, copy and move constructors, assignment and compare operators overload, destructor, accessors and mutators.
- Full coverage of class methods is provided with unit-tests using the GTest library;
- Makefile with targets clean, check_style, s21_matrix_oop.a, test, gcov_report is provided.

### Class s21Matrix
```cpp
class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        ~S21Matrix();             // Destructor

        // Other methods..
}
```

You can get the desired element using indices as follows A(1,1) = 1, where the first index is the row number, the second is the column number.

The order of a matrix is the number of its rows or columns. \
The main diagonal of a square matrix is the diagonal from the upper left to the lower right corner.

A rectangular matrix (B) is a matrix with the number of rows not equal to the number of columns. \
A square matrix (A) is a matrix with the number of rows equal to the number of columns.

## Matrix operations

Below is a brief description of the S21Matrix class methods.

Constructors and destructors:

| Method | Description |
| ----------- | ----------- |
| `S21Matrix()` | A basic constructor that initialises a matrix of some predefined dimension. |  
| `S21Matrix(int rows, int cols) ` | Parametrized constructor with number of rows and columns. |
| `S21Matrix(const S21Matrix& other)` | Copy constructor. |
| `S21Matrix(S21Matrix&& other)` | Move constructor. |
| `~S21Matrix()` | Destructor. |

Operators overload:

| Operator | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `+`      | Addition of two matrices. | Different matrix dimensions. |
| `-`   | Subtraction of one matrix from another. | Different matrix dimensions. |
| `*`  | Matrix multiplication and matrix multiplication by a number. | The number of columns of the first matrix does not equal the number of rows of the second matrix. |
| `==`  | Checks for matrices equality (`EqMatrix`). | |
| `=`  | Assignment of values from one matrix to another one. | |
| `+=`  | Addition assignment (`SumMatrix`) | different matrix dimensions. |
| `-=`  | Difference assignment (`SubMatrix`) | different matrix dimensions. |
| `*=`  | Multiplication assignment (`MulMatrix`/`MulNumber`). | The number of columns of the first matrix does not equal the number of rows of the second matrix. |
| `(int i, int j)`  | Indexation by matrix elements (row, column). | Index is outside the matrix. |

Class methods:

| Operation | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const S21Matrix& other)` | Checks matrices for equality with each other. |  |
| `void SumMatrix(const S21Matrix& other)` | Adds the second matrix to the current one | different matrix dimensions. |
| `void SubMatrix(const S21Matrix& other)` | Subtracts another matrix from the current one | different matrix dimensions. |
| `void MulNumber(const double num) ` | Multiplies the current matrix by a number. |  |
| `void MulMatrix(const S21Matrix& other)` | Multiplies the current matrix by the second matrix. | The number of columns of the first matrix is not equal to the number of rows of the second matrix. |
| `S21Matrix Transpose()` | Creates a new transposed matrix from the current one and returns it. |  |
| `S21Matrix CalcComplements()` | Calculates the algebraic addition matrix of the current one and returns it. | The matrix is not square. |
| `double Determinant()` | Calculates and returns the determinant of the current matrix. | The matrix is not square. |
| `S21Matrix InverseMatrix()` | Calculates and returns the inverse matrix. | Matrix determinant is 0. |
