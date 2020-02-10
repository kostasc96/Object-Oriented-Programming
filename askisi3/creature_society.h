#ifndef __creature_soc__
#define __creature_soc__

#include <iostream>
#include <string>
#include "creature.h"

using namespace std;

class creature;

class creature_society
{
	private:
		creature** pinakas;
		int creature_num;
		int good_t;      /*good_thrsh*/
		int bad_t;       /*bad_thrsh*/
	public:
		creature_society(int a,int b,int c,int d);
		~creature_society();
		void beat(int );
		void bless(int );
		void clone_next(int );
		void clone_zobies(int );
		int no_of_good();
		int no_of_zobies();
		creature* get_pinakas(int );
};

#endif

