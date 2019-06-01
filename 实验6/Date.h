#ifndef DATE_H//аміЮіЮ
#define DATE_H
#include<iostream>
using namespace std;
class Date{
private:int year;
		int month;
public:Date(){};
	   Date(int pyear,int pmonth);
	   void setDate(int pyear,int pmonth);
	   int calculate(int pyear,int pmonth);
};
#endif