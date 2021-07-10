namespace profile_creation
{
    using namespace std;
    template<typename st, typename db, typename it>
    class profile_create
    {
        st name,pass;
    public:


         profile_create()
        {
            st x;
            cout<<setfill(' ')<<setw(50)<<" ";
            cout<<"PROFILE CREATION";
            cout<<endl<<setfill('#')<<setw(134)<<"#\n\n\n";
            cout<<setfill(' ')<<setw(50)<<" ";
            cout<<"profile name: ";
            cin.ignore();
            getline(cin,x);
            name=x;
            cout<<endl<<setfill(' ')<<setw(50)<<" ";
            cout<<"password:";
            getline(cin,pass);
            name.append(".txt");
            ofstream out(name);
            out<<pass<<endl;
            out.close();
            cout<<endl<<endl;
        }
        it create_completion()
        {

            //system("cls");
            cout<<setfill(' ')<<setw(50)<<" ";
            cout<<"profile creation successful"<<endl;
            system("cls");
            cout<<setfill(' ')<<setw(50)<<" "<<"press 1 to add your BMI as well"<<endl;
            cout<<setfill(' ')<<setw(50)<<" "<< "and press 0 to skip\n";
            it BMI_permission;
            cout<<setfill(' ')<<setw(50)<<" ";
            cout<<"choice: ";
            cin>>BMI_permission;
            system("cls");
            return BMI_permission;
        }
        it BMI_calc()
        {
            cout<<"your height please(foot inch) :\n";
            db foot,inch,weight,bmi,height;
            cin>>foot>>inch;
            cout<<"your weight please(in kg): " ;
            cin>>weight;
            height=((foot*12)+inch)*2.54/100;
            //cout<<height;
            bmi=weight/(height*height);
            cout<<endl<<"Your BMI: "<<bmi;
            ofstream out(name,ios::app);
            out<<"HEIGHT_in_m: "<<height<<endl;
            out<<"WEIGHT_in_kg: "<<weight<<endl;
            out<<"BMI: "<<bmi<<endl;
            out.close();

        }


    };
}
