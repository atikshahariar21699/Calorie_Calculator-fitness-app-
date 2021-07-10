namespace aup
{
    using namespace std;
string name,pass;
class graph
{
    int size;
public:
    double *data;
graph()
{}
graph(int size)
{
    this->size=size;
   // cout<<" asdasda "<<size;
    data=new double[size];
}

void show()
{
    int i;
    for(i=0;i<size;i++)
    {
//       cout<<data[i]<<endl;
    }
}
/*void auto_update()
{

}*/
~graph()
{
    delete[] data;
}
};
 string login()
    {
        system("pause");
        system("cls");
        cout<<"To auto update profile data you first need to log in:"<<endl<<"profile name:";
        cin.ignore();
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
            cout<<"login unsuccessfull\n";
            cin.ignore();
            //system("pause");
            inp.close();
            login();
        }
        return name;

    }

 int file_read()
    {
        string ps,fn,tm;
        double fv;
        int cnt=0;
        ifstream inp(name);
        inp>>ps;
        while(!inp.eof())
        {
            inp>>fn>>fv;
            if(tm==fn)
                continue;
            if(fn=="total_weight_gain_or_lose_in_gm:")
                cnt++;
            fn=tm;

        }
        inp.close();
        return cnt;
    }

/*graph semi_main(int sz)
    {
        graph gr(sz);
        string ps,fn,tm;
        double fv;
        int cnt=0;
        ifstream inp(name);
        inp>>ps;
        while(!inp.eof())
        {
            inp>>fn>>fv;
            if(tm==fn)
                continue;
            if(fn=="total_weight_gain_or_lose_in_gm:")
                {
                    gr.data[cnt]=fv;
                   // cout<<gr.data[cnt]<<endl;
                    cnt++;
                }
            fn=tm;

        }
        inp.close();
       // gr.show();
        return gr;

    }*/

    int auto_update()
    {
        string nm,tm,ps,fn,hg,wt;
        int cnt,i;
        double nwgt,wgt=0,fv,nbmi,bmi,hv,wv;
        nm=login();
       // cout<<nm;
        //cout<<name;
        cnt=file_read();
        //cout<<cnt;
        //graph gr;
        //gr=semi_main(cnt);
        graph gr(cnt);
        //string ps,fn,tm;
        //double fv;
        int loop=0;
        ifstream inp(name);
        inp>>ps;
        while(!inp.eof())
        {
            inp>>fn>>fv;
            if(tm==fn)
                continue;
            if(fn=="total_weight_gain_or_lose_in_gm:")
                {
                    gr.data[loop]=fv;
                   // cout<<gr.data[cnt]<<endl;
                    loop++;
                }
            fn=tm;

        }
        inp.close();
        gr.show();
      //  cout<<gr.data[0];
        //lambda
        auto update=[&,nm,cnt,gr]()->int
        {   // cout<<nm;
            for(i=0;i<cnt;i++)
            {
               wgt=wgt+gr.data[i];
            }
            //cout<<wgt<<endl;
            //cout<<nm;
            double bmi;
            ofstream out;
            out.open("temp.txt");
            ifstream inp;
            inp.open(name);
            inp>>ps>>hg>>hv>>wt>>wv;
            //out<<ps<<endl<<hg<<" "<<hv<<endl<<wt<<" "<<wv;
            nwgt=((wv*1000)+wgt)/1000;
            cout<<"\n\nUpdated weight: "<<nwgt;

            nbmi=(nwgt)/(hv*hv);
            cout<<"\n\nUpdated BMI :"<<nbmi<<"\n";
            inp.close();
            inp.open(name);
            inp>>ps;
            out<<ps<<endl;
            while(!inp.eof())
            {
                inp>>fn>>fv;
                if(fn==tm)
                    continue;
                if(fn=="WEIGHT_in_kg:")
                {
                    fv=nwgt;
                    //cout<<"asdasdasdaddddddddddd";
                }
                if(fn=="BMI:")
                    fv=nbmi;
                out<<fn<<" "<<fv<<endl;
                tm=fn;

            }
            inp.close();
            out.close();
            out.open(nm);
            inp.open("temp.txt");
            inp>>ps;
            out<<ps<<endl;
            while(!inp.eof())
            {
                inp>>fn>>fv;
                if(fn==tm)
                    continue;
                out<<fn<<" "<<fv<<endl;
                tm=fn;

            }

        };

update();
    }
}
