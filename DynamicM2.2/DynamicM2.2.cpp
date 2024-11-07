#include <iostream>
using namespace std;

void removeColumn(int**& array, int rows, int currentCols, int colToRemove) {
    int** newArray = new int* [rows];
    for (int i = 0; i < rows; i++) {
        newArray[i] = new int[currentCols - 1];
        int colIndex = 0;
        for (int j = 0; j < currentCols; j++) {
            if (j == colToRemove) continue;
            newArray[i][colIndex++] = array[i][j];
        }
    }

    for (int i = 0; i < rows; i++) delete[] array[i];
    delete[] array;
    array = newArray;
}

int main() {
    int rows = 3, currentCols = 3;
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[currentCols] {i + 1, i + 2, i + 3};
    }
    int colToRemove = 1;
    removeColumn(array, rows, currentCols, colToRemove);
    currentCols--;

    cout << "после удаления столбца:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < currentCols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) delete[] array[i];
    delete[] array;
    return 0;
}
