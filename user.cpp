#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include "owner.cpp"

using namespace std;

class userfun
{
public:

    char add(product pro,char uname[50]);
};
char userfun::add(product pro,char uname[50])
{
    char filename;
	fstream file;
    file.open(uname,ios::in|ios::out|ios::app);
    file.write((char *)&pro,sizeof(pro));
    file.close();
}
int prolist(char uname[50])
{
    fstream file;
    product produc;
    string lc;
    stringstream sc;
    file.open(uname,ios::in);
    int count=1,len=9;
	cout<<endl<<"\t\t";
	cout<<endl<<"\t\t** RECORDS **";
	cout<<endl<<"\t\t\n";
	cout<<"\n| Sr.No. |    Product Name    |";
	while(file.read((char*)&produc,sizeof(produc)))
	{
	    sc<<count;
	    lc=sc.str();
	    char* clc=(char *)lc.c_str();
	    cout<<"\n| "<<count<<setw(len-strlen(clc));
        cout<<"| "<<produc.getName()<<setw(20-strlen(produc.getName()));
        cout<<"|";
        count++;
        len++;
    }
	fp.close();
	if(count==0)
        cout<<"\n\t!!! No Records Found !!!";
    
    return count;
}
product getdetail(int ch)
{
    fstream file;
    product produc;
    file.open("prolist.dat",ios::in);
    int loc=(ch-1)*sizeof(produc);
    file.seekg(loc,ios::beg);
    file.read((char *)&produc,sizeof(produc));
    produc.show_product();
    return produc;
    file.close();
}

char display(char uname[50])
{
    int flag=0;
    fstream file;
    file.open(uname,ios::in);
    product pro;
    while(file.read((char *)&pro,sizeof(pro)))
    {
        pro.show_product();
        flag=1;
    }
    if(flag==0)
        cout<<"\n\t!!! No Favourites !!!";
}

void checkout(char uname[50])
{
	fstream file;
	product pro;
	float sum=0;
	file.open(uname,ios::in);
	while(file.read((char *)&pro,sizeof(pro)))
	{
		sum=sum+pro.getsp();
	}
	cout<<"\n\t Cart Value = Rs."<<sum<<"/-";
	if(sum>=3000)
	{
		cout<<"\n\t\t!!! You got a discount !!!";
		cout<<"\n\t Discount = Rs."<<(sum*0.05)<<"/-";
		sum=sum-(sum*0.05);
		cout<<"\n\t Total Bill = Rs."<<sum<<"/-";
	}
	file.close();
}
char user(char uname[35])
{
    int option,ch,count;
    product produc;
    userfun fun;
    char temp[35],fav[50],cart[50],uname1[35];
    strcpy(uname1,uname);
    strcpy(temp,uname);
    strcat(uname,"fav.dat");
    strcpy(fav,uname);
    strcat(temp,"cart.dat");
    strcpy(cart,temp);
    do
    {
    	goto lab;
    	label:
			count=prolist("prolist.dat");
    		cout<<"\nEnter choice:";
    		cin>>ch;
    		if(ch>=count)
    		{
    			cout<<"\n\t!!! No Records Found !!!";
    			goto label;
			}
    		produc=getdetail(ch);
    	lab:
		cout<<"\n-----------------------------------\n";
    	getch();
    	system("cls");
        cout<<"\n\t\t!!! MENU !!!";
        cout<<"\n\t1. Product List";
        cout<<"\n\t2. Add to Favourite";
		cout<<"\n\t3. Display Favourite";
		cout<<"\n\t4. Delete Favourite";
        cout<<"\n\t5. Add to Cart";
		cout<<"\n\t6. Display Cart";
		cout<<"\n\t7. Delete from Cart";
        cout<<"\n\t8. Checkout";
        cout<<"\n\t9. Logout";
        cout<<"\nEnter choice:";
        cin>>option;
    	cout<<"\n-----------------------------------\n";
        switch(option)
        {
            case 1:
    				goto label;
    				break;
    		case 2:		
                    fun.add(produc,fav);
                    break;
            case 3:
                    prolist(fav);
                    break;
            case 4:
            		delete_product(fav);
            		break;
            case 5:
            		fun.add(produc,cart);
            		break;
            case 6:
            		show_all_product(cart);
            		break;
			case 7:
					delete_product(cart);
					break;
			case 8:
					checkout(cart);
					break;
			case 9:
                    cout<<"\n\n\t\tLogining Out...";
                	Sleep(1000);
                	system("cls");
					break;
					
			default:
               		cout<<"\n\t !!! Enter valid choice !!!\n";
                	getch();
                    user(uname1);
					break;

        }
    }while(option<9);
}
