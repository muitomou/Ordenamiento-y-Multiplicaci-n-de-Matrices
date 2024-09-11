#include <vector>
#include "quicksort.h"

// función auxiliar para dividir el vector en partes
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // seleccionar el último elemento como pivote
    int i = low - 1; // índice del menor elemento

    for (int j = low; j <= high - 1; j++) {
        // si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++; // incrementar el índice del menor elemento
            std::swap(arr[i], arr[j]); // intercambiar
        }
    }
    std::swap(arr[i + 1], arr[high]); // mover el pivote a su lugar
    return i + 1; // retornar el índice del pivote
}

// función para aplicar quicksort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // encontrar el índice de partición
        int pi = partition(arr, low, high);

        // ordenar los subvectores de forma recursiva
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
