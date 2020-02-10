#include <iostream>
#include <string>
#include "post.h"

using namespace std;

class Thread
{
	private:
	string subject;
	string creator;
	Date dt;
	Post **p;
	int counter;  /*Number of posts that exist in thread*/
	public:
	string get_subject();
	void ektupwsh_post(int );
        void add_post(int ,string ,string ,string ,Date ,int );
	void print_thread();
	void print_thread2();
	Post* epistrofh_post(int );
	Thread(string , string ,Date );
	~Thread();
};


