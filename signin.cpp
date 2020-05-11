#include<iostream>
#include "user.cpp"
using namespace std;

void signin(int ch)
{
	fstream file;
	login l,s;
	int ch1;
	int flag=0;
	if(ch==1)
		file.open("dataowner.dat",ios::in|ios::binary);
	if(ch==2)
		file.open("datauser.dat",ios::in|ios::binary);
	login1:s.loginc();
	file.seekg(0,ios::beg);
	while(file.read((char *)&l,sizeof(l)))
	{
		if(strcmp(l.getuname(),s.getuname())==0)
		{
			if(strcmp(l.getpassword(),s.getpassword())==0)
			{
                cout<<"\n\t!!! Login Succesfully !!!";
                if(ch==1)
                    owner();
                else if(ch==2)
                    user(l.getname());
				flag=1;
			}
			else
			{
				c:cout<<"\n\t1.Enter details again\t2.Forgot username or password\n\tEnter choice:";
				cin>>ch1;
				switch(ch1)
				{
					case 1:
						goto login1;
						break;
					case 2:
						forgot(ch);
						goto login1;
						break;
					default:
						cout<<"\nInvalid choice";
						goto c;
				}
			}
		}
	}
	if(flag==0)
		cout<<"\n!!! No record found !!!";
}
void forgot(int ch)
{
			int flag=0,i=0;
			char uname[30];
			fstream file;
			login l,n;
			if(ch==1)
				file.open("dataowner.dat",ios::in|ios::out|ios::binary);
			if(ch==2)
				file.open("datauser.dat",ios::in|ios::out|ios::binary);
			cout<<"\nEnter username or email: ";
			//if(i>0)
				cin.ignore();
			cin.getline(uname,30);
			i++;
			while(file.read((char *)&l,sizeof(l)))
			{
				if(strcmp(l.getuname(),uname)==0 || strcmp(l.getemail(),uname)==0)
				{
					cout<<"\nEnter new details:";
					n.set(ch);
					int pos=-1*sizeof(l);
					file.seekp(pos,ios::cur);
					file.write((char *)&n,sizeof(n));
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\n!!! No records found !!!";
			}
}
void forgotuser(int ch)
{
        int flag=0,i=0,ch1;
		char uname[30],email[30];
		fstream file;
		login l,n;
        if(ch==1)
			file.open("dataowner.dat",ios::in|ios::out|ios::binary);
		if(ch==2)
			file.open("datauser.dat",ios::in|ios::out|ios::binary);
		cout<<"\nReset using : 1.Username 2.E-Mail\nEnter:";
		cin>>ch1;
		if(ch1==1)
        {
			cout<<"\nEnter username: ";
			cin>>uname;
			while(file.read((char *)&l,sizeof(l)))
			{
				if(strcmp(l.getuname(),uname)==0)
				{
					cout<<"\nEnter new details:";
					n.set(ch);
					int pos=-1*sizeof(l);
					file.seekp(pos,ios::cur);
					file.write((char *)&n,sizeof(n));
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\n!!! No records found !!!";
			}
        }
    if(ch1==2)
        {
			cout<<"\nEnter E-Mail: ";
			cin>>email;
			while(file.read((char *)&l,sizeof(l)))
			{
				if(strcmp(l.getemail(),email)==0)
				{
					cout<<"\nEnter new details:";
					n.set(ch);
					int pos=-1*sizeof(l);
					file.seekp(pos,ios::cur);
					file.write((char *)&n,sizeof(n));
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\n!!! No records found !!!";
			}
        }
}
