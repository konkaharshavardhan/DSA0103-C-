#include <iomanip>
#include <iostream>
using namespace std;
class Money {
    long long paise;
public:
    Money(long long rupees=0,int p=0):paise(rupees*100+p){}
    Money operator+(const Money& m) const { Money result; result.paise=paise+m.paise; return result; }
    bool operator==(const Money& m) const { return paise==m.paise; }
    Money& operator+=(const Money& m) { paise+=m.paise; return *this; }
    friend ostream& operator<<(ostream& out,const Money& m) {
        long long v=m.paise; if(v<0) { out<<"-Rs "; v=-v; } else out<<"Rs ";
        return out<<v/100<<'.'<<setw(2)<<setfill('0')<<v%100<<setfill(' ');
    }
};
int main() {
    Money a(120,75),b(79,25); Money c=a+b;
    cout<<c<<'\n'<<boolalpha<<(c==Money(200))<<'\n';
    Money x(0,75),y(0,50); cout<<x+y<<'\n';
}
