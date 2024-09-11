#include <vector>
#include "iterativocubicotrad.h"

// función para multiplicar dos matrices utilizando el algoritmo cúbico tradicional
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = A[0].size();
    
    // inicializar la matriz de resultado con ceros
    std::vector<std::vector<int>> C(n, std::vector<int>(m, 0));

    // realizar la multiplicación de matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}
