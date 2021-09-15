#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void register1();
void login();

int main()
{
    int choice;
    cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	cout<<"\n\t\t\tTO CREATE AN NEW ACCOUNT\t";
	cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	cout<<endl;
    cout<<"1. REGISTER "<<endl;
    cout<<"2. LOGIN"<<endl;
    cout<<"ENTER YOUR CHOICE: "<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
            register1();
            break;
        case 2:
            login();
            break;
        case 4:
            cout<<"THANKS FOR USING LOGIN PAGE"<<endl;
            break;

        default:
            cout<<"SORRY, YOU HAVE SELECTED WRONG OPTION"<<endl;
            main();
    }

}

void register1()
{
        string regUser,regPass,regPass2,account_number;
        char type;
        char actype[10];
        float accountBalance;

        system("cls");
        cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
        cout<<"\n\t\t\tREGISTRATION FORM\t";
        cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
        cout<<"\nENTER YOUR USERNAME :";
        cin>>regUser;
        cout<<"\nENTER YOUR ACCOUNT NUMBER :";
        cin>>account_number;
        password:
        cout<<"\nENTER 6-DIGIT PIN:";
        cin>>regPass;
        cout<<"\nRE-ENTER 6-DIGIT PIN:";
        cin>>regPass2;

        if(regPass != regPass2){
            cout<<"\nPASSWORD NOT MATCHING";
            cout<<"\nENTER AGAIN";
            goto password;
        }

        cout<<"\nENTER TYPE OF ACCOUNT.\n(C FOR CURRENT & S FOR SAVING"<<endl;
        cin>>type;
        type=toupper(type);

        cout<<"\nENTER THE INITIAL AMMOUNT: ";
        again:
        cout<<"\n>=500 FOR SAVING & >=1000 FOR CURRENT"<<endl;
        cin>>accountBalance;

        if(accountBalance<500 && type=='S' || accountBalance<1000 && type=='C'){
            cout<<"INSUFFICIENT BALANCE"<<endl;
            cout<<"RE-ENTER INITIAL AMMOUNT"<<endl;
            goto again;
        }



        ofstream reg("database.txt",ios::app);
        reg<<regUser<<' '<<regPass<<' '<<account_number<<endl;
        system("cls");
        cout<<"\nREGISTRATION SUCCESSFULL\n";
        main();
}

void login()
{
        int count;
        string username,pin_code,u,p;
        system("cls");
        cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
        cout<<"\n\t\t\tLOGIN FORM\t";
        cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
        cout<<"\nUSERNAME :";
        cin>>username;
        cout<<"PIN CODE :";
        cin>>pin_code;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==username && p==pin_code)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHELLO "<<username<<"\nLOGIN SUCESS.\nTHANKS FOR LOG IN\n";
                cin.get();
                cin.get();
                main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPLEASE CHECK YOUR USERNAME AND PASSWORD\n";
                main();
        }
}


















