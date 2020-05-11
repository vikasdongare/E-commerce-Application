#include<iostream>
#include "register.cpp"
#include "signin.cpp"
using namespace std;

int main()
{
	int ch;
	do
	{
		system("cls");
		cout<<"\n1.Register as a user\n2.Sign in as a owner\n3.Sign in as a user\n4.Forgot Credentials\n5.Exit\nEnter choice:";
		cin>>ch;
		cout<<"\n-----------------------------------\n";
		switch(ch)
		{
			case 1:
				writedata(2);
				break;
			case 2:
				signin(1);
				getch();
				break;
			case 3:
				signin(2);
				getch();
				break;
			case 4:
			    cout<<"\nPress: 1.Owner  2.User\nEnter:";
			    cin>>ch;
				forgotuser(ch);
				break;
            case 5:
                exit(0);
			default:
				cout<<"\n\t!!! Enter valid choice !!!";
		}
		cout<<"\n-----------------------------------\n";
	}while(ch<5);
	
}
