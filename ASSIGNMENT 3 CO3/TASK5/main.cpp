#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class Time {
    int seconds;
public:
    explicit Time(int s=0):seconds(s<0?0:s){}
    Time& operator++(){ ++seconds; return *this; }
    Time operator++(int){ Time old=*this; ++seconds; return old; }
    bool operator==(const Time& t)const{return seconds==t.seconds;}
    bool operator<(const Time& t)const{return seconds<t.seconds;}
    void show()const{cout<<seconds/3600<<":"<<(seconds/60)%60<<":"<<seconds%60;}
};
class Playlist {
    string* tracks; int n;
public:
    Playlist(const string a[],int count):tracks(new string[count]),n(count){for(int i=0;i<n;++i)tracks[i]=a[i];}
    ~Playlist(){delete[] tracks;}
    string& operator[](int i){if(i<0||i>=n)throw out_of_range("Playlist index out of range");return tracks[i];}
    const string& operator[](int i)const{if(i<0||i>=n)throw out_of_range("Playlist index out of range");return tracks[i];}
};
int main(){
    Time t(3599); Time a=t++; Time b=++t;
    cout<<"a=";a.show();cout<<" b=";b.show();cout<<" current=";t.show();cout<<'\n';
    string songs[]={"Track One","Track Two","Track Three"}; Playlist p(songs,3);
    cout<<"Selected: "<<p[1]<<'\n';
    try{cout<<p[3]<<'\n';}catch(const out_of_range& e){cout<<e.what()<<'\n';}
}
