#include <vector>
#include "strassen.h"

// función auxiliar para sumar dos matrices
std::vector<std::vector<int>> sumarMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// función auxiliar para restar dos matrices
std::vector<std::vector<int>> restarMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

// funcion principal para multiplicar matrices utilizando el algoritmo de Strassen
std::vector<std::vector<int>> strassenMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();

    // Caso base: matrices 1x1
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;

    // crear submatrices para A y B
    std::vector<std::vector<int>> A11(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> A12(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> A21(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> A22(newSize, std::vector<int>(newSize));

    std::vector<std::vector<int>> B11(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> B12(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> B21(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> B22(newSize, std::vector<int>(newSize));

    // dividir las matrices A y B en submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // calcular los productos de Strassen
    auto M1 = strassenMultiply(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    auto M2 = strassenMultiply(sumarMatrices(A21, A22), B11);
    auto M3 = strassenMultiply(A11, restarMatrices(B12, B22));
    auto M4 = strassenMultiply(A22, restarMatrices(B21, B11));
    auto M5 = strassenMultiply(sumarMatrices(A11, A12), B22);
    auto M6 = strassenMultiply(restarMatrices(A21, A11), sumarMatrices(B11, B12));
    auto M7 = strassenMultiply(restarMatrices(A12, A22), sumarMatrices(B21, B22));

    // calcular las submatrices de la matriz resultante
    auto C11 = sumarMatrices(restarMatrices(sumarMatrices(M1, M4), M5), M7);
    auto C12 = sumarMatrices(M3, M5);
    auto C21 = sumarMatrices(M2, M4);
    auto C22 = sumarMatrices(restarMatrices(sumarMatrices(M1, M3), M2), M6);

    // combinar las submatrices en la matriz resultado
    std::vector<std::vector<int>> C(n, std::vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}
