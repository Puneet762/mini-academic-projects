#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
fstream cart;

class items
{
    int f;
    string y[20];
    fstream file;
    static int i;
public:
    items(string);
    void options(string);
};

int items::i=0;

void again(string u)
{   char x;

cout<<"\n";
for(int k=0;k<50;k++)
    cout<<"**";

    cout<<"\nDo you want to buy other items?\n\n";
    cout<<"Yes(y)\tOr\tNo(n)";
    cin>>x;

cout<<"\n";
for(int k=0;k<50;k++)
    cout<<"**";

    if(x=='y')
        items a(u);
    else
    {
        return;
    }
}

void items::options(string user)
{   int x;
    string username=user;
    cout<<"\n\n1.Add to cart\t\t2.Never Mind\n";
    cin>>x;
    if(x==1)
    {
        int p=0;
        cout<<"\nAdding to cart";
        for( int j=0;j<15;j++){
	     Sleep(50);
	     cout<<".";
         }
          ofstream writefile;
    string file = username+".txt";
    writefile.open(file.c_str(),ios::app);

        cout<<"\n\n";
    while(p<=i)
        {
         writefile<<y[p]<<"  ";
         p++;
        }
        writefile<<endl;
    writefile.close();
    i=0;
    }
    if(x==2)
    {  i=0;
       return;
    }

}
void delete_line(const char* x,int n)
{
    ifstream is(x);

    ofstream ofs;
    ofs.open("temp.txt",ofstream::out);

    char c;
    int line_no=1;
    while(is.get(c))
    {
        if(c=='\n')
            line_no++;
        if(line_no!=n)
            ofs<< c;
    }
    ofs.close();
    is.close();
    remove(x);
    rename("temp.txt",x);
}
void view_cart(string& u)
{ string name=u+".txt";
        ifstream x(name.c_str());
                char c;
                int j=2;
                cout<<"1.";
                while(x.get(c))
                {
                    cout<<c;
                    if(c=='\n')
                       {cout<<j<<".";
                        j++;
                       }
                }
                cout<<"\nDo you want to buy(y/n)?";
                char a;
                cin>>a;
                if(a=='y')
                {cout<<"\nEnter the number for buying:";
                cin>>j;
                delete_line(name.c_str(),j-1);
                cout<<"\n\nItem Successfully Bought..";
                again(u);
                }
                else
                    again(u);
}
items::items(string user)
{
            string u=user;
            string filename ="new_file.txt";
            string word;
            file.open("new_file.txt",ios::in);
            cout<<"\n\n\n\t\t\tEnter the item you want to buy:\n"
            <<"\t\t\t1.SmartPhones\n\t\t\t2.TV\n\t\t\t3.Washing Machine\n\t\t\t4.Laptops\n\t\t\t5.View Cart\n\t\t\t6.Exit\n";
            cin>>f;

            switch(f)
            {
            case 1:
                while(file>>word)
                {
                    if(word=="SmartPhone:")
                    {
                        y[i]=word;
                        cout<<word;
                        i++;
                        while(file>>word)
                        {if(word=="TV:"||word=="Washing"||word=="Laptop:"||file.eof())
                        break;
                        cout<<word<<"  ";
                        y[i]=word;
                        i++;
                        }
                        if(word=="TV:"||word=="Washing"||word=="Laptop:")
                            {options(u);
                            }
                         if(file.eof())
                            {
                            file>>y[i];
                            cout<<y[i];
                            options(u);
                            }
                    }

                }
                cout<<"\nNo more SmartPhones!";
                again(u);
                break;
            case 2:
                while(file>>word)
                {
                    if(word=="TV:")
                    {
                        y[i]=word;
                        cout<<word;
                        i++;
                        while(file>>word)
                        {if(word=="SmartPhone:"||word=="Washing"||word=="Laptop:"||file.eof())
                         break;
                         cout<<word<<"  ";
                         y[i]=word;
                         i++;
                        }
                        if(word=="SmartPhone:"||word=="Washing"||word=="Laptop:")
                            {options(u);
                            }
                        if(file.eof())
                        {
                            file>>y[i];
                            cout<<y[i];
                            options(u);
                        }
                    }
                }
                cout<<"\nNo more TVs!";
                again(u);
                break;
            case 3:
                while(file>>word)
                {
                    if(word=="Washing")
                    {
                        y[i]=word;
                        cout<<word;
                        i++;
                        while(file>>word)
                        {if(word=="TV:"||word=="SmartPhone"||word=="Laptop:"||file.eof())
                        break;
                        cout<<word<<"  ";
                        y[i]=word;
                        i++;
                        }
                        if(word=="TV:"||word=="SmartPhone"||word=="Laptop:")
                        {options(u);
                        }
                        if(file.eof())
                        {
                            file>>word;
                            cout<<word;
                            y[i]=word;
                            options(u);
                        }
                    }
                }
                cout<<"\nNo more Washing Machines!";
                again(u);
                break;
            case 4:
                while(file>>word)
                {
                    if(word=="Laptop:")
                    {
                        y[i]=word;
                        cout<<word;
                        i++;
                        while(file>>word)
                        {if(word=="TV:"||word=="Washing"||word=="SmartPhone:"||file.eof())
                        break;
                        cout<<word<<"  ";
                        y[i]=word;
                        i++;
                        }
                        if(word=="TV:"||word=="Washing"||word=="SmartPhone:")
                        {options(u);
                        }

                    if(file.eof())
                        {
                            i++;
                            file>>y[i];
                            cout<<y[i];
                            options(u);
                        }
                    }
                }
                cout<<"\nNo more Laptops!";
                again(u);
                break;
            case 5:
                view_cart(u);
                break;
            case 6:
                exit(0);
            }
}
