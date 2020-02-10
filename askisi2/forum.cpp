#include <iostream>
#include <string>
#include "forum.h"
#include <cstdlib>

using namespace std;

List::Node::Node(Post& a,Node* b):dedomena(a),next(b)
{
	
}
 
int List::get_megethos()    /*megethos listas*/
{
	return megethos;
}

void List::push(Post& a)      /*prosthiki enos post sth lista*/
{
	Node* n=new Node(a,kefali);
	n->next=kefali;
	kefali=n;
	megethos++;
}

void List::print_list()       /*ektupwsh listas*/
{
	Node* temp=kefali;
	int i;
	for(i=0;i<megethos;i++)
	{
		temp->dedomena.print_post();
		temp=temp->next;
	}
}

void List::delete_list()     /*diagrafh listas*/
{
	int i;
	for(i=0;i<megethos;i++)
	{
		Node* temp;
		temp=kefali;
		kefali=kefali->next;
		delete temp;
	}
}

void List::union_list(List a)
{
	int i;
	Node* temp=a.kefali;
	for(i=0;i<a.megethos;i++)
	{
		push(temp->dedomena);
		temp=temp->next;
	}
}

Post List::return_data()
{
	return kefali->dedomena;
}


Tree::Treekomvos* Tree::get_riza()
{
	return riza;
}


void Tree::Treekomvos::push2(Post& a)     /*prosthiki enos post sth lista l tou komvou tou dentrou*/
{
	l.push(a);
}

Tree::Treekomvos::Treekomvos::Treekomvos(string a):name(a)
{
	left=NULL;
	right=NULL;
}

Tree::Treekomvos* Tree::insert_p(Treekomvos* a,Post& b)
{
	if(a==NULL)
	{
		a=new Treekomvos(b.get_creator());
		a->push2(b);	
	}
	else
	{
		if(b.get_creator()==(a->name))
		{
			a->push2(b);
		}
		else if(b.get_creator()<(a->name))
		{
			a->left=insert_p(a->left,b);
		}
		else if(b.get_creator()>(a->name))
		{
			a->right=insert_p(a->right,b);
		}
    }

    return a;
}

void Tree::print_tree(Treekomvos* a)      /*ektupwsh tou dentrou*/
{
	if(a!=NULL)
	{
		print_tree(a->left);
		cout<<"To onoma tou creator einai: "<<a->name<<endl;
		cout<<"Ektupwsh listas :"<<endl;;
		a->l.print_list();
		cout<<"**********************************"<<endl;
		print_tree(a->right);
	}
}

void Tree::delete_tree(Treekomvos* a)       /*diagrafh tou dentrou*/
{
	if(a!=NULL)
	{
		delete_tree(a->left);
		a->l.delete_list();
		delete_tree(a->right);
	}
}

Tree::Tree(Thread& a)
{
	int i;
	riza=NULL;
	for(i=0;i<10;i++)
	{
		 riza=insert_p(riza,*(a.epistrofh_post(i)));
	}	
}

void Tree::add_tree(Tree a)      
{
	enhance(a.riza);
}

void Tree::enhance(Treekomvos* a)
{
	if(a!=NULL)
	{
		enhance(a->left);
		List prosorino=a->l;
		riza=enhance2(riza,prosorino);
		enhance(a->right);
	}	
}

Tree::Treekomvos* Tree::enhance2(Treekomvos* a,List& b)         
{
	if(a==NULL)
        {
                a=new Treekomvos(b.return_data().get_creator());
                Post temp=b.return_data();
		a->push2(temp);    
        }
        else
        {
                if(b.return_data().get_creator()==(a->name))
                {
                        a->l.union_list(b);
                }
                else if(b.return_data().get_creator()<(a->name))
                {
                        a->left=enhance2(a->left,b);
                }
                else if(b.return_data().get_creator()>(a->name))
                {
                        a->right=enhance2(a->right,b);
                }
    }
    return a;
}


Forum::Forum(string i)
{
	forum_title=i;
        t= new Thread*[5];
	Date c,d;            
	d.set_date();   
	int k; 
	for(k=0;k<5;k++)                            
	{
        string a=get_subject_for_thread(k);
	string b=get_creator_for_thread(k);
	c.set_date();
	add_thread(a,b,c,k);
        }         
	cout<<endl;
	cout<<"Forum with title:"<<forum_title<<" has just been created!"<<endl;                             
}

Forum::~Forum()
{
	int j=1;
	for(j=0;j<5;j++)
	{
		delete t[j];   
	}
	delete [] t;
	cout<<"Forum with title:"<<forum_title<<" is about to be destroyed"<<endl;
}

void Forum::print_sorted()          
{
	Tree dentro(*t[2]);
	Tree dentro1(*t[1]);
	Tree dentro2(*t[0]);
	dentro.add_tree(dentro1);            /*prosthiki dentrou*/
	dentro.add_tree(dentro2);             /*prosthiki dentrou*/
	dentro.print_tree(dentro.get_riza());
	dentro.delete_tree(dentro.get_riza());
	cout<<"Tree deleted"<<endl;
	dentro1.delete_tree(dentro1.get_riza());
	cout<<"Tree deleted"<<endl;
	dentro2.delete_tree(dentro2.get_riza());
	cout<<"Tree deleted"<<endl;
}         

void Forum:: add_thread(string a,string b,Date c,int d)
{
    t[d]=new Thread(a,b,c);
}

void Forum::print_forum()                     
{
	cout<<"O titlos tou forum einai "<<forum_title<<endl;
	int i;
	for(i=0;i<5;i++)
	t[i]->print_thread2();
}                                            

void Forum::print_t(string a)           /*gia ektupwsh tou thread: Kanones kai xrhsimes plhrofories*/         
{
	cout<<"Ektupwsh tou thread: Kanones kai xrhsimes plhrofories"<<endl;
	int i;
	for(i=0;i<5;i++)
	{
		if(t[i]->get_subject()==a)
		{
			t[i]->print_thread();
		}
	}
}            

void Forum::print_tuxaia_p2()          
{ 
		int w;
		for(w=0;w<5;w++)
	{
		int k;
		k=rand()%50+1;
		int i;
		for(i=0;i<=4;i++)
		t[i]->ektupwsh_post(k);		
	}
}                    

