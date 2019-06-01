#include"Date.h"//аміЮіЮ
Date::Date(int pyear,int pmonth)
{
	year=pyear;
	month=pmonth;
}
int Date::calculate(int pyear,int pmonth)
{
	int a=year-pyear;
	int b=month-pmonth;
	if(b<0)
		a--;
	return a;
}
void Date::setDate(int pyear,int pmonth)
{
	year=pyear;
	month=pmonth;
}