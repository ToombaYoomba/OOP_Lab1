#include <iostream>
#include <cstddef>

#include "funcs.h"


static void print_menu(){
    std::cout << "1. Create matrix\n";
    std::cout << "2. FILL matrix\n";
    std::cout << "3. Scuttle matrix\n";
    std::cout << "4. Print matrix\n";
    std::cout << "5. Spinny view of matrix\n";
    std::cout << "0. Walk the plank\n";
}

static int** g_m = nullptr;
static std::size_t g_rows = 0;
static std::size_t g_cols = 0;

static void action_create(){
    if (g_m != nullptr){
        std::cout << "Matrix was already created. Destroy it first.\n";
        return;
    }

    std::size_t rows = 0, cols = 0;
    std::cout << "Rows:    ";
    std::cin >> rows;
    std::cout << "Columns: ";
    std::cin >> cols;

    g_m    = matrix_create(rows, cols);
    g_rows = rows;
    g_cols = cols;

    std::cout << "Matrix " << rows << "x" << cols << " born\n";
}

static void action_fill(){
    if (g_m == nullptr){
        std::cout << "Matrix was not born\n";
        return;
    }

    int value = 0;
    std::cout << "Value: ";
    std::cin >> value;

    matrix_fill(g_m, g_rows, g_cols, value);
    std::cout << "Matrix filled with value " << value << "\n";
}

static void action_delete(){
    if (g_m == nullptr){
        std::cout << "Matrix was already born\n";
        return;
    }

    matrix_delete(g_m, g_rows);
    g_m    = nullptr;
    g_rows = 0;
    g_cols = 0;

    std::cout << "Matrix exterminated\n";
}

static void action_print(){
    if (g_m == nullptr){
        std::cout << "Matrix was not born\n";
        return;
    }

    std::cout << "Matrix: ";
    matrix_print(g_m, g_rows, g_cols);
}

static void action_spiral(){
    if (g_m == nullptr){
        std::cout << "Matrix was not born\n";
        return;
    }

    std::size_t size = 0;
    int* spiral = matrix_spiral_read(g_m, g_rows, g_cols, size);

    std::cout << "Spinny view: ";
    printArray(spiral, size);

    delete[] spiral;
}

int main(){
    int choice = -1;
    print_menu();

    while (true){
        std::cout << "MAKE YOUR CHOICE: ";
        std::cin >> choice;
        std::cout << "\n";

        switch (choice){
            case 1: action_create(); break;
            case 2: action_fill();   break;
            case 3: action_delete(); break;
            case 4: action_print();  break;
            case 5: action_spiral(); break;
            case 0:
                if (g_m != nullptr) matrix_delete(g_m, g_rows);
                return 0;
            default:
                std::cout << "Wrong choice, but I'll give you another chance ya Crum bum\n";
        }

        std::cout << "\n";
    }
}