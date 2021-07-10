namespace login
{
    using namespace std;
    template<typename st,typename db,typename it>
    class login_info
    {
        st name,pass,pass_check;
        it checker=1;

    public:
        login_info()
        {
            cout<<"profile name: ";
            cin.ignore();
            getline(cin,name);
            name.append(".txt");
            ifstream inp(name);
            inp>>pass_check;
            cout<<"password: ";
            cin>>pass;
            cin.ignore();
            if(pass==pass_check)
            {
                cout<<"login successfull\n";
                checker=1;
                inp.close();
            }
            else
            {
                checker=0;
                cout<<"wrong password or username";
                cout<<"\nPress 1 To try login again and 0 to exit: ";
                int recheck=0;
                cin>>recheck;
                if(recheck)
                {
                    login_info();
                }
            }
        }
        void after_login_op()
        {
                it choice;
                cout<<"press 1 to record your daily food data:"<<endl;
               // cout<<"press 2 to show all your recorded data:"<<endl;
                cin>>choice;
                if(choice==1)
                {

                    data_recoder();
                }

        }
        void data_recoder()
        {
            it day_numb,food_count,check=1;

            db food_value,data_value,total,food_calc;

            st food_name,data_name;
            system("cls");
            cout<<"welcome to your daily food recoder \n";
            cout<<"put a number of the day as 1 for (the record of day 1):\n";
            cout<<"DAY : ";
            cin>>day_numb;
            cout<<"\nnow put the total number of different types of food you have eaten today:";
            cin>>food_count;
            ofstream out(name,ios::app);
            out<<"Day"<<" "<<day_numb<<endl;
            cout<<"\nNow put the food name and and total amount of it you consumed"<<endl<<
            "\n\n(for example:RICE 100)means you ate 100 grams of rice ";
            cout<<"\n";//Foodname(space)total amount\n";
            for(int i=0;i<food_count;i++)
            {
                ifstream data("data.txt");
                cout<<"\nFOOD NAME: ";
                cin>>food_name;
                cout<<"\nFOOD WEIGHT IN gm: ";
                cin>>food_value;

                while(!data.eof())
                {
                    data>>data_name>>data_value;

                   // cout<<data_name<<endl;
                    if(data_name==food_name)
                    {

                        food_calc=(data_value*food_value)/100;
                        check=0;
                        //cout<<food_calc;
                    }

                }

                out<<food_name<<" "<<food_calc<<endl;
                total=total+food_calc;
                check=1;
                data.close();



            }
            out<<"total_calory_consumption: "<<total<<endl;
            system("cls");
            cout<<"\nhow much calories did you burnt during exercise today?\n"<<"if none then enter 0 or else enter the value:"<<endl;
            db wg,bn;
            cin>>bn;
            out<<"total_calory_burnt: "<<bn<<endl;
            wg=(total-2500-bn)/100;
            out<<"total_weight_gain_or_lose_in_gm: "<<wg<<endl;
            out.close();
            cout<<"\nData recorded ";
            //system("pause");

        }



    } ;
}

