#include <iostream>
#include <algorithm>
#include <vector>
#include "matrix.h"

using namespace std;

int Matrix::get_rows() {
    return this->m_rows;
}

int Matrix::get_cols() {
    return this->m_cols;
}

void Matrix::print_matrix() {
    for (auto row : this->m_matrix) {
        cout << "( ";
        for (auto value : row) {
            cout << value << " ";
        }
        cout << ")" << endl;
    }
    cout << endl;
}

void Matrix::set_value_at(unsigned row, unsigned col, double value) {
    int size = this->m_matrix.size();
    try {
        this->m_matrix[row][col] = value;
    } catch (std::exception &exc) {
        std::cerr << "You tried to insert a value in a position that does not exist." << exc.what() << endl;
    }
}

int Matrix::get_value_at(unsigned row, unsigned col) {
    return this->m_matrix[row][col];
}

void Matrix::transpose() {
    Matrix transposed_matrix(this->m_cols, this->m_rows, 0);
    for (int row = 0; row < this->m_rows; row++) {
        for (int col = 0; col < this->m_cols; col++) {
            transposed_matrix.set_value_at(col, row, this->m_matrix[row][col]);
        }
    }
    this->m_matrix = transposed_matrix.m_matrix;
}

Matrix Matrix::add_matrix(Matrix m2) {
    Matrix result_m(this->get_cols(), this->get_rows(), 0); // initialize result matrix
    for (int row = 0; row < this->get_rows(); row++) {
        for (int col = 0; col < this->get_cols(); col++) {
            result_m.m_matrix[row][col] = this->m_matrix[row][col] + m2.m_matrix[row][col];
        }
    }
    return result_m;
}

Matrix Matrix::multiply(Matrix matrix_term) {
    Matrix result_matrix(3, 3, 0);
    int tmp_value = 0;
    for (int row = 0; row < this->get_rows(); row++) {
        for (int col = 0; col < matrix_term.get_cols(); col++) {
            tmp_value = this->m_matrix[row][col] * matrix_term.m_matrix[col][row];
            result_matrix.m_matrix[row][col] = tmp_value;
        }
    }

    return result_matrix;
}
