#include <iostream>
#include <vector>
using namespace std;
 
void bSortBase(vector<int>& arr, int& comparaciones, int& intercambios) { 
    int len = arr.size();
    comparaciones = 0;
    intercambios = 0;
 
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1; j++) {
            comparaciones++;
            if (arr[j] > arr[j + 1]) { //ordenamiento ascendente
                swap(arr[j], arr[j + 1]);
                intercambios++;
            }
        }
    }
}
 
void print(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << " ";
    }
}
 
void test(vector<int> arr) {
    cout << "Arreglo original: ";
    print(arr);
    cout << endl;

    int comparaciones = 0;
    int intercambios = 0;
    bSortBase(arr, comparaciones, intercambios);
 
    cout << "Arreglo ordenado: ";
    print(arr);
    cout << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Intercambios : " << intercambios << endl;
    cout << endl;
}
 
int main() {
    cout << "Caso 1: [5, 3, 8, 2]" << endl;
    test({5, 3, 8, 2});
    cout << "Caso 2: [1, 2, 3, 4, 5]" << endl;
    test({1, 2, 3, 4, 5});
    cout << "Caso 3: [5, 4, 3, 2, 1]" << endl;
    test({5, 4, 3, 2, 1});
 
    return 0;
}
