#include<iostream>
#include<iomanip>
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#pragma warn -rch
#pragma warn -par
#pragma warn -rch

using namespace std;

int j1,i1;//GLOBAL MEMBERS
class xii
{
public://CLASS MEMBERS
int roll;
char na[20];
int m1,m2,m3,m4,m5;
char g[10];
int t;
int p;
void input()
  {
	cout<<"\t Do you want to clear the screen? (Yes (1) \ NO (2)) ";
	int x1;
	cin>>x1;
	if(x1==1) system("cls");
	cout<<"\tENTER NAME OF THE STUDENT  "<<i1+1<<" : "<<" "; gets(na);
	cout<<"\n\tENTER THE ROLL NO OF STUDENT  "<<i1+1<<" : "<<" ";cin>>roll;
	cout<<"\n\n \t ENTER MARKS OF THE 5 SUBJECTS OUT OF 100";cout<<'\n';
	cout<<"\tENTER MARKS IN ENGLISH : "; cin>>m1; cout<<"\n";
	cout<<"\tENTER MARKS IN MATHS : ";
	cin>>m2;
	 cout<<"\n";
	cout<<"\tENTER MARKS IN PHYSICS : ";
	cin>>m3;
	 cout<<"\n";
	cout<<"\tENTER MARKS IN CHEMISTRY : ";
	cin>>m4;
	 cout<<"\n";
	cout<<"\tENTER MARKS IN COMPUTER : ";
	cin>>m5;
	 cout<<"\n";
	t=m1+m2+m3+m4+m5; p=t/5;
    }

void output()
  {
 	cout<<"\n";
	cout<<" "<<roll<<" "<<" "<<na<<setw(10)<<"\t";
	cout<<"="" "<<m1<<","<<m2<<","<<m3<<","<<m4<<","<<m5<<"\t";
	cout<<p<<"%"<<"\t"<<""<<"="<<g<<"\n";
	cout<<"\t";
    }
    }//END OF CLASS XII
    s[20];//CREATION OF OBJECTS

int i;

void writes()
   {
      ofstream r("Cbse_record.dat",ios::binary);
	system("cls");
	cout<<"\n";
	for(i=0;i<j1;i++)
	  {
		strcpy(s[i].g,"A1");
		if(s[i].p>=90&&s[i].p<95)
			strcpy(s[i].g,"A2");
		if(s[i].p>=80&&s[i].p<90)
			strcpy(s[i].g,"B1");
		if(s[i].p>=70&&s[i].p<80)
			strcpy(s[i].g,"B2");
		if(s[i].p>=60&&s[i].p<70)
			strcpy(s[i].g,"C1");
		if(s[i].p>=50&&s[i].p<60)
			strcpy(s[i].g,"C2");
		if(s[i].p>=40&&s[i].p<50)
			strcpy(s[i].g,"D1");
		if(s[i].p<40)
			strcpy(s[i].g,"D2");
		r.write((char*)&s[i],sizeof(s[i]));
	     }
       }

ifstream t("Cbse_record.dat",ios::binary|ios::in);

void search()//SEARCHING THE RECORDS USING LINEAR SEARCH
  {
	system("cls");//CLEAR SCREEN
	char name[20]; int flag=0;
	cout<<"\n";
	cout<<"\t\t\t*-----------*" <<"\n";
	cout<<"\t\t\t| SEARCHING |" <<"\n";
	cout<<"\t\t\t*-----------*" <<"\n"<<"\n";
	step:
	cout<<"\n\tENTER THE NAME TO BE SEARCHED :";
	gets(name);
	cout<<"\n";
	cout<<"ROLL	 NAME	      MARKS	   PERCENTAGE	    GRADE"<<"\n";
	for(i=0;i<j1;i++)
	  {
		t.read((char*)&s[i],sizeof(s[i]));
		if(strcmpi(name,s[i].na)==0)
		  {
			flag=1;
			s[i].output();
			break;
		    }
	    }
	if(flag==0)
	  {
		cout<<"Sorry , the name does not exist\n";
	    }
    }


void sortDS()//SORTING THE RESULT USING SELECTION SORT(DESCENDING)

  {
	system("cls");
	xii tp;
	cout<<"\t\t\t*-------------------------------*"<<"\n";
	cout<<"\t\t\t| THE REPORT CARD OF CLASS XII |"<<"\n";
	cout<<"\t\t\t*-------------------------------*"<<"\n"<<"\n";
	cout<<"\t\t\t\t\t\t\tSORTED\n";
	cout<<"ROLL	 NAME	 MARKS		 PERCENTAGE 	GRADE"<<"\n";
	cout<<"---------------------------------------------------------"<<"\n";
	t.read((char*)&s[i],sizeof(s[i]));
	for(int k=0;k<j1;k++)
		  for(int i=0;i<j1-1;i++)
		  {
			if(s[i].p>s[i+1].p)
			  {
			     tp=s[i];
			     s[i]=s[i+1];
			     s[i+1]=tp;
			  }

		  }
		for(i=0;i<j1;i++)
		s[i].output();

	    getchar();
    }

void sortAS()//SORTING THE RESULT USING SELECTION SORT (ASCENDING)

  {
	system("cls");
	xii tp;
	cout<<"\t\t\t*-------------------------------*"<<"\n";
	cout<<"\t\t\t| THE REPORT CARD OF CLASS XII |"<<"\n";
	cout<<"\t\t\t*-------------------------------*"<<"\n"<<"\n";
	cout<<"\t\t\t\t\t\t\tSORTED\n";
	cout<<"ROLL	 NAME	 MARKS		 PERCENTAGE 	GRADE"<<"\n";
	cout<<"---------------------------------------------------------"<<"\n";
	t.read((char*)&s[i],sizeof(s[i]));
	for(int k=0;k<j1;k++)
		  for(int i=0;i<j1-1;i++)
		  {
			if(s[i].p<s[i+1].p)
			  {
			     tp=s[i];
			     s[i]=s[i+1];
			     s[i+1]=tp;
			  }

		  }
		for(i=0;i<j1;i++)
		s[i].output();

	    getchar();
    }

void failed()

  {
	getchar();
	system("cls");
	cout<<"\t**----------------------------------------------------------**"<<"\n";
	cout<<"\t|| THE LIST OF STUDENTS WHO FAILED IN MORE THAN ONE SUBJECT 		||"<<"\n";
	cout<<"\t**----------------------------------------------------------**\n\n";
	cout<<"ROLL 	NAME 	MARKS 	PERCENTAGE 	GRADE"<<"\n";
	cout<<"-------------------------------------------------------"<<"\n";
	for(i=0;i<j1;i++)
	  {
	    int c=0;
	    t.read((char *)&s[i],sizeof(s[i]));
	    if (s[i].m1<40)
		c++;
	    if (s[i].m2<40)
		 c++;
	    if (s[i].m3<40)
		c++;
	    if (s[i].m4<40)
		c++;
	    if (s[i].m5<40)
		 c++;
	     if(c>=2)
	     {
		s[i].output();
	       }
	   }
	getchar();
}

void reads()

  {
	system("cls");
	cout<<"**------------------------------------------------**"<<"\n";
	cout<<"|| THE   REPORT CARD OF STUDENTS OF CLASS XII ||"<<"\n";
	cout<<"**------------------------------------------------**"<<"\n"<<"\n";
	cout<<"\t\t\tFINAL\n";
	cout<<"ROLL     NAME	   MARKS	 PERCENTAGE	   GRADE"<<"\n";
	cout<<"--------------------------------------------------------"<<"\n";
	for(i=0;i<j1;i++)
	  {
	    t.read((char*)&s[i],sizeof(s[i]));
	    s[i].output();
	    }
	getchar();
     }

int main()//THE MAIN FUNCTION

   {
	system("cls");
	cout<<"\n\n\nEnter the number of records of student you\nwant to create ";
	 cin>>j1;
	  for(i1=0;i1<j1;i1++)
	    {
		  s[i1].input();
	    }
	writes();
	cout<<"\t Do you want to search the record? (Yes (1)/No (2)) ";
	 int ch;
	 cin>>ch;
	   if(ch==1)
	     {
		search();
 	     }
	failed();int ty;
	cout<<"\t Do you want to see the report card in sorted format? (Yes (1)/No (2)) ";
	cin>>ch;
	 getchar();
	    if(ch==1)
	      {
		cout<<"For ascending press 1 and for dscending press 2";
		cin>>ty;
		if(ty==1)
		 sortDS();
		else if(ty==2)
		 sortAS();
	       }
	    else
	      {
		reads();
	       }
	cout<<"\n\n\n\n\n******************____THANK____YOU____**********************";
	getchar();
	return 0;
      }


