// TASK 3: Data types and exact money representation
#include <climits>
#include <iostream>
using namespace std;

int main() {
    long long farePaise = 3000;
    long long balancePaise = 10000;
    long long journeys = 3000000LL;
    double fareRupees = 30.00;
    cout << "Task 3 - Data types\n";
    cout << "sizeof(bool) = " << sizeof(bool) << " byte(s)\n";
    cout << "sizeof(char) = " << sizeof(char) << " byte(s)\n";
    cout << "sizeof(int) = " << sizeof(int) << " byte(s)\n";
    cout << "sizeof(long long) = " << sizeof(long long) << " byte(s)\n";
    cout << "sizeof(double) = " << sizeof(double) << " byte(s)\n";
    cout << "INT_MAX = " << INT_MAX << "\n";
    cout << "Fare in integer paise = " << farePaise << "\n";
    cout << "Balance in integer paise = " << balancePaise << "\n";
    cout << "3,000,000 fares of Rs 30 = Rs " << journeys * 30LL << "\n";
    cout << "A double stores rupees approximately; integer paise keeps money exact.\n";
    cout << "Example double fare: Rs " << fareRupees << "\n";
    return 0;
}
