#include <iostream>
#include <iomanip>
using namespace std;

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);
}

void addMatrices(int matrix1[10][10], int matrix2[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}

void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10],
                      int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nProduct of Matrices:\n";
    displayMatrix(result, rowsA, colsB);
}

int main()
{
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows, cols;

    // PART A - Transpose Matrix
    cout << "PART A - Transpose Matrix\n";
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
    {
        cout << "Invalid matrix size." << endl;
        return 0;
    }

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix1, rows, cols);

    transposeMatrix(matrix1, rows, cols);

    // PART B - Add Two Matrices
    cout << "\nPART B - Add Two Matrices\n";

    cout << "Enter first matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter second matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    addMatrices(matrix1, matrix2, rows, cols);

    // PART C - Multiply Two Matrices
    cout << "\nPART C - Multiply Two Matrices\n";

    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns for Matrix A: ";
    cin >> colsA;
    cout << "Enter rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns for Matrix B: ";
    cin >> colsB;

    if (rowsA <= 0 || rowsA > 10 || colsA <= 0 || colsA > 10 ||
        rowsB <= 0 || rowsB > 10 || colsB <= 0 || colsB > 10)
    {
        cout << "Invalid matrix size." << endl;
        return 0;
    }

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication is not possible." << endl;
        return 0;
    }

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter Matrix B:\n";
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    multiplyMatrices(matrix1, matrix2, result, rowsA, colsA, colsB);

    return 0;
}
