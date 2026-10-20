// TASK 2: Tokens, identifiers, constants and enum class
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long BASE_PAISE[] = {1000, 2000, 3000};

int main() {
    Zone zone = Zone::Middle;
    cout << "Task 2 - Constants and tokens\n";
    cout << "Middle zone base fare: Rs " << BASE_PAISE[1] / 100 << "\n";
    cout << "Peak surcharge: " << PEAK_SURCHARGE_PERCENT << "%\n";
    cout << "Minimum remaining balance: Rs " << MIN_BALANCE_PAISE / 100 << "\n";
    cout << "enum class prevents accidental mixing of zone values.\n";
    return 0;
}
