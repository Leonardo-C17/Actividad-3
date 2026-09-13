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

void bSortI1(vector<int>& arr, int& comparaciones, int& intercambios) { 
    int len = arr.size();
    comparaciones = 0;
    intercambios = 0;
 
    for (int i = 0; i < len - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < len - 1; j++) {
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambios++;
                swapped = true;
            }
        }
        if (!swapped) {
            break; // termina el algoritmo antes de tiempo si no hubo intercambios (el arreglo ya estaba ordenado)
        }
    }
}

void bSortI2(vector<int>& arr, int& comparaciones, int& intercambios) { 
    int len = arr.size();
    comparaciones = 0;
    intercambios = 0;
 
    for (int i = 0; i < len - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < len - i - 1; j++) { //ciclo interno reducido
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambios++;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void sSort(vector<int>& arr, int& comparaciones, int& intercambios) { 
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
 
void testAll(vector<int> arr) {
    cout << "Arreglo original: ";
    print(arr);
    cout << endl;

    int comparaciones = 0;
    int intercambios = 0;

    cout << "BUBBLE SORT BASE" << endl;
    bSortBase(arr, comparaciones, intercambios);
    cout << "Arreglo ordenado: ";
    print(arr);
    cout << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Intercambios : " << intercambios << endl;
    cout << endl;

    cout << "BUBBLE SORT MEJORA 1" << endl;
    bSortI1(arr, comparaciones, intercambios);
    cout << "Arreglo ordenado: ";
    print(arr);
    cout << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Intercambios : " << intercambios << endl;
    cout << endl;

    cout << "BUBBLE SORT MEJORA 2" << endl;
    bSortI2(arr, comparaciones, intercambios);
    cout << "Arreglo ordenado: ";
    print(arr);
    cout << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Intercambios : " << intercambios << endl;
    cout << endl;

    cout << "SELECTION SORT" << endl;
    sSort(arr, comparaciones, intercambios);
    cout << "Arreglo ordenado: ";
    print(arr);
    cout << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Intercambios : " << intercambios << endl;
    cout << endl;
}
 
int main() {
    cout << "Caso 1: [5, 3, 8, 2]" << endl;
    testAll({5, 3, 8, 2});
    cout << "Caso 2: [1, 2, 3, 4, 5]" << endl;
    testAll({1, 2, 3, 4, 5});
    cout << "Caso 3: [5, 4, 3, 2, 1]" << endl;
    testAll({5, 4, 3, 2, 1});
 
    return 0;
}