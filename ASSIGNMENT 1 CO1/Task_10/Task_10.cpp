// TASK 10: Compare totals, int range and double
#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const long long journeys[] = {20000LL, 500000LL, 3000000LL};
    const long long farePaise = 3000; // Rs 30
    cout << "Journeys | Exact total (paise) | Total (rupees)\n";
    for (long long n : journeys) {
        long long totalPaise = n * farePaise;
        double totalDouble = static_cast<double>(n) * 30.0;
        cout << n << " | " << totalPaise << " | " << fixed << setprecision(2) << totalDouble << '\n';
    }
    cout << "INT_MAX = " << INT_MAX << '\n';
    cout << "3,000,000 journeys at Rs 30 = Rs 90,000,000; this exceeds 32-bit signed int.\n";
    cout << "Use long long for the aggregate total and integer paise for exact money.\n";
    return 0;
}
