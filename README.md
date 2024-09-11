# Repositorio Análisis Comparativo del Rendimiento de Algoritmos de Ordenamiento y Multiplicación de Matrices: Informe Experimental y Comparación Teórica
Este es el repositorio en el cual se adjuntan los archivos correspondientes al informe de análisis comparativo y asintótico de algortimos de ordenamiento y multiplicación de matrices
Nombre1 : Mauro Castillo
Rol : 202273627-5

InsertionSort está implementado en insertionsort.cpp
MergeSort está implementado en mergesort.cpp
QuickSort está implementado en quicksort.cpp
Sort estándar está implementado en standardsort.cpp

Multiplicación Iterativa está implementada en iterativocubicotrad.cpp
Multiplicación Iterativa Optimizada con transposición de la segunda matriz está implementada en iterativocubico2transpuesta.cpp
Strassen está implementado en strassen.cpp

multiplicacion.cpp es el codigo para ejecutar la prueba experimental de las multiplicaciones y su respectiva compilación y ejecución entrega los resultados utilizados para el informe
ordenamiento.cpp es el codigo para ejecutar la prueba experimental de los ordenamientos y su respectiva compilación y ejecución entrega los resultados utilizados para el informe

el dataset fue generado mediante el código generar_datasets.py
los gráficos de ordenamiento fueron generados mediante el código generar_ordenamientos.py
los gráficos de multiplicacion fueron generados mediante el código generar_multiplicacion.py

para compilar multiplicacion.cpp por ej se usó:
g++ -o multiplicacion multiplicacion.cpp iterativocubicotrad.cpp iterativocubico2transpuesta.cpp strassen.cpp -std=c++11
./multiplicacion

los resultados fueron traspasados a multiplicacion.txt y ordenamiento.txt respectivamente.

