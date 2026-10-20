// TASK 4: Implicit conversions and explicit casts
#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;
    double c = a / b;
    double d = static_cast<double>(a) / b;
    cout << c << ' ' << d << '\n';

    char ch = 'A' + 2;
    cout << ch << ' ' << ch + 1 << '\n';

    bool flag = 5;
    cout << flag << ' ' << boolalpha << flag << '\n';

    unsigned int u = 1;
    int s = -1;
    cout << (s < u ? "s < u" : "s >= u") << '\n';
    return 0;
}
// Expected output:
// 3.5? No: integer division happens first, so output is 3 3.5
// C 68
// 1 true
// s >= u
