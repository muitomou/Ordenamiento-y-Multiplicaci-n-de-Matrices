#include <vector>
#include "iterativocubico2transpuesta.h"


// función para transponer una matriz
std::vector<std::vector<int>> transponerMatriz(const std::vector<std::vector<int>>& B) {
    int n = B.size();
    int m = B[0].size();
    std::vector<std::vector<int>> B_T(m, std::vector<int>(n));

    // realizar la transposición de la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            B_T[j][i] = B[i][j];
        }
    }

    return B_T;
}

// función para multiplicar matrices utilizando la transposición para mejorar la localidad de datos
std::vector<std::vector<int>> multiplicarMatricesOptimizado(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = A[0].size();

    // transponer la matriz B
    std::vector<std::vector<int>> B_T = transponerMatriz(B);

    // inicializar la matriz de resultado con ceros
    std::vector<std::vector<int>> C(n, std::vector<int>(m, 0));

    // realizar la multiplicación de matrices usando la matriz transpuesta
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }

    return C;
}
