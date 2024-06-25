#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
    public:
        unsigned int m_rows; // Number of rows in the matrix
        unsigned int m_cols; // Number of columns in the matrix
        T initial_value = 0; // Initial value for all elements in the matrix

        vector<vector<T>> m_matrix; // 2D vector to store the matrix elements

        /**
         * Constructor to create a matrix with specified dimensions and initial value.
         * @param rows The number of rows in the matrix.
         * @param cols The number of columns in the matrix.
         * @param initial_value The initial value for all elements in the matrix.
         */
        Matrix(unsigned rows, unsigned cols, T initial_value) {
            this->m_rows = rows;
            this->m_cols = cols;
            this->initial_value = initial_value;

            m_matrix.resize(rows);
            for (int row = 0; row < rows; row++) {
                m_matrix[row].resize(cols, initial_value);
            }
        }

        /**
         * Constructor to create a matrix from a 2D vector of values.
         * @param values The 2D vector containing the values for the matrix.
         */
        Matrix(vector<vector<T>> values) {
            this->m_cols = values[0].size();
            this->m_rows = values.size();
            this->m_matrix = values;
        }

        /**
         * Get the number of rows in the matrix.
         * @return The number of rows in the matrix.
         */
        int get_rows() {
            return this->m_rows;
        }

        /**
         * Get the number of columns in the matrix.
         * @return The number of columns in the matrix.
         */
        int get_cols() {
            return this->m_cols;
        }

        /**
         * Print the matrix to the console appropriately.
         */
        void print_matrix() {
            for (auto row : this->m_matrix) {
                cout << "( ";
                for (auto value : row) {
                    cout << value << " ";
                }
                cout << ")" << endl;
            }
            cout << endl;
        }

        /**
         * Set the value at the specified position in the matrix.
         * @param row The row index.
         * @param col The column index.
         * @param value The value to set.
         */
        void set_value_at(unsigned row, unsigned col, double value) {
            int size = this->m_matrix.size();
            try {
                this->m_matrix[row][col] = value;
            } catch (std::exception &exc) {
                std::cerr << "You tried to insert a value in a position that does not exist." << exc.what() << endl;
            }
        }

        /**
         * Transpose the matrix by swapping rows and columns.
         */
        void transpose() {
            for (int row = 0; row < this->m_rows; row++) {
                for (int col = 0; col < this->m_cols; col++) {
                    this->set_value_at(col, row, this->m_matrix[row][col]);
                }
            }
        }

        /**
         * Mathmatically add another matrix to this matrix and return the result.
         * @param m2 The matrix to add.
         * @return The result of the addition.
         */
        Matrix add_matrix(Matrix m2) {
            Matrix result_m(this->get_cols(), this->get_rows(), 0); // initialize result matrix
            for (int row = 0; row < this->get_rows(); row++) {
                for (int col = 0; col < this->get_cols(); col++) {
                    result_m.m_matrix[row][col] = this->m_matrix[row][col] + m2.m_matrix[row][col];
                }
            }
            return result_m;
        }

        /**
         * Multiply this matrix with another matrix and return the result.
         * @param matrix_term The matrix to multiply with.
         * @return The result of the multiplication.
         */
        Matrix multiply(Matrix matrix_term) {
            Matrix<int> result_matrix(3, 3, 0);
            int tmp_value = 0;
            for (int row = 0; row < this->get_rows(); row++) {
                for (int col = 0; col < matrix_term.get_cols(); col++) {
                    tmp_value = this->m_matrix[row][col] * matrix_term.m_matrix[col][row];
                    result_matrix.m_matrix[row][col] = tmp_value;
                }
            }

            return result_matrix;
        }
};

class IdentityMatrix : public Matrix<int> {
    public:
        IdentityMatrix(unsigned extent) : Matrix<int>(extent, extent, 0) {
            // fill diagonal with 1
            for (int idx = 0; idx < this->get_rows(); idx++) {
                this->m_matrix[idx][idx] = 1;
            }
        }
};