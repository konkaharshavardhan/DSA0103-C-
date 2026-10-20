// TASK 5: Operators, precedence and expressions
#include <iostream>
using namespace std;

int main() {
    int x = 5, y = 3;
    cout << x + y * 2 << ' ' << (x + y) * 2 << '\n';

    int z = x++ + ++y;
    cout << z << ' ' << x << ' ' << y << '\n';

    cout << (x > y ? x : y) << ' ' << x % 4 * 2 << '\n';
    cout << 10 / 3 << ' ' << 10 % 3 << ' ' << -10 / 3 << ' ' << -10 % 3 << '\n';

    int k = 0;
    for (int i = 0; i < 10; i += 3) k += i;
    cout << k << '\n';
    return 0;
}
// Expected output:
// 11 16
// 10 6 4
// 6 4
// 3 1 -3 -1
// 18
