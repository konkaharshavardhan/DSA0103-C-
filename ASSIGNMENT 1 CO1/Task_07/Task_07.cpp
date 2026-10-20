// TASK 7: Procedural and object-oriented versions
#include <iostream>
using namespace std;
constexpr long long MIN_BALANCE = 5000;

bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= MIN_BALANCE;
}
class SmartCard {
private:
    long long balance;
public:
    explicit SmartCard(long long initial) : balance(initial) {}
    bool canTravel(long long fare) const {
        return fare >= 0 && balance - fare >= MIN_BALANCE;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balance -= fare;
        return true;
    }
    long long getBalance() const { return balance; }
};
int main() {
    long long proceduralBalance = 10000, fare = 3000;
    cout << "Procedural journey allowed: " << (proceduralCanTravel(proceduralBalance, fare) ? "Yes" : "No") << '\n';
    SmartCard card(10000);
    cout << "OOP journey allowed: " << (card.deduct(fare) ? "Yes" : "No") << '\n';
    cout << "OOP remaining balance: Rs " << card.getBalance() / 100 << '\n';
    return 0;
}
