// TASK 9: Complete fare logic with test cases
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
constexpr long long MIN_BALANCE = 5000;
long long fare(Zone z, int hour) {
    long long base;
    switch (z) {
        case Zone::Inner: base = 1000; break;
        case Zone::Middle: base = 2000; break;
        case Zone::Outer: base = 3000; break;
        default: return -1;
    }
    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    return peak ? base + base * 20 / 100 : base;
}
bool canTravel(long long balance, long long f) {
    return f >= 0 && balance - f >= MIN_BALANCE;
}
int main() {
    struct Test { Zone zone; int hour; long long expected; const char* label; };
    Test tests[] = {
        {Zone::Inner, 7, 1000, "Inner off-peak"},
        {Zone::Inner, 8, 1200, "Inner at 08:00"},
        {Zone::Middle, 10, 2000, "Middle at 10:00"},
        {Zone::Outer, 17, 3600, "Outer at 17:00"},
        {Zone::Outer, 20, 3000, "Outer at 20:00"}
    };
    cout << "Test case | Expected paise | Actual paise | Result\n";
    for (const Test& t : tests) {
        long long actual = fare(t.zone, t.hour);
        cout << t.label << " | " << t.expected << " | " << actual << " | "
             << (actual == t.expected ? "PASS" : "FAIL") << '\n';
    }
    cout << "Balance 6200 paise, fare 1200 paise leaves exactly 5000 paise: "
         << (canTravel(6200, 1200) ? "Allowed" : "Denied") << '\n';
    return 0;
}
