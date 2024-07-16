#include <gtest/gtest.h>
#include "matrix.h"

class MatrixTestFixture : public ::testing::Test {
    public:
        Matrix m1 = Matrix({{3, 3, 0},{3, 3, 0},{3, 3, 0}});
        Matrix m2 = Matrix({{3, 3, 0},{3, 3, 0},{3, 3, 0}});
};

// class MatrixTestDeterminant : public ::testing::Test {
//     public:
//         Matrix m1 = Matrix({{1,2},{3,4}});
// };

TEST(MatrixTest, MatrixConstructor) {
    Matrix m(3, 3, 0);
    EXPECT_EQ(m.get_rows(), 3);
    EXPECT_EQ(m.get_cols(), 3);
}

TEST(MatrixTest, MatrixSetAndGet) {
    Matrix m(3, 3, 0);
    m.set_value_at(0, 0, 1);
    m.set_value_at(0, 1, 2);
    m.set_value_at(0, 2, 3);
    m.set_value_at(1, 0, 4);
    m.set_value_at(1, 1, 5);
    m.set_value_at(1, 2, 6);
    m.set_value_at(2, 0, 7);
    m.set_value_at(2, 1, 8);
    m.set_value_at(2, 2, 9);
    EXPECT_EQ(m.get_value_at(0, 0), 1);
    EXPECT_EQ(m.get_value_at(0, 1), 2);
    EXPECT_EQ(m.get_value_at(0, 2), 3);
    EXPECT_EQ(m.get_value_at(1, 0), 4);
    EXPECT_EQ(m.get_value_at(1, 1), 5);
    EXPECT_EQ(m.get_value_at(1, 2), 6);
    EXPECT_EQ(m.get_value_at(2, 0), 7);
    EXPECT_EQ(m.get_value_at(2, 1), 8);
    EXPECT_EQ(m.get_value_at(2, 2), 9);
}

TEST(MatrixTest, MatrixTranspose) {
    Matrix m(3, 3, 0);
    m.set_value_at(0, 0, 1);
    m.set_value_at(0, 1, 2);
    m.set_value_at(0, 2, 3);
    m.set_value_at(1, 0, 4);
    m.set_value_at(1, 1, 5);
    m.set_value_at(1, 2, 6);
    m.set_value_at(2, 0, 7);
    m.set_value_at(2, 1, 8);
    m.set_value_at(2, 2, 9);
    m.transpose();
    EXPECT_EQ(m.get_value_at(0, 0), 1);
    EXPECT_EQ(m.get_value_at(0, 1), 4);
    EXPECT_EQ(m.get_value_at(0, 2), 7);
    EXPECT_EQ(m.get_value_at(1, 0), 2);
    EXPECT_EQ(m.get_value_at(1, 1), 5);
    EXPECT_EQ(m.get_value_at(1, 2), 8);
    EXPECT_EQ(m.get_value_at(2, 0), 3);
    EXPECT_EQ(m.get_value_at(2, 1), 6);
    EXPECT_EQ(m.get_value_at(2, 2), 9);
}

TEST_F(MatrixTestFixture, MatrixAddition) {
    Matrix m3 = m1 + m2;
    EXPECT_EQ(m3.get_value_at(0, 0), 6);
    EXPECT_EQ(m3.get_value_at(0, 1), 6);
    EXPECT_EQ(m3.get_value_at(0, 2), 0);
    EXPECT_EQ(m3.get_value_at(1, 0), 6);
    EXPECT_EQ(m3.get_value_at(1, 1), 6);
    EXPECT_EQ(m3.get_value_at(1, 2), 0);
    EXPECT_EQ(m3.get_value_at(2, 0), 6);
    EXPECT_EQ(m3.get_value_at(2, 1), 6);
    EXPECT_EQ(m3.get_value_at(2, 2), 0);
}

TEST_F(MatrixTestFixture, MatrixEquals) {
    EXPECT_TRUE(m1 == m2);
    m2.set_value_at(0, 0, 90);
    EXPECT_FALSE(m1 == m2);
}

// TEST_F(MatrixTestDeterminant, MatrixDeterminant) {
//     EXPECT_EQ(m1.determinant(), -2);
// }