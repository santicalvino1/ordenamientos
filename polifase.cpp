#include <iostream>
#include <vector>

using namespace std;

// Función para imprimir los elementos de un vector
void imprimirVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Función para ordenar un vector utilizando el método de ordenación polifase
void ordenarPolifase(vector<int>& vec) {
    int n = vec.size();
    int fase = 1;

    while (fase < n) {
        int i = 0;
        int j = fase;
        int k = 0;

        while (j < n) {
            while (i < fase && j < n) {
                if (vec[i] <= vec[j]) {
                    vec[k] = vec[i];
                    i++;
                }
                else {
                    vec[k] = vec[j];
                    j++;
                }
                k++;
            }

            while (i < fase) {
                vec[k] = vec[i];
                i++;
                k++;
            }

            while (j < n && j < i + fase) {
                vec[k] = vec[j];
                j++;
                k++;
            }

            i += fase;
        }

        fase *= 2;
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    vector<int> numeros(n);

    cout << "Ingrese los números:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    cout << "Vector ingresado:" << endl;
    imprimirVector(numeros);

    ordenarPolifase(numeros);

    cout << "Vector ordenado con el método de ordenación polifase:" << endl;
    imprimirVector(numeros);

    return 0;
}