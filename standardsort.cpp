#include <vector>
#include <algorithm> // incluir para usar sort
#include "standardsort.h"


// función para ordenar usando la función sort de la biblioteca estándar
void standardSort(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end()); // ordenar utilizando la función sort
}
