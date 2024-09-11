import matplotlib.pyplot as plt

# datos de ejemplo actualizados para matrices cuadradas
tamaños_cuadradas = [8, 64, 1024]

# tiempos para matrices cuadradas (en segundos)
tiempos_cuadradas = {
    'Iterativo Cúbico Tradicional': [1.3765e-05, 0.00403872, 15.1515],
    'Iterativo Cúbico Transpuesta': [1.2063e-05, 0.0035036, 14.3649],
    'Strassen': [0.000982717, 0.321565, 843.541]
}

# datos actualizados para matrices no cuadradas
tamaños_no_cuadradas = [(8, 16), (64, 128), (1024, 2048)]

# tiempos para matrices no cuadradas (en segundos)
tiempos_no_cuadradas = {
    'Iterativo Cúbico Tradicional': [2.0278e-05, 0.00925821, 47.2131],
    'Iterativo Cúbico Transpuesta': [2.112e-05, 0.00693982, 38.1348],
    'Strassen': [0.000996051, 0.338729, 1141.46]
}

# definir colores para cada algoritmo
colores = {
    'Iterativo Cúbico Tradicional': 'blue',
    'Iterativo Cúbico Transpuesta': 'green',
    'Strassen': 'red'
}

# graficar tiempos para matrices cuadradas
plt.figure(figsize=(12, 8))

# graficar los tiempos de ejecución para cada algoritmo en matrices cuadradas
for algoritmo, color in colores.items():
    plt.plot(
        tamaños_cuadradas,
        tiempos_cuadradas[algoritmo],
        label=f'{algoritmo}',
        color=color,
        marker='o'
    )

# configurar etiquetas y título para el gráfico de matrices cuadradas
plt.xlabel('Tamaño de la matriz (n x n)')
plt.ylabel('Tiempo (segundos)')
plt.xscale('log')
plt.yscale('log')
plt.title('Tiempos de Ejecución para Multiplicación de Matrices Cuadradas')
plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)

# guardar el gráfico en un archivo
plt.savefig('tiempos_ejecucion_cuadradas.png', dpi=300)

# mostrar el gráfico
plt.show()

# graficar tiempos para matrices no cuadradas
plt.figure(figsize=(12, 8))

# graficar los tiempos de ejecución para cada algoritmo en matrices no cuadradas
for algoritmo, color in colores.items():
    plt.plot(
        [t[0] for t in tamaños_no_cuadradas],  # Usar solo la primera dimensión como tamaño de la matriz
        tiempos_no_cuadradas[algoritmo],
        label=f'{algoritmo}',
        color=color,
        marker='o'
    )

# configurar etiquetas y título para el gráfico de matrices no cuadradas
plt.xlabel('Tamaño de la matriz (n x m) - Usando n')
plt.ylabel('Tiempo (segundos)')
plt.xscale('log')
plt.yscale('log')
plt.title('Tiempos de Ejecución para Multiplicación de Matrices No Cuadradas')
plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)

# guardar el gráfico en un archivo
plt.savefig('tiempos_ejecucion_no_cuadradas.png', dpi=300)

# mostrar el gráfico
plt.show()
