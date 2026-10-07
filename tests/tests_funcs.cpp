#include <gtest/gtest.h>
#include "funcs.h"


TEST(FuncsTest, DeleteMatrixCheckDeletion){
    std::size_t rows = 4, cols = 4;

    int** m = matrix_create(rows, cols);

    matrix_delete(m, rows);

    EXPECT_EQ(m, nullptr);
}

TEST(FuncsTest, CreateMatrixCheckNullptr){
    std::size_t rows = 4, cols = 4;

    int** m = matrix_create(rows, cols);

    EXPECT_NE(m, nullptr);

    for (std::size_t i = 0; i < rows; i++){
        EXPECT_NE(m[i], nullptr);
    }

    matrix_delete(m, rows);
}

TEST(FuncsTest, CreateOneMatrixCheckForValue){
    std::size_t rows = 1, cols = 1;

    int** m = matrix_create(rows, cols);

    EXPECT_EQ(m[0][0], 0);
}

TEST(FuncsTest, CreateZeroMatrixCheckNullptr){
    std::size_t rows = 0, cols = 0;

    int** m = matrix_create(rows, cols);

    EXPECT_EQ(m, nullptr);
}

TEST(FuncsTest, MatrixFillWithNumber){
    std::size_t rows = 3, cols = 4;

    int** m = matrix_create(rows, cols);
    matrix_fill(m, rows, cols, 7);

    for (std::size_t i = 0; i < rows; i++){
        for (std::size_t j = 0; j < cols; j++){
            EXPECT_EQ(m[i][j], 7);
        }
    }

    matrix_delete(m, rows);
}

TEST(FuncsTest, MatrixFillNullptr){
    matrix_fill(nullptr, 4, 4, 5);
    SUCCEED();
}

TEST(FuncsTest, PrintNonEmpty){
    int** m = matrix_create(2, 2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;
    testing::internal::CaptureStdout();
    matrix_print(m, 2, 2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("1"), std::string::npos);
    EXPECT_NE(output.find("4"), std::string::npos);
    matrix_delete(m, 2);
}

TEST(FuncsTest, PrintNullptr){
    testing::internal::CaptureStdout();
    matrix_print(nullptr, 0, 0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("empty"), std::string::npos);
}

TEST(FuncsTest, MatrixSpiralReadRegular){
    std::size_t rows = 3, cols = 3;

    int** m = matrix_create(rows, cols);
    int counter = 1;
    for (std::size_t i = 0; i < rows; i++){
        for (std::size_t j = 0; j < cols; j++){
            m[i][j] = counter++;
        }
    }

    std::size_t size = 0;
    int* spiral = matrix_spiral_read(m, rows, cols, size);

    ASSERT_EQ(size, rows * cols);

    int expected[9] = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    for (std::size_t i = 0; i < size; i++){
        EXPECT_EQ(spiral[i], expected[i]);
    }

    delete[] spiral;
    matrix_delete(m, rows);
}

TEST(FuncsTest, MatrixSpiralReadThin){
    std::size_t rows = 1, cols = 5;

    int** m = matrix_create(rows, cols);
    for (std::size_t j = 0; j < cols; j++){
        m[0][j] = static_cast<int>(j + 1);
    }

    std::size_t size = 0;
    int* spiral = matrix_spiral_read(m, rows, cols, size);

    ASSERT_EQ(size, rows * cols);

    const int expected[5] = {1, 2, 3, 4, 5};
    for (std::size_t i = 0; i < size; i++){
        EXPECT_EQ(spiral[i], expected[i]);
    }

    delete[] spiral;
    matrix_delete(m, rows);
}

TEST(FuncsTest, MatrixSpiralReadZero){
    std::size_t rows = 0, cols = 0;

    int** m = matrix_create(rows, cols);

    std::size_t size = 0;
    int* spiral = matrix_spiral_read(m, rows, cols, size);

    EXPECT_EQ(size, 0u);

    delete[] spiral;
    matrix_delete(m, rows);
}
