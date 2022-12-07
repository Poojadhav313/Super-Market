#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class customer;
class admin
{
  public:
  int choice;
  int Pid, Pprice;
  string Pname;
  void auth();
  void display();
  void add();
  void modify();
  void del();
  

  int adminMain()
  {
    
    do
    {
      cout<<"\n\t\t\t\t---------------------------Menu---------------------------"<<endl;
      cout<<"\t\t\t\t1  Display Product Details"<<endl;
      cout<<"\t\t\t\t2  Add Product"<<endl;
      cout<<"\t\t\t\t3  Modify Product"<<endl;
      cout<<"\t\t\t\t4  Delete Product"<<endl;
      cout<<"\t\t\t\t5  Go back to Main menu"<<endl;
      cout<<"\t\t\t\tEnter the choice: ";
      cin>>choice;
      
      switch(choice)
      {
        case 1: 
          display();
          break;
        case 2:
          add(); 
          break;
        case 3:
          modify();
          break;
        case 4:
          del();
          break;
        case 5:
          return 0;
          break;
        default:
          cout<<"\t\t\t\tInvalid input.. "<<endl;
          system("cls");

      }
    }while(true);
  }
};

void admin::auth()
{
  string Aname;
  string Apass;

  cout<<"\t\t\t\tEnter Admin Name: ";
  cin.ignore();
  getline(cin, Aname);
  cout<<"\t\t\t\tEnter Admin Password: ";
  cin>>Apass;
  if(Aname=="admin" && Apass=="1234")
  {
  cout<<"\n\n\t\t\t\tWelcome "<<Aname<<endl;
  adminMain();
  }
  else
  {
    cout<<"\n\t\t\t\tIncorrect ID or Password!"<<endl;
  }
}

void admin:: display()
{
  fstream file;
  file.open("database.txt", ios::in);
  if(!file)
  {
    cout<<"\n\t\t\t\tFile Not Found!!";
  }
  else
  {
    file>>Pid>>Pname>>Pprice;
    cout<<"\n\n\n\n\t\t\t\tProduct Details.."<<endl;
    cout<<"\t\t\t\t------------------------------------------------\n";
    cout<<"\t\t\t\t"<<setw(12)<<"Product ID"<<setw(15)<<"Name"<<setw(8)<<"Price"<<endl;
    cout<<"\t\t\t\t------------------------------------------------\n";
    while(!file.eof())
    {
      cout<<"\t\t\t\t"<<setw(12)<<Pid<<setw(15)<<Pname<<setw(8)<<Pprice<<endl;
      file>>Pid>>Pname>>Pprice;
    }
    cout<<"\t\t\t\t------------------------------------------------\n\n";
    file.close();
  }
}

void admin::add()
{
  fstream file;
  cout<<"\t\t\t\tEnter Product ID: ";
  cin>>Pid;
  cout<<"\t\t\t\tEnter Product Name: ";
  cin.ignore();
  getline(cin,Pname);
  cout<<"\t\t\t\tEnter Product Price: ";
  cin>>Pprice;
  file.open("database.txt", ios::app);
  file<<Pid<<" "<<Pname<<" "<<Pprice<<endl;
  file.close();
  cout<<"\n\t\t\t\tProduct added succesfully"<<endl;
}

void admin::modify()
{
  int Pid0, Pprice0;
  string Pname0;
  int Pfind;
  cout<<"\t\t\t\tEnter Product ID to modify: ";
  cin>>Pfind;
  fstream file;
  fstream tempFile;
  file.open("database.txt", ios::in|ios::out);
  tempFile.open("temp.txt", ios::out);
  if(!file)
  {
    cout<<"\n\t\t\t\tFile not found!!"<<endl;
  }
  else
  {
    while(!file.eof())
    {
      file>>Pid>>Pname>>Pprice;
      if(Pfind==Pid)
      {
        cout<<"\t\t\t\tEnter Modified Product ID: ";
        cin>>Pid0;
        cout<<"\t\t\t\tEnter Modified Product Name: ";
        getline(cin,Pname0);
        cout<<"\t\t\t\tEnter Modified Product Price: ";
        cin>>Pprice0;
        tempFile<<Pid0<<" "<<Pname0<<" "<<Pprice0<<endl;
      }
      else
      {
        tempFile<<Pid<<" "<<Pname<<" "<<Pprice<<endl;
      }
    }
  }
  file.close();
  tempFile.close();
  remove("database.txt");
  rename("temp.txt", "database.txt");
  cout<<"\n\t\t\t\tProduct modified succesfully"<<endl;
}

void admin::del()
{
  int Pfind;
  fstream file;
  fstream tempFile;
  file.open("database.txt", ios::in|ios::out);
  tempFile.open("temp.txt", ios::out);
  cout<<"\t\t\t\tEnter Product ID to Delete: ";
  cin>>Pfind;
  
  if(!file)
  {
    cout<<"\n\t\t\t\tFile not found!!"<<endl;
  }
  else
  {
    while(!file.eof())
    {
      file>>Pid>>Pname>>Pprice;
      if(Pfind==Pid)
      {
        cout<<"\n\t\t\t\tProduct record deleted succesfully";
      }
      else
      {
        tempFile<<Pid<<" "<<Pname<<" "<<Pprice<<endl;
      }
    }
  }
  file.close();
  tempFile.close();
  remove("database.txt");
  rename("temp.txt", "database.txt");
}

class customer
{
  public:
  int choice;
  int Pid, Pprice, Pamount;
  string Pname;
  string Cname;
  string Cadd;
  char Phone[10];
  int customerMain();
  void display();
  void receipt();
};

int customer::customerMain()
{
  cout<<"\n\n\t\t\t\t---------------------------Menu---------------------------"<<endl;
  cout<<"\t\t\t\t1  Purchase"<<endl;
  cout<<"\t\t\t\t2  Go back to Main menu"<<endl;
  cout<<"\t\t\t\tEnter the choice: ";
  cin>>choice;
  switch(choice)
  {
    case 1:
      cout<<"\t\t\t\tEnter Name: ";
      cin.ignore();
      getline(cin,Cname);
      cout<<"\t\t\t\tEnter Address: ";
      getline(cin,Cadd);
      cout<<"\t\t\t\tEnter Phone no: ";
      cin>>Phone;
      display(); 
      receipt();
      break;
    case 2:
      return 0;
      break;
    default:
      cout<<"\t\t\t\tInvalid input.. "<<endl;
  }
}

void customer::display()
{
  fstream file;
  file.open("database.txt", ios::in);
  if(!file)
  {
    cout<<"\t\t\t\tFile Not Found!!";
  }
  else
  {
    file>>Pid>>Pname>>Pprice;
    cout<<"\n\n\n\n\t\t\t\tProduct Details.."<<endl;
    cout<<"\t\t\t\t------------------------------------------------\n";
    cout<<"\t\t\t\t"<<setw(12)<<"Product ID"<<setw(15)<<"Name"<<setw(8)<<"Price"<<endl;
    cout<<"\t\t\t\t------------------------------------------------\n";
    while(!file.eof())
    {
      cout<<"\t\t\t\t"<<setw(12)<<Pid<<setw(15)<<Pname<<setw(8)<<Pprice<<endl;
      file>>Pid>>Pname>>Pprice;
    }
    cout<<"\t\t\t\t------------------------------------------------\n\n";
    file.close();
  }
}

void customer::receipt()
{
  int ID[100],q[100];
  int x = 0;
  int total = 0;
  char ans;
  do
  {
    cout<<"\n\t\t\t\tEnter the Product ID you want to purchase: ";
    cin>>ID[x];
    cout<<"\t\t\t\tEnter quantity: ";
    cin>>q[x];
    cout<<"\t\t\t\tContinue to purchase? If yes enter 'y' else enter 'n': ";
    cin>>ans;
    x++;
  }while(ans=='y');

  system("cls");
  cout<<"\n\n\t\t\t\t------------------------RECEIPT------------------------"<<endl;
  cout<<"\t\t\t\tName - "<<Cname<<endl;
  cout<<"\t\t\t\tAddress - "<<Cadd<<endl;
  cout<<"\t\t\t\tPhone no - "<<Phone<<endl<<endl;
  cout<<"\n\t\t\t\t-------------------------------------------------------"<<endl;
  cout<<"\t\t\t\t"<<setw(12)<<"Product ID"<<setw(15)<<"Name"<<setw(8)<<"Price"<<setw(12)<<"Quantity"<<setw(10)<<"Amount"<<endl;
  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
  fstream file;
  
  for(int i=0; i<x; i++)
  {
    file.open("database.txt", ios::in);
    file>>Pid>>Pname>>Pprice;
    while(!file.eof()) 
    {
      if(ID[i]==Pid)
      {
         cout<<"\t\t\t\t"<<setw(12)<<Pid<<setw(15)<<Pname<<setw(8)<<Pprice<<setw(12)<<q[i]<<setw(10)<<Pprice*q[i]<<endl;
        total = total + Pprice*q[i];
      }
      file>>Pid>>Pname>>Pprice;
    }
    file.close();
  }
  cout<<"\n\t\t\t\t------Total = "<<total<<"------"<<endl;
  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
}

int main()
{
  admin a1;
  customer c1;
  int choice;
  do
  {
    cout<<"\n\n\t\t\t\t---------------------------Menu---------------------------"<<endl;
    cout<<"\t\t\t\t1  Admin"<<endl;
    cout<<"\t\t\t\t2  Customer"<<endl;
    cout<<"\t\t\t\t3  Exit"<<endl;
    cout<<"\t\t\t\tEnter the choice: ";
    cin>>choice;
    switch(choice)
  {
    case 1:
      a1.auth();
      break;
    case 2:
      c1.customerMain();
      break;
    case 3:
      exit(1);
      break;
    default:
      system("cls");
      cout<<"\t\t\t\tInvalid input... Try Again"<<endl;
      main();
  }
  } while(true);

  return 0;
}
