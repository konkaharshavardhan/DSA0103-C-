#include <iostream>
#include <string>
using namespace std;
const double DA_RATE=0.42;
class Staff { protected: string name; int id; double basic; public: Staff(const string& n,int i,double b):name(n),id(i),basic(b){} virtual double pay() const=0; virtual void display() const { cout<<name<<" (ID "<<id<<") - Pay: Rs "<<pay()<<'\n'; } virtual ~Staff(){} };
class Professor:public Staff { double research; public: Professor(const string& n,int i,double b,double r):Staff(n,i,b),research(r){} double pay() const { return basic+basic*DA_RATE+research; } };
class LabAssistant:public Staff { public: LabAssistant(const string& n,int i,double b):Staff(n,i,b){} double pay() const { return basic+basic*DA_RATE; } };
class GuestFaculty:public Staff { double hours,rate; public: GuestFaculty(const string& n,int i,double h,double r):Staff(n,i,0),hours(h),rate(r){} double pay() const { return hours*rate; } };
int main(){ Professor p("Anita",101,50000,8000); LabAssistant l("Ravi",102,30000); GuestFaculty g("Meena",103,20,1000); Staff* a[3]={&p,&l,&g}; cout<<"COLLEGE PAYROLL\n"; for(int i=0;i<3;++i)a[i]->display(); }
