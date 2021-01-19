#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
//#include<direct.h>
using namespace std;
ofstream new_file;
void printstar(char ch , int n)
{
for(int i=1;i<=n;i++)
{
cout<< ch;
}
cout<<"\n";

}

class smart_phone
{
    string name_keyfeat;
    int price;
    int weight;
    int ram;
    int storage;
    int battery;
    string cam;
public:
    void enter_specs(void);

};
void smart_phone::enter_specs(void)
{

        cout<<"\n\nEnter model name\t";
        cin>>name_keyfeat;
        cout<<"Enter RAM and external storage(in GB)\t";
        cin>>ram>>storage;
        cout<<"Enter weight(in g)\t";
        cin>>weight;
        cout<<"Enter battery backup(in mAh)";
        cin>>battery;
        cout<<"Enter camera specifications\t";
        cin>>cam;
        cout<<"Enter price\t";
        cin>>price;
        new_file<<"\nSmartPhone: "<<name_keyfeat
        <<"\nRAM: "<<ram<<"\nStorage: "<<storage<<"\nWeight: "<<weight
        <<"\nCamera: "<<cam<<"\nBattery: "<<battery<<"\nPrice: "<<price;
}
class tv
{
   string name;
   int display;
   int price;
   public:
   void enter_specs(void)
   {
       cout<<"\n\nEnter model name";
       cin>>name;
       cout<<"Enter display(in inches)\t";
       cin>>display;
       cout<<"Enter price\t";
       cin>>price;
       new_file<<"\nTV: "<<name<<"\nDisplay(in inches): "<<display<<"\nPrice: "<<price;
   }
};
class wm
{
    string name;
    int price;

public:
    void enter_specs(void)
    {
        cout<<"\nEnter model name and features\t";
        cin>>name;
        cout<<"\nEnter Price";
        cin>>price;
        new_file<<"\nWashing Machine: "<<name<<"\nPrice: "<<price;
    }
};
class pc
{
    string name;
    int price;
    string storage;
    string operating_sys;
    string graphics;
    int display;
public:
    void enter_specs(void)
    {
        cout<<"\nEnter model name:"<<setw(30);
        cin>>name;
        cout<<"\nEnter storage:"<<setw(30);
        cin>>storage;
        cout<<"\nEnter operating system:"<<setw(30);
        cin>>operating_sys;
        cout<<"\nEnter graphics:"<<setw(30);
        cin>>graphics;
        cout<<"\nEnter display(in inches):"<<setw(30);
        cin>>display;
        cout<<"\nEnter price:"<<setw(30);
        cin>>price;
        new_file<<"\nLaptop: "<<name<<"\nStorage: "<<storage
        <<"\nOperating system: "<<operating_sys<<"\nGraphics: "<<graphics
        <<"\nDisplay(in inches): "<<display<<"\nPrice: "<<price;
    }
};
class elec
{    int y;
    //This class includes various types of electronic items//
public:
    elec(void);
};
elec::elec(void)
{
    printstar('%',90);
    printstar('%',90);
cout<<"\n\n\n\t\t\tWhich item you want to sell?\n"
    <<"\t\t\t1.SmartPhones\n\t\t\t2.TV\n\t\t\t3.Washing Machine\n\t\t\t4.Laptops\n\t\t\t5.Exit\n";
cin>>y;
if(y==1)
{
    smart_phone s1;
    s1.enter_specs();
}
else if(y==2)
{
    tv s2;
    s2.enter_specs();
}
else if(y==3)
{
    wm s3;
    s3.enter_specs();
}
else if(y==4)
{
    pc s4;
    s4.enter_specs();
}
else
    return;
}
