#include "LOG.CPP"
void welcome() // Welcome Page
{
     clrscr();
     randomize();
     int gd=DETECT,gm;
     initgraph(&gd,&gm,""); // Type your BGI directory inside the quotes
     settextstyle(3,HORIZ_DIR,4);
     int x;
     setcolor(BLUE);
     outtextxy(201,40,"eACCOUNTANT");
     delay(500);
     outtextxy(198,40,"__________");
     outtextxy(39,94,"WE ARE COMMITTED TO YOUR SUCCESS");
     setcolor(BROWN);
     outtextxy(0,153,"A SOLUTION TO DO YOUR ACCOUNTS FAST!!");
     delay(500);
     setcolor(BLUE);
     outtextxy(157,195,"PROJECT DONE BY:");
     delay(500);
     setcolor(random(6)+3);
     settextstyle(4,HORIZ_DIR,4);
     outtextxy(144,225,"G SHALOM SHREYAN");
     delay(500);
     setcolor(random(13)+2);
     outtextxy(149,254,"A BADRI KRISHNAN");
     delay(500);
     setcolor(random(6)+1);
     settextstyle(1,HORIZ_DIR,4);
     outtextxy(1,284,"CLASS:XII-A KENDRIYA VIDYALAYA CLRI");
     delay(500);
     setcolor(random(5)+2);
     outtextxy(10,314,"2018-19 COMPUTER SCIENCE PROJECT");
     delay(500);
     outtextxy(110,354,"PRESS ANY KEY TO CONTINUE");
     getch();
     cleardevice();
     closegraph();
}
void main() //Home page
{
     clrscr();
     int y;
     char c;
     welcome();
     do{
     clrscr();
     _setcursortype(0);
     cout<<"\n\n\n\n\t\t\t Enter 1 to Create an account.\n\n";
     delay(300);
     cout<<"\t\t\t Enter 2 to Login into your account.\n\n";
     delay(300);
     cout<<"\t\t\t Enter 3 to exit.\n\n";
     _setcursortype(2);
     cout<<"\t\t\t Enter Your Choice(1 or 2 or 3):";
     cin>>y;
     closegraph();
     switch(y)
     {
	  case 1: clrscr();
		  getinfo();
		  cout<<"\n\t\t\tThank you Try Again!!";
		  delay(300);
		  cout<<"\n\t\t\t Have A Nice Day!!";
		  delay(300);
		  break;
	  case 2: clrscr();
		  login();
		  cout<<"\n\t\t\tThank you Try Again!!";
		  delay(300);
		  cout<<"\n\t\t\t Have A Nice Day!!";
		  delay(300);
		  break;
	  case 3: clrscr();
		  cout<<"\n\t\t\tThank you Try Again!!";
		  delay(300);
		  cout<<"\n\t\t\t Have A Nice Day!!";
		  exit(0);
	  default:cout<<"\nEnter Proper value in the range [1,3] only!!";
		  cout<<"\n\t\t\tThank you Try Again!!";
		  delay(300);
		  cout<<"\n\t\t\t Have A Nice Day!!";
		  getch();
		  break;
     }
     cout<<"\nDo you want to go back(Y/N):"; cin>>c;
     }while(c=='y'|| c=='Y');
     getch();
}
