#include <iostream>
#include "date.h"
#include <cstdlib>

using namespace std;


void Date::set_day(int a)
{
	day=a;
}

int Date::get_day()
{
	return day;
}

void Date::set_month(int a)
{
	month=a;
}

int Date::get_month()
{
	return month;
}

void Date::set_year(int a)
{
	year=a;
}

int Date::get_year()
{
	return year;
}

void Date::set_date()
{
    int i = rand() % 30+1;
    int j=rand() % 12+1;
    int k=2015;
    day=i;
    month=j;
    year=k;
}

