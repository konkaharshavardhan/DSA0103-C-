#include <iostream>
#include <string>
using namespace std;
class Prescription {
    int n; string* medicines;
public:
    explicit Prescription(int count) : n(count > 0 ? count : 0), medicines(new string[n]) {}
    Prescription(const Prescription& other) : n(other.n), medicines(new string[other.n]) {
        for (int i=0;i<n;++i) medicines[i]=other.medicines[i];
        cout << "Deep copy constructor called\n";
    }
    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            string* fresh = new string[other.n];
            for (int i=0;i<other.n;++i) fresh[i]=other.medicines[i];
            delete[] medicines; medicines=fresh; n=other.n;
        }
        return *this;
    }
    ~Prescription() { delete[] medicines; }
    void set(int i,const string& m) { if(i>=0 && i<n) medicines[i]=m; }
    string get(int i) const { return (i>=0 && i<n) ? medicines[i] : ""; }
    void show() const { for(int i=0;i<n;++i) cout<<medicines[i]<<(i+1<n?" ":""); }
};
int main() {
    Prescription p(2); p.set(0,"Paracetamol"); p.set(1,"ORS");
    Prescription q=p; q.set(1,"Cetirizine");
    Prescription r(1); r=p; p.set(0,"Ibuprofen");
    p.show(); cout<<" | "; q.show(); cout<<" | "; r.show(); cout<<'\n';
}
