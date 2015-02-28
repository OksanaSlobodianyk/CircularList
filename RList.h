#ifndef RLIST_H_
#define RLIST_H_

#include <iostream>

class RElem
{
private:
	int value;
public:
	RElem* next;
	RElem();
	RElem(int val);
	~RElem();
	int getvalue();
};
class List
{
private:
	RElem* current;
	RElem* find_prev();
	RElem* get_cur();
public:
	List();
	~List();
	List(List &l);
	List &operator = (List &b);
	
	int len();
	void next();
	int cur();
	void insert(int n);
	void del_cur();
	
	void AddAll(List &l);
	void fulllist();
	friend std::ostream& operator<<(std::ostream &a, List &b);
	friend List maxlenght(List &p);
};

#endif
