#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int CountColumnsWithoutZeros(int** a, const int rowCount, const int colCount)
{
    int count = 0;

    for (int j = 0; j < colCount; j++) {
        bool hasZero = false;
        for (int i = 0; i < rowCount; i++) {
            if (a[i][j] == 0)
            {
                hasZero = true;
                break;
            }
        }
        if (!hasZero)
        {
            count++;
        }
    }
    return count;
}

int RowCharacteristic(int* row, const int colCount)
{
    int sum = 0;
    for (int j = 0; j < colCount; j++) {
        if (row[j] > 0 && row[j] % 2 == 0) {
            sum += row[j];
        }
    }
    return sum;
}

void SortRows(int** a, const int rowCount, const int colCount) 
{
    for (int i = 0; i < rowCount - 1; i++) {
        for (int j = 0; j < rowCount - 1 - i; j++) {
            if (RowCharacteristic(a[j], colCount) > RowCharacteristic(a[j + 1], colCount)) 
            {
                
                for (int k = 0; k < colCount; k++) {
                    swap(a[j][k], a[j + 1][k]);
                }
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Low = -41;
    int High = 23;
    int rowCount, colCount;

    cout << "k = ";
    cin >> rowCount;
    cout << "n = ";
    cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int zeroColumns = CountColumnsWithoutZeros(a, rowCount, colCount);
    cout << "Стовпці які не містять нулів: " << zeroColumns << endl;

    SortRows(a, rowCount, colCount);
    cout << "Відсортована матриця:";
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
