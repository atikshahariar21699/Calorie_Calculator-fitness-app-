#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include"profile_creation.h"
#include"login.h"
#include"edit_dlet.h"
#include"search&show.h"
#include"autoup.h"
#include"bmi.h"
using namespace std;
int func_caller()
{
    int choice;
    cout<<endl<<setfill(' ')<<setw(70)<<" CALORIE CALCULATOR"<<endl<<setfill('#')<<setw(134)<<"#"
    <<endl<<endl<<setfill(' ')<<setw(75)<<" Press 1 to create new profile"<<endl<<setfill(' ')<<setw(72)<<"press 2 to record new data"
    <<endl<<setfill(' ')<<setw(69)<<"press 3 to edit profile"<<endl<<setfill(' ')<<setw(76)<<"press 4 to delete profile data"
    <<endl<<setfill(' ')<<setw(66)<<"press 5 to show data"<<endl<<setfill(' ')<<setw(68)<<" press 6 to auto update"<<endl<<setfill(' ')<<setw(46)<<" "<<"press 7 to use BMI calculator only\n";
    cout<<setfill(' ')<<setw(46)<<" ";
    cout<<"Your choice:";
    cin>>choice;
    system("cls");
    switch(choice)
    {
        case 1:
        {
            using namespace profile_creation;

            profile_create<string,double,int>obj;
            int x;
            x=obj.create_completion();
            if(x)
            {
                obj.BMI_calc();
            }
            break;
        }
        case 2:
            {  cout<<"WELCOME TO DATA RECODER\n";
               using namespace login;
               login_info<string,double,int>obj;
               obj.after_login_op();
               break;
            }
        case 3:
            {
                cin.ignore();
                using namespace edelet;
                 poly_morph *p;
                 edit e;
                 p=&e;
                 p->getdata();
                 p->editor();
                 p->editor2();
                 system("cls");
                 cout<<"Data edited\n";
                 //system("pause");
                 break;
            }
        case 4:
            {
                cin.ignore();
                using namespace edelet;
                 poly_morph *p;
                 dlet f;
                 p=&f;
                 p->getdata();
                 p->editor();
                 p->editor2();
                 system("cls");
                 cout<<"Data deleted\n";
                 //system("pause");
                 break;
            }
        case 5:
            {
                using namespace ssw;
                show();
                break;
            }
        case 6:
            {
                using namespace aup;
                auto_update();
                break;

            }
        case 7:
            {
                using namespace last;
                BMI();
            }

}
int b;
system("pause");
system("cls");
cout<<"press 1 to main menu 0 to exit\n";
    cin>>b;
    if(b)
    {
        system("cls");
        func_caller();
    }

}
int main()
{
    func_caller();

}
