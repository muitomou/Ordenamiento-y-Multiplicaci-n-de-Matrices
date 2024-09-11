#include <vector>
#include "mergesort.h"

// función auxiliar para mezclar dos subvectores ordenados
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // tamaño del primer subvector
    int n2 = right - mid;     // tamaño del segundo subvector

    // vectores temporales para guardar las mitades
    std::vector<int> L(n1), R(n2);

    // copiar datos a los vectores temporales L y R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // mezclar los vectores temporales de vuelta al vector original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copiar los elementos restantes de L, si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copiar los elementos restantes de R, si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// función para dividir el vector y aplicar MergeSort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // calcular el punto medio

        // dividir y ordenar las dos mitades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // combinar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}
