#include <iostream>
#include <string>
#include "creature.h"
#include "creature_society.h"

using namespace std;

creature::~creature()
{
    //cout<<"Deleting creature"<<endl;
}


creature::creature(string a,int b,creature_society* c):name(a),life(b),cs(c)
{
	//cout<<"Creature "<<name<<" has just been created"<<endl;
}

creature::creature(const creature& s)
{
	name=s.name;
	life=s.life;
	cout<<"I just created a creature with name "<<get_name()<<" by copying"<<endl;
}



bool creature::is_a_zobie()
{
	if(get_life()==0)
	{
        return true;
	}
	else
    {
        return false;
    }
}

bool creature::is_a_good()
{
	return true;
}

void creature::bless()
{
	if(!(is_a_zobie()))
	{
		life++;
	}
	cout<<"Creature with name "<<get_name()<<" was blessed"<<endl;
}

void creature::beat()
{
	if(!(is_a_zobie()))
	{
		life--;
	}
	cout<<"Creature with name "<<get_name()<<" was beated"<<endl;

}


int creature::get_life()
{
	return life;
}

string creature::get_name()
{
    return name;
}

creature_society* creature::get_cs()
{
    return cs;
}

good_creature::good_creature(string a,int b,creature_society* c):creature(a,b,c)
{
    cout<<"Good Creature "<<get_name()<<" has just been created"<<endl;
}

good_creature::good_creature(const good_creature& s):creature(s)
{

}

good_creature::~good_creature()
{
    cout<<"Destroying good creature with name "<<get_name()<<endl;
}

bool good_creature::is_a_good()
{
    if(get_life()>0)
    return true;
}

creature* good_creature::clone(creature* a)
{
   creature* cloned=new good_creature(a->get_name(),a->get_life(),a->get_cs());
   cout<<"Creature "<<a->get_name()<<" cloned"<<endl;
   return cloned;
}

bool bad_creature::is_a_good()
{
    if(get_life()>0)
    return false;
}

bad_creature::bad_creature(string a,int b,creature_society* c):creature(a,b,c)
{
    cout<<"Bad Creature "<<get_name()<<" has just been created"<<endl;
}

bad_creature::bad_creature(const bad_creature& s):creature(s)
{

}

bad_creature::~bad_creature()
{
    cout<<"Destroying bad creature with name "<<get_name()<<endl;
}

creature*  bad_creature::clone(creature* a)
{
    creature* cloned=new bad_creature(a->get_name(),a->get_life(),a->get_cs());
    cout<<"Creature "<<a->get_name()<<" cloned"<<endl;
    return cloned;
}

