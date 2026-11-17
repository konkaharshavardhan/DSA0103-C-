#include <iostream>
using namespace std;
class Event {
    int rows, seats, booked; bool** map;
public:
    Event(int r,int s) : rows(r>0?r:0), seats(s>0?s:0), booked(0), map(nullptr) {
        if(rows>0) { map=new bool*[rows]; for(int i=0;i<rows;++i) map[i]=new bool[seats](); }
        cout<<"Event created: "<<rows<<" rows x "<<seats<<" seats\n";
    }
    bool book(int r,int s) { if(r<0||r>=rows||s<0||s>=seats||map[r][s]) return false; map[r][s]=true; ++booked; return true; }
    bool cancel(int r,int s) { if(r<0||r>=rows||s<0||s>=seats||!map[r][s]) return false; map[r][s]=false; --booked; return true; }
    ~Event() { for(int i=0;i<rows;++i) delete[] map[i]; delete[] map; cout<<"Event closed. Seats currently booked: "<<booked<<'\n'; }
};
int main() {
    Event hall(2,3); hall.book(0,1); hall.book(1,2); hall.cancel(0,1);
    { Event small(1,2); small.book(0,0); }
    Event* special=new Event(1,1); special->book(0,0); delete special;
}
