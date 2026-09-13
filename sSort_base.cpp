#include <iostream>
#include <vector>
using namespace std;
 
void bSortI2(vector<int>& arr, int& comparaciones, int& intercambios) { 
    int len = arr.size();
    comparaciones = 0;
    intercambios = 0;
 
    for (int i = 0; i < len - 1; i++) {
        int minindex = i;
 
        for (int j = i + 1; j < len; j++) {
            comparaciones++;
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        /* Se hace el swap siempre que el minimo encontrado no sea la
        misma posicion i */
        if (minindex != i) {
            swap(arr[i], arr[minindex]);
            intercambios++;
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
    bSortI2(arr, comparaciones, intercambios);
 
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
