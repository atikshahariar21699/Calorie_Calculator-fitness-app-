#include<iostream>
using namespace std;
class bmi
{ double w;
public:
    bmi(){};
    bmi(double h):w{h}{}
    double operator()(double h)
    {
        double h2;
        h=(h*2.54)/100;
        return w/(h*h);
    }

};


    int main()
    { //system("cls");
      cout<<"WELCOME TO BMI CALCULATOR\n\nPlease put your weight: ";
      double w,h;
      cin>>w;
      bmi op(w);
      cout<<"\n now put your height(in inch): ";
      cin>>h;
      cout<<"\nYOUR BMI: "<<op(h);
    }
