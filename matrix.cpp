#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Matrix {
    private:
        unsigned int m_rows;
        unsigned int m_cols;
        double initial_value = 0;

        vector<vector<double>> m_matrix;
    
    public:
        Matrix(unsigned rows, unsigned cols, double initial_value) {
            this->m_rows = rows;
            this->m_cols = cols;
            this->initial_value = initial_value;

            m_matrix.resize(rows);
            for (int row = 0; row < rows; row++) {
                m_matrix[row].resize(cols, initial_value);
            }
        }

        Matrix(vector<vector<double>> values) {
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
            if (row >= size || col >= size) {
                // throw error
            }
            else {
                this->m_matrix[row][col] = value;
            }
        }

        void transpose() {
            vector<vector<double>> tmp_matrix = m_matrix;
            for (int row = 0; row < this->m_rows; row++) {
                for (int col = 0; col < this->m_cols; col++) {
                    this->set_value_at(col, row, tmp_matrix[row][col]);
                }
            }
        }

        /*Matrix multiply(Matrix matrix_term) {
            Matrix result_matrix(matrix_term[0].size(), matrix_term.size(), 0);
            for (auto row : this->m_matrix)

            return result_matrix;
        }*/

};

int main() {
    // test1 create empty matrix
    Matrix m1(2,2,0);
    cout << m1.get_cols() << " x " << m1.get_rows() << " initialized" << endl;
    //m1.print_matrix();
    m1.set_value_at(1,0,1);
    m1.print_matrix();

    // test2 create matrix with 2x2 values
    //vector<vector<int>> input_vector1,2], [3,4]];
    Matrix m2({{1,2},{3,4}});
    m2.print_matrix();
    m2.transpose();
    m2.print_matrix();

    // test3 create a 3x3 matrix with values
    Matrix m3({{1,2,3}, {4,5,6}, {7,8,9}});
    m3.print_matrix();
    m3.transpose();
    m3.print_matrix();
}