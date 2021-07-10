namespace ssw
{
    using namespace std;
class show_data
{
    string name,pass,pass_check;
public:
    void login()
    {       system("cls");
            cout<<"you need to log in to your profile";
            cout<<"\nprofile name:";
            cin.ignore();
            getline(cin,name);
            name.append(".txt");
            ifstream inp(name);
            inp>>pass_check;
            cout<<"password:";
            cin>>pass;
            cin.ignore();
            if(pass==pass_check)
            {
                cout<<"login successfull\n";

            }
            else
            {
                cout<<"wrong password or username\n";
                system("pause");
                login();
            }
    }
    void show()
    {
        int loop=0;
        ifstream inp(name);
        string fon;
        double fov;
        inp>>pass;
        vector<string>fn;
        vector<double>fv;
        while(!inp.eof())
        {
            inp>>fon>>fov;
            fn.push_back(fon);
            fv.push_back(fov);
        }
        //cout<<fn.size();
        system("cls");
        cout<<"your profile data:\n"<<endl;
        cout<<"Pass: "<<pass<<endl<<endl;
        while(loop<(fn.size()-1))
        {
             cout<<fn[loop]<<" "<<fv[loop]<<endl<<endl;
             loop++;
        }
        inp.close();

    }
    void search_show()
    {
        cout<<"put the day name which data you want to search:";
        int dn,loop=0;
        string fn;
        double fv ;
        cin>>dn;
        ifstream inp(name);
        inp>>pass;
        while(loop<dn)
        {
            inp>>fn>>fv;
            if(fn=="Day")
                loop++;
        }
        system("cls");
        cout<<"\nshowing data of day "<<dn<<endl;
        dn++;
        while(1)
        {
            inp>>fn>>fv;
            if(fn=="Day"&&fv==dn)
                break;

            cout<<fn<<" "<<fv<<endl;
        }


    }
};

void show()
{
    show_data obj;
    obj.login();
    cout<<"press 1 to show complete profile data & press 2 to show data of any selected day:";
    int a;
    cin>>a;
    if(a==1)
    {
        obj.show();
    }
    else if(a==2)
    {
        obj.search_show();
    }
}
}
