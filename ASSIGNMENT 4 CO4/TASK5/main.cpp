#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class Cart { string items[10];double prices[10];int n;double discount; public: Cart():n(0),discount(0){} Cart& add(const string& item,double price){if(n<10&&price>=0){items[n]=item;prices[n]=price;++n;}return *this;} Cart& setDiscount(double discount){this->discount=discount;if(this->discount<0)this->discount=0;if(this->discount>100)this->discount=100;return *this;} double total()const{double t=0;for(int i=0;i<n;++i)t+=prices[i];return t*(100-discount)/100;} void display()const{cout<<"Cart items:\n";for(int i=0;i<n;++i)cout<<" - "<<items[i]<<": Rs "<<prices[i]<<'\n';cout<<"Discount: "<<discount<<"%\n";} };
int main(){Cart c;c.add("Rice",60).add("Dal",120).setDiscount(10);Cart* p=&c;p->add("Oil",180);p->display();cout<<fixed<<setprecision(2)<<"Final total: Rs "<<p->total()<<'\n';Cart& ref=c;cout<<"Access through reference: Rs "<<ref.total()<<'\n';Cart* d=new Cart();d->add("Milk",50);cout<<"Dynamic cart total: Rs "<<d->total()<<'\n';delete d;}
