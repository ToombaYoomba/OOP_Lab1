#include <iostream>

using namespace std;

int main(){
    int** m = matrix_create(4, 4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            m[i][j] = (i+1)*(j+2);
        }
    }
    matrix_print(m, 4, 4);
    std::size_t lengh;
    int* r = matrix_spiral_read(m, 4, 4, lengh);
    printArray(r, lengh);
}