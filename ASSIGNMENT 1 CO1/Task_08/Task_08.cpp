// TASK 8: Safe input and formatted output
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    double amount;
    cout << "Enter fare in rupees (example 20.50): ";
    while (!(cin >> amount) || amount < 0) {
        cout << "Invalid input. Enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    long long paise = static_cast<long long>(amount * 100 + 0.5);
    cout << fixed << setprecision(2);
    cout << "Accepted fare: Rs " << paise / 100 << '.' << setw(2) << setfill('0') << paise % 100 << '\n';
    return 0;
}
