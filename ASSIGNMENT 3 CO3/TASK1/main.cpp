#include <iostream>
#include <string>
using namespace std;
class Book {
    string title, author; int copies;
public:
    Book() : Book("Untitled", "Unknown", 0) {}
    explicit Book(const string& t) : Book(t, "Unknown", 1) {}
    Book(const string& t, const string& a, int c) : title(t), author(a), copies(c < 0 ? 0 : c) {}
    void display() const { cout << title << " | " << author << " | copies: " << copies << '\n'; }
};
int main() {
    Book empty; Book donated("Wings of Fire"); Book full("The Guide", "R. K. Narayan", 5);
    cout << "Default constructor: "; empty.display();
    cout << "Title constructor: "; donated.display();
    cout << "Parameterized constructor: "; full.display();
    Book invalid("Invalid", "Test", -4);
    cout << "Negative copies are corrected: "; invalid.display();
}
