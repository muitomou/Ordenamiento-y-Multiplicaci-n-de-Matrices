#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "standardsort.h"

using namespace std;

// Función para leer un arreglo desde un archivo
vector<int> leerArregloDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<int> arr;
    int valor;

    while (archivo >> valor) {
        arr.push_back(valor);
    }

    archivo.close();
    return arr;
}

// Sobrecarga de la función para medir algoritmos que solo toman un vector
void medirYEjecutar(void (*sortFunction)(vector<int>&), vector<int> arr, const string& nombreAlgoritmo, const string& nombreArchivo) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Algoritmo: " << nombreAlgoritmo << " - Archivo: " << nombreArchivo << " - Tiempo: " << duration.count() << " segundos." << endl;
}

// Sobrecarga de la función para medir algoritmos como mergeSort y quickSort que requieren parámetros adicionales
void medirYEjecutar(void (*sortFunction)(vector<int>&, int, int), vector<int> arr, const string& nombreAlgoritmo, const string& nombreArchivo) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Algoritmo: " << nombreAlgoritmo << " - Archivo: " << nombreArchivo << " - Tiempo: " << duration.count() << " segundos." << endl;
}

int main() {
    vector<string> archivos = {
        "datasets/arreglo_aleatorio_100.txt",
        "datasets/arreglo_parcial_100.txt",
        "datasets/arreglo_casi_ordenado_100.txt",
        "datasets/arreglo_aleatorio_1000.txt",
        "datasets/arreglo_parcial_1000.txt",
        "datasets/arreglo_casi_ordenado_1000.txt",
        "datasets/arreglo_aleatorio_10000.txt",
        "datasets/arreglo_parcial_10000.txt",
        "datasets/arreglo_casi_ordenado_10000.txt"
    };

    for (const auto& archivo : archivos) {
        vector<int> arr = leerArregloDesdeArchivo(archivo);
        
        // Ejecutar y medir cada algoritmo
        medirYEjecutar(insertionSort, arr, "InsertionSort", archivo);
        medirYEjecutar(mergeSort, arr, "MergeSort", archivo);
        medirYEjecutar(quickSort, arr, "QuickSort", archivo);
        medirYEjecutar(standardSort, arr, "StandardSort", archivo);
    }

    return 0;
}


//g++ -pg -o ordenamiento ordenamiento.cpp insertionsort.cpp mergesort.cpp quicksort.cpp standardsort.cpp
// gprof ordenamiento gmon.out > .txt