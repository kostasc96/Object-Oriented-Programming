#include <iostream>

using namespace std;

struct Date
{
        private:
	int day;
	int month;
	int year;
        public:
	void set_day(int );
	int get_day();
	void set_month(int );
	int get_month();
	void set_year(int );
	int get_year();
        void set_date();
       // Date(int ,int ,int );
};


