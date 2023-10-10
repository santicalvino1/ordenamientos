#include <iostream>
#include <vector>

using namespace std;

// Función para realizar el ordenamiento Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Calcula el espacio inicial (gap)
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realiza el ordenamiento por inserción para cada intervalo (gap)
        for (int i = gap; i < n; i++) {
            int temp = arr[i];

            // Mueve los elementos de arr[0..i-gap] que son mayores que temp
            // a una posición adelante de su posición actual
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Coloca temp en su posición correcta
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Ingrese los números uno por uno:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Llama a la función de ordenamiento Shell Sort
    shellSort(arr);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}