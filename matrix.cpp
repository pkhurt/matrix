#include <iostream>
#include <algorithm>
#include <vector>
#include "matrix.h"

using namespace std;

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
