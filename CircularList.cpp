// CircularList.cpp: главный файл проекта.

#include "stdafx.h"
#include "RList.h"
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace System;

bool Search(List &pd, int a);
List Let(List &L1, List &L2);
void counting(int n, int m);
List maxlenght(List &p);
List delrepeat(List &p);
void maxminelem(List &p);
ostream &operator<<(ostream &a, List &b);

const unsigned num = 2;

typedef enum{
	s_main=0,
	s_change=1,
	s_c = 2,
	s_op2 = 3
} state;

List lists[num];
state st = s_main;

void OutputLists()
{
	for (unsigned i=0;i<num;i++)
		cout<<"List "<<i+1<<": "<<lists[i]<<"\n";
}

unsigned getIndex(unsigned from,unsigned to)
{
	unsigned i=0;
	do 
	{
		cin>>i;
	} while (i>to && i<from);
	return i;
}

bool MainMenu()
{
	cout<<"1. Change list\n";
	cout<<"2. Counting list\n";
	cout<<"3. Add two lists\n";
	cout<<"4. Exit\n";

	unsigned t=getIndex(1,4);

	if (t == 4)
		return true;
	
	st = (state) t;
	return false;
}

void ChangeList()
{
	cout<<"Select list:";
	unsigned i=getIndex(1,num)-1;
	if ((i>num-1) && (i<0))
	{
		cout<<"Input the Number of the list again\n";
		i=getIndex(1,num)-1;
	}

	List* l = &(lists[i]);

	cout<<"1. Input list\n";
	cout<<"2. Add one element\n";
	cout<<"3. Delete the n-th element\n";
	cout<<"4. Search element in the list\n";
	cout<<"5. Find maxlength sublist\n";
	cout<<"6. Delete all elements that repeat\n";
	cout<<"7. The substraction between max and min\n";
	cout<<"8. Back\n";

	unsigned t=getIndex(1,8);

	switch(t)
	{
	case 1:
		{
			l->fulllist();
			l->next();
		}
		break;
	case 2:
		{
			int val;
			cout<<"Enter new value\n";
			cin>>val;
			l->insert(val);
		break;
		}
	case 3:
		{
			int n;
			cout<<"Enter number\n";
			cin>>n;
			for(int i=1; i<n; i++)
				l->next();
			l->del_cur();
			for (int i=1; i<l->len()-n+2; i++)
				l->next();
		}
		break;
	case 4:
		{
			int a;
			bool b;
			cout<<"Enter element:\n";
			cin>>a;
			b=Search(*l,a);
			if (b) 
				cout<<"Founded!\n";
			else cout<<"Not Founded=(\n";
			system("pause");
		}
		break;
	case 5:
		{
			cout<<"Maxlength sublist is: \n";
			cout<<maxlenght(*l)<<"\n";
			system("pause");
		}
		break;
	case 6:
		{
			cout<<"Delete All number that repeat \n";
			cout<<delrepeat(*l)<<"\n";
			system("pause");
		}
		break;

	case 7:
		{
			maxminelem(*l);
			system("pause");
		}
		break;

	case 8:
		st = s_main;
		break;
	}
}

int main()
{
	bool quit= false;
	while (!quit)
	{
		OutputLists();

		switch (st)
		{
			case s_main:
				quit = MainMenu();
				break;
			case s_change:
				ChangeList();
				break;
			case s_c:
				{
					int n,m;
					cout<<"Input How Many people\n";
					cin>>n;
					cout<<"Input How many words\n";
					cin>>m;
					counting(n,m);
					system("pause");
					st = s_main;
				}
				break;
			case s_op2:
				{
					cout<<"Union list: "<< Let(lists[0],lists[1])<<"\n";
					system("pause");
					st = s_main;
				}
				break;
			default:
				break;
		}
		system("CLS");
	}
	return 0;
}

