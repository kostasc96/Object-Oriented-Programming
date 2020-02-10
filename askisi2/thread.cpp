#include <iostream>
#include <string>
#include "thread.h"
#include <cstdlib>

using namespace std;

string Thread::get_subject()
{
	return subject;
}

void Thread::add_post(int a,string b,string c,string d,Date e,int f)
{
        p[f]=new Post(a,b,c,d,e);
}

void Thread::print_thread()                               
{
		cout<<"Subject of thread is "<<subject<<endl;
		cout<<"Creator of thread is "<<creator<<endl;
		cout<<"Date of thread is "<<dt.get_day()<<"/"<<dt.get_month()<<"/"<<dt.get_year()<<endl;
		cout<<"**********"<<endl;
		int i;
		for(i=0;i<10;i++)
		p[i]->print_post();	                              
}

void Thread::print_thread2()
{
	cout<<"Subject of thread is "<<subject<<endl;
}

       
void Thread::ektupwsh_post(int id_tou_post)         
{
	int i;
	for(i=0;i<10;i++)
	{
		if(p[i]->get_id()==id_tou_post)
		{
			p[i]->print_post();
		}
	}
}    


Post* Thread::epistrofh_post(int a)          //new
{
	return p[a];
}       
      

Thread::Thread(string a, string b,Date c)  
{
    subject=a;
    creator=b;
    dt=c;
    c.set_date();
    p=new Post*[10];
    int k;
    for(k=0;k<10;k++)
    {
    string e=get_title_for_post();
    string f=get_creator_for_post();
    string g=get_text_for_post();
    Date h;
    h.set_date();
    add_post(id_for_post,e,f,g,h,k);
    id_for_post++;
    }
    cout<<"*********"<<endl;
    cout<<"Thread with subject: "<<subject<<" has just been created!"<<endl;
}



Thread::~Thread()
{
	int i;
	for(i=0;i<10;i++)
	{
		delete p[i];
	}
	delete [] p;
	cout<<"Thread with subject: "<<subject<<" is about to be destroyed"<<endl;
}

