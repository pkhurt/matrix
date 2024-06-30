#include <gtest/gtest.h>
#include "matrix.h"

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