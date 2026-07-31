#include <iostream>
using namespace std;

void printTable(int number)
{
    cout << "\nMultiplication Table for " << number << ":\n";

    for (int i = 1; i <= 12; i++)
    {
        cout << number << " x " << i << " = " << number * i << endl;
    }
}

void printTables(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printTable(i);

        if (i != n)
        {
            cout << "---------------------------" << endl;
        }
    }
}

int main()
{
    int number, n;

    cout << "Enter a number: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "Error: Number must be greater than 0." << endl;
        return 0;
    }

    printTable(number);

    cout << "\nEnter a number N: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: Number must be greater than 0." << endl;
        return 0;
    }

    printTables(n);

    return 0;
}
