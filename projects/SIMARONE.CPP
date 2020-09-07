#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<iomanip.h>
#include<ctype.h>
#include<fstream.h>
#define max 50
#include<conio.h>
/******************************CLASS FOR DEFINING FUNCTION**************/
class book
{
int c,rec,a,status;
char name[max],au[max],issuer[max];
 public:

	void add_book();
	void display_details();
	void search_book();
	void modify_book();
	void delete_book();
	void issue_book();
	void return_book();
	void showissue_book();
	};
/*********************FUNCTION FOR ADDING BOOK*****************/
void book::add_book()
{
  book b;
  char ch;
  fstream file1;
  file1.open("bcd",ios::out|ios::app|ios::binary);
  do
  {     clrscr();
	cout<<"\t\t\tADDITION OF BOOK\n\n\n";
	cout<<"ENTER THE BOOK NAME: ";
	gets(b.name);
	cout<<"ENTER ITS AUTHOR- ";
	gets(b.au);
	cout<<"ENTER THE CLASS TO WHICH IT BELONGS- ";
	cin>>b.a;
	cout<<"ENTER THE RECORD NO. (must be integer)- ";
	cin>>b.rec;
	cout<<"HOW MANY COPIES- ";
	cin>>b.c;
	b.status=0;
	file1.write((char*)&b,sizeof b);
	cout<<"****BOOK ADDED IN THE LIBRARY****";
	cout<<"\nEnter Y for adding more data Or N for EXIT :";
	cin>>ch;
	}while(ch=='Y'||ch=='y');
	clrscr();
	//file1.close();
}
/**********************FUNCTION FOR DISPLAYING DETAILS OF BOOK***************/
void book::display_details()
{
	book b;
	fstream file1;
	file1.open("bcd",ios::in|ios::binary);
	cout<<"BOOK NAME |"<<setw(12)<<"AUTH0R NAME |"<<setw(12)<<"CLASS |"<<setw(12)<<"REC. NO. |"<<setw(12)<<"COPIES |\n"<<endl;
	while((file1.read((char*)&b,sizeof(b))))
       { cout<<setw(5);
	puts(b.name);
	cout<<setw(12);
	puts(b.au);
	cout<<setw(12)<<b.a;
	cout<<setw(12)<<b.rec;
	cout<<setw(12)<<b.c<<endl;
	getch();
	}
       //	file1.close();
}
/*********************FUNCTION FOR SEARCHING DETAILS OF BOOK*****************/
void book::search_book()
{
	book b;
	char nm[max];
	int flag=0;
	fstream file1;
	cout<<"ENTER THE NAME OF THE BOOK  U WANT TO SEARCH";
	gets(nm);
	file1.open("bcd",ios::in|ios::binary);
	file1.seekg(0);
	while(file1.read((char*)&b,sizeof b))
	{
	if (strcmp(nm,b.name)==0)
		{
			cout<<"\t\t\tMATCH FOUND!!!!!!!!!!!!"<<endl;
			cout<<"\tNAME OF THE BOOK IS- "<<b.name<<endl;
			cout<<"\tITS AUTHOR IS- "<<b.au<<endl;
			cout<<"\tNO. OF COPIES ARE- "<<b.c<<endl;
			cout<<"\tRECORD NUMBER IS- "<<b.rec<<endl;
			flag++;
		}
	 }
	if(flag==0)
	 cout<<"********************SORRY!!! CURRENT BOOK IS NOT AVAILABLE********************************"<<endl;
	// file1.close();
	 getch();
	 clrscr();
}
/*********************FUNCTION FOR MODIFYING THE BOOK*****************/
void book::modify_book()
{

	  book b;
	  int num;
	  fstream file1;
	  file1.open("bcd",ios::in|ios::out|ios::ate|ios::binary);
	  cout<<"ENTER THE REC. NO. OF THE BOOK WHICH U WANT TO MODIFY";
	  cin>>num;
	 file1.seekg(0);
	  while(file1.read((char*)&b,sizeof b))
	  {
			if(num==b.rec)
			{
				  file1.seekg(file1.tellg()-(sizeof b),ios::beg);
				 cout<<"ENTER THE BOOK NAME- ";
				  gets(b.name);
				 cout<<"ENTER ITS AUTHOR- ";
				  gets(b.au);
				 cout<<"ENTER THE RECORD NUMBER- ";
				  cin>>b.rec;
				 cout<<"ENTER NO. OF COPIES- ";
				  cin>>b.c;
				 cout<<"ENTER TO WHICH CLASS DOES IT BELONG- ";
				  cin>>b.a;
				 file1.write((char*)&b,sizeof b);
				 cout<<"*****DETAILS MODIFIED FOR THE BOOK*****";
			}


	  }
	  getch();
	  clrscr();
	 // file1.close();

}
/*********************FUNCTION FOR DELETING THE REC. BOOK*****************/

void book::delete_book()
{
	book b;
	int v;
	fstream file1,file2;
	cout<<"ENTER THE REC NO. OF THE BOOK WHICH U WANT TO DELETE";
		cin>>v;
	file1.open("bcd",ios::in|ios::binary);
	file2.open("bac",ios::out|ios::binary);
	while(file1.read((char*)&b,sizeof b))
	{
	if(b.rec!=v)
	{
	 file2.write((char*)&b,sizeof b);
	 }
	 }
	 file1.close();
	 file2.close();
	 file1.open("bcd",ios::out|ios::binary);
	 file2.open("bac",ios::in|ios::binary);
	 while(file2.read((char*)&b,sizeof b))
	 file1.write((char*)&b,sizeof b);

	 file1.close();
	// file2.close();
	 cout<<"\t\n*******************BOOK DELETED************************"<<endl;
	 getch();
	 clrscr();
}
/*********************FUNCTION FOR ISSUING THE BOOK*****************/
void book::issue_book()
{
	book b;
	fstream file1;
	char book[max];
	int flag=0;
	cout<<"NAME OF THE BOOK TO BE ISSUE: ";
	gets(book);
	file1.open("bcd",ios::in|ios::out|ios::binary);
	  while(file1.read((char*)&b,sizeof b))
	  {
			if(strcmp(book,b.name)==0&&b.c>0)
			{
			  file1.seekg(file1.tellp()-(sizeof b),ios::beg);
			  --b.c;
			  cout<<"ENTER THE NAME OF THE PERSON: ";
			  gets(b.issuer);
			  b.status=1;
			  file1.write((char*)&b,sizeof b);
			  flag++;
			  cout<<"*********************BOOK IS ISSUED*********************"<<endl;
				 break;
			}
			if(strcmp(book,b.name)==0&&b.c==0)
			{
				cout<<"\t\tTHE BOOK IS OUT OF STOCK!!!!!!!!!!!"<<endl;
				flag++;
				break;
			}
	 }
	 if(flag==0)
	 cout<<"SORRY!!!!!!!BOOK IS NOT IN THE LIBRARY....."<<endl;
	// file1.close();
	 getch();
	 clrscr();
}
/*********************FUNCTION TO SHOW THE ISSUED BOOKS*****************/
void book::showissue_book()
{
	book b;
	fstream file1;
	cout<<"\nNAME"<<setw(20)<<"BOOK_NAME\n\n";
	file1.open("bcd",ios::in|ios::binary);
	file1.seekg(0);
	while(file1.read((char*)&b,sizeof b))
	{ if(b.status==1)
	cout<<b.issuer<<setw(20)<<b.name;
	}
       //	file1.close();
	getch();
	clrscr();
}
/*********************FUNCTION FOR RETURNING THE  ISSUED BOOK*****************/
void book::return_book()
{ 	book b;
	fstream file1;
	char book[max];
	int flag=0;
	cout<<"NAME OF THE BOOK TO BE RETURN";
	gets(book);
	file1.open("bcd",ios::in|ios::out|ios::binary);
	  while(file1.read((char*)&b,sizeof b))
	  {
			if(strcmp(book,b.name)==0&&b.status==1)
			{
			  file1.seekg(file1.tellp()-(sizeof b),ios::beg);
			  ++b.c;
			  b.status=0;
			  file1.write((char*)&b,sizeof b);
			  flag++;
			  cout<<"*********************BOOK IS RETURNED*********************"<<endl;
				 break;
			}
			if(strcmp(book,b.name)==0&&b.status==0)
			{
				cout<<"\t\t BOOK IS NOT ISSUED YET..... "<<endl;
				flag++;
				break;
			}
	 }
	 if(flag==0)
	 cout<<"SORRY!!!!!!!BOOK DOES NOT BELONGS TO LIBRARY....."<<endl;
	 getch();
	 clrscr();
       //	 file1.close();
}



 void main()
{
	 book b;
	 clrscr();
	 int choice;
         do{
		  cout<<"\t\t\t\t\t\t\n\n\n\n\n\n\n               WELCOME TO SIMARPREET's LIBRARY MGMT. SYSTEM ...."<<endl;


		  cout<<"\t\t       -:MENU:-\n"<<endl
				<<"\t\t1. ADD NEW BOOK TO LIBRARY"<<endl
				<<"\t\t2. DISPLAY DETAIS OF THE BOOKS"<<endl
				<<"\t\t3. SEARCH THE BOOK IN LIBRARY"<<endl
				<<"\t\t4. ISSUE A BOOK"<<endl
				<<"\t\t5. MODIFY THE RECORD OF THE BOOK"<<endl
				<<"\t\t6. DELETE THE BOOK FROM LIBRARY"<<endl
				<<"\t\t7. SHOW THE ISSUED BOOK"<<endl
				<<"\t\t8. RETURN A BOOK"<<endl
				<<"\t\t9. EXIT FROM PROGRAM"<<endl
				<<"ENTER UR CHOICE-> ";
		  cin>>choice;
		  cout<<endl;
		  switch(choice)
		  {
				 case 1:b.add_book();
							break;
				 case 2:b.display_details();
							break;
				 case 3:b.search_book();
							break;
				 case 4:b.issue_book();
							break;
				 case 5:b.modify_book();
							break;
				 case 6:b.delete_book();
							break;
				 case 7:b.showissue_book();
							break;
				 case 8:b.return_book();
							 break;
				 case 9:cout<<"***************THANK YOU**************";break;

				 default:cout<<"\n\tWRONG INPUT\n";
		  }
                  }while(choice!=9);
 getch();

    }
