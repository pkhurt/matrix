#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Matrix {
    private:
        unsigned int m_rows; // Number of rows in the matrix
        unsigned int m_cols; // Number of columns in the matrix
        int initial_value = 0; // Initial value for all elements in the matrix
    public:
        vector<vector<int>> m_matrix; // 2D vector to store the matrix elements
        
        /// \brief Constructor to create a matrix with specified dimensions and initial value.
        /// \param[in] rows The number of rows in the matrix.
        /// \param[in] cols The number of columns in the matrix.
        /// \param[in] initial_value The initial value for all elements in the matrix.
        Matrix(unsigned rows, unsigned cols, int initial_value) {
            this->m_rows = rows;
            this->m_cols = cols;
            this->initial_value = initial_value;

            m_matrix.resize(rows);
            for (int row = 0; row < rows; row++) {
                m_matrix[row].resize(cols, initial_value);
            }
        }

        /// \brief Constructor to create a matrix from a 2D vector of values.
        /// \param[in] values The 2D vector containing the values for the matrix.
        Matrix(vector<vector<int>> values) {
            this->m_cols = values[0].size();
            this->m_rows = values.size();
            this->m_matrix = values;
        }
    
        /// \brief Get the number of rows in the matrix.
        /// \param[out] rows The number of rows in the matrix.
        int get_rows();

        
        /// \brief Get the number of columns in the matrix.
        /// \param[out] cols The number of columns in the matrix.
        int get_cols();

        /// \brief Print the matrix to the console appropriately.
        void print_matrix();

        /// \brief Set the value at the specified position in the matrix.
        /// \param[in] row The row index.
        /// \param[in] col The column index.
        /// \param[in] value The value to set.
        void set_value_at(unsigned row, unsigned col, double value);

        /// \brief Get the value at the specified position in the matrix.
        /// \param[in] row The row index.
        /// \param[in] col The column index.
        int get_value_at(unsigned row, unsigned col);

        /// \brief Transpose the matrix by swapping rows and columns.
        void transpose();

        double determinant();

        /// \brief Mathmatically add another matrix to this matrix and return the result.
        /// \param[in] m2 The matrix to add.
        /// \param[out] matrix The result of the addition.
        Matrix add_matrix(Matrix m2);

        /// \brief Multiply this matrix with another matrix and return the result.
        /// \param[in] matrix_term The matrix to multiply with.
        /// \param[out] matrix The result of the multiplication.
        Matrix multiply(Matrix matrix_term);

        // Overload operators
        Matrix operator+(Matrix m2);
        Matrix operator*(Matrix m2);
        bool operator== (Matrix m2);
};

class IdentityMatrix : public Matrix {
    public:
        IdentityMatrix(unsigned extent) : Matrix(extent, extent, 0) {
            // fill diagonal with 1
            for (int idx = 0; idx < this->get_rows(); idx++) {
                this->m_matrix[idx][idx] = 1;
            }
        }
};

#endif // MATRIX_H