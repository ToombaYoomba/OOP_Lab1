#include "funcs.h"
#include <iostream>


int** matrix_create(std::size_t rows, std::size_t cols){
    int** m = new int*[rows];

    for (std::size_t i=0; i < rows; i++){
        m[i] = new int[cols];
    }

    return m;
}

void matrix_delete(int** m, std::size_t rows){
    for (std::size_t i = 0; i < rows; i++){
        delete[] m[i];
    }

    delete[] m;
    m = nullptr;
}

void matrix_fill(int** m, std::size_t rows, std::size_t cols, int value){
    for (std::size_t i=0; i < rows; i++){
        for (std::size_t j=0; j < cols; j++){
            m[i][j] = value;
        }
    }
}

void matrix_print(const int* const* m, std::size_t rows, std::size_t cols){
    std::cout << "[";
    for (std::size_t i=0; i < rows; i++){
        std::cout << "[";
        for (std::size_t j=0; j < cols-1; j++){
            std::cout << m[i][j] << ",";
        }
        std::cout << m[i][cols-1];
        if (i < rows-1) std::cout << "],";
        else std::cout << "]]" ;
    }
    std::cout<< std::endl;
}

int* matrix_spiral_read(const int* const* m, std::size_t rows, std::size_t cols, std::size_t& out_size){
    out_size = rows*cols;
    int* res = new int[out_size];
    std::size_t left=0, right=cols, up=0, down=rows, size = 0;
    int dir = 0;

    while(size < out_size){
        if (dir == 0){ //right
            for (std::size_t j = left; j < right && size < out_size; j++){
                res[size] = m[up][j];
                size++;
            }
            up++;
            dir = 1;
        }
        else if (dir == 1){ //down
            for (std::size_t i = up; i < down && size < out_size; i++){
                res[size] = m[i][right-1];
                size++;
            }
            right--;
            dir = 2;
        }
        else if (dir == 2){ //left
            for (std::size_t j = right; j-- > left && size < out_size; ){
                res[size] = m[down-1][j];
                size++;
            }
            down--;
            dir = 3;
        }
        else if (dir == 3){ //up
            for (std::size_t i = down; i-- > up && size < out_size; ){
                res[size] = m[i][left];
                size++;
            }
            left++;
            dir = 0;
        }
    }

    return res;
}

void printArray(const int *ptr, size_t size) {
    std::cout << "{";
    for (size_t i = 0; i < size-1; ++i) {
        std::cout << *ptr << ",";
        ptr++; 
    }
    std::cout << *ptr << "}\n";
}