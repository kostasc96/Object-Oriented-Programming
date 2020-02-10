#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "creature.h"
#include "creature_society.h"

using namespace std;


int main(int argc,char** argv)
{
    srand(time(NULL)); 
    if(argc!=6)
    {
	cout<<"Please give the right arguements"<<endl;
    }
    int N=atoi(argv[1]);  /*arithmos plasmatwn*/
    int M=atoi(argv[2]);   /*arithmos energeiwn*/
    int L=atoi(argv[3]);    /*zwh ka8e plasmatos*/
    int good_thrsh=atoi(argv[4]);
    int bad_thrsh=atoi(argv[5]);
    creature_society a(N,L,good_thrsh,bad_thrsh);
    int k;
    for(k=0;k<M;k++)
    {  
        int t=rand()%2+0;   /*gia 0 ginetai beat kai gia 1 ginetai bless*/
        if(t!=0)
        {
            int n=rand()%N+0;   /*epilogh tuxaiou plasmatos gia na eulogithei*/
            a.bless(n);
        }
        else
        {
            int n=rand()%N+0;   /*epilogh tuxaiou plasmatos gia na xtupithei*/
            a.beat(n);
        }
    }
    int g=a.no_of_good();
    int z=a.no_of_zobies();
    if(g==N)                           /*an o arithmos twn good_creature isoutai me ton sunoliko arithmo twn plasmatwn*/
    {
        cout<<"------------------------"<<endl;
        cout<<"Good Dominates the world"<<endl;
        cout<<"------------------------"<<endl;
    }
    else if(z==N)                      /*an o arithmos twn zobie isoutai me ton sunoliko arithmo twn plasmatwn*/
    {
        cout<<"----------------------"<<endl;
        cout<<"This is a dead society"<<endl;
        cout<<"----------------------"<<endl;
    }
    else
    {
        cout<<"------------------------------"<<endl;
        cout<<"Try again to improve the world"<<endl;
        cout<<"------------------------------"<<endl;
    }
	return 0;
}

