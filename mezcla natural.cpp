#include <iostream>
#include <vector>

// Función para realizar el ordenamiento mezcla natural
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

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

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de números: ";
    std::cin >> n;

    std::vector<int> numeros(n);

    std::cout << "Ingrese los números uno por uno:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    mergeSort(numeros, 0, n - 1);

    std::cout << "Vector ordenado:\n";
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
