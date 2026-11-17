
#include <iostream>
#include <string>
using namespace std;

class Address
{
    string city;
    int pin;

public:
    Address(const string& c, int p)
    {
        city = c;
        pin = p;
        cout << "Address constructed" << endl;
    }

    ~Address()
    {
        cout << "Address destroyed" << endl;
    }

    string str() const
    {
        char num[20];
        int n = pin;
        int i = 0;

        if (n == 0)
        {
            num[i++] = '0';
        }

        while (n > 0)
        {
            num[i++] = (n % 10) + '0';
            n = n / 10;
        }

        num[i] = '\0';

        string result = city + "-";

        while (i > 0)
        {
            result += num[--i];
        }

        return result;
    }
};

class Person
{
protected:
    string name;
    int age;
    Address home;

public:
    Person(const string& n, int a, const string& c, int p)
        : name(n), age(a), home(c, p)
    {
        cout << "Person constructed" << endl;
    }

    virtual ~Person()
    {
        cout << "Person destroyed" << endl;
    }
};

class Course
{
    string title;

public:
    Course(const string& t)
    {
        title = t;
        cout << "Course constructed" << endl;
    }

    ~Course()
    {
        cout << "Course destroyed" << endl;
    }

    string getTitle() const
    {
        return title;
    }
};

class Student : public Person
{
    long long regNo;
    Course course;

public:
    Student(const string& n, int a, long long r,
            const string& c, int p, const string& co)
        : Person(n, a, c, p), regNo(r), course(co)
    {
        cout << "Student constructed" << endl;
    }

    ~Student()
    {
        cout << "Student destroyed" << endl;
    }

    void print() const
    {
        cout << regNo << " "
             << name << " (" << age << ") "
             << home.str() << " | "
             << course.getTitle() << endl;
    }
};

int main()
{
    cout << "STUDENT OBJECT" << endl;

    {
        Student s("Kavya", 19, 192311001,
                  "Salem", 636001, "C++ Programming");

        s.print();
    }

    cout << "End of program" << endl;

    return 0;
}

