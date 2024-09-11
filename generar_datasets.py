import numpy as np
import os

# Crear un directorio para guardar los archivos si no existe
os.makedirs('datasets', exist_ok=True)

# Función para generar un arreglo aleatorio
def generar_arreglo_aleatorio(size, filename):
    arr = np.random.randint(0, 10000, size)
    np.savetxt(f'datasets/{filename}', arr, fmt='%d')
    print(f'{filename} generado.')

# Función para generar un arreglo parcialmente ordenado
def generar_arreglo_parcialmente_ordenado(size, filename, porcentaje_ordenado=50):
    arr = np.random.randint(0, 10000, size)
    tamano_ordenado = int(size * (porcentaje_ordenado / 100))
    arr[:tamano_ordenado] = np.sort(arr[:tamano_ordenado])
    np.savetxt(f'datasets/{filename}', arr, fmt='%d')
    print(f'{filename} generado.')

# Función para generar un arreglo casi ordenado
def generar_arreglo_casi_ordenado(size, filename):
    arr = np.arange(size)
    np.random.shuffle(arr[int(size*0.9):])
    np.savetxt(f'datasets/{filename}', arr, fmt='%d')
    print(f'{filename} generado.')

# Función para generar una matriz aleatoria
def generar_matriz_aleatoria(rows, cols, filename):
    matrix = np.random.randint(0, 10000, (rows, cols))
    np.savetxt(f'datasets/{filename}', matrix, fmt='%d')
    print(f'{filename} generado.')

# Función para generar una matriz parcialmente ordenada
def generar_matriz_parcialmente_ordenada(rows, cols, filename, porcentaje_ordenado=50):
    matrix = np.random.randint(0, 10000, (rows, cols))
    filas_ordenadas = int(rows * (porcentaje_ordenado / 100))
    for i in range(filas_ordenadas):
        matrix[i] = np.sort(matrix[i])
    np.savetxt(f'datasets/{filename}', matrix, fmt='%d')
    print(f'{filename} generado.')

# Función para generar una matriz casi ordenada
def generar_matriz_casi_ordenada(rows, cols, filename):
    matrix = np.arange(rows * cols).reshape(rows, cols)
    np.random.shuffle(matrix[int(rows*0.95):, :])
    np.savetxt(f'datasets/{filename}', matrix, fmt='%d')
    print(f'{filename} generado.')

# Generación de los datasets para arreglos
tamanos_arreglo = [100, 1000, 10000]
for tamano in tamanos_arreglo:
    generar_arreglo_aleatorio(tamano, f'arreglo_aleatorio_{tamano}.txt')
    generar_arreglo_parcialmente_ordenado(tamano, f'arreglo_parcial_{tamano}.txt', porcentaje_ordenado=50)
    generar_arreglo_casi_ordenado(tamano, f'arreglo_casi_ordenado_{tamano}.txt')

# Generación de los datasets para matrices cuadradas
tamanos_matriz = [8, 64, 1024]
for tamano in tamanos_matriz:
    generar_matriz_aleatoria(tamano, tamano, f'matriz_aleatoria_{tamano}x{tamano}.txt')
    generar_matriz_parcialmente_ordenada(tamano, tamano, f'matriz_parcial_{tamano}x{tamano}.txt', porcentaje_ordenado=50)
    generar_matriz_casi_ordenada(tamano, tamano, f'matriz_casi_ordenada_{tamano}x{tamano}.txt')

# Generación de los datasets para matrices no cuadradas
dimensiones_no_cuadradas = [(8, 16), (64, 128), (1024, 2048)]
for filas, columnas in dimensiones_no_cuadradas:
    generar_matriz_aleatoria(filas, columnas, f'matriz_aleatoria_{filas}x{columnas}.txt')
    generar_matriz_parcialmente_ordenada(filas, columnas, f'matriz_parcial_{filas}x{columnas}.txt', porcentaje_ordenado=50)
    generar_matriz_casi_ordenada(filas, columnas, f'matriz_casi_ordenada_{filas}x{columnas}.txt')


