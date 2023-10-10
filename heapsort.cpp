#include <iostream>
#include <vector>

// Función para ajustar un montículo máximo
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Función principal de Heapsort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Construir un montículo máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraer elementos uno por uno del montículo
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de números: ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Ingrese los números uno por uno:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    heapSort(arr);

    std::cout << "Números ordenados: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}