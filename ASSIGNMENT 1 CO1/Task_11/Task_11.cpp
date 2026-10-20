// TASK 11: Recommended final design
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
constexpr long long FARE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long calculateFare(Zone z, bool peak) {
    int index = static_cast<int>(z);
    if (index < 0 || index >= 3) return -1;
    long long result = FARE_PAISE[index];
    if (peak) result += result * PEAK_PERCENT / 100;
    return result;
}
int main() {
    cout << "Recommended design: enum class Zone, constexpr fare table, integer paise.\n";
    cout << "Single source of truth: base fares, surcharge and minimum balance constants.\n";
    cout << "Example Outer peak fare: " << calculateFare(Zone::Outer, true) << " paise.\n";
    cout << "Minimum remaining balance: " << MIN_BALANCE_PAISE << " paise.\n";
    cout << "Complexity: fare calculation O(1); suitable for high journey volume.\n";
    return 0;
}
