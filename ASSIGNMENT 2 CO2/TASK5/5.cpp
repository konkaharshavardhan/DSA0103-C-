#include <iostream>
#include <string>
using namespace std;

class BusTicket
{
private:
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:

    BusTicket(const string &n)
    {
        name = n;
        seat = 0;

        // TODO 1
        if (issued < CAPACITY)
        {
            issued++;
            seat = issued;
        }
    }

    // TODO 2
    static int count()
    {
        return issued;
    }

    void print() const
    {
        cout << name << ": ";

        if (seat != 0)
            cout << "Seat " << seat << endl;
        else
            cout << "Waiting" << endl;
    }
};

// Definition of static data member
int BusTicket::issued = 0;

int main()
{
    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (int i = 0; i < 4; i++)
    {
        trip[i].print();
    }

    cout << "Issued: "
         << BusTicket::count() << endl;

    return 0;
}
