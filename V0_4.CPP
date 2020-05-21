#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
void mainload()
{
 clrscr();
 _setcursortype(0);
 cout<<"\n\n\n\n\n\n\t\tExpense Manager v0.4 is initiating\n\t\t\t      Please wait\n\n";
 char a=177,b=219;

 for(int i=0;i<52;i++)
  cout<<a;
  cout<<"\r\r";
  cout<<"\t\t";
  for(i=0;i<36;i++)
  {
   cout<<b;
   delay(500);
  }
  clrscr();
  _setcursortype(2);
}
void loading()
{
 clrscr();
 _setcursortype(0);
 cout<<"\n\n\n\t\t\t\t     Loading\n\n";
 char a=177,b=219;
 cout<<"\t\t\t\t";
 for(int i=0;i<=15;i++)
  cout<<a;
  cout<<"\r";
  cout<<"\t\t\t\t";
  for(i=0;i<=15;i++)
  {
   cout<<b;
   delay(150);
  }
  clrscr();
  _setcursortype(2);
}
class expenses
{
 int month;
 char nAme[10];
 double income;
 long rent,insurance,home,edu,health,lei,gift,food,cloth,loan,trans,sub,misc,left;
 public:
 void create();
 void display();
 int search()
 {
  return month;
 }
 int check(char I[10])
 {
     return strcmp(nAme,I);
 }
};

class wish
{
 public:
 char name[10],wish1[20],wish2[20],wish3[20];
 long w1,w2,w3;
};
void get()
{
   expenses x;
   expenses x1;
   fstream file,f;
   char ch='n';
   file.open("em.dat",ios::binary|ios::app);
   f.open("temp.dat",ios::binary|ios::app);
   file.read((char*)&x,sizeof(x));
   while(!file.eof()&&ch=='n')
   {
    if(x1.search()<=x.search())
    {
     f.write((char*)&x1,sizeof(x1));
     ch='y';
     break;
    }
    else
    {
     f.write((char*)&x,sizeof(x));
    }
    file.write((char*)&x,sizeof(x));
   }
   if(ch=='y')
   {
    while(!file.eof())
    {
     f.write((char*)&x,sizeof(x));
     file.read((char*)&x,sizeof(x));
    }
   }
   else
    f.write((char*)&x1,sizeof(x1));
   file.close();
   f.close();
   remove("em.dat");
   rename("temp.dat","em.dat");
 }

void expenses::create()
{
 clrscr();
 loading();
 cout<<" Hello, I am Miguel, your expense manager"<<endl;
 delay(300);
 cout<<"\nEnter Your Username:"; gets(nAme);
 delay(300);
 cout<<endl<<" Please remind me what month is going on now \n Press 1 for January, 2 for February...\t ";
 cin>>month;
  cout<<endl<<" Can you tell me how much is your monthly income in rupees\t "; cin>>income;
  cout<<endl<<"\n Rent/Mortgage : \t";cin>>rent;
  cout<<endl<<" Insurance : \t";cin>>insurance;
  cout<<endl<<" Home & Utilities : \t"; cin>>home;
  cout<<endl<<" Education : \t"; cin>>edu;
  cout<<endl<<" Health & Personal Care : \t"; cin>>health;
  cout<<endl<<" Leisure : \t"; cin>>lei;
  cout<<endl<<" Gifts : \t"; cin>>gift;
  cout<<endl<<" Food & Drinks : \t"; cin>>food;
  cout<<endl<<" Clothing & Footwear: \t";cin>>cloth;
  cout<<endl<<" Loans : \t";cin>>loan;
  cout<<endl<<" Transport : \t"; cin>>trans;
  cout<<endl<<" Subscriptions (netflix,amazon prime,hulu) : \t"; cin>>sub;
  cout<<endl<<" Miscellaneous : \t"; cin>>misc;
  left=income-(rent+insurance+home+edu+health+lei+gift+food+cloth+loan+trans+sub+misc);
  if(left>=0)
  {
   cout<<endl<<" Money left in your pocket is rupees"<<left;
   cout<<endl<<endl<<" Finally, you can do some savings";
  }
  else
   {
    cout<<" You have a deficit of "<<(-1)*left<<" rupees ";
    cout<<endl<<endl<<" You are drowning in debt ! Take a loan ASAP!!!";
   }
   get();
 }
 void expenses::display()
 {
   clrscr();
   if(income==0)
    {
     cout<<endl<<" You have not told us your monthly exoenses \n Please tell us your expenses before trying to view them ";
    }
    else
    {
     cout<<endl<<" Thank you "<<nAme<<" ! \nYour expenses are as follows : \n";
     cout<<endl<<" Income : "<<income;
     cout<<endl<<" Rent : "<<rent<<endl;
     cout<<" Insurance : "<<insurance<<endl;
     cout<<" Home & Utilities : "<<home<<endl;
     cout<<" Education : "<<edu<<endl;
     cout<<" Health & Personal Care : "<<health<<endl;
     cout<<" Leisure : "<<lei;
     cout<<endl<<" Gifts : "<<gift<<endl;
     cout<<" Food & Drinks: "<<food<<endl;
     cout<<" Clothing & Footwear : "<<cloth<<endl;
     cout<<" Loans : "<<loan<<endl;
     cout<<" Transport : "<<trans<<endl;
     cout<<" Subscriptions : "<<sub;
     cout<<endl<<" Miscellaneous : "<<misc;
     if(left>=0)
     cout<<endl<<" Leftover money : "<<left<<endl;
     else
     cout<<endl<<" Excess money spent : "<<(-1)*left<<endl;
    }
 }

void show()
{
 expenses e;
 loading();
 char l[10];
 char ch='f';
 cout<<" Please tell me which month expenses you require:";
 int currentmonth;
 cin>>currentmonth;
 cout<<"\nEnter Your Username:"; gets(l);
 fstream f;
 f.open("em.dat",ios::binary);
 f.seekg(0);
 while(f.read((char*)&e,sizeof(e)))
 {
  if(e.search()==currentmonth && e.check(l)==0)
  {
   e.display();
   ch='t';
   break;
  }
 }
 f.close();
 if(ch!='t')
 cout<<"\nYou have not told that month's expenses!!";
}
void wishlist()
{
 int b;
 wish w;
 clrscr();
 loading();
 fstream file;
 file.open("wish.dat",ios::binary|ios::in|ios::out);
 cout<<"  Press 1 to see the items in your wishlist\n";
 cout<<"\t2 to enter items in your wishlist \n";
 cout<<"\t3 to get back";
 cout<<endl<<endl<<"  What do you want to do ?  ";
 cin>>b;
 switch(b)
 {
  case 1:
   file.read((char*)&w,sizeof(w));
   if(w.w1==0&&w.w2==0&&w.w3==0)
    cout<<endl<<" No items in wishlist ! ";
   else
    {
     cout<<endl<<" Here are the items currently in your wishlist : "<<endl;
     cout<<" "<<w.wish1<<"\t"<<w.w1<<endl<<" "<<w.wish2<<"\t"<<w.w2<<endl<<" "<<w.wish3<<"\t"<<w.w3<<endl;
    }
   break;
   case 2:
   cout<<endl<<" Enter your 1st item : ";
   gets(w.wish1);
   cout<<endl<<" Enter its cost : ";
   cin>>w.w1;
   cout<<endl<<" Enter your 2nd item : ";
   gets(w.wish2);
   cout<<endl<<" Enter its cost : ";
   cin>>w.w2;
   cout<<endl<<" Enter your 3rd item : ";
   gets(w.wish3);
   cout<<endl<<" Enter its cost : ";
   cin>>w.w3;
   file.write((char*)&w,sizeof(w));
   break;
   case 3:
   return;
   default:
   cout<<endl<<" Invalid key pressed ";
 }
 file.close();
}

void loan()
{
 int p;
 loading();
 cout<<" Enter 1 for saving account rates\n";
 cout<<"       2 for loan interest rates\n";
 cout<<endl<<" Enter your choice : ";
 cin>>p;
 switch(p)
 {
  case 1:
   clrscr();
   cout<<" SBI - 3.5% to 4%\n HDFC - 3.5% to 4%\n Kotak - 5% to 6%\n IDBI - 4%\n ";
   break;
  case 2:
   clrscr();
   cout<<" SBI - 12.5%\n HDFC - 11.25%\n Kotak - 11.5%\n IDBI - 13.99%\n ";
   break;
 }
}
 void important()
 {
  mainload();
  clrscr();
  int y;
  expenses e;
  char h;
  do
   {
    clrscr();
    cout<<" Hello, I am Miguel, your personal expense manager \n What can I do for you ? ";
    delay(300);
    cout<<endl<<endl<<" Kindly Press 1 if you want me to take your expenses \n";
    delay(300);
    cout<<" \tPress 2 to show you your expenses \n";  delay(300);
    cout<<" \tPress 3 to see your wishlist \n";       delay(300);
    cout<<" \tPress 4 for interest rates \n";         delay(300);
    cout<<" \tPress 5 to exit ";                      delay(300);
    cout<<endl<<endl<<" What do you want to do ? ";
    cin>>y;
    switch(y)
    {
     case 1:
      e.create();
      break;
     case 2:
      show();
      break;
     case 3:
      wishlist();
      break;
     case 4:
      clrscr();
      loan();
      getch();
      break;
      case 5:
      clrscr();
      cout<<endl<<" Nice knowing you ";
      cout<<endl<<" Press any key to get out of here ";
      getch();
      cout<<endl<<" \n  Closing everything....";
      delay(500);
   }
   cout<<"\nDo you want to access expense manager home page again(Y/N):";
   cin>>h;
  }while(h=='y'|| h=='Y');
}


