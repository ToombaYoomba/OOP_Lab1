#include <gtest/gtest.h>
#include "funcs.h"

TEST(FuncsTest, FindMaxFillsValueByRef) {
    int data[] = {3, 9, 4, 1};
    int value = 0;
    EXPECT_TRUE(find_max(data, 4, value));
    EXPECT_EQ(value, 9);
}

TEST(FuncsTest, FindMaxEmptyReturnsFalse) {
    int value = 0;
    EXPECT_FALSE(find_max(nullptr, 0, value));
}

TEST(FuncsTest, CreateMatrixReturnSize){
    int** m = matrix_create(4, 4);
    
}