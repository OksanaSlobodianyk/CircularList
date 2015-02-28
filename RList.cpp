#include "stdafx.h"
#include "RList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

RElem::~RElem()
{
}

RElem::RElem(int val)
{
	value = val;
	next = NULL;
}


int RElem::getvalue()
{
	return value;
}

RElem* List::get_cur()
{
	return current;
}

RElem* List::find_prev()
{
	RElem *p;
	if (current == NULL) 
		p = NULL;
	else
	{
		p = current;
		while (p -> next != current)
			p = p -> next;
	}
	return p;
} 

List::List()
{
	current = NULL;
}


List::~List()
{
	while (current!=NULL)
	{
		del_cur();
	}
}

List::List(List &l)
{
	current=NULL;
	AddAll(l);                 
}
 
List & List::operator = (List &b)
{
	if (this!=&b)
	{
		b.~List();
		AddAll(b);
	}
	return *this;
}
               
int List::len()
{
	int i = 0;
	RElem *p;
	p = current;
	if (p != NULL)
	{
		do {
			p = p -> next;
			i++;
		} while (p != current);
	}
	return i;
}
 
void List::next()
{
	if (current != NULL)
		current = (current) -> next;
} 
  
int List::cur()
{
	if (current != NULL)
		return current->getvalue();
	else 
	{
		exit(1);
	}
}

void List::insert(int n)
{
	RElem *p;
	p = new RElem(n);
	if(len() == 0)
	{
		current=p;
		p -> next = p;
	}
	else
	{
		p->next = current->next;
		current->next=p;
		current = p;
	}
} 

void List::del_cur()
{
	RElem *p;
	if (current != NULL)
	{
		p = current;
		if (len() == 1) 
		{
			current = NULL;
		}
		else
		{
			find_prev() -> next = current -> next;
			current = (current)  -> next;
		}
		delete(p);
	}
}

void List::AddAll(List &l)
{
	for (int i=0;i<l.len();i++)
	{
		insert(l.cur());
		l.next();
	}
}

void List::fulllist()
{
	int i;
	int a;
	int b;
	cout<<"The number of elements\n";
	cin>>b;
	if (len()!=0) 
	{
		this->~List();
	}
	cout<<"Elements\n";
	for (i=0; i<b; i++)
	{
		cin>>a;
		insert(a);
	}
}   

std::ostream &operator <<(std::ostream &a, List &b)
{
	if (b.len()!=0)
	{
		for (int i=0; i<b.len(); i++) 
		{
			cout<<b.cur()<<" ";
			b.next();
		}
	}
	return a;
}

//пошук у списку елемента рівного заданому числу

 bool Search(List &pd, int a)
 {
	 if (pd.len()!=0)
	 {
		 for (int i=0; i<pd.len();i++) 
		 {
			 if (pd.cur()==a) 
				 return 1;
		 }
		 pd.next();
	 }
	 return 0;
 }

//конкатенація двох списків

List Let (List &L1, List &L2)
{
	List L3;
	L3.AddAll(L1);
	L3.AddAll(L2);
	L3.next();
	return L3;
}
 
 //«лічилка» 
void counting(int n, int m)
{
	int i;
	List pd;
	List p;
	for (i = 1; i <= n; i++) 
	{
		pd.insert(i);
	}
	pd.next();
	cout<<pd<<"\n";
	while (pd.len()!=0)
	{
		for (i = 1; i <= m-1; i++)
		{
			pd.next();
		}
		p.insert(pd.cur());
		pd.del_cur();
	}
	p.next();
	cout<<p<<"\n";
}         
  
//послідовність рівних елементів списку, що йдуть підряд, максимальної довжини
        
List maxlenght(List &p)
{
	if (p.len()!=0)
	{
		List q;
		int i=0,j;
		int n = p.len();
		while(p.get_cur()->next->getvalue()==p.cur() && i<n)
		{
			p.next();
			i++;
			
		}
		p.next();
		int t;
		int max = 0;
		if (i==n)
		{
			max = n;
			t = p.cur();
			
		}		
		else
		{
			j=1;
			for (i=1;i<n-1;i++)
			{
				if (p.cur()!= p.get_cur()->next->getvalue())
				{
					max = j;
					t = p.cur();
					j=0;
				}
				j++;
				p.next();
			}
		}
		for (i=0;i<max;i++)
			q.insert(t);
		return q;
	}
	else return List();
}
        
//видалити зі списку всі повторні входження елементів;
    
List delrepeat(List &p)
{
	if(p.len()!=0)
	{
		List q;
		int i;
		for (i=0; i<p.len(); i++)
		{
			if (!(Search(q,p.cur())))
				q.insert(p.cur());
			p.next();
		}
		p.~List();
		return q;
	}
	else return List();
}
       
       
//Знайти пару елементів списку, різниця між якими є максимальною за абсолютною величиною для всіх пар елементів списку;
                  
void maxminelem(List &p)
{
	if (p.len()!=0)
	{
		int Min=p.cur();
		int Max=p.cur();
		int i,a;
		for (i=0; i<p.len(); i++)
		{
			a=p.cur();
			if (a>Max) Max=a;
			if (a<Min) Min=a;
			p.next();
		}
		cout<<"maxel="<<Max<<" "<<"minel="<<Min<<"\n";
		cout<<"the substraction= "<<Max-Min<<"\n";
	}
	else exit(1);
}
