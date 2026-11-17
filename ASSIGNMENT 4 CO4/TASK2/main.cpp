#include <iostream>
#include <string>
using namespace std;
class Person { protected: string name; int id; public: Person(const string& n,int i):name(n),id(i){cout<<"Person constructed\n";} virtual ~Person(){} };
class Student:virtual public Person { protected: string programme; double cgpa; public: Student(const string& n,int i,const string& p,double c):Person(n,i),programme(p),cgpa(c){cout<<"Student constructed\n";} };
class Staff:virtual public Person { protected: string department; double salary; public: Staff(const string& n,int i,const string& d,double s):Person(n,i),department(d),salary(s){cout<<"Staff constructed\n";} };
class TeachingAssistant:public Student,public Staff { public: TeachingAssistant(const string& n,int i,const string& p,double c,const string& d,double s):Person(n,i),Student(n,i,p,c),Staff(n,i,d,s){cout<<"TeachingAssistant constructed\n";} void show()const{cout<<"Name: "<<name<<"\nID: "<<id<<"\nProgramme: "<<programme<<"\nDepartment: "<<department<<"\nCGPA: "<<cgpa<<"\nSalary: "<<salary<<'\n';} };
class ResearchScholar:public Student { double fellowship; public: ResearchScholar(const string& n,int i,const string& p,double c,double f):Person(n,i),Student(n,i,p,c),fellowship(f){} void show()const{cout<<"Research Scholar: "<<name<<", Fellowship: "<<fellowship<<'\n';} };
int main(){TeachingAssistant ta("Kavya",201,"AI&DS",8.7,"CSE",35000); cout<<"\nTEACHING ASSISTANT DETAILS\n";ta.show();cout<<"\nRESEARCH SCHOLAR\n";ResearchScholar rs("Arun",202,"CSE",9.1,12000);rs.show();}
