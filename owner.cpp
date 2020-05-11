#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>
#include<windows.h>

using namespace std;

class product
{
	int pro_id;
	char product_name[50];
	float mrp,product_quantity,tax,d,sp;

	public:

	void create_product()
	{
		cout<<endl<<" Enter The Product Number: ";
		cin>>pro_id;
		cout<<" Enter The Name of The Product: ";
		cin.ignore();
		cin.getline(product_name ,50);
		cout<<" Enter The Price of The Product: ";
		cin>>mrp;
		cout<<" Enter The Discount (%): ";
		cin>>d;
                           sp=mrp-(mrp*(d/100));
	}

	void show_product()
	{
		cout<<endl<<"Product Id: "<<pro_id;
		cout<<endl<<"Product Name: "<<product_name;
		cout<<endl<<"MRP: "<<mrp;
		cout<<endl<<"Discount : "<<d;
        cout<<endl<<"Selling Price: "<<sp;
	}

    void table_product()
    {
        string lid,lmrp,ld,lsp;
        stringstream sid,smrp,sd,ssp;
        sid<<pro_id;
        lid=sid.str();
        char* clid=(char*)lid.c_str();
        smrp<<mrp;
        lmrp=smrp.str();
        char* cmrp=(char*)lmrp.c_str();
        sd<<d;
        ld=sd.str();
        char* cd=(char*)ld.c_str();
        ssp<<sp;
        lsp=ssp.str();
        char* csp=(char*)lsp.c_str();
        cout<<"\n| "<<pro_id<<setw(13-strlen(clid));
        cout<<"| "<<product_name<<setw(21-strlen(product_name));
        cout<<"| "<<mrp<<setw(9-strlen(cmrp));
        cout<<"| "<<d<<setw(13-strlen(cd));
        cout<<"| "<<sp<<setw(22-strlen(csp))<<"|";
    }
	int getProduct()
	{
		return pro_id;
	}

	float getPrice()
	{
		return mrp;
	}

	char* getName()
	{
		return product_name;
	}

	float getDiscount()
	{
		return d;
	}
	
	float getsp()
	{
		return sp;
	}
};



fstream fp;
product produc;

void save_product()
{
	fp.open("prolist.dat",ios::out|ios::app);
	produc.create_product();
	fp.write((char*)&produc,sizeof(product));
	fp.close();
	cout<<endl<<endl<<"The Product Has Been Sucessfully Created...";
	Sleep(1000);
}

void show_all_product(char *filename)
{
	int count=0;
	cout<<endl<<"\t\t";
	cout<<endl<<"\t\t** RECORDS **";
	cout<<endl<<"\t\t\n";
	fp.open(filename,ios::in);
	cout<<"\n| Product Id |    Product Name    |   MRP  |  Discount  |  Selling Price(Rs.)  |";
	while(fp.read((char*)&produc,sizeof(product)))
	{
	    count++;
		produc.table_product();
	}

		Sleep(1000);
	fp.close();
	if(count==0)
        cout<<"\n\t!!! No Records Found !!!";
}


void edit_product()
{
	int num,count=0;
	cout<<endl<<endl<<"\t Enter The Product Id: ";
	cin>>num;

	fp.open("prolist.dat",ios::in|ios::out);
	while(fp.read((char*)&produc,sizeof(product)))
	{
		if(produc.getProduct()==num)
		{
			produc.show_product();
			cout<<"\n Enter The New Details of Product: "<<endl;
			produc.create_product();
			int pos=-1*sizeof(produc);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&produc,sizeof(product));
			cout<<endl<<endl<<"\t !!! Record Successfully Updated !!!";
			count++;
		}
	}
	fp.close();
	if(count==0)
		cout<<"\n\t\t!!! No Record Found !!!";
	Sleep(1000);
}

void delete_product(char uname[50])
{
	int num,count=0;
	cout<<endl<<endl<<" Enter The product Id: ";
	cin>>num;
	fp.open(uname,ios::in|ios::out);
	while(fp.read((char*)&produc,sizeof(product)))
	{
		if(produc.getProduct()!=num)
		{
            fstream fp2;
            fp2.open("Temp.dat",ios::out);
            fp.seekg(0,ios::beg);
            while(fp.read((char*)&produc,sizeof(product)))
            {
                if(produc.getProduct()!=num)
                {
                    fp2.write((char*)&produc,sizeof(product));
                }
            }
            fp2.close();
            fp.close();
            remove(uname);
            rename("Temp.dat",uname);
            cout<<endl<<endl<<"\t !!! Record Deleted !!!";
            getchar();
            count++;
		}
	}
	if(count==0)
        cout<<"\n\t!!! No Record Found !!!";
}

void product_menu()
{
	fp.open("prolist.dat",ios::in);

	cout<<endl<<endl<<"\t\tProduct MENU\n\n";
	cout<<"\n";
	cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	cout<<"\n";
	while(fp.read((char*)&produc,sizeof(product)))
	{
		cout<<produc.getProduct()<<"\t\t"<<produc.getName()<<"\t\t"<<produc.getPrice()<<endl;
	}
	fp.close();
}


void owner()
{

	int option;
    do
    {
	system("cls");
	cout<<"\t";
	cout<<"\n\t1. Create Product";
	cout<<"\n\t2. Display All Products";
	cout<<"\n\t3. Modify Product";
	cout<<"\n\t4. Delete Product";
	cout<<"\n\t5. Logout";
	cout<<"\n\t";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1:
                system("cls");
				save_product();
				break;

		case 2:
                system("cls");
                show_all_product("prolist.dat");
                cout<<"\n";
                getch();
				break;

		case 3:
                system("cls");
                edit_product();
                break;

		case 4:
                system("cls");
                delete_product("prolist.dat");
		        break;

		case 5:
                cout<<"\n\n\t\tLogining Out...";
                Sleep(1000);
                system("cls");
				break;

		default:
                cout<<"\n\t !!! Enter valid choice !!!\n";
                getch();
                owner();
	}
    }while(option<5);
}
