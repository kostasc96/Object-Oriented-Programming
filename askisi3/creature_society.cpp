#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include "creature.h"
#include "creature_society.h"

using namespace std;


extern int N;

string good_names[]={"Dolphin_","Dog_","Hamster_","Cat_","Fish_"};
string bad_names[]={"Lion_","Tiger_","Snake_","Cobra_","Anaconda_"};

creature_society::creature_society(int a,int b,int c,int d):creature_num(a),good_t(c),bad_t(d)
{
    int i;
    pinakas=new creature*[creature_num];
    for(i=0;i<creature_num;i++)
    {
        int random_num=rand()%2+0;
        if(random_num!=0)
        {
            int r=rand()%5+0;
            string s=good_names[r];  /*epilogh tuxaiou onomatos gia good_creature*/
            std::stringstream ss;
            ss << i;
            s.append(ss.str());         /*prosarthsh enos arithmou sto onoma tou creature*/
            pinakas[i]=new good_creature(s,b,this);
        }
        else
        {
            int r1=rand()%5+0;
            string s1=bad_names[r1];  /*epilogh tuxaiou onomatos gia bad_creature*/
            std::stringstream ss;
            ss << i;
            s1.append(ss.str());         /*prosarthsh enos arithmou sto onoma tou creature*/
            pinakas[i]=new bad_creature(s1,b,this);
        }
    }
    cout<<"Creature society created"<<endl;
}

creature_society::~creature_society()
{
    int i;
    for(i=0;i<creature_num;i++)
    {
        delete pinakas[i];
    }
    delete [] pinakas;
    cout<<"Creature Society destroyed"<<endl;
}

void creature_society::beat(int i)
{
	pinakas[i]->beat();
}

void creature_society::bless(int i)
{
	pinakas[i]->bless();        		/*arxika kaleitai h bless ths class creature*/
	if(pinakas[i]->is_a_good())    		/*an to plasma einai good_creature*/
    {
        if(pinakas[i]->get_life()>good_t)    	/*an h zwh tou plasmatos einai megaluterh apo ena good_thrsh*/
        {
            this->clone_next(i);              	/*kaleitai h clone_next*/
        }
    }
    else					/*an to plasma einai bad_creature*/
    {
        if(pinakas[i]->get_life()>bad_t)	/*an h zwh tou plasmatos einai megaluterh apo ena bad_thrsh*/
        {
            this->clone_zobies(i);		/*kaleitai h clone_zobies*/
        }
    }
}

void creature_society::clone_next(int i)
{
	int pos=(i+1)%creature_num;
	delete pinakas[pos];
	pinakas[pos]=pinakas[i]->clone(pinakas[i]);
}

void creature_society::clone_zobies(int i)
{
	int j;
	if(i<creature_num-1)   /*to i den prepei na antistoixei sthn teleftaia thesi*/
	{
        for(j=i+1;j<creature_num;j++)
        {
            if(pinakas[j]->is_a_zobie())
            {
                delete pinakas[j];
                pinakas[j]=pinakas[i]->clone(pinakas[i]);
            }
        }
   	}
}


int creature_society::no_of_good()
{
    int number_good=0;
    int i;
    for(i=0;i<creature_num;i++)
    {
        if(pinakas[i]->is_a_good())
        {
            number_good++;
        }
    }
    return number_good;
}

int creature_society::no_of_zobies()
{
    int number_zobies=0;
    int i;
    for(i=0;i<creature_num;i++)
    {
        if(pinakas[i]->is_a_zobie())
        {
            number_zobies++;
        }
    }
    return number_zobies;
}

creature* creature_society::get_pinakas(int i)
{
    return pinakas[i];
}


