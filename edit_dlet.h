namespace edelet
{
using namespace std;
class poly_morph
{protected:
    string name,pass;
public:
    virtual void getdata()=0;
    virtual void editor()=0;
    virtual void editor2()=0;

};
class edit:public poly_morph
{
protected:
    int day_counter;
public:
    void getdata()
    {
        system("cls");
        cout<<"WELCOME TO DATA EDITOR";
        cout<<"\n\nTo edit profile data you first need to log in"<<endl<<"profile name:";
        getline(cin,name);
        cout<<endl<<"Password:";
        cin>>pass;
        name.append(".txt");
        ifstream inp(name);
        string ps;
        inp>>ps;
        inp.close();
        if(ps==pass)
        {
            cout<<"login successfull";
            inp.close();
        }
        else
        {
            cout<<"login unsuccessfull";
            system("pause");
            cin.ignore();
            inp.close();
            getdata();

        }
    }
    void editor()
    {
        cout<<endl<<"\n\nplease put the day numb of which data you want to edit\n";
        int dt=0;
        cout<<"Day :";
        string ps,bmi,fon,tmp;
        double fov,bm;
        cin>>day_counter;
        ofstream out("tmp.txt");
        ifstream inp(name);
        inp>>ps;
        //cout<<name<<ps<<day_counter;
        out<<ps<<endl;//<<bmi<<" "<<bm<<endl;
        out.close();
        while(!inp.eof())
        {
            //cout<<"asdadasd";
            inp>>fon>>fov;
            if(tmp==fon)
                continue;
            if(fon=="Day")
            {
                dt++;
            }
            if(dt==day_counter)
            {
                //cout<<"asdasdsadsd";
                retake();
                dt++;
                inp>>fon>>fov;
                while(fon!="total_weight_gain_or_lose_in_gm:")
                {
                    inp>>fon>>fov;
                    //out<<"asdasd";
                }


            }
            else
            {
                ofstream out("tmp.txt",ios::app);
                out<<fon<<" "<<fov<<endl;
                tmp=fon;
                out.close();
            }
        }
        inp.close();

    }
    void retake()
    {
            int day_numb,food_count,check=1;

            double food_value,data_value,total,food_calc;

            string food_name,data_name,tm;
            day_numb=day_counter;

            cout<<"\nlets retake your food data of day "<<day_numb<<endl;

            cout<<"now put the total number of different types of food you have eaten that day: ";
            cin>>food_count;
            ofstream out("tmp.txt",ios::app);
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
                { data>>data_name>>data_value;


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
           // out<<"total_calory_consumption: "<<total<<endl;
            cout<<"\nhow much calories did you burnt during exercise today \nif none then enter 0 or else enter the value:"<<endl;
            double wg,bn;
            cin>>bn;
            out<<"total_calory_burnt: "<<bn<<endl;
            wg=(total-2500-bn)/100;
            out<<"total_weight_gain_or_lose_in_gm: "<<wg<<endl;
            out.close();
            //out.close();
    }
    void editor2()
    {
        string p,tmp,fn;
        double fv;
        ifstream inp("tmp.txt");
        ofstream out(name);
        inp>>p;
        out<<p<<endl;
        while(!inp.eof())
        {
            inp>>fn>>fv;
            if(tmp==fn)
                continue;
            out<<fn<<" "<<fv<<endl;
            tmp=fn;
        }
        inp.close();
        out.close();
    }

};
class dlet:public poly_morph
{
  protected:
    int day_counter,choice;
public:
    void getdata()
    {
         system("cls");
        cout<<"WELCOME TO DATA DELETOR\n";
        cout<<"to delete profile data you first need to log in"<<endl<<"profile name:";
        getline(cin,name);
        cout<<endl<<"\nPassword:";
        cin>>pass;
        name.append(".txt");
        ifstream inp(name);
        string ps;
        inp>>ps;
        inp.close();
        if(ps==pass)
        {
            cout<<"login successfull ";
            inp.close();

            system("pause");
            system("cls");
        }
        else
        {
            cout<<"login unsuccessfull\n";
            cin.ignore();
            inp.close();
            system("pause");
            getdata();
            //system("pause");


        }
    }
    void editor()
    {
        cout<<"To wipe out whole profile data press 1 \n\nTO delete the data of a specific day press 2 \nchoice: ";
        //int choice;
        cin>>choice;
        if(choice==1)
        {
        string p="DATA_WIPED_BY_USER:})";
        ofstream out(name);
        cout<<p;
        out<<p;
        out.close();
        }
        else if(choice==2)
        {
        cout<<endl<<"please put the day numb of which data you want to delete";
        cout<<"\nDAY: ";
        int dt=0;
        string ps,bmi,fon,tmp;
        double fov,bm;
        cin>>day_counter;
        ofstream out("tmp.txt");
        ifstream inp(name);
        inp>>ps>>bmi>>bm;
        cout<<name<<ps<<day_counter;
        out<<ps<<endl<<bmi<<" "<<bm<<endl;
        out.close();
        while(!inp.eof())
        {
            //cout<<"asdadasd";
            inp>>fon>>fov;
            if(tmp==fon)
                continue;
            if(fon=="Day")
            {
                dt++;
            }
            if(dt==day_counter)
            {
                //cout<<"asdasdsadsd";
                retake();
                dt++;
                inp>>fon>>fov;
                while(fon!="total_weight_gain_or_lose_in_gm:")
                {
                    inp>>fon>>fov;
                }


            }
            else
            {
                ofstream out("tmp.txt",ios::app);
                out<<fon<<" "<<fov<<endl;
                tmp=fon;
                out.close();
            }
        }
        inp.close();
        }

    }
    void retake()
    {
        if(choice==2)
        {
            int day_numb,food_count=0;
            string food_name="DATA_DELETED",data_name;
            day_numb=day_counter;
            ofstream out("tmp.txt",ios::app);
            out<<"Day"<<" "<<day_numb<<endl<<food_name<<" "<<food_count<<endl  ;
           // out<<"total_calory_consumption: "<<0<<endl;
            out.close();
        }
    }
    void editor2()
    {
      if(choice==2)
      {
        string p,tmp,fn;
        double fv;
        ifstream inp("tmp.txt");
        ofstream out(name);
        inp>>p;
        out<<p<<endl;
        while(!inp.eof())
        {
            inp>>fn>>fv;
            if(tmp==fn)
                continue;
            out<<fn<<" "<<fv<<endl;
            tmp=fn;
        }
        inp.close();
        out.close();
    }
    }
};
}
