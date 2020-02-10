#include <iostream>
#include <string>
#include "post.h"
//#include "global.h"

using namespace std;




Post::Post(int a,string b,string c,string d,Date e): id(a),title(b),creator(c),text(d),d(e)
{
	id_for_post=id;     
}



Post::~Post()
{
    cout<<"Post number: "<<id<<" is about to be destroyed"<<endl;
}

void Post::set_id(int a)
{
    id=a;
}

void Post::set_title(string b)
{
   title=b;
}

void Post::set_creator(string c)
{
   creator=c;
}

void Post::set_text(string d)
{
   text=d;
}

int Post::get_id()
{
   return id;
}

string Post::get_title()
{
   return title;
}

string Post::get_creator()
{
   return creator;
}

string Post::get_text()
{
   return text;
}

void Post::print_post()
{
	cout<<"To noumero tou post einai "<<id<<endl;
	cout<<"O titlos tou post einai "<<title<<endl;
	cout<<"o creator tou post einai "<<creator<<endl;
	cout<<"To keimeno tou post einai "<<text<<endl;
	cout<<"H hmeromhnia tou post einai "<<d.get_day()<<"/"<<d.get_month()<<"/"<<d.get_year()<<endl;
	cout<<endl;
}

      
