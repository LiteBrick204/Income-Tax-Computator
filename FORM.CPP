#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
//The code for IT filling form
//It's a lot of content!!
//#HYPE!

class form{
char name[30],dob[12],email[50],add[100],user[30],pass[10],PAN[10],phno[10];
public:
void get();
void put();
void modify();
int checkuser(char ss[30]) //Function to verify user; Accessor fn
{
   return strcmp(user,ss);
}
int givepan(char pan[10]){ return strcmp(PAN,pan); }
int checkkey(char k[10]){ return strcmp(pass,k); }
}k;
void form::get() //Fn which gets IT Form info
{
    int i; char a;
    cout<<"\nEnter Your Name:"; gets(name);
    cout<<"\nEnter Your Date Of Birth in mm/dd/yyyy format:"; gets(dob);
    cout<<"\nEnter Your Residential address:"; gets(add);
    cout<<"\nEnter Your Phone Number:"; gets(phno);
    cout<<"\nEnter Your E-Mail ID:"; gets(email);
    cout<<"\nEnter Your PAN Number(This cannot be modified):"; gets(PAN);
    cout<<"\nEnter Your Username which you are going to use(This cannot be modified):"; gets(user);
    cout<<"\nEnter Your Password(Maximum 10 characters only):";
    for(i=0;;)
    {
       a=getch();
       if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0'&& a<='9'))
       {
	    pass[i]=a;
	    i++;
	    cout<<"*";
       }
       if(a=='\b' && i>=1)
       {
	  cout<<"\b \b";
	  i--;
       }
       if(a=='\r' || i>10) { break; }
    }
    pass[i]='\0';
}
void form::put() //fn which prints user info
{
   cout<<"\nName:"<<name;
   cout<<"\nDOB:"<<dob;
   cout<<"\nResidential Address:"<<add;
   cout<<"\nPAN Number:"<<PAN;
   cout<<"\nPhone Number:"<<phno;
   cout<<"\nE-Mail ID:"<<email;
   cout<<"\nUserName:"<<user;
   cout<<"\nPassword:"<<pass;
}
void form::modify() // fn which is used to modify user content
{
   put();
   char Name[30],DOB[12],Email[50],adD[100],Pass[10],Phno[10];
   cout<<"\nEnter New Name(Enter '.' to retain old name):"; gets(Name);
   cout<<"\nEnter New DOB(Enter '$'to retain old DOB):"; gets(DOB);
   cout<<"\nEnter New Phone Number(Enter '0'to retain old Phone Number):"; gets(Phno);
   cout<<"\nEnter New E-Mail ID(Enter 'a' to retain old email id):"; gets(Email);
   cout<<"\nEnter New Address(Enter '*' to retain old address):"; gets(adD);
   cout<<"\nEnter New Password(Enter '#' to retain old password:"; gets(Pass);
   if(strcmp(Name,".")!=0)
   strcpy(name,Name);
   if(strcmp(DOB,"$")!=0)
   strcpy(dob,DOB);
   if(strcmp(Phno,"0")!=0)
   strcpy(phno,Phno);
   if(strcmp(Email,"a")!=0)
   strcpy(email,Email);
   if(strcmp(adD,"*")!=0)
   strcpy(add,adD);
   if(strcmp(Pass,"#")!=0)
   strcpy(pass,Pass);
   cout<<"\nYour Account Info has been modified!!";
}
void getinfo() // Fn which gives info the login file
{
    fstream file("LOGIN.DAT",ios::app|ios::in|ios::binary);
    k.get();
    file.write((char *)&k,sizeof(k));
    file.close();
}
void changeinfo()  // fn which updates modified info to login file
{
  fstream file("LOGIN.DAT",ios::app|ios::in|ios::binary);
  char s[10]; char u[30],ch='f';
  long pos;
  cout<<"\nTo modify account info-\n"<<" Enter Your Username:";
  gets(u);
  cout<<"\n Also enter your PAN number:"; gets(s);
  while(!file.eof())
  {
     file.read((char *)&k, sizeof(k));
     if(k.checkuser(u)==0 && k.givepan(s)==0)
     {
	k.modify();
	pos=file.tellg();
	file.seekg(pos-sizeof(k),ios::cur);
	file.write((char *)&k, sizeof(k));
	ch='t'; break;
     }
  }
  if(ch=='f')
  cout<<"\nError 404:Wrong Input!! Account does not exist!!";
  file.seekg(0);
  file.close();
}
void putinfo() //fn which gets user info from login file
{
  char us[30],ps[10];
  fstream file("LOGIN.DAT",ios::app|ios::in|ios::binary);
  cout<<"\nEnter Your UserName:"; gets(us);
  cout<<"\nEnter Your Password:"; gets(ps);
  while(!file.eof())
  {
      file.read((char *)&k,sizeof(k));
      if(k.checkuser(us)==0 && k.checkkey(ps)==0)
      {
	 k.put();
	 break;
      }
  }
  file.close();
}
void delacc() //fn which removes user account from system
{
  char us[30],ps[10];
  char c='n',found='n';
  fstream file("LOGIN.DAT",ios::app|ios::in|ios::binary);
  ofstream f("TEMP.DAT",ios::binary);
  cout<<"\nEnter Your UserName:"; gets(us);
  cout<<"\nEnter Your Password:"; gets(ps);
  while(!file.eof())
  {
      file.read((char *)&k,sizeof(k));
      if(k.checkuser(us)==0 && k.checkkey(ps)==0)
      {
	  k.put();
	  found='t';
	  cout<<"\nAre You Sure You Want to Terminate Your Account(y/n):";
	  cin>>c;
	  break;
      }
      if(c=='n'||c=='N')
	  f.write((char *)&k,sizeof(k));
      else
      file.write((char *)&k,sizeof(k));
  }
  if(found=='f')
  cout<<"\nAccount With Given Credentials Does not Exist!!";
  file.close();
  f.close();
  remove("LOGIN.DAT");
  rename("TEMP.DAT","LOGIN.DAT");
}
void viewinfo() //fn which contains "About Project" tab
{
   clrscr();
   cout<<"\n\t\t\t  About the Software\n";
   cout<<"\t\t\t  ___________________________\n";
   cout<<"\n eAccountant is a free, easy-to-use, expense tracker and income tax computator.\n";
   delay(300);
   cout<<"\n\t\t\t Runs on Turbo C++ Version 4.0.\n";
   delay(300);
   cout<< "\n Today, it takes more brains and effort to make out the income tax form than it does to make the income";
   cout<<"\n\t\t\t\t\t  -Alfred E. Neuman";
   delay(300);
   cout<<"\nBut with eAccountant, it is easy to fill our form out!!";
   delay(300);
   cout<<"\n eAccountant approximates income tax for entered data!!";
   delay(300);
   cout<<"\n WARNING: It provides an estimate only following methods from IT dept website!!\n";
   delay(400);
   cout<<"\n\t\t\t  Information about EXPENSE MANAGER\n";
   cout<<"\t\t\t  ___________________________\n";
   delay(402);
   cout<<"\n Version:4.0.10135\n";
   delay(402);
   cout<<"\n Developed by: X.\n";
   delay(402);
   cout<<"Patch Notes:";
   delay(300);
   cout<<"\n\t - New option to view old expenses !";
   delay(300);
   cout<<" \n\t - New loading animations !";
   delay(300);
   cout<<"\n\t - New wishlist !";
   delay(300);
   cout<<"\n\t - Changed titles for expenses !";
   delay(300);
   cout<<"\n\t - Added interest rates for various banks !";
   delay(300);
   cout<<"\n\t\t and many under the hood fixes !!!";
   delay(402);
   cout<<"\n\n\t\t\t  Information about INCOME TAX COMPUTATOR\n";
   cout<<"\t\t\t  ___________________________\n";
   delay(402);
   cout<<"Version:5.2.10444\n";
   delay(402);
   cout<<"Developed by: X.\n";
   delay(402);
   cout<<"Patch Notes:\n";
   delay(402);
   cout<<"\t- New Rainbow GeNe Loading Animation!!"; delay(300);
   cout<<"\n\t- Option to view Declarations !!";     delay(300);
   cout<<"\n\t- New Information about schemes to invest for reducing tax available.";
   delay(300);
   cout<<"\n\t- Other Internal Changes for User-Friendly Interaction!!";
   delay(300);
   cout<<"\n\t- New File Terminator 1.0 to permanently delete your IT record!!";
   delay(300);
   cout<<"\n\n\t\t\t  Information about ACCOUNT SETTING\n";
   cout<<"\t\t\t  ___________________________\n";
   delay(402);
   cout<<"\n Version:0.10.10135\n";
   delay(402);
   cout<<"Patch Notes:";
   delay(300);
   cout<<"\n\t- New 'About the Software' tab";  delay(300);
   cout<<"\n\t- New Account Terminator to permanently delete your account!!";
   delay(300);
}
void account() //Account settings fn
{
   int x;  char g;
   clrscr();
   do{
   clrscr();
   delay(300);
   cout<<"\n\t\t\t  Welcome to Account Settings\n";
   cout<<"\t\t\t  ___________________________\n";
   delay(250);
   cout<<"\nEnter 1 to View Account Information\n";
   delay(250);
   cout<<"\nEnter 2 to Modify Account Information\n";
   delay(250);
   cout<<"\nEnter 3 to Terminate Your Account\n";
   delay(250);
   cout<<"\nEnter 4 to View Information About The Software\n";
   delay(250);
   cout<<"\nEnter 5 to Exit Account Settings\n";
   delay(250);
   cout<<"\nEnter Your Choice(1-5):"; cin>>x;
   switch(x)
   {
       case 1: putinfo();
	       break;
       case 2: changeinfo();
	       break;
       case 3: delacc();
	       break;
       case 4: viewinfo();
	       break;
       case 5: break;
   }
   cout<<"\nDo You Want to go to Account Settings again(y/n):"; cin>>g;
   clrscr();
   }while(g=='y'||g=='Y');
}
