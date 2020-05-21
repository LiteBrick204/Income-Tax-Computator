#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
//This file contains the internal working of FORM.CPP
//This code computes how much you need to pay as IT Returns
//It's very long!
//Handle With Care!!

struct D13
{
   long PP,LIP,PPF,NSC,ULIP,ELSS,TF,PAHL,FD_5Y,SSS,NPS;
   int no;
};
struct D15A
{
  int MPP_S,MPP_P,PHC;
  char ch;
};
class salary //class which stores user's salary info to compute IT returns
{
   public:
   long Basic,HRA,LTA,TA,OA,GS,PF_DEDUCT,PT;
   char HCITY[3],T_1_0[3];
   void getsall();
}a;
void salary::getsall()
   {
       cout<<"\nEnter Your Basic Salary for the whole year:";
       cin>>Basic;
       cout<<"\nEnter Your HRA for the whole year:"; cin>>HRA;
       cout<<"\nIs Your Residence in Delhi,Mumbai,Kolkatta or Chennai or any other city. Enter the first 3 letters of the city name:";
       gets(HCITY);
       cout<<"\nEnter Your LTA for the year:"; cin>>LTA;
       cout<<"\nEnter Travel/Conveyance Allowance:"; cin>>TA;
       cout<<"\nIs the allowance used for official purposes.Enter 'y' for yes and 'n' for no.:"; gets(T_1_0);
       cout<<"\nEnter Other Allowance:"; cin>>OA;
       cout<<"\nEnter PF Deductions:"; cin>>PF_DEDUCT;
       cout<<"\nEnter Professional Tax paid:"; cin>>PT;
       GS=Basic+HRA+LTA+TA;
       cout<<"\nGross Salary = Rs."<<GS;
   }
//Now the declarations part

class declar:public salary{
public:
char D1[50],D2[250],D3[10],D5[150],MOT[3];
char ch,D11ch,k;
int per,age;
long D4,D6,D7,D9,D12A,D12B,D14,D15B,D15C,D15D,D15E,D15F;
D13  A;
D15A B;
void getdeclar();
void dispdeclar();
};
void declar::getdeclar() // fn which gets your declarations
{
     cout<<"\n\t\t\t DECLARATIONS TO BE OBTAINED";
     cout<<"\nEnter Your Name:"; gets(D1);
     cout<<"\nEnter Your Residential Address:"; gets(D2);
     cout<<"\nEnter Your Age:"; cin>>age;
     cout<<"\nEnter Your PAN Number:"; gets(D3);
     cout<<"\nEnter House Rent Allowance for the year:"; cin>>D4;
     cout<<"\nEnter The Address of the Rented Place:";   gets(D5);
     cout<<"\nEnter The Rent Paid for the year:"; cin>>D6;
     cout<<"\nEnter LTA-Travel Expense for the Shortest Route:"; cin>>D7;
     cout<<"\nEnter Mode Of Travel(Enter first 3 letters of mode of travel):"; gets(MOT);
     cout<<"\nHave you already availed LTA exemption twice for the calendar years 2018-2021(y/n):";
     cin>>ch;
     cout<<"\nInterest on Housing Loan:"; cin>>D9;
     cout<<"\n Is the house(a/b):"<<"\n  (a)For Self-Occupation or (b) Let Out:";
     cin>>D11ch;
     cout<<"\nEnter Rent received for the year:"; cin>>D12A;
     cout<<"\nEnter Municipal Taxes paid for the year:"; cin>>D12B;
     cout<<"\nEnter Deductions under Chapter VIA Section 80C(Restricted	to Rs.1,50,000):\n";
     cout<<"\nEnter Appropriate Values for proper commuting!!\n";
     cout<<"  Contribution to Pension Plans:"; cin>>A.PP;
     cout<<"\n  Premium Payment of Life Insurance Premium(For Self,spouse and children):";
     cin>>A.LIP;
     cout<<"\n  Deposit in Public Provident Fund(PPF)(For Self,spouse and children):";
     cin>>A.PPF;
     cout<<"\n  Purchase of National Saving Certificates(VIII Issue):";
     cin>>A.NSC;
     cout<<"\n  Contribution to Unit Linked Insurance Scheme(ULIP):";
     cin>>A.ULIP;
     cout<<"\n  Contribution to Equity Linked Savings Scheme(ELSS):";
     cin>>A.ELSS;
     cout<<"\n  Payment of Tution fess to any School,College,University or Educational Institution:";
     cin>>A.TF;
     cout<<"\n  Number of School/College going children(Maximum-2):";
     cin>>A.no;
     cout<<"\n  Repayment of Principal Amount of Housing Loan:";
     cin>>A.PAHL;
     cout<<"\n  Fixed Deposit(FD) for 5 years with a Scheduled Bank:";
     cin>>A.FD_5Y;
     cout<<"\n  Sukanya Samriddhi Scheme:"; cin>>A.SSS;
     cout<<"\n  Contribution to National Pension Scheme (NPS) under section 80CCD(1)(restricted to 10% of basic salary):";
     cin>>A.NPS;
     if(A.NPS==(0.10*Basic))
     {
	 D14=50000;
     }
     else
     D14=0;
     cout<<"\nDeduction under Section 80D,80DD,80DDB,80U,80E and 80CCG.\n";
     cout<<"  Are Your Parents Senior Citizens(i.e, age of both parents>=60) or not(y/n):"; cin>>B.ch;
     if(B.ch=='y'||B.ch=='Y')
     {     cout<<"\n For Senior citizen Parents,Deduction under 80D is upto Rs.30,000/.";
	   cout<<"  Mediclaim Policy Premium (under Section 80D):";
	   cin>>B.MPP_S;
	   cout<<"\n  Mediclaim Policy Premium for Parents(MPPP)(under Section 80D):";
	   cin>>B.MPP_P;
	   cout<<"\n  Preventive health Checkup (under section 80D,restricted to Rs.5000/.)";
	   cin>>B.PHC;
     }
     else if(ch=='n'||ch=='N'||ch!='y'||ch!='Y')
     {
	   cout<<"\n For Non-Senior Citizen Parents,deduction under 80D is upto 25,000/.";
	   cout<<"  Mediclaim Policy Premium (under Section 80D):";
	   cin>>B.MPP_S;
	   cout<<"  Mediclaim Policy Premium (under Section 80D):";
	   cin>>B.MPP_P;
	   cout<<"\n Preventive health Checkup (under section 80D,restricted to Rs.5000/.)";
	   cin>>B.PHC;
     }
     cout<<"\nDo You have a handicapped dependent?(y/n):";   cin>>k;
     if(k=='y'||k=='Y')
     {
	cout<<"\nEnter Percentage of disability(Integer figures only):";
	cin>>per;
	if(per>=80)
	{
	   cout<<"\nEnter Medical treatment cost for handicapped dependent(under section 80DD,upto Rs.1,50,000/.):";
	   cin>>D15B;
	}
	else if(per<80)
	{
	   cout<<"\nEnter Medical treatment cost for handicapped dependent(under section 80DD,upto Rs.75,000/.):";
	   cin>>D15B;
	}
     }
     else
     D15B=0;
     cout<<"\nEnter Medical treatment cost for specified diseases under section 80DDB";
     if(age<60)
     {
	 cout<<"(Upto Rs.40,000/-):"; cin>>D15C;
     }
     else if(age>=60)
     {
	 cout<<"(Upto Rs.60,000/-):"; cin>>D15C;
     }
     else if(age>=80)
     {
	 cout<<"(Upto Rs.80,000/-):"; cin>>D15C;
     }
     cout<<"\nAre You Either Blind or Physically Handicapped(y/n):";
     cin>>k;
     if(k=='y'||k=='Y')
     {
	cout<<"\nEnter Percentage of disability(Integer figures only):";
	cin>>per;
	if(per>=80 && per<90)
	{
	   cout<<"\nDeduction in case of person with disabilities=Rs.75,000/.";
	   D15D=75000;
	}
	if(per>=90 && per<=100)
	{
	   cout<<"\nDeduction in case of person with severe disabilities=Rs.1,25,000/.";
	   D15D=125000;
	}
     }
     else if(k!='y'||k!='Y')
     D15D=0;
     cout<<"\nEnter Payment of interest on Loan Taken for higher education for a full time course under section 80E:";
     cin>>D15E;
     cout<<"\nEnter Investment made under notified equity savings scheme under section 80CCG(upto Rs.50,000):";
     cin>>D15F;
}
void declar::dispdeclar() //fn to display your declarations
{
     cout<<"\nName:"<<D1;    delay(300);
     cout<<"\nResidential Address:"<<D2; delay(300);
     cout<<"\nAge:"<<age;    delay(300);
     cout<<"\nPAN Number:"<<D3;    delay(300);
     cout<<"\nHouse Rent Allowance for the year:Rs "<<D4; delay(300);
     cout<<"\nThe Address of the Rented Place: "<<D5;   delay(300);
     cout<<"\nThe Rent Paid for the year:Rs "<<D6;        delay(300);
     cout<<"\nLTA-Travel Expense for the Shortest Route:"<<D7;                         delay(300);
     cout<<"\nMode Of Travel(Enter first 3 letters of mode of travel):"<<MOT;
     delay(300);
     cout<<"\nInterest on Housing Loan:Rs "<<D9;    delay(300);
     cout<<"\nIs the house(a/b):";
     if(D11ch=='a')
     cout<<"For Self-Occupation";
     else if(D11ch=='b')
     cout<<"Let Out";
     delay(300);
     cout<<"\nRent received for the year:Rs "<<D12A;   delay(300);
     cout<<"\nMunicipal Taxes paid for the year:Rs "<<D12B; delay(300);
     cout<<"\nDeductions under Chapter VIA Section 80C (Restricted to Rs.1,50,000):\n";
     cout<<"\nContribution to Pension Plans:Rs "<<A.PP;
     delay(300);
     cout<<"\nPremium Payment of Life Insurance premium(ForSelf,spouse & children):Rs "<<A.LIP;
     delay(300);
     cout<<"\nDeposit in Public Provident Fund(PPF)(ForSelf,spouse & children):Rs "<<A.PPF;
     cout<<"\nPurchase of National Saving Certificates(VIII Issue):Rs "<<A.NSC;
     delay(300);
     cout<<"\nContribution to Unit Linked Insurance Scheme(ULIP):Rs "<<A.ULIP;
     delay(300);
     cout<<"\nContribution to Equity Linked Savings Scheme(ELSS):Rs "<<A.ELSS;
     delay(300);
     cout<<"\nPayment of Tution fess to any School,College,University or Educational Institution:Rs ";
     cout<<A.TF;
     delay(300);
     cout<<"\nNumber of School/College going children:Rs "<<A.no;
     delay(300);
     cout<<"\nRepayment of Principal Amount of Housing Loan:Rs "<<A.PAHL;
     delay(300);
     cout<<"\nFixed Deposit(FD) for 5 years with a Scheduled Bank:Rs "<<A.FD_5Y;
     delay(300);
     cout<<"\nSukanya Samriddhi Scheme:Rs "<<A.SSS;
     delay(300);
     cout<<"\nContribution to National Pension Scheme (NPS) under section 80CCD(1)(restricted to 10% of basic salary):Rs "<<A.NPS;
     delay(300);
     cout<<"\nContribution to National Pension Scheme (NPS) under section 80CCD(1B):Rs "<<D14;
     delay(300);
     cout<<"\nDeduction under Section 80D,80DD,80DDB,80U,80E and 80CCG:\n";
     delay(300);
     cout<<"Mediclaim Policy Premium (under Section 80D):Rs "<<B.MPP_S;
     delay(300);
     cout<<"\nMediclaim Policy Premium for Parents(MPPP)(under Section 80D):Rs "<<B.MPP_P;
     delay(300);
     cout<<"\nPreventive health Checkup (under section 80D):Rs "<<B.PHC;
     delay(300);
     cout<<"\Medical treatment of handicapped dependent(under section 80DD):"<<D15B;
     delay(300);
     cout<<"\nMedical treatment cost for specified diseases under section 80DDB:"<<D15C;
     delay(300);
     cout<<"\nDeduction in case of self being blind or physically handicapped under Section 80C:Rs "<<D15D;
     delay(300);
     cout<<"\nPayment of interest on loan taken for higher education for a full time course under section 80E:Rs "<<D15E;
     delay(300);
     cout<<"\nInvestment made under notified equity savings scheme under section 80CCG:Rs "<<D15F;
     delay(300);
}
class otherdata:public declar{
long DN_80,SD,HRA2,HRA4,HRA5,IHP3,IHP4,IHP5,IHP6,D13N,DN,OT,TI,Tax,SUR,HCess,ECess,ShECess;
void calslab();//Compute Deductions
void slabside();//Compute Tax and other payables
public:
void compute();//Computes Taxable Income and shows how much to pay
void call(); //calls getdeclar() and compute() one after other
}A;
void otherdata::calslab()
{
   long t,a[3];
   if(strcmpi(HCITY,"CHE")==0||strcmpi(HCITY,"MUM")==0||strcmp(HCITY,"KOL")==0||strcmpi(HCITY,"DEL")==0)
   {
      HRA2=(0.50*Basic);
   }
   else
   HRA2=(0.40*Basic);
   HRA4=D6-(0.10*Basic);
   a[0]=HRA,a[1]=HRA2,a[2]=HRA4;
   for(int i=0; i<3; i++)
   {
      t=a[0];
      if(a[i]<a[0])
      {
	 t=a[i];
      }
   }
   HRA5=t;
   IHP3=D12A-D12B;
   IHP4=(0.30*IHP3);
   IHP6=IHP3-(IHP4+D9);
   D13N=A.PP+A.LIP+A.PPF+A.NSC+A.ULIP+A.ELSS+A.TF+A.PAHL+A.FD_5Y+A.SSS+A.NPS;
   if(D13N<=150000 && D14==0)
   {
      DN=D13N;
   }
   else if((D13N<=150000)&&(D14>0)&&(D13N+D14<=200000))
   {
       DN=D13N+D14;
   }
   DN_80=B.MPP_S+B.MPP_P+B.PHC;
   OT=D15B+D15C+D15D+D15E+D15F;
}
void otherdata::slabside()
{
   if(age<60)
   {
	 if(TI<=250000)
	 Tax=0;
	 else if(TI>250000 && TI<=500000)
	 {
	    Tax=(0.05*(TI-250000));
	 }
	 else if(TI>500000 && TI<=1000000)
	 {
	     Tax=25000+(0.20*(TI-500000));
	 }
	 else if(TI>1000000)
	 Tax=112500+(0.30*(TI-1000000));
     }
     else if(age>=60 && age<=80)
     {
	  if(TI<=300000)
	  Tax=0;
	  else if(TI>300000 && TI<=500000)
	  {
	      Tax=0.05*(TI-300000);
	  }
	  else if(TI>500000 && TI<=1000000)
	  {
	      Tax=10000+(0.20*(TI-500000));
	  }
	  else if(TI>1000000)
	  Tax=110000+(0.30*(TI-1000000));
     }
     else if(age>80)
     {
	  if(TI<=500000)
	  Tax=0;
	  else if(TI>500000 && TI<=1000000)
	  Tax=(0.20*(TI-500000));
	  else if(TI>1000000)
	  Tax=1000000+(0.30*(TI-1000000));
     }

     if(Tax>=5000000 && Tax<=10000000)
     SUR=0.10*Tax;
     else if(Tax>10000000)
     SUR=0.15*Tax;
     else
     SUR=0;
     HCess=0.01*(Tax+SUR);
     ECess=0.02*(Tax+SUR);
     ShECess=0.01*(Tax+SUR);
}
void otherdata::compute()
{
    TI=GS;
    calslab();
    SD=40000;
    cout<<"\nGross Salary : Rs."<<GS;
    delay(150);
    getch();
    cout<<"\nStandard Deduction(SD): Rs.40,000/."<<" => Taxable Income= Rs.";
    TI-=SD;
    cout<<TI;
    getch();
    if(strcmpi(T_1_0,"Y")==0||strcmpi(T_1_0,"y")==0)
    {
	 cout<<"\nConveyance/Travel Allowance(TA) deduction : Rs."<<TA;
	 TI-=TA;
	 delay(150);
	 cout<<" =>Taxable Income=TI-TA=Rs."<<TI;
    }
    cout<<"\nProfessional Tax(PT) deduction : Rs."<<PT;
    TI-=PT;
    delay(150);
    cout<<" =>Taxable Income=TI-PT=Rs."<<TI;
    getch();
    cout<<"\nHRA deduction : Rs."<<HRA5;
    delay(150);
    TI-=HRA5;
    cout<<" =>Taxable Income=Rs."<<TI;
    getch();
    cout<<"\nIncome from House Property Deduction : Rs."<<IHP6;
    delay(150);
    TI-=IHP6;
    cout<<" =>Taxable Income=Rs."<<TI;
    getch();
    cout<<"\nLTA Deduction : Rs."<<D7;
    delay(150);
    TI-=D7;
    cout<<" =>Taxable Income=Rs."<<TI;
    getch();
    cout<<"\nChapter VI-A deduction : Rs."<<DN;
    TI-=DN;
    delay(150);
    cout<<" =>Taxable Income=Rs."<<TI;
    getch();
    cout<<"\nDeductions under Mediclaim : Rs."<<DN_80;
    TI-=DN_80;
    delay(150);
    cout<<" =>Taxable Income=Rs."<<TI;
    getch();
    cout<<"\nOther Chapter VI-A deduction :Rs."<<OT;
    TI-=OT;
    slabside();
    cout<<"\nOverall Taxable Income = Rs."<<TI;
    delay(150);  getch();
    cout<<"\n Tax on Taxable Income = Rs."<<Tax;
    delay(150);
    cout<<"\nSurcharge = Rs."<<SUR;
    delay(150);  getch();
    cout<<"\nHealth Cess = Rs."<<HCess;
    delay(150);  getch();
    cout<<"\nEducation Cess = Rs."<<ECess;
    delay(150);  getch();
    cout<<"\nSecondary and Higher Education Cess = Rs."<<ShECess;
    delay(150);  getch();
    cout<<"\nTotal Amount Payable = Rs."<<(Tax+SUR+HCess+ECess+ShECess);
}
void otherdata::call()
{
     getdeclar();
     compute();
}
int c=0;  //For Changing Loading bar color
void load_plugin(char *m=" ")
{
    system("cls");
    randomize();
    int i,x=10,gd=DETECT,gm;
    if(strlen(m)<=10)
    x=strlen(m)+33;
    else if(strlen(m)<=20)
    x=strlen(m)+53;
    else if(strlen(m)<=30)
    x=strlen(m)+73;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setcolor(WHITE);
    for(i=35; i<555; i++)
    { line(25+i,170,25+i,200); }
    for(i=35; i<555; i++)
    {
	if(c!=0)
	setcolor(random(15)+c);
	else if(c==0)
	setcolor(GREEN);
	line(25+i,170,25+i,200);
	delay(5);
	setcolor(WHITE);
	settextstyle(SMALL_FONT,0,16);
	outtextxy(197+x,126,"LOADING");
	delay(10);
	if(strlen(m)<=10)
	settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
	else
	settextstyle(SMALL_FONT,HORIZ_DIR,16);
	outtextxy(191-x+(x/2),220,m);
	delay(10);
    }
    closegraph();
    c++;
}

void createfile(char fname[15])
{
    strcat(fname,".DAT");
    fstream file(fname,ios::app|ios::in|ios::binary);
    A.getsall();
    file.write((char *)&a,sizeof(a));
    //encode(fname);
    file.close();
}
void computeIT(char PaN[15])
{
    strcat(PaN,".DAT");
    fstream file(PaN,ios::app|ios::in|ios::binary);
    A.call();
    file.write((char *)&A,sizeof(A));
    file.close();
}
void viewdeclar(char PaN[15])
{
    fstream file(PaN,ios::app|ios::in|ios::binary);
    file.read((char *)&A,sizeof(A));
    A.dispdeclar();
    file.close();
}
void terminate_file(char fi[15])
{
     char w;
     cout<<"\Are You Sure You Want to Delete your IT RECORD(y/n):";
     cin>>w;
     fstream f;
     if(w=='y'||w=='Y')
     {
     if(remove(fi)!=0)
     {
      f.open(fi,ios::trunc);
      perror("remove");
     }
     else
     cout<<"\nFile Deleted!!";
     }
     return;
}
void viewslab()
{
  char ch='y';
  int x;
  do{
  _setcursortype(0);
  clrscr();
  cout<<"\nFor Which slab(s) do you want to see Tax Rate?";
  cout<<"\nEnter 1 to see Tax Rate for individuals less than 60 years(Non-Senior Citizens)";
  delay(250);
  cout<<"\nEnter 2 to see Tax Rate for individuals between 60 and 80 years(Senior Citizens)";
  delay(250);
  cout<<"\nEnter 3 to see Tax Rate for individuals above 80 years(Super-Senior Citizens)";
  delay(250);
  cout<<"\nEnter 4 to see Tax Rate for both Non-Senior and Senior Citizens";
  delay(250);
  cout<<"\nEnter 5 to see Tax Rate for both Senior and Super-Citizen Citizens";
  delay(250);
  cout<<"\nEnter 6 to see Tax Rate for both Non-Senior and Super-Senior Citizens";
  delay(250);
  cout<<"\nEnter 7 to see Tax Rate for Non-Senior,Senior and Super-Senior Citizens.";
  delay(150);
  _setcursortype(2);
  cout<<"\nEnter Your Choice(1-7):"; cin>>x;
  _setcursortype(0);
  switch(x)
  {
  case 1: cout<<"\nFor Individuals less than 60 years(Non-Senior Citizens).";
	  cout<<"\n+----------------------------+---------------------------+";
	  cout<<"\n|       Taxable Income       |            Tax Rate       |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  cout<<"|      Up to Rs. 2,50,000    |              Nil          |\n";
	  cout<<"| Rs.2,50,000 to Rs.5,00,000 |              5 %          |\n";
	  cout<<"|Rs.5,00,000 to Rs.10,00,000 |             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  break;
  case 2: cout<<"\nFor Individuals between 60 and 80 years(Senior Citizens).";
	  cout<<"\n+----------------------------+---------------------------+";
	  cout<<"\n|       Taxable Income       |            Tax Rate       |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  cout<<"|      Up to Rs. 3,00,000    |              Nil          |\n";
	  cout<<"|  Rs.3,00,000 to Rs.5,00,000|              5 %          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  break;
  case 3: cout<<"\nFor Individuals above 80 years(Super-Senior Citizens):";
	  cout<<"\n+----------------------------+---------------------------+";
	  cout<<"\n|       Taxable Income       |            Tax Rate       |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  cout<<"|      Up to Rs. 5,00,000    |              Nil          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  break;
  case 4: cout<<"\nFor Both Non-Senior and Senior Citizens:";
	  cout<<"\n+----------------------------+---------------------------+";
	  cout<<"\n|       Taxable Income       |            Tax Rate       |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  cout<<"|                 For Non-Senior Citizens:               |\n";
	  cout<<"|      Up to Rs. 2,50,000    |              Nil          |\n";
	  cout<<"|  Rs.2,50,000 to Rs.5,00,000|              5 %          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"|----------------------------|---------------------------|\n";
	  cout<<"|                   For Senior Citizens:                 |\n";
	  cout<<"|      Up to Rs. 3,00,000    |              Nil          |\n";
	  cout<<"|  Rs.3,00,000 to Rs.5,00,000|              5 %          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  break;
  case 5: cout<<"\nFor Senior and Non-Senior Citizens:";
	  cout<<"\n+----------------------------+---------------------------+";
	  cout<<"\n|       Taxable Income       |            Tax Rate       |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  cout<<"|                   For Senior Citizens:                 |\n";
	  cout<<"|      Up to Rs. 3,00,000    |              Nil          |\n";
	  cout<<"|  Rs.3,00,000 to Rs.5,00,000|              5 %          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"|----------------------------|---------------------------|\n";
	  cout<<"|                For Super-Senior Citizens:              |\n";
	  cout<<"|      Up to Rs. 5,00,000    |              Nil          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  break;
  case 6: cout<<"\nFor Both Non-Senior and Super-Senior Citizens:";
	  cout<<"\n+----------------------------+---------------------------+";
	  cout<<"\n|       Taxable Income       |            Tax Rate       |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  cout<<"|                 For Non-Senior Citizens:               |\n";
	  cout<<"|      Up to Rs. 2,50,000    |              Nil          |\n";
	  cout<<"|  Rs.2,50,000 to Rs.5,00,000|              5 %          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"|----------------------------|---------------------------|\n";
	  cout<<"|                For Super-Senior Citizens:              |\n";
	  cout<<"|      Up to Rs. 5,00,000    |              Nil          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  break;
  case 7: cout<<"\nFor Non-Senior,Senior and Super-Senior Citizens:";
	  cout<<"\n+----------------------------+---------------------------+";
	  cout<<"\n|       Taxable Income       |            Tax Rate       |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  cout<<"|                 For Non-Senior Citizens:               |\n";
	  cout<<"|      Up to Rs. 2,50,000    |              Nil          |\n";
	  cout<<"|  Rs.2,50,000 to Rs.5,00,000|              5 %          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"|----------------------------|---------------------------|\n";
	  cout<<"|----------------------------|---------------------------|\n";
	  cout<<"|                 For Non-Senior Citizens:               |\n";
	  cout<<"|      Up to Rs. 2,50,000    |              Nil          |\n";
	  cout<<"|  Rs.2,50,000 to Rs.5,00,000|              5 %          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"|----------------------------|---------------------------|\n";
	  cout<<"|----------------------------|---------------------------|\n";
	  cout<<"|                For Super-Senior Citizens:              |\n";
	  cout<<"|      Up to Rs. 5,00,000    |              Nil          |\n";
	  cout<<"| Rs.5,00,000 to Rs.10,00,000|             20 %          |\n";
	  cout<<"|      Above Rs.10,00,000    |             30 %          |\n";
	  cout<<"+----------------------------|---------------------------+\n";
	  break;
	  default:
	  cout<<"\nEnter Proper input in the range[1,7] only!!";
	  break;
  }
  _setcursortype(2);
  cout<<"\nDo you want to Try Again(y/n):"; cin>>ch;
  }while(ch=='y'||ch=='Y');
}
void viewschinfo()
{
   int x;
   char k='y';
   cout<<"\nThe Best schemes to invest for saving tax are:\n\n";
   do{
   _setcursortype(0);
   delay(300);
   delay(300);
   cout<<" 1. Life Insurance \n\n"; delay(300);
   cout<<" 2. Health Insurance \n\n"; delay(300);
   cout<<" 3. ELSS \n\n"; delay(300);
   cout<<" 4. FD \n\n";   delay(300);
   cout<<" 5. NPS \n\n";  delay(300);
   cout<<" 6. NSC\n\n";   delay(300);
   cout<<" 7. SSS\n\n";   delay(300);
   cout<<" To know about each, enter corresponding number next to the scheme shown above.\n";
   delay(300);
   _setcursortype(2);
   cout<<"\n Enter Your Choice(1-7):"; cin>>x;
   delay(200);
   clrscr();
   switch(x)
   {
       case 1: cout<<"Life Insurance :\n";
       delay(300);
       cout<<"\n ==> Acts as a financial cushion in a case of a contingency.";
       delay(300);
       cout<<"\n ==>U/S 80C,the premium you pay on a life insurance plan is deductible";
       delay(300);
       cout<<" from your total income.\n";
       delay(300);
       cout<<"\n ==>Interest : 0-6%."<<endl;
       delay(300);
       cout<<"\n ==>Premium paid for Unit Linked Insurance Plans(ULIPs) are exempted from taxes U/S 80C.";
       delay(300);
       cout<<"\n ==> Limit:Rs 1,00,000/-, Maximum 5 years lock time.";
       delay(300);
       cout<<"\n ==> Other Life Insurance plans in the market:\n";
       cout<<" ==> Term Plans\n"; delay(300);
       cout<<" ==> Endownment Plans\n"; delay(300);
       cout<<" ==> ULIPs\n"; delay(300);
       cout<<" ==> Money Back Plans\n"; delay(300);
       clrscr();
       break;
       case 2: cout<<"Health Insurance(HI) :\n";
       cout<<"\n ==>U/s 80D, tax is deductible on the premium you pay for the HI plan.";
       delay(300);
       cout<<"\n==>Limit:Rs 15000 for non-senior parents & Rs 30000 for senior citizen parents.";
       delay(300);
       cout<<"\n==>Deductions u/s 80D is not applicable to group HI given by employer.\n";
       delay(300);
       cout<<"\n==>Best HI are: \n Religare Care\n Apollo Munich Optima Restore Family\n";
       delay(300);
       cout<<" Star Family Health Optima\n MAX BUPA Health Companion\n HDFC Health Suraksha\n";
       delay(300);
       clrscr();
       break;
       case 3:cout<<"Equity Linked Saving Scheme(ELSS) :\n";
       delay(300);
       cout<<"==> High risks with High returns u/s 80C as it is linked to the market.\n";
       delay(300);
       cout<<"==> 3 years lock in period and no fixed interest rate.\n";
       delay(300);
       cout<<"==>Investment in ELSS can also be made through a SIP(Systematic Investment Plan)";
       delay(300);
       cout<<"\n==>Wherein you get to spend a small fixed fraction every month,";
       delay(300);
       cout<<"\n Instead of paying high sum altogether.";
       delay(300);
       cout<<"\n==>A SIP multiples the money better than other forms of investment.";
       clrscr();
       break;
       case 4:cout<<"Fixed Deposit (FD):\n";
       delay(400);
       cout<<"==> Covered u/s 80C upto Rs 1,00,000 only for 5-years FD.\n";
       delay(400);
       cout<<"==>Interest: 5.5-7.5%.\n"; delay(400);
       cout<<"==>Minimum limit: Rs 100 to Rs 10000.";
       clrscr();
       break;
       case 5:cout<<"National Pension Scheme(NPS) :\n";
       delay(300);
       cout<<"==>Interest : 4-10%.\n";  delay(300);
       cout<<"\n==> Open for all central govt employees' Pension Fund(PF) after retirement.\n";
       delay(300);
       cout<<"\n==>Tax is deductible u/s 80C.\n";   delay(300);
       cout<<"\n==>Age limit to enter NPS: 18-60.\n"; delay(300);
       cout<<"==>Top Pension Fund Managers(PFM) in NPS:\n";
       delay(300);
       cout<<" 1.SBI PF(Best)"<<"\n 2. LIC PF"<<"\n 3. UTI PF"<<"\n 4. ICICI Prudential PF";
       delay(300);
       cout<<"\n 5. HDFC PF"<<"\n 6. Kotak PF"<<"\n 7. Reliance capital PF"<<"\n 8. Birla Sun Life PF\n";
       clrscr();
       break;
       case 6: cout<<"National Saving Certificate(VIII Issue) :\n";
       delay(300);
       cout<<"==>Interest : 8%.\n";
       delay(300);
       cout<<"\n==>5 years lock-in period.\n";
       delay(500);
       cout<<"\n==>Low risk. Tax is deductible u/s 80C.\n";
       delay(300);
       cout<<"\n==> Can be use as collateral for loans.\n";
       clrscr();
       break;
       case 7: cout<<"Sukanya Samriddhi Scheme(SSS) :\n";
       delay(300);
       cout<<"\n==>Interest: 8.4%.\n";
       delay(300);
       cout<<"\n==>For Girl child.\n";
       delay(300);
       cout<<"\n==>Lock in until the girl turns 18.\n";
       delay(300);
       cout<<"\n==>Overall limit in general : Rs 1,50,000/-. Minimum : Rs 1,000/-.\n";
       delay(300);
       cout<<"\n==>Tax is deductible u/s 80C.";
       clrscr();
       break;
   }
   cout<<"\n DO YOU TO WANT SEE OTHER SCHEMES IN THE LIST(Y/N):"; cin>>k;
   clrscr();
   }while(k=='y'|| k=='Y');
}
void IT()
{
   int x;
   char ch,name[15],PAN[15]=" ";
   do{
   clrscr();
   load_plugin("IT COMPUTATOR v5.2");
   _setcursortype(0);
   cout<<"\n\t\t\t WELCOME TO INCOME TAX COMPUTATOR v5.2.10444\n";
   delay(300);
   cout<<"\n Enter 1 to Add IT Record by Filling Gross Salary Data.\n";
   delay(300);
   cout<<"\n Enter 2 to Fill The Declarations Required To Compute Tax and To Compute Tax.\n";
   delay(300);
   cout<<"\n Enter 3 to View All Declarations.\n";
   delay(300);
   cout<<"\n Enter 4 to Terminate Your Income Tax record.\n";
   delay(300);
   cout<<"\n Enter 5 to View Income Tax Rate For All Tax Slabs.\n";
   delay(300);
   cout<<"\n Enter 6 to know about the schemes to invest for income tax reduction.\n";
   delay(300);
   cout<<"\n Enter 7 to Exit Income Tax Computator.\n";
   delay(300);
   _setcursortype(2);
   cout<<"\n Enter Your Choice(1-7):"; cin>>x;
   switch(x)
   {
      case 1: cout<<"\nEnter What you want to name your file(Max-10 characters):";
	      gets(name);
	      cout<<"\nEnter Your PAN number as well:"; gets(PAN);
	      load_plugin("Salary Calculator");
	      createfile(name);
	      break;
      case 2: cout<<"\n\n LOADING TAX CALCULATOR!!";
	      load_plugin("Tax Calculator");
	      computeIT(PAN);
	      break;
      case 3: cout<<"\n\n LOADING ALL DECLARATIONS!!";
	      load_plugin("Declarations & Forms");
	      viewdeclar(PAN);
	      break;
      case 4: load_plugin("File Terminator 1.0");
	      terminate_file(PAN);
	      break;
      case 5: load_plugin("Tax Slab Information");
	      viewslab();
	      break;
      case 6: load_plugin("Info on Schemes");
	      viewschinfo();
	      break;
      case 7: clrscr();
      cout<<"\nThank You for using IT COMPUTATOR v5.2\n";
      delay(300);
      cout<<"\nPay your taxes for Development of India!!\n";
      delay(300);
      cout<<"\nAs,Taxes are the lifeblood of government!!\n";
      delay(400);
      cout<<"\nNo taxpayer should be permitted to escape his just share!!\n";
      delay(300);
      cout<<"\n JAI HIND!! JAI BHARAT!! BHARATA MATA KI JAI!!";
      delay(300);
      break;
   }
   cout<<"\nDo You Want To Access IT COMPUTATOR Again(y/n):"; cin>>ch;
   clrscr();
   }while(ch=='y'||ch=='Y');
}
