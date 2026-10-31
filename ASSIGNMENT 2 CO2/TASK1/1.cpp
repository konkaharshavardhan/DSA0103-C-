#include <iostream>
using namespace std;

// Call by value
void applyByValue(long long fee, int percent)
{
    fee -= fee * percent / 100;
}

// Call by reference
void applyByReference(long long &fee, int percent)
{
    fee -= fee * percent / 100;
}

// Call by pointer
void applyByPointer(long long *fee, int percent)
{
    *fee -= (*fee) * percent / 100;
}

// Complete the assignment's change function
void change(int a, int &b, int *c)
{
    a += 10;
    b += 10;
    *c += 10;
}

int main()
{
    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;

    applyByValue(fee1, 10);
    applyByReference(fee2, 10);
    applyByPointer(&fee3, 10);

    cout << "After call by value: " << fee1 << endl;
    cout << "After call by reference: " << fee2 << endl;
    cout << "After call by pointer: " << fee3 << endl;

    int a = 1, b = 2, c = 3;

    change(a, b, &c);

    cout << "\nPredict the output program:" << endl;
    cout << a << " " << b << " " << c << endl;

    // bigger() returns a reference
    int &bigger = (a > c) ? a : c;
    bigger = 100;

    cout << a << " " << c << endl;

    // Default arguments
    cout << 1 + 5 + 10 << " ";
    cout << 1 + 2 + 10 << " ";
    cout << 1 + 2 + 3 << endl;

    return 0;
}
