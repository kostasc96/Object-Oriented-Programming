#include <iostream>
#include <string>
#include "thread.h"

using namespace std;


struct List
{
	private:
		struct Node
		{
   				Post dedomena;
   				Node* next;
   				Node(Post& ,Node* );
		};
		Node* kefali;
		int megethos;
	public:
		int get_megethos();	/*megethos ths listas*/
		void push(Post& );     /*prosthiki enos post sth lista*/
		void print_list();     /*ektupwsh listas*/
		void delete_list();    /*diagrafh listas*/
		void union_list(List );  /*enwsh 2 listwn*/
		Post return_data();    /*epistrofh twn post ths listas*/
};


                  

struct Tree
{
	private:
		struct Treekomvos
		{
   			string name;
   			List l;
   			Treekomvos* left;
   			Treekomvos* right;
   			Treekomvos(string );
			void push2(Post& );   		
		};
		Treekomvos* riza;
	public:
		Treekomvos* get_riza();
		void push2(Post& );     /*prosthiki enos post sth lista l tou komvou tou dentrou*/
		Tree(Thread& );
		Treekomvos* insert_p(Treekomvos* ,Post& );    
		void print_tree(Treekomvos* );      /*ektupwsh dentrou*/
		void delete_tree(Treekomvos* );     /*diagrafh dentrou*/
		void add_tree(Tree );   /*eisagwgh dentrou se dentro*/
		void enhance(Treekomvos* );
		Treekomvos* enhance2(Treekomvos* ,List& );
};




class Forum
{
	private:
	string forum_title;
	Thread **t;
	int tcounter;
	public:
	void add_thread(string ,string ,Date ,int );
	void print_forum(); 
	void print_t(string );
	void print_tuxaia_p2();
	void print_sorted();
	Forum(string );
	~Forum();
};


typedef struct listkomvos* listptr;

struct listkomvos
{
   Post* dedomena;
   listptr next;
};

typedef struct treekomvos* treeptr;

struct treekomvos
{
   string name;
   listptr start;
   listptr left;
   listptr right;
};
