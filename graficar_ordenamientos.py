import matplotlib.pyplot as plt

# datos de ejemplo
tamaños = [100, 1000, 10000]
tipos_datos = ['aleatorio', 'parcial', 'casi_ordenado']

# datos para cada algoritmo y tipo de arreglo
tiempos = {
    'InsertionSort': {
        'aleatorio': [5.8171e-05, 0.00611605, 0.600536],
        'parcial': [4.9995e-05, 0.00455664, 0.44768],
        'casi_ordenado': [3.496e-06, 4.7029e-05, 0.00182648]
    },
    'MergeSort': {
        'aleatorio': [0.000120199, 0.00139112, 0.0156859],
        'parcial': [0.000118315, 0.00136076, 0.015223],
        'casi_ordenado': [0.000128114, 0.0013319, 0.014947]
    },
    'QuickSort': {
        'aleatorio': [5.1297e-05, 0.000439577, 0.00641421],
        'parcial': [3.9536e-05, 0.000439898, 0.0068229],
        'casi_ordenado': [0.000276677, 0.0263313, 2.68483]
    },
    'StandardSort': {
        'aleatorio': [5.2671e-05, 0.000651592, 0.00868938],
        'parcial': [4.731e-05, 0.000689893, 0.00872624],
        'casi_ordenado': [3.9595e-05, 0.00048846, 0.0075526]
    }
}

# definir colores para cada algoritmo
colores = {
    'InsertionSort': 'blue',
    'MergeSort': 'green',
    'QuickSort': 'red',
    'StandardSort': 'orange'
}

# crear gráficos separados para cada tipo de arreglo
for tipo_dato in tipos_datos:
    plt.figure(figsize=(12, 8))
    
    # graficar los tiempos de ejecución para cada algoritmo
    for algoritmo, color in colores.items():
        plt.plot(
            tamaños,
            tiempos[algoritmo][tipo_dato],
            label=f'{algoritmo}',
            color=color,
            marker='o'
        )
    
    # configurar etiquetas y título para el gráfico actual
    plt.xlabel('Tamaño del arreglo')
    plt.ylabel('Tiempo (segundos)')
    plt.xscale('log')
    plt.yscale('log')
    plt.title(f'Tiempos de Ejecución de Algoritmos de Ordenamiento - {tipo_dato.capitalize()}')
    plt.legend()
    plt.grid(True, which='both', linestyle='--', linewidth=0.5)
    
    # guardar el gráfico en un archivo
    plt.savefig(f'tiempos_ejecucion_{tipo_dato}.png', dpi=300)
    
    # mostrar el gráfico
    plt.show()
