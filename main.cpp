#include <iostream>
#include <cstddef>

#include "funcs.h"

#define CLR_RESET   "\033[0m"
#define CLR_BOLD    "\033[1m"
#define CLR_RED     "\033[31m"
#define CLR_GREEN   "\033[32m"
#define CLR_YELLOW  "\033[33m"
#define CLR_MAGENTA "\033[35m"
#define CLR_CYAN    "\033[36m"
#define CLR_GRAY    "\033[90m"


static void prt_menu(){
    std::cout << CLR_CYAN << CLR_BOLD
        << "1. Create matrix\n"
        << "2. FILL matrix\n"
        << "3. Scuttle matrix\n"
        << "4. Print matrix\n"
        << "5. Spinny view of matrix\n"
        << "0. Walk the plank\n" << CLR_RESET;
}

static int** g_m = nullptr;
static std::size_t g_rows = 0;
static std::size_t g_cols = 0;

static void create(){
    if (g_m != nullptr){
        std::cout << CLR_RED << "Matrix was already created. Destroy it first.\n" << CLR_RESET;
        return;
    }

    std::size_t rows = 0, cols = 0;
    std::cout << CLR_YELLOW << "Rows:    " << CLR_RESET;
    std::cin >> rows;
    std::cout << CLR_YELLOW << "Columns: " << CLR_RESET;
    std::cin >> cols;

    g_m    = matrix_create(rows, cols);
    g_rows = rows;
    g_cols = cols;

    std::cout << CLR_GREEN << "Matrix " << rows << "x" << cols << " born" << CLR_RESET << "\n";
}

static void fill(){
    if (g_m == nullptr){
        std::cout << CLR_RED << "Matrix was not born" << CLR_RESET << "\n";
        return;
    }

    int value = 0;
    std::cout << CLR_YELLOW << "Value: " << CLR_RESET;
    std::cin >> value;

    matrix_fill(g_m, g_rows, g_cols, value);
    std::cout << CLR_GREEN << "Matrix filled with value " << value << CLR_RESET << "\n";
}

static void del(){
    if (g_m == nullptr){
        std::cout << CLR_RED << "Matrix was already born" << CLR_RESET << "\n";
        return;
    }

    matrix_delete(g_m, g_rows);
    g_m    = nullptr;
    g_rows = 0;
    g_cols = 0;

    std::cout << CLR_GREEN << "Matrix exterminated" << CLR_RESET << "\n";
}

static void prt(){
    if (g_m == nullptr){
        std::cout << CLR_RED << "Matrix was not born" << CLR_RESET << "\n";
        return;
    }

    std::cout << CLR_MAGENTA << "Matrix: " << CLR_RESET;
    matrix_print(g_m, g_rows, g_cols);
}

static void spiral(){
    if (g_m == nullptr){
        std::cout << CLR_RED << "Matrix was not born" << CLR_RESET << "\n";
        return;
    }

    std::size_t size = 0;
    int* spiral = matrix_spiral_read(g_m, g_rows, g_cols, size);

    std::cout << CLR_MAGENTA << "Spinny view: " << CLR_RESET;
    printArray(spiral, size);

    delete[] spiral;
}

int main(){
    int choice = -1;
    prt_menu();

    while (true){
        std::cout << CLR_GRAY << "MAKE YOUR CHOICE: " << CLR_RESET;
        std::cin >> choice;

        switch (choice){
            case 1: create(); break;
            case 2: fill();   break;
            case 3: del(); break;
            case 4: prt();  break;
            case 5: spiral(); break;
            case 0:
                if (g_m != nullptr) matrix_delete(g_m, g_rows);
                std::cout << "\n" << CLR_MAGENTA << CLR_BOLD << "fair winds t' ye" << CLR_RESET;
                return 0;
            default:
                std::cout << CLR_RED << "Wrong choice" << CLR_GRAY << ", but I'll give you another chance ya " << CLR_RED << "Crum bum" << CLR_RESET << "\n";
        }

        std::cout << "\n";
    }
}