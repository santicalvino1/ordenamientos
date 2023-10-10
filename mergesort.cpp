#include <iostream>
#include <vector>

// Función para fusionar dos subarrays ordenados
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crear subarrays temporales
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copiar datos a los subarrays temporales leftArr[] y rightArr[]
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    // Combinar los subarrays temporales en arr[left..right]
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de leftArr[], si los hay
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de rightArr[], si los hay
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Encuentra el punto medio del array
        int middle = left + (right - left) / 2;

        // Ordena la primera mitad
        mergeSort(arr, left, middle);

        // Ordena la segunda mitad
        mergeSort(arr, middle + 1, right);

        // Fusiona las dos mitades ordenadas
        merge(arr, left, middle, right);
    }
}

int main() {
    int n;
    std::cout << "Ingrese el número de elementos: ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Ingrese los elementos uno por uno:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    std::cout << "El arreglo ordenado es:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}