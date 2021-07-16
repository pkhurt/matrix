#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
    public:
        unsigned int m_rows;
        unsigned int m_cols;
        T initial_value = 0;

        vector<vector<T>> m_matrix;

        Matrix(unsigned rows, unsigned cols, T initial_value) {
            this->m_rows = rows;
            this->m_cols = cols;
            this->initial_value = initial_value;

            m_matrix.resize(rows);
            for (int row = 0; row < rows; row++) {
                m_matrix[row].resize(cols, initial_value);
            }
        }

        Matrix(vector<vector<T>> values) {
            this->m_cols = values[0].size();
            this->m_rows = values.size();
            this->m_matrix = values;
        }

        int get_rows() {
            return this->m_rows;
        }

        int get_cols() {
            return this->m_cols;
        }

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

        void set_value_at(unsigned row, unsigned col, double value) {
            int size = this->m_matrix.size();
            try {
                this->m_matrix[row][col] = value;
            } catch (std::exception &exc) {
                std::cerr << "You tried to insert a value in a position that does not exist." << exc.what() << endl;
            }
        }

        void transpose() {
            for (int row = 0; row < this->m_rows; row++) {
                for (int col = 0; col < this->m_cols; col++) {
                    this->set_value_at(col, row, this->m_matrix[row][col]);
                }
            }
        }

        Matrix add_matrix(Matrix m2) {
            Matrix result_m(this->get_cols(), this->get_rows(), 0); // initialize result matrix
            for (int row = 0; row < this->get_rows(); row++) {
                for (int col = 0; col < this->get_cols(); col++) {
                    result_m.m_matrix[row][col] = this->m_matrix[row][col] + m2.m_matrix[row][col];
                }
            }
            return result_m;
        }

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

        Matrix square() {
            Matrix<int> tmp_matrix (this->m_rows, this->m_cols, 0);
            tmp_matrix = this->multiply(this);
            return this;
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

int main() {
    // test1 create empty matrix
    Matrix<int> m1(2,2,0);
    cout << m1.get_cols() << " x " << m1.get_rows() << " initialized" << endl;
    //m1.print_matrix();
    m1.set_value_at(1,0,1);
    m1.print_matrix();

    // test2 create matrix with 2x2 values
    //vector<vector<int>> input_vector1,2], [3,4]];
    Matrix<int> m2({{1,2},{3,4}});
    m2.print_matrix();
    m2.transpose();
    m2.print_matrix();

    // test3 create a 3x3 matrix with values
    Matrix<int> m3({{1,2,3}, {4,5,6}, {7,8,9}});
    m3.print_matrix();
    m3.transpose();
    m3.print_matrix();

    // test4 add two matrices
    Matrix<int> result = m1.add_matrix(m2);
    result.print_matrix();

    // test5 create identy matrix
    IdentityMatrix i1 (3);
    i1.print_matrix();

    // test6 create vector
    Matrix<int> vec(3,1,0);
    vec.print_matrix();

    // test7 multiplication
    Matrix<int> multi = m3.multiply(m3);
    multi.print_matrix();

    Matrix<int> squared = m3.square();
}