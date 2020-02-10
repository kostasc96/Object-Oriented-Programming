#ifndef __crea__
#define __crea__

#include <iostream>
#include <string>
#include "creature_society.h"

using namespace std;


class creature
{
	private:
		string name;
		int life;
		creature_society* cs;   /*deikths se creature_society*/
	public:
		creature(string ,int ,creature_society* );
		creature(const creature& );
		virtual ~creature();
		bool is_a_zobie();
		virtual bool is_a_good()=0;
		virtual creature* clone(creature* )=0;
		void beat();
		void bless();
		int get_life();
		string get_name();
		creature_society* get_cs();
};

class good_creature:public creature
{
	public:
		good_creature(string ,int ,creature_society* );
		good_creature(const good_creature& );
		~good_creature();
		creature* clone(creature* );
		bool is_a_good();
};

class bad_creature:public creature
{
	public:
		bad_creature(string ,int ,creature_society* );
		bad_creature(const bad_creature& );
		~bad_creature();
		creature* clone(creature* );
		bool is_a_good();
};

#endif

