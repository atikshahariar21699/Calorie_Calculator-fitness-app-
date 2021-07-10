namespace last
{
using namespace std;
class bmi
{ double w;
public:
    bmi(){};
    bmi(double h):w{h}{}
    double operator()(double h)
    {
       // double h2;
        h=(h*2.54)/100;
        return w/(h*h);
    }

};


    int BMI()
    { system("cls");
      cout<<"WELCOME TO BMI CALCULATOR\n\nPlease put your weight(in kg): ";
      double w,h;
      cin>>w;
      bmi op(w);
      cout<<"\nNow put your height(in inch): ";
      cin>>h;
      cout<<"\nYOUR BMI: "<<op(h)<<"\n";
    }

}
