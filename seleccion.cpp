#include <iostream>
#include <vector>

using namespace std;

void ordenamientoSeleccion(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Intercambiar el elemento mínimo con el elemento en la posición actual
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    vector<int> numeros(n);
    cout << "Ingrese " << n << " números separados por espacios: ";
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    ordenamientoSeleccion(numeros);

    cout << "Lista ordenada: ";
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}