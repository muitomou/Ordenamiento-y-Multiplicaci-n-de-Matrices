#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include "iterativocubicotrad.h"
#include "iterativocubico2transpuesta.h"
#include "strassen.h"

using namespace std;

// función para leer una matriz desde un archivo
vector<vector<int>> leerMatrizDesdeArchivo(const string& nombreArchivo, int filas, int columnas) {
    ifstream archivo(nombreArchivo);
    vector<vector<int>> matriz(filas, vector<int>(columnas));
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            archivo >> matriz[i][j];
        }
    }

    archivo.close();
    return matriz;
}

// sobrecarga de la función para medir algoritmos de multiplicación de matrices
void medirYEjecutarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, 
                            const string& nombreAlgoritmo, 
                            const string& archivoA, const string& archivoB,
                            vector<vector<int>> (*algoritmo)(const vector<vector<int>>&, const vector<vector<int>>&)) {
    
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> resultado = algoritmo(A, B);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Algoritmo: " << nombreAlgoritmo << " - Archivos: " << archivoA << " y " << archivoB 
         << " - Tiempo: " << duration.count() << " segundos." << endl;
}

int main() {
    // lista de archivos de matrices y sus correspondientes tamaños
    vector<pair<string, pair<int, int>>> archivos = {
        {"datasets/matriz_aleatoria_8x8.txt", {8, 8}},
        {"datasets/matriz_aleatoria_64x64.txt", {64, 64}},
        {"datasets/matriz_aleatoria_1024x1024.txt", {1024, 1024}},
        {"datasets/matriz_aleatoria_8x16.txt", {8, 16}},
        {"datasets/matriz_aleatoria_64x128.txt", {64, 128}},
        {"datasets/matriz_aleatoria_1024x2048.txt", {1024, 2048}}
    };

    // iterar sobre todos los archivos de matrices
    for (const auto& archivoMatriz : archivos) {
        string archivoA = archivoMatriz.first;
        int filasA = archivoMatriz.second.first;
        int columnasA = archivoMatriz.second.second;

        for (const auto& archivoMatrizB : archivos) {
            string archivoB = archivoMatrizB.first;
            int filasB = archivoMatrizB.second.first;
            int columnasB = archivoMatrizB.second.second;

            if (columnasA == filasB) { // Verificar compatibilidad para multiplicación de matrices
                vector<vector<int>> A = leerMatrizDesdeArchivo(archivoA, filasA, columnasA);
                vector<vector<int>> B = leerMatrizDesdeArchivo(archivoB, filasB, columnasB);

                // ejecutar y medir cada algoritmo
                medirYEjecutarMatrices(A, B, "Iterativo Cúbico Tradicional", archivoA, archivoB, multiplyMatrices);
                medirYEjecutarMatrices(A, B, "Iterativo Cúbico Transpuesta", archivoA, archivoB, multiplicarMatricesOptimizado);
                medirYEjecutarMatrices(A, B, "Strassen", archivoA, archivoB, strassenMultiply);
            }
        }
    }

    return 0;
}
