#include <iostream>
using namespace std;
class Account { public: double rate()const{return 3.5;} virtual double vrate()const{return 3.5;} virtual ~Account(){cout<<"Account destroyed\n";} };
class SeniorAccount:public Account { double* history; public: SeniorAccount():history(new double[100]){cout<<"SeniorAccount created\n";} double rate()const{return 4.0;} double vrate()const{return 4.0;} ~SeniorAccount(){delete[] history;cout<<"SeniorAccount destroyed\n";} };
int main(){SeniorAccount s;Account* p=&s;Account copy=s;cout<<"Non-virtual rate: "<<p->rate()<<'\n';cout<<"Virtual rate: "<<p->vrate()<<'\n';cout<<"Sliced copy virtual rate: "<<copy.vrate()<<'\n';Account* a[2]={new Account(),new SeniorAccount()};cout<<"\nACCOUNT ARRAY\n";for(int i=0;i<2;++i)cout<<a[i]->vrate()<<'\n';for(int i=0;i<2;++i)delete a[i];}
