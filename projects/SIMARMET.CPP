//************************************************************************
//			    BY - SIMARPREET SINGH
//************************************************************************


//************************************************************************
//                  PROJECT ON METRO RAILWAY TICKET RESERVATION
//************************************************************************
//REQUIRED HEADER FILES
//************************************************************************

#include<ctype.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>

//************************************************************************
//STRUCTURE CONTAINING VARIABLES FOR RAILWAY RESERVATION.
//************************************************************************

struct railway
{
	char name[20],sex,from[20],rstatus[2],nat[10];
	int passno,age,des;
};

//************************************************************************
//CLASS TO CONTROL ALL THE FUNCTIONS RELATE TO RAILWAY RESERVATION.
//************************************************************************

class train
{
     private:
     railway r;
     void getdata(int);
     void add();
     void list();
     void pinfo();
     void cancel();
     void mod();
     char select();
     public:
     void srs1();
     void srs();
};

//************************************************************************
//FUNCTION NAME:SRS
//DESCRIPTION:THIS FUNCTION OPENS UP THE MAIN MENU
//            AND CALLS OTHER RELATED FUNCTIONS.
//************************************************************************

void train::srs1()
{
 do
 {
	   clrscr();
	   char choice;
	   gotoxy(30,2);
	   cout<<"******MAIN  MENU****** ";
	   cout<<endl;
	   gotoxy(30,7);
	   cout<<" 1-RESERV TOKEN ";
	   gotoxy(30,9);
	   cout<<" 2-PASSENGER INFO.  ";
	   gotoxy(30,11);
	   cout<<" 3-MODIFY TOKEN    ";
	   gotoxy(30,13);
	   cout<<" 4-DISPLAY LIST    ";
	   gotoxy(30,15);
	   cout<<" 5-CANCELLATION     ";
	   gotoxy(30,17);
	   cout<<" 6-QUIT TO SYSTEM   ";
	   gotoxy(34,22);
	   cout<<"ENTER CHOICE:";
	   choice=getch();
	   choice=toupper(choice);
	   switch(choice)
	   {
	      case '1':add();   break;
	      case '2':pinfo(); break;
	      case '3':mod();   break;
	      case '4':list();  break;
	      case '5':cancel();break;
	      case '6':exit(1);
	      default:cout<<"\a";
	   }
 }while(1);
}

//************************************************************************
//FUNCTIONS NAME : SELECT
//DESCRIPTION : THIS FUNCTION OPENS UP A SUB MENU FOR THE USER
// TO SELECT AN TRAIN FROM THE LIST.
//************************************************************************

char train::select()
{
	 char choice;
	 do
	 {
	   clrscr();
	   gotoxy(25,5);
	   cout<<"SELECT A ";
	   gotoxy(23,6);
	   gotoxy(27,9);
	   cout<<"1-BLUE LINE\n";
	   gotoxy(27,10);
	   cout<<"2-YELLOW LINE\n";
	   gotoxy(27,11);
	   cout<<"3-RED LINE\n";
	   gotoxy(27,12);
	   cout<<"4-BROWN LINE\n";
	   gotoxy(27,13);
	   cout<<"5-GREEN LINE\n";
	   gotoxy(27,15);
	   cout<<"R-RETURN TO MAIN MENU\n";
	   gotoxy(27,16);
	   cout<<"Q-QUIT TO SYSTEM\n";
	   gotoxy(30,20);
	   cout<<"ENTER CHOICE:";
	   choice=getch();
	   choice=toupper(choice);
	   switch(choice)
	   {
		  case '1':return(choice);
		  case '2':return(choice);
		  case '3':return(choice);
		  case '4':return (choice);
		  case '5':return(choice);
		  case 'R':srs1();
		  case 'Q':exit(1);
		  default:cout<<"\a" ;select();
	   }
	 }while(1);
}

//************************************************************************
//FUNCTION NAME:GETDATA
//DESCRIPTION:FUNCTION TO GET PASSENGER INFO. FROM
//	      USER FOR ADDITION AND MODIFICATION.
//************************************************************************

void train::getdata(int p)
{

	char ch;
	cout<<"\n ROUTES ARE:";
	cout<<"\n 1.DILSHAND GARDEN - RITHALA";
	cout<<"\n 2.KASHMIRI GATE - IP Ext";
	cout<<"\n 3.SEELAMPUR - NEW DELHI RAILWAY STATION";
	cout<<"\n 4.DHAULA KUAN - AIRPORT";
	cout<<"\n PLEASE SELECT YOUR ROUTE:";
	cin>>r.des;
	clrscr();
	r.passno=p;
	gotoxy(20,7);
	cout<<"PASSENGER NO.:";
	cout<<r.passno;
	gotoxy(20,9);
	cout<<"ENTER NAME OF PASSENGER:";
	gets(r.name);
	gotoxy(20,10);
	cout<<"ENTER SEX OF PASSENGER(M/F):";
	cin>>r.sex;
	while(1)
	{
		gotoxy(34,12);
		cout<<"          ";
		if(r.sex=='m'||r.sex=='M'||r.sex=='f'||r.sex=='F')
		break;
		gotoxy(34,12);
		cout<<"ENTER M or F"<<endl;
		getch();
		gotoxy(34,12);
		cout<<"		 ";
		gotoxy(20,10);
		cout<<"		";
		gotoxy(20,10);
		cout<<"ENTER SEX OF PASSENGER(M/F):";
		cin>>r.sex;
	}
	gotoxy(20,11);
	cout<<"ENTER AGE OF PASSENGER:";
	cin>>r.age;
	while(1)
	{
		gotoxy(34,12);
		cout<<"            ";
		if(r.age>=4 && r.age<=100)
		break;
		gotoxy(34,12);
		cout<<"ENTER CORRECT AGE";
		getch();
		gotoxy(34,12);
		cout<<"          ";
		gotoxy(20,11);
		cout<<"                   ";
		gotoxy(20,11);
		cout<<"ENTER AGE OF PASSENGER     :";
		cin>>r.age;
	}
	gotoxy(20,12);
	cout<<"ENTER THE NATIONALITY     :";
	gets(r.nat);
	gotoxy(20,13);
	cout<<"STARTING POINT       :";
	cout<<"DELHI\n";
	gotoxy(20,14);
	cout<<"DESTINATION POINT       :";
	switch(r.des)
	{
	   case 1:cout<<"RK PURAM\n";     break;
	   case 2:cout<<"ANAND VIHAR\n";   break;
	   case 3:cout<<"LAXMI NAGAR\n";      break;
	   case 4:cout<<"AIIMS\n";break;
	}
	gotoxy(20,16);
	cout<<"TICKET NO.     :";
	cout<<r.passno;
}

//************************************************************************
//FUNCTION NAME : ADD
//DESCRIPTION : FUNCTION TO ADD THE DATA PROVIDED
//      	FROM GETDATA INTO THE REQUIRED FILE.
//************************************************************************

void train::add()
{
	train temp;
	int t;
	fstream trains;
	char c,filename[8],choice1,choice2;
	do
	{
	      t=0;
	      c=select();
	      switch(c)
	      {
		     case '1':strcpy(filename,"IND.DAT"); break;
		     case '2':strcpy(filename,"BRIT.DAT");break;
		     case '3':strcpy(filename,"GULF.DAT");break;
		     case '4':strcpy(filename,"UNIT.DAT");break;
		     case '5':strcpy(filename,"LUF.DAT"); break;
	      }
	      trains.open(filename,ios::in|ios::binary|ios::app);
	      while(trains.read((char*)&temp,sizeof(railway)))
	      t++;
	     trains.close();
	      do
		{
		     if(t<5)
		     strcpy(r.rstatus,"C");
		     else strcpy(r.rstatus,"W");
		     if(t<8)
		     {
			t++;
			clrscr();
			gotoxy(25,3);
			cout<<"ADDITION OF NEW PASSENGER";
			gotoxy(23,4);
			cout<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII";
			gotoxy(20,6);
			cout<<"TRAIN NAME       :";
			switch(c)
			{
			    case '1':cout<<"BLUE LINE METRO";      break;
			    case '2':cout<<"RED LINE METRO";break;
			    case '3':cout<<"YELLOW LINE METRO";   break;
			    case '4':cout<<"BROWN LINE METRO ";break;
			    case '5':cout<<"GREEN LINE METRO";      break;
			}
			getdata(t);
			gotoxy(20,16);
			cout<<"STATUS            :";
			if(t<5)
			cout<<"\aCONFIRMED";
			else cout<<"\aWAITING LIST";
			getch();
			trains.open(filename,ios::out|ios::binary|ios::app);
			trains.write((char*)&r,sizeof(railway));
			trains.close();
		}
		else
		{
			clrscr();
			gotoxy(22,20);
			cout<<"NO MORE TICKETS AVAILABLE FOR THIS TRAIN\a";
			getch();
		}
		gotoxy(12,25);
		cout<<"\aDO YOU WISH TO MAKE ANY MORE RESERVATION ON THIS TRAIN(Y/N)";
		do
		{
			choice1=getch() ;
			choice1=toupper(choice1) ;
		} while((choice1!='Y')&&(choice1!='N')) ;
	}       while(choice1=='Y') ;
		gotoxy(12,25);
		cout<<"DO YOU WISH TO MAKE ANY MORE RESERVATION ON ANY TRAIN(Y/N)";
		do
		{
		     choice2=getch();
		     choice2=toupper(choice2);
		} while((choice2!='Y')&&(choice2!='N'));
	} while(choice2=='Y');
}

//***************************************************************************
//FUNCTION NAME: PINFO
//DESCRIPTION: FUNCTION TO GET FULL DETAILS OF A PARTICULAR PASSENGER
//***************************************************************************

void train::pinfo()
{
	fstream trains;
	int p,k=0;
	char c,filename[8];
	c=select();
	switch(c)
	{
	   case '1':strcpy(filename,"IND.DAT"); break;
	   case '2':strcpy(filename,"BRIT.DAT");break;
	   case '3':strcpy(filename,"GULF.DAT");break;
	   case '4':strcpy(filename,"UNIT.DAT");break;
	   case '5':strcpy(filename,"LUF.DAT"); break;
	}
	clrscr();
	gotoxy(10,3);
	cout<<"ENTER PASSENGER NUMBER :";
	cin>>p;
	trains.open(filename,ios::in|ios::binary|ios::app);
	while(trains.read((char *)&r,sizeof(railway)))
	{
	   k++;
	}
	trains.close();
	if(p>k)
	{
	    clrscr();
	    gotoxy(25,25);
	    cout<<"RECORD NOT FOUND.........\a";
	    getch();
	}
	else
	{
	    trains.open(filename,ios::in|ios::binary|ios::app);
	    while(trains.read((char *)&r,sizeof(railway)))
	    {
	      if(r.passno==p)
	      {
	      clrscr();
	      gotoxy(27,3);
	      cout<<"PASSENGER INFORMATION";
	      gotoxy(23,6);
	      cout<<"TRAIN NAME   :";
	      switch(c)
		{
		case '1':cout<<"BLUE LINE METRO";      break;
		case '2':cout<<"RED LINE METRO";break;
		case '3':cout<<"YELLOW LINE METRO";   break;
		case '4':cout<<"BROWN LINE METRO ";break;
		case '5':cout<<"GREEN LINE METRO";      break;
		}
	      gotoxy(23,7);
	      cout<<"PASSENGER NO.    :";
	      cout<<r.passno;
	      gotoxy(23,9);
	      cout<<"NAME OF PASSENGER :";
	      cout<<r.name;
	      gotoxy(23,10);
	      cout<<"SEX OF PASSENGER :";
	      cout<<r.sex;
	      gotoxy(23,11);
	      cout<<"AGE OF PASSENGER :";
	      cout<<r.age;
	      gotoxy(23,12);
	      cout<<"NATIONALITY  :";
	      cout<<r.nat;
	      gotoxy(23,13);
	      cout<<"STARTING POINT  :";
	      cout<<"DELHI";
	      gotoxy(23,14);
	      cout<<"DESTINATION   :";
	      switch(r.des)
	      {
	   case 1:cout<<"RK PURAM\n";     break;
	   case 2:cout<<"ANAND VIHAR\n";   break;
	   case 3:cout<<"LAXMI NAGAR\n";      break;
	   case 4:cout<<"AIIMS\n";break;
	      }
	      gotoxy(23,16);
	      cout<<"TICKET NO.    :";
	      cout<<r.passno;
	      gotoxy(23,17);
	      cout<<"STATUS         :";
	      if(strcmp(r.rstatus,"W")==0)
	      cout<<"WAITING LIST";
	      else cout<<"CONFIRMED";
	      gotoxy(5,25);
	      cout<<"PRESS ANY KEY TO CONTINUE....";
	      getch();
	      }
	    } trains.close();
	}
}

//***************************************************************************
//FUNCTION NAME : LIST
//DESCRIPTION : FUNCTION TO SHOW PASSENGER LIST TRAIN WISE.
//***************************************************************************

void train::list()
{
	 fstream trains;
	 char c,filename[8];
	 c=select();
	 switch(c)
	 {
	    case '1': strcpy(filename,"IND.DAT");  break;
	    case '2': strcpy(filename,"BRIT.DAT"); break;
	    case '3': strcpy(filename,"GULF.DAT"); break;
	    case '4': strcpy(filename,"UNIT.DAT"); break;
	    case '5': strcpy(filename,"LUF.DAT");  break;
	 }
	 clrscr();
	 gotoxy(29,3);
	 cout<<"PASSENGER LIST";
	 gotoxy(27,4);
	 cout<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIII";
	 gotoxy(33,5);
	 switch(c)
	 {
			  case '1':cout<<"BLUE LINE METRO";      break;
			    case '2':cout<<"RED LINE METRO";break;
			    case '3':cout<<"YELLOW LINE METRO";   break;
			    case '4':cout<<"BROWN LINE METRO ";break;
			    case '5':cout<<"GREEN LINE METRO";      break;
	 }
	 gotoxy(3,7);
	 cout<<"PASSENGER NUMBER";
	 gotoxy(27,7);
	 cout<<"PASSENGER-NAME";
	 gotoxy(62,7);
	 cout<<"RESERVATION STATUS";
	 int i=9;
	 trains.open (filename,ios::in|ios::binary);
	 while(trains.read((char *)&r,sizeof(railway)))
	 {
	   gotoxy(10,i);
	   cout<<r.passno;
	   gotoxy(30,i);
	   cout<<r.name;
	   gotoxy(66,i);
	   if (strcmp(r.rstatus,"C")==0)
	   cout<<"CONFIRMED";
	   else
	   cout<<"WAITING LIST";
	   i++;
	 }
	 gotoxy(25,25);
	 cout<<"\aPRESS ANY KEY YO CONTINUE........";
	 getch();
	 trains.close();
}

//***************************************************************************
//FUNCTION NAME : MOD
//DESCRIPTION : FUMCTION TO GET MODIFY TICKET
//		DETAILS ENTERED DURING RESERVATION
//***************************************************************************

void train::mod()
{
	 fstream trains,trains1;
	 railway t;
	 int p,flag;
	 char c,filename[8];
	 c=select();
	 switch(c)
	 {
	   case '1':strcpy(filename,"IND.DAT");  break;
	   case '2':strcpy(filename,"BRIT.DAT"); break;
	   case '3':strcpy(filename,"GULF.DAT"); break;
	   case '4':strcpy(filename,"UNIT.DAT"); break;
	   case '5':strcpy(filename,"LUF.DAT");  break;
	 }
	 clrscr();
	 int k=0;
	 gotoxy(10,3);
	 cout<<"ENTER PASSENGER NUMBER :";
	 cin>>p;
	 trains.open(filename,ios::in|ios::binary|ios::app);
	 while(trains.read((char *)&r,sizeof(railway)))
	 {
	    k++;
	 }
	 trains.close();
	 if(p>k)
	 {
	    clrscr();
	    gotoxy(25,24);
	    cout<<"\aPASSENGER NUMBER DOES NOT EXIST......";
	    getch();
	    return;
	 }
	 clrscr();
	 gotoxy(25,3);
	 cout<<"MODIFICATION OF PASSENGER";
	 gotoxy(23,4);
	 cout<<" IIIIIIIIIIIIIIIIIIIIIIIIIIIII ";
	 getdata(p);
	 trains1.open("TEMP.DAT",ios::out|ios::binary);
	 trains.seekg(0);
	 while(trains.read((char *)&t,sizeof(railway)))
	 {
	  if(t.passno!=r.passno)
	  trains1.write((char *)&t,sizeof(railway));
	  else
	  trains1.write((char *)&r,sizeof(railway));
	 }
	 trains.close();
	 trains1.close() ;
	 remove(filename);
	 rename("TEMP.DAT",filename);
	 clrscr();
	 gotoxy(20,25);
	 cout<<"\aTICKET DETAILS SUCCESSFULLY MODIFIED.....";
	 getch();
}

//************************************************************************
//FUNCTION NAME : CANCEL
//DESCRIPTION : FUNCTION TO CANCEL A TICKET.
//************************************************************************

void train::cancel()
{
	 fstream trains,trains1;
	 int p,k=0;
	 char c,filename[8];
	 c=select();
	 switch(c)
	 {
	   case '1':strcpy(filename,"IND.DAT"); break;
	   case '2':strcpy(filename,"BRIT.DAT");break;
	   case '3':strcpy(filename,"GULF.DAT");break;
	   case '4':strcpy(filename,"UNIT.DAT");break;
	   case '5':strcpy(filename,"LUF.DAT"); break;
	 }
	 clrscr();
	 gotoxy(10,3);
	 cout<<"ENTER PASSENGER NUMBER : ";
	 cin>>p;
	 trains.open(filename,ios::in|ios::binary|ios::app);
	 while(trains.read((char *)&r,sizeof(railway)))
	 {
	   k++;
	 }
	 trains.close();
	 if(p>k)
	 {
	   clrscr();
	   gotoxy(25,24);
	   cout<<"\aPASSENGER NUMBER DOES NOT EXIST";
	   getch();
	   return;
	 }
	 clrscr();
	 gotoxy(25,3);
	 cout<<"CANCELLATION OF TICKET";
	 trains.open(filename,ios::in|ios::binary);
	 trains1.open("TEMP.DAT",ios::out|ios::binary);
	 while (trains.read((char *)&r,sizeof(railway)))
	 {
	      if(r.passno>p)
	      {
		      r.passno--;
		      trains1.write((char *)&r,sizeof(railway));
	      }
	      else if (r.passno<p)
	      trains1.write((char *)&r,sizeof(railway));
	 }
	 trains.close();
	 trains1.close();
	 remove(filename);
	 rename("TEMP.DAT",filename);
	 trains.open(filename,ios::in|ios::binary);
	 trains1.open("TEMP.DAT",ios::out|ios::binary);
	 while (trains.read((char *)&r,sizeof(railway)))
	 {
	    if(r.passno<=5)
	    strcpy(r.rstatus,"C");
	    else
	    strcpy(r.rstatus,"W");
	    trains1.write((char *)&r,sizeof(railway));
	 }
	 trains.close();
	 trains1.close();
	 remove(filename);
	 rename("TEMP.DAT",filename);
	 clrscr();
	 gotoxy(25,24);
	 cout<<"\a	TICKET SUCCESSFULLY CANCELLED........";
	 getch();

}


void train::srs()
{
	clrscr();
	cout<<"\n\n\n\t     ---------M----------";
	delay(125);
	cout<<"\n\n\n\t	 -------- E---------";
	delay(125);
	cout<<"\n\n\n\t	   ---------T----------";
	delay(25);
	cout<<"\n\n\n\t	     ----------R----------";
	delay(125);
	cout<<"\n\n\n\t	       ----------O----------";
	delay(425);
}


//************************************************************************
//			    Main Function
//************************************************************************

void main()
{
	train obj;
	obj.srs();
    obj.srs1();
}
