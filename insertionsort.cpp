#include <vector>
#include "insertionsort.h"

// función para ordenar un vector usando insertion sort
void insertionSort(std::vector<int>& arr) {
    // iterar a través de cada elemento del vector
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i]; // elemento actual a ser insertado en la posición correcta
        int j = i - 1;
        
        // mover elementos mayores al 'key' una posición adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // insertar 'key' en la posición correcta
    }
}
