#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());

    int range = max - min + 1;
    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); ++i) {
        count[arr[i] - min]++;
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de números: ";
    std::cin >> n;

    std::vector<int> numbers;

    std::cout << "Ingrese los números uno por uno:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    countingSort(numbers);

    std::cout << "Vector ordenado: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}