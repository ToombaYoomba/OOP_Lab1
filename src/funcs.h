#pragma once
#include <cstddef>

int** matrix_create(std::size_t rows, std::size_t cols);

void matrix_delete(int**& m, std::size_t rows);

void matrix_fill(int** m, std::size_t rows, std::size_t cols, int value);

void matrix_print(const int* const* m, std::size_t rows, std::size_t cols);

int* matrix_spiral_read(const int* const* m, std::size_t rows, std::size_t cols, std::size_t& out_size);

void printArray(const int* ptr, std::size_t size);