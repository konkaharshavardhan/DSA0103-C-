// TASK 1: Objects and OOP analysis - Namma Metro Smart-Card Fare System
#include <iostream>
#include <string>
using namespace std;

class SmartCard {
private:
    long long balancePaise;
public:
    explicit SmartCard(long long balance) : balancePaise(balance) {}
    long long getBalance() const { return balancePaise; }
    bool canTravel(long long farePaise, long long minimumPaise) const {
        return balancePaise - farePaise >= minimumPaise;
    }
    bool deduct(long long farePaise, long long minimumPaise) {
        if (farePaise < 0 || !canTravel(farePaise, minimumPaise)) return false;
        balancePaise -= farePaise;
        return true;
    }
};

int main() {
    SmartCard card(10000); // Rs 100.00
    const long long minimum = 5000;
    const long long fare = 2000;
    cout << "Namma Metro - Task 1\n";
    cout << "Initial balance: Rs " << card.getBalance() / 100 << "\n";
    cout << "Journey fare: Rs " << fare / 100 << "\n";
    cout << "Journey allowed: " << (card.canTravel(fare, minimum) ? "Yes" : "No") << "\n";
    cout << "OOP objects: SmartCard, Passenger, Journey, Zone, FareTable\n";
    cout << "Rule: balance after fare must be at least Rs 50.\n";
    return 0;
}
