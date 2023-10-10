#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<int>& arr) {
    int n = arr.size();

    // Encontrar el valor máximo y mínimo en el arreglo.
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());

    // Determinar el número de cubetas y el tamaño de cada cubeta.
    int num_buckets = max_val - min_val + 1;

    // Crear un vector de cubetas.
    vector<vector<int>> buckets(num_buckets);

    // Colocar elementos en las cubetas correspondientes.
    for (int i = 0; i < n; ++i) {
        int bucket_index = arr[i] - min_val;
        buckets[bucket_index].push_back(arr[i]);
    }

    // Ordenar cada cubeta usando un algoritmo de ordenamiento (por ejemplo, inserción).
    for (int i = 0; i < num_buckets; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenar las cubetas ordenadas para obtener el arreglo ordenado.
    int index = 0;
    for (int i = 0; i < num_buckets; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de números a ordenar: ";
    cin >> n;

    vector<int> arr;
    cout << "Ingrese los números (valores entre 1 y 10): ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    bucketSort(arr);

    cout << "Arreglo ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}