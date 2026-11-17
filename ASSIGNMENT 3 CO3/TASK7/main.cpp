#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
class Complex {
    double re,im;
public:
    Complex():re(0),im(0){}
    Complex(double r):re(r),im(0){}
    Complex(double r,double i):re(r),im(i){}
    Complex operator+(const Complex& z)const{return Complex(re+z.re,im+z.im);}
    Complex operator-(const Complex& z)const{return Complex(re-z.re,im-z.im);}
    Complex operator*(const Complex& z)const{return Complex(re*z.re-im*z.im,re*z.im+im*z.re);}
    Complex operator/(const Complex& z)const{double d=z.re*z.re+z.im*z.im;if(d==0)throw runtime_error("Division by zero impedance");return Complex((re*z.re+im*z.im)/d,(im*z.re-re*z.im)/d);}
    bool operator==(const Complex& z)const{return fabs(re-z.re)<1e-9&&fabs(im-z.im)<1e-9;}
    double magnitude()const{return sqrt(re*re+im*im);}
    friend ostream& operator<<(ostream& out,const Complex& z){out<<z.re<<(z.im<0?" - j":" + j")<<fabs(z.im);return out;}
};
int main(){
    Complex resistor(10,0),inductor(0,5),capacitor(0,-2);
    Complex series=resistor+inductor+capacitor;
    Complex parallel=(resistor*inductor)/(resistor+inductor);
    cout<<"Series impedance: "<<series<<" ohms\n";
    cout<<"Series magnitude: "<<series.magnitude()<<" ohms\n";
    cout<<"Parallel impedance: "<<parallel<<" ohms\n";
    try{Complex invalid=resistor/Complex(0,0);cout<<invalid;}catch(const runtime_error& e){cout<<e.what()<<'\n';}
}
