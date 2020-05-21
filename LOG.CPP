#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include "FORM.CPP"
#include "IT.CPP"
#include "V0_4.CPP"
form X;
void loginmenu();
void box(int left, int top, int right, int bottom) // Function to draw outler box
{   char a=218,b=196,c=191,d=179,e=192,f=217;
    _setcursortype(0);
    gotoxy(left,top);
    cout<<a;
    for(int i=0; i<(right-left-1); i++)
    { cout<<b;  }
    cout<<c;
    for(i=1;i<(bottom-top); i++)
    {
	gotoxy(left,top+i);
	cout<<d;
	gotoxy(right,top+i);
	cout<<d;
    }
    gotoxy(left,bottom);
    cout<<e;
    for(i=0; i<(right-left-1); i++)
    { cout<<b; }
    cout<<f;
}
void login() //fn which handles login process
{
    int i;
    char t;
    _setcursortype(2);
    box(20,5,59,20);
    char l[10],k[10];
    fstream file("LOGIN.DAT",ios::app|ios::in|ios::binary);
    char name[10],pss[10];
    do{
    box(20,5,59,20);
    gotoxy(26,11); cout<<"UserName:"; gets(name);
    gotoxy(26,14); cout<<"Password:";
    for(i=0;;)
    {
       t=getch();
       if((t>='a' && t<='z') || (t>='A' && t<='Z') || (t>='0'&& t<='9'))
       {
	    pss[i]=t;
	    i++;
	    cout<<"*";
       }
       if(t=='\b' && i>=1)
       {
	  i--;
       }
       if(t=='\r' || i>10) { break; }
    }
    pss[i]='\0';
    while(!file.eof())
    {
       file.read((char *)&X,sizeof(X));
       if(X.checkuser(name)==0 && X.checkkey(pss)==0)
       {
	   clrscr();
	   gotoxy(0,0);
	   cout<<"\n\t\t\t\tWELCOME TO eAccountant!!";
	   delay(1500);
	   clrscr();
	   t='t';
	   break;
       }
    }
    file.close();
    if(t!='t')
    {
       clrscr();
       cout<<"\nINVALID";
       getch();
    }
    else if(t=='t')
      loginmenu();
    }while(t=='y' || t=='Y');
    }
void loginmenu() //fn which displays login menu
{
       clrscr();
       int y;
       char c;
       do{
       _setcursortype(0);
       cout<<"\n\t\t\t WELCOME TO HOME PAGE\n";
       cout<<"\n\t\t\t ____________________\n";
       delay(300);
       cout<<"\nEnter 1 to access INCOME TAX COMPUTING.\n";
       delay(300);
       cout<<"\nEnter 2 to access EXPENSE MANAGER.\n";
       delay(300);
       cout<<"\nEnter 3 to access ACCOUNT SETTINGS.\n";
       delay(300);
       cout<<"\nEnter 4 to logout of your account.\n";
       delay(300);
       _setcursortype(2);
       cout<<"\nEnter Your Choice(1-4):";
       cin>>y;
       clrscr();
	switch(y){
	  case 1:clrscr();
	  IT();
	  break;
	  case 2: clrscr();
	  important();
	  clrscr();
	  break;
	  case 3: clrscr();
	  account();
	  clrscr();
	  break;
	  case 4: clrscr();
	  cout<<"\n\t\t\t You Have Logged Out Of Your Account!!!";
	  delay(30);
	  clrscr();
	  break;
	  default:cout<<"\nEnter Number in the range [1,4] only!!";
	  break;
	  }
	  if(y>0 && y<4)
	  cout<<"\nDo you want to go to home page again(Y/N):";
	  cin>>c;
	  clrscr();
      }while(c=='y' || c=='Y');
}
