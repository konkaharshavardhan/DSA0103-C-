#include <iostream>
#include <string>
using namespace std;

// Integer weight in grams
double charge(int grams, bool express = false,
              bool insured = false)
{
    cout << "Integer grams overload selected: ";

    double amount = grams * 0.10;

    if (express)
        amount += 20;

    if (insured)
        amount += 10;

    return amount;
}

// Weight in kilograms
double charge(double kg, bool express = false,
              bool insured = false)
{
    cout << "Double kilograms overload selected: ";

    double amount = kg * 100;

    if (express)
        amount += 20;

    if (insured)
        amount += 10;

    return amount;
}

// Parcel class
class Parcel
{
public:
    int weight;

    Parcel(int w)
    {
        weight = w;
    }
};

// Parcel overload
double charge(const Parcel &p)
{
    cout << "Parcel overload selected: ";
    return p.weight * 0.10;
}

int main()
{
    Parcel p(500);

    cout << "charge(2): " << charge(2) << endl;

    cout << "charge(2.0f): " << charge(2.0f) << endl;

    cout << "charge(500): " << charge(500) << endl;

    cout << "charge(1.5): " << charge(1.5) << endl;

    cout << "charge(Parcel): " << charge(p) << endl;

    cout << "charge(2, true): "
         << charge(2, true) << endl;

    return 0;
}
