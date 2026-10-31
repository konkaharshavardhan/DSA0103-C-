#include <iostream>
using namespace std;

// Returns a reference to the highest mark
int& highestMark(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

// Returns a copy of the highest mark
int highestMarkCopy(int marks[], int size)
{
    int max = marks[0];

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > max)
        {
            max = marks[i];
        }
    }

    return max;
}

// Returns a const reference
const int& highestMarkConst(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

int main()
{
    int marks[5] = {75, 88, 92, 80, 85};

    cout << "Original marks: ";

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    highestMark(marks, 5) += 2;

    cout << "After moderation: ";

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    cout << "Highest mark: "
         << highestMarkCopy(marks, 5) << endl;

    cout << "Highest mark using const reference: "
         << highestMarkConst(marks, 5) << endl;

    return 0;
}

/*
Dangerous example:

int& dangerousFunction()
{
    int x = 100;
    return x;
}

This returns a reference to a local variable.
The variable is destroyed when the function ends.
Using the returned reference causes undefined behaviour.
*/
