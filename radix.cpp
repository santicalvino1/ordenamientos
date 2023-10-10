#include <iostream>
#include <vector>

// Función para obtener el dígito en una posición específica
int getDigit(int num, int pos) {
    while (pos > 0) {
        num /= 10; // Suponiendo números enteros
        pos--;
    }
    return num % 10;
}

// Implementación del algoritmo Radix Sort LSD
void radixSort(std::vector<int>& arr) {
    int maxDigits = 0;
    for (int num : arr) {
        int digits = 0;
        while (num > 0) {
            num /= 10;
            digits++;
        }
        if (digits > maxDigits) {
            maxDigits = digits;
        }
    }

    for (int digitPlace = 0; digitPlace < maxDigits; digitPlace++) {
        std::vector<std::vector<int>> buckets(10);

        // Coloca los elementos en los contenedores según el dígito actual
        for (int num : arr) {
            int digit = getDigit(num, digitPlace);
            buckets[digit].push_back(num);
        }

        // Reorganiza los elementos en el orden de los contenedores
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int num : buckets[i]) {
                arr[index++] = num;
            }
        }
    }
}

int main() {
    std::vector<int> arr;
    int n;

    std::cout << "Ingrese la cantidad de números: ";
    std::cin >> n;

    std::cout << "Ingrese los números uno por uno:" << std::endl;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        arr.push_back(num);
    }

    // Aplicar Radix Sort para ordenar el vector
    radixSort(arr);

    std::cout << "Array ordenado: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
