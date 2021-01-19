
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<fstream>
#include"MMSystem.h"
#include "sell.cpp"
#include "buy-1-1.cpp"
using namespace std;

void login();

void registr();

void forgot();

/*void printstar(char ch , int n)
{
for(int i=1;i<=n;i++)
{
cout<< ch;
}
cout<<"\n";

}
*/

COORD coord = {0, 0};
void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void scroll_note()	//welcome note
{
		system("color B0");
	int j,i,x,y;
	for(i=0;i<27;i++)
	{
		gotoxy(i,13);
		cout<<" ";
		cout<<"DTU E-COMMERCE SERVICE";
		Sleep(40);
	}

	for(j=67;j>50;j--)
	{
		gotoxy(j,13);
		cout<<"WELCOMES YOU";cout<<"            ";
		Sleep(40);
	}

	gotoxy(27,13);cout<<"DTU E-COMMERCE SERVICE";
	gotoxy(50,13);cout<<"WELCOMES YOU";
	int k=0;
	for(int j=78;j>=0&&k<=78;j--&&k++)
	{
		gotoxy(j,20);cout<<"|";
		gotoxy(k,4);cout<<"|";
		Sleep(30);
	}

	gotoxy(56,23);cout<<"PUNEET   2K18/IT/92";
	gotoxy(56,24);cout<<"MOHAK  2K18/IT/71";
	Sleep(2000);

}
;
char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}
class main1{

public:
    main1(){

    int choice;
        printstar('%',80);
        cout<<"\n";

        cout<<"                      Welcome to login page                               \n\n";

        cout<<"*******************        MENU        *******************************\n\n";

        cout<<"1.LOGIN"<<endl;

        cout<<"2.REGISTER"<<endl;

        cout<<"3.FORGOT PASSWORD (or) USERNAME"<<endl;

        cout<<"4.Exit"<<endl;

        cout<<"\nEnter your choice :";

        cin>>choice;

        cout<<endl;

        switch(choice)

        {

                case 1:

                        login();


                        break;

                case 2:

                        registr();

                        break;

                case 3:

                        forgot();

                        break;

                case 4:



                        cout<<"Thanks for using this program\nThis program is created by puneet\n\n";
                        exit(1);

                        break;

                default:

                        system("cls");

                        cout<<"You've made a mistake , give it a try again\n"<<endl;

                        main1();

        }


    }

};
bool is_empty(std::ifstream& pfile){
return pfile.peek()==std::ifstream::traits_type::eof();
}
int main()

{
   // PlaySound(TEXT("C:\\Users\\admin\\Desktop\\New folder\\music.wav"), NULL, SND_SYNC);
	//system("pause");
system("color B0");
char s[20];
strcpy(s,date_time());
cout<<s<<endl;

scroll_note();
cout<<endl<<endl;
/*cout<<"\n\t\t ========================================="<< endl;

cout<<"\t\t ========================================="<< endl;
//gotoxy(50,15);
cout<<"\t\t \t|| E-COMMERCE ||"<< endl;

cout<<"\t\t ========================================="<< endl;

cout<<"\t\t ========================================\n\n"<< endl;
*/
cout<<"Loading";
for(int i=0;i<15;i++){
	Sleep(50);
	cout<<".";
}
cin.get();
system("cls");
	cout<<endl;
//printstar('*',80);

main1 obj;
}
void login()

{
        int count;
        string user,pass,u,p;

        system("cls");

        cout<<"please enter the following details"<<endl;

        cout<<"USERNAME :";
        cin>>user;

        cout<<"PASSWORD :";
        cin>>pass;

        ifstream input("database.txt");

        while(input>>u>>p)

        {
                if(u==user && p==pass)

                {
                        count=1;

                        system("cls");
                }
        }
        input.close();
        if(count==1)

        {    int a;
             cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
               while(a!=5){

                cout<<"\n\nwhat u wanna do???\n1.sell\n2.buy\n3.show my cart\n4.Log out\n5.exit\n"<<endl;

                cin>>a;
                if(a==1){
                cout<<"sell items"<<endl;
                new_file.open("new_file.txt",ios::app);
    elec e;
      char x='y';
    do
    {
        for(int a=1;a<=20;a++)
        {
            cout<<"--";
        }
        cout<<"\nDo you want to sell another item?";
    cout<<"\nYes(y)\or\tNo(n)";

    cin>>x;
    if(x=='y')
        elec e2;
        else
        system("cls");
    }
    while(x=='y');
    new_file.close();
              //  cin.get();
                //cin.get();

                }
                else if(a==2)
                {

                 system("cls");
                    items i(user);
                }
                else if(a==3){

cout<<"item in ur cart"<<endl;
string name=user+".txt";
        ifstream x(name.c_str());
                char c;
                int j=2;

    if(is_empty(x)){
        cout<<"nothing to show"<<endl;
    }
    else{
                    while(x.get(c))
                {
                    cout<<c;
                    if(c=='\n')
                       {cout<<j<<".";
                        j++;
                       }
                }
    cout<<endl;
    }
    cout<<"\n\n";
}


                else if(a==4){
                        system("cls");
                    main1();
                }
                else if(a==5){
                    exit(1);
                }
                else
                    cout<<"wrong choice\n";
        }
        }
        else
        {
            cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main1();
        }

}
void registr()
{
        string reguser,regpass,ru,rp;

        system("cls");

        cout<<"Enter the username :";

        cin>>reguser;

        cout<<"\nEnter the password :";

        cin>>regpass;

        ofstream reg("database.txt",ios::app);

        reg<<reguser<<' '<<regpass<<endl;

        system("cls");

        cout<<"\nRegistration Sucessful\n";

        main1();
}
void forgot()

{

        int ch;

        system("cls");

        cout<<"Forgotten ? We're here for help\n";

        cout<<"1.Search your id by username"<<endl;

        cout<<"2.Search your id by password"<<endl;

        cout<<"3.Main menu"<<endl;

        cout<<"Enter your choice :";

        cin>>ch;

        switch(ch)

        {

                case 1:

                {

                        int count=0;

                        string searchuser,su,sp;

                        cout<<"\nEnter your remembered username :";

                        cin>>searchuser;



                        ifstream searchu("database.txt");

                        while(searchu>>su>>sp)

                        {

                                if(su==searchuser)

                                {

                                        count=1;

                                }

                        }

                        searchu.close();

                        if(count==1)

                        {

                                cout<<"\n\nHurray, account found\n";

                                cout<<"\nYour password is "<<sp;

                                cin.get();

                                cin.get();

                                system("cls");

                                main1();

                        }

                        else

                        {

                                cout<<"\nSorry, Your userID is not found in our database\n";

                                cout<<"\nPlease kindly contact your system administrator for more details \n";

                                cin.get();

                                cin.get();

                                main1();

                        }

                        break;

                }

                case 2:

                {

                        int count=0;

                        string searchpass,su2,sp2;

                        cout<<"\nEnter the remembered password :";

                        cin>>searchpass;

                        ifstream searchp("database.txt");

                        while(searchp>>su2>>sp2)

                        {

                                if(sp2==searchpass)

                                {

                                        count=1;

                                }

                        }

                        searchp.close();

                        if(count==1)

                        {

                                cout<<"\nYour password is found in the database \n";

                                cout<<"\nYour Id is : "<<su2;

                                cin.get();

                                cin.get();

                                system("cls");

                                main1();

                        }

                        else

                        {

                                cout<<"Sorry, We cannot found your password in our database \n";

                                cout<<"\nkindly contact your administrator for more information\n";

                                cin.get();

                                cin.get();

                                main1();
                    }

                        break;

                }

                case 3:

                {

                        cin.get();

                        main1();
                }

                default:

                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;

                        forgot();
        }

}
