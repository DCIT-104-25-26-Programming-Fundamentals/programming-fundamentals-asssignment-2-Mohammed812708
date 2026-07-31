#include <iostream>
using namespace std;

void printFibonacci(int n)
{
    if (n <= 0)
    {
        cout << "Error: Number of terms must be greater than 0." << endl;
        return;
    }

    int first = 0, second = 1, next;

    cout << "Fibonacci sequence: ";

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            cout << first << " ";
        else if (i == 2)
            cout << second << " ";
        else
        {
            next = first + second;
            cout << next << " ";

            first = second;
            second = next;
        }
    }

    cout << endl;
}

void checkFibonacci(int num)
{
    if (num < 0)
    {
        cout << num << " is NOT a Fibonacci number." << endl;
        return;
    }

    int first = 0;
    int second = 1;
    int next = 0;

    while (next < num)
    {
        next = first + second;
        first = second;
        second = next;
    }

    if (num == 0 || num == 1 || next == num)
        cout << num << " is a Fibonacci number." << endl;
    else
        cout << num << " is NOT a Fibonacci number." << endl;
}

int main()
{
    int n, number;

    cout << "How many terms? ";
    cin >> n;

    printFibonacci(n);

    cout << "\nEnter a number to check: ";
    cin >> number;

    checkFibonacci(number);

    return 0;
}
