#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar arr[j] y arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
    
        //verifica si no se hizo ningun intercambio, y deja de iterar.
        
        if (!swapped) {

            break;
        }
    }


}

int main() {
    int n;
    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Ingrese los números separados por espacios: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr);

    cout << "Lista ordenada: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}