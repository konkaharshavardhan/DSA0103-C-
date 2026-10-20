// TASK 12: Revised design - Airport zone, weekend discount and monthly pass
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };
constexpr long long FARE_PAISE[] = {1000, 2000, 3000, 6000};
constexpr int PEAK_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
constexpr long long MIN_BALANCE_PAISE = 5000;

class MonthlyPass {
private:
    Zone first, second;
public:
    MonthlyPass(Zone a, Zone b) : first(a), second(b) {}
    bool covers(Zone z) const { return z == first || z == second; }
};

long long calculateFare(Zone zone, bool peak, bool weekend, const MonthlyPass* pass = nullptr) {
    if (pass && pass->covers(zone)) return 0;
    int index = static_cast<int>(zone);
    if (index < 0 || index >= 4) return -1;
    long long result = FARE_PAISE[index];
    if (weekend) {
        result -= result * WEEKEND_DISCOUNT_PERCENT / 100; // weekend discount replaces peak surcharge
    } else if (peak) {
        result += result * PEAK_PERCENT / 100;
    }
    return result;
}
int main() {
    MonthlyPass pass(Zone::Inner, Zone::Middle);
    cout << "Airport off-peak fare: " << calculateFare(Zone::Airport, false, false) << " paise\n";
    cout << "Airport peak fare: " << calculateFare(Zone::Airport, true, false) << " paise\n";
    cout << "Airport weekend fare: " << calculateFare(Zone::Airport, true, true) << " paise\n";
    cout << "Inner fare with monthly pass: " << calculateFare(Zone::Inner, true, false, &pass) << " paise\n";
    cout << "Middle fare with monthly pass: " << calculateFare(Zone::Middle, false, true, &pass) << " paise\n";
    cout << "Outer weekend fare: " << calculateFare(Zone::Outer, false, true) << " paise\n";
    return 0;
}
