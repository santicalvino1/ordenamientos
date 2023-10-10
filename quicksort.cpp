#include <iostream>
#include <vector>

// Función para realizar la partición
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Elegir el último elemento como pivot
    int i = low - 1; // Índice del elemento más pequeño

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Función Quicksort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de números: ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Ingrese los números uno por uno:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    std::cout << "Lista ordenada: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
