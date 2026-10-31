#include <iostream>
#include <cstdlib>
using namespace std;

class Time
{
private:
    int h, m;

public:

    Time(int hh, int mm)
    {
        h = hh;
        m = mm;
    }

    friend inline int minutesBetween(
        const Time &a, const Time &b);

    friend inline bool earlier(
        const Time &a, const Time &b);
};

// TODO 1
inline int minutesBetween(const Time &a, const Time &b)
{
    int time1 = a.h * 60 + a.m;
    int time2 = b.h * 60 + b.m;

    return abs(time1 - time2);
}

// TODO 2
inline bool earlier(const Time &a, const Time &b)
{
    int time1 = a.h * 60 + a.m;
    int time2 = b.h * 60 + b.m;

    return time1 < time2;
}

int main()
{
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << minutesBetween(departure, arrival)
         << " ";

    cout << boolalpha
         << earlier(arrival, departure) << endl;

    // Same time test
    Time t1(10, 30);
    Time t2(10, 30);

    cout << "Same time difference: "
         << minutesBetween(t1, t2) << endl;

    // Before noon and after noon
    Time morning(9, 00);
    Time afternoon(14, 00);

    cout << "Is morning earlier? "
         << earlier(morning, afternoon) << endl;

    return 0;
}
