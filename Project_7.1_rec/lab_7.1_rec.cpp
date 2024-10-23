#include <iostream>
#include <iomanip>
#include <ctime> 
using namespace std;

void Create(int** T, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** T, const int rowCount, const int colCount, int i = 0, int j = 0);
void SortRows(int** T, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void SwapRows(int** T, const int row1, const int row2, const int colCount, int j = 0);
void CalcSumAndCount(int** T, const int rowCount, const int colCount, int& sum, int& count, int i = 0, int j = 0);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = -17;
    const int High = 14;
    const int rowCount = 8;
    const int colCount = 5;

    int** T = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        T[i] = new int[colCount];

    Create(T, rowCount, colCount, Low, High);
    cout << "Original matrix:" << endl;
    Print(T, rowCount, colCount);

    SortRows(T, rowCount, colCount);
    cout << "Sorted matrix:" << endl;
    Print(T, rowCount, colCount);

    int sum = 0;
    int count = 0;
    CalcSumAndCount(T, rowCount, colCount, sum, count);

    cout << "Sum = " << sum << endl;
    cout << "Count of elements = " << count << endl;
    cout << "Modified matrix:" << endl;
    Print(T, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] T[i];
    delete[] T;

    return 0;
}

void Create(int** T, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i >= rowCount)
        return;
    if (j < colCount) {
        T[i][j] = Low + rand() % (High - Low + 1);
        Create(T, rowCount, colCount, Low, High, i, j + 1);
    }
    else {
        Create(T, rowCount, colCount, Low, High, i + 1, 0);
    }
}

void Print(int** T, const int rowCount, const int colCount, int i, int j)
{
    if (i >= rowCount)
        return;
    if (j < colCount) {
        cout << setw(5) << T[i][j];
        Print(T, rowCount, colCount, i, j + 1);
    }
    else {
        cout << endl;
        Print(T, rowCount, colCount, i + 1, 0);
    }
}

void SortRows(int** T, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 >= rowCount - 1)
        return;
    if (i1 < rowCount - i0 - 1) {
        bool shouldSwap = false;
        if (T[i1][0] > T[i1 + 1][0]) {
            shouldSwap = true;
        }
        else if (T[i1][0] == T[i1 + 1][0]) {
            if (T[i1][1] > T[i1 + 1][1]) {
                shouldSwap = true;
            }
            else if (T[i1][1] == T[i1 + 1][1]) {
                if (T[i1][2] > T[i1 + 1][2]) {
                    shouldSwap = true;
                }
            }
        }
        if (shouldSwap)
            SwapRows(T, i1, i1 + 1, colCount);
        SortRows(T, rowCount, colCount, i0, i1 + 1);
    }
    else {
        SortRows(T, rowCount, colCount, i0 + 1, 0);
    }
}

void SwapRows(int** T, const int row1, const int row2, const int colCount, int j)
{
    if (j >= colCount)
        return;
    int temp = T[row1][j];
    T[row1][j] = T[row2][j];
    T[row2][j] = temp;
    SwapRows(T, row1, row2, colCount, j + 1);
}

void CalcSumAndCount(int** T, const int rowCount, const int colCount, int& sum, int& count, int i, int j)
{
    if (i >= rowCount)
        return;
    if (j < colCount) {
        if (T[i][j] < 0 && !(T[i][j] % 4 == 0)) {
            sum += T[i][j];
            count++;
            T[i][j] = 0;
        }
        CalcSumAndCount(T, rowCount, colCount, sum, count, i, j + 1);
    }
    else {
        CalcSumAndCount(T, rowCount, colCount, sum, count, i + 1, 0);
    }
}