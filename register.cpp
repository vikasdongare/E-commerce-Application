#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int i=0;

void forgot(int ch);
class login
{
		char uname[35],name[30],password[10],a,email[30];
		int l;
	public:
	    login()
	    {
	        strcpy(uname," ");
	        strcpy(name," ");
	        strcpy(password," ");
	        strcpy(email," ");
	    }
		void set(int ch)
		{
		    i=0;
			cout<<"\nEnter Name: ";
			//if(i>0)
                cin.ignore();
			cin.getline(name,30);
			cout<<"Enter E-Mail: ";
			cin>>email;
			U:cout<<"Enter Username: ";
			cin>>uname;
			P:cout<<"Enter Password: ";
			for(int j=0;;)
			{
				a=getch();
				if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')||(a=='@'&&a=='#'))
				{
					password[j++]=a;
					cout<<"*";
				}
				if(a=='\b'&&j>=1)
				{
					cout<<"\b \b";
					--j;
				}
				if(a=='\r')
				{
					password[j]='\0';
					break;
				}
			}
			l=strlen(password);
			if(l>10 || l<4) {
				cout<<"\n\t!!! Length of Password must be between 4-10 characters !!! ";
				goto P;
			}
			if(strcmp(uname,password)==0) {
				cout<<"\n\t!!! Username and Password should not be same !!! ";
				goto U;
			}
			check(ch);
		}
		void display()
		{
			cout<<"\nName: "<<name;
			cout<<"\nE-Mail: "<<email;
			cout<<"\nUsername: "<<uname;
			cout<<"\nPassword: "<<password;
		}
		void check(int ch)
		{
			fstream file;
			login l;
			if(ch==1)
				file.open("dataowner.dat",ios::app|ios::binary);
			if(ch==2)
				file.open("datauser.dat",ios::app|ios::binary);
			while(file.read((char *)&l,sizeof(l)))
			{
				if(strcmp(l.getuname(),uname)==0)
				{
					cout<<"\n\t\t!!! Username already taken !!!";
					set(ch);
				}
				if(strcmp(l.getemail(),email)==0)
				{
					cout<<"\n\t\t!!! Telephone already taken !!!";
					set(ch);
				}
			}
			file.close();
		}
		void loginc()
		{
			cout<<"\n\t\t LOGIN";
			cout<<"\n\t-----------------------------";
			cout<<"\n\tEnter Username: ";
			cin>>uname;
			cout<<"\tEnter Password: ";
			for(int j=0;;)
			{
				a=getch();
				if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')||(a=='@'&&a=='#'))
				{
					password[j++]=a;
					cout<<"*";
				}
				if(a=='\b'&&j>=1)
				{
					cout<<"\b \b";
					--j;
				}
				if(a=='\r')
				{
					password[j]='\0';
					break;
				}
			}
			cout<<"\n\n\t\tLogining in...";
			Sleep(1000);
			system("cls");
		}

		char* getuname()
		{
		    return uname;
		}
		char* getpassword()
		{
		    return password;
		}
		char* getemail()
		{
		    return email;
		}
		char* getname()
		{
		    return name;
		}
};
void writedata(int ch)
{
	fstream file;
	login l;
	file.open("datauser.dat",ios::app|ios::binary);
	l.set(ch);
	file.write((char *)&l,sizeof(l));
	file.close();
}
