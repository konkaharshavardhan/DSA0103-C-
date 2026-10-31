
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Original design: shifting array
class OriginalAccount
{
private:
    string transactions[10];
    int count;

public:
    OriginalAccount()
    {
        count = 0;
    }

    void addTransaction(string value)
    {
        if (count < 10)
        {
            transactions[count] = value;
            count++;
        }
        else
        {
            for (int i = 0; i < 9; i++)
            {
                transactions[i] = transactions[i + 1];
            }

            transactions[9] = value;
        }
    }
};

// Redesigned: circular array
class CircularAccount
{
private:
    string transactions[10];
    int nextIndex;
    int count;

public:
    CircularAccount()
    {
        nextIndex = 0;
        count = 0;
    }

    void addTransaction(string value)
    {
        transactions[nextIndex] = value;

        nextIndex = (nextIndex + 1) % 10;

        if (count < 10)
        {
            count++;
        }
    }
};

int main()
{
    OriginalAccount original;
    CircularAccount redesigned;

    const int TOTAL = 100000;

    clock_t start1 = clock();

    for (int i = 0; i < TOTAL; i++)
    {
        original.addTransaction("Transaction");
    }

    clock_t end1 = clock();

    clock_t start2 = clock();

    for (int i = 0; i < TOTAL; i++)
    {
        redesigned.addTransaction("Transaction");
    }

    clock_t end2 = clock();

    double originalTime =
        (double)(end1 - start1) / CLOCKS_PER_SEC * 1000000;

    double redesignedTime =
        (double)(end2 - start2) / CLOCKS_PER_SEC * 1000000;

    cout << "TRANSACTION HISTORY COMPARISON" << endl;

    cout << "Total transactions: " << TOTAL << endl;

    cout << "\nOriginal shifting method: "
         << originalTime << " microseconds" << endl;

    cout << "Redesigned circular method: "
         << redesignedTime << " microseconds" << endl;

    cout << "\nOriginal method complexity: O(10) per insertion "
         << "after the array is full." << endl;

    cout << "Circular method complexity: O(1) per insertion."
         << endl;

    cout << "\nConclusion: Circular array avoids shifting "
         << "and provides constant-time insertion." << endl;

    return 0;
}

