#include <iostream>
#include "data.h"
#include <cstdlib>

using namespace std;

int get_id_for_post()
{
	return id_for_post;
}

string get_title_for_post()
{
	int thesi=rand() % 19+0;
	return title_for_post[thesi];
}

string get_creator_for_post()
{
	int thesi=rand() % 19+0;
	return creator_for_post[thesi];
}

string get_text_for_post()
{
	int thesi=rand() % 19+0;
	return text_for_post[thesi];
}

string get_subject_for_thread(int a)
{
	return subject_for_thread[a];
}

string get_creator_for_thread(int a)
{
	return creator_for_thread[a];
}

